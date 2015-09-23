

#include "OssSubObject.h"
#include "OssStats.h"
#include "Ali.h"
#include "OssFS.h"
#include "AliConf.h"
#include "log.h"
#include "util.h"
#include <iostream>
using namespace std;
//using namespace afs;
OssSubObject::OssSubObject(OssFS *fs, Oss *oss, const char *bucket,
        const char *pathname, const char *filename, OssStats * stats,
        size_t part_num, OssGroupObject *group) /*:
        OssObject(fs, oss, bucket, pathname, filename, stats)*/ {
    // TODO Auto-generated constructor stub
	pthread_mutexattr_t mutexattr;
	pthread_mutexattr_init(&mutexattr);
	pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_RECURSIVE);	    
    pthread_mutex_init(&m_mutex, &mutexattr);
	pthread_mutexattr_destroy(&mutexattr);

    m_readonly = true;    
    m_read_pos = 0;
    m_write_pos = 0;
    
    //the buf size
    m_buf_size = 0;
    m_synced = true;
    m_data = NULL;
	m_part_num = part_num;
    m_group = group;
}

OssSubObject::~OssSubObject() {

    destory();
    pthread_mutex_destroy(&m_mutex);
}


/*
д�����߼�����:
	д����ʱ��Ϊ�������: 
	���1) ��ǰд��ʱ, ������������
		   ����Ѿ���������, ����Ҫ�����е�����һ���Լ��ص��ڴ���, �ٽ���д��;
		   д��ʱ���������: 
		   ���1: д���offset <= ��ǰ��ʵ�ʴ�С, ��������ͨ��д��
		   ���2: д���offset > ��ǰ��ʵ�ʴ�С, �ڵ�ǰ����offset֮�����0
	
	���2) ��ǰд��ʱ, ���鲢������
			����������, �������OSS��������, ֱ��д��
			д��ʱҲ���������:
		   ���1: д���offset ��0��ʼ, ��������ͨ��д��
		   ���2: д���offset > ����0, ��0��offset֮�����0	

*/
int OssSubObject::write_data(off_t offset, size_t size, const char *buf) 
{
	log_debug("offset:%Zd, size:%Zd", offset, size);
    int written = (int) size;

    //ע�� �����ȡ���С��Ҫ��������, �������pthread_mutex_lock(&m_mutex) ֮ǰ
	size_t subobject_size = m_group->get_subobject_size(m_part_num);

    pthread_mutex_lock(&m_mutex);
    m_synced = false;
	m_readonly = false;			

	//��ȡ��ǰ��Ĵ�С
	if ((subobject_size > 0) && (m_buf_size == 0))
	{
		//��OSS�����������ݵ�cloudfs��
		RE_ALOCATE(m_data, m_buf_size, subobject_size, m_group->get_cloudfs())
		int res = m_group->get_cloudfs()->get_oss()->get_object_data_with_range(AliConf::BUCKET.c_str(), 
										  m_group->get_path_name(), 
										  m_data, 
										  m_part_num * AliConf::BLOCK_SIZE, 
										  subobject_size);
		if (res < 0)
		{
			log_error("file: [%s] get_object_data_with_range range[%Zd-%Zd] failed", 
										m_group->get_path_name(), 
										(m_part_num * AliConf::BLOCK_SIZE), 
										(m_part_num * AliConf::BLOCK_SIZE+subobject_size-1));
			pthread_mutex_unlock(&m_mutex);							
			return 0;							
										
		}
		
	}

	//offset С���ļ���С, ��������д��, ���ݱ���д��Ľ�β�����ڴ�
    if (((size_t) offset) <= subobject_size) {
        RE_ALOCATE(m_data, m_buf_size, (offset+size), m_group->get_cloudfs())
    }
    //offset �����ļ���С, subobject��ǰβ��-offset֮����д0
    else 
	{
		log_error("file[%s] offset [%Zd] is bigger than fileSize [%Zd]", 
					get_path_name(), offset, subobject_size);
		log_error("subObject buff info: [m_read_pos: %Zd m_write_pos = %Zd m_buf_size: %Zd m_stats->size: %Zd]", 
									m_read_pos, m_write_pos, m_buf_size, subobject_size);

		//�ȷ����ڴ�
        RE_ALOCATE(m_data, m_buf_size, (offset+size), m_group->get_cloudfs())

        //subobject��ǰβ��-offset֮����д0
		memset((m_data+subobject_size), 0, (offset -  subobject_size));

    }

	//�ѱ�����Ҫд����������m_data
    memcpy(m_data + offset, buf, size);
    m_write_pos = std::max(m_write_pos, (size_t)(offset + size));
    pthread_mutex_unlock(&m_mutex);
    return written;
}


int OssSubObject::read_data(off_t offset, size_t size, char *buf) {

    //ע�� �����ȡ���С��Ҫ��������, �������pthread_mutex_lock(&m_mutex) ֮ǰ
	size_t subobj_size = m_group->get_subobject_size(m_part_num);

    pthread_mutex_lock(&m_mutex);

	log_debug("offset:%d, size:%d", (int)offset, (int)size);

	// �����ʼƫ�Ƴ������ļ��ܳ��ȣ������ٶ�ȡ��ֱ�ӷ���
    if (subobj_size <= (size_t) offset) 
	{
    	pthread_mutex_unlock(&m_mutex);
        return 0;
    }    

	// ����������ݵ����ƫ�Ƴ����ļ����ȣ������ļ����ֶ���
    if (subobj_size < (offset + size)) {
        size = subobj_size - offset;
	}


	//��һ�μ���, һ���԰��ڴ�����, OSS object����ȫ�����ص�cloudfs��
	if ((subobj_size > 0) && (m_buf_size == 0))
	{
		RE_ALOCATE(m_data, m_buf_size, subobj_size, m_group->get_cloudfs())
        int res = m_group->get_cloudfs()->get_oss()->get_object_data_with_range(AliConf::BUCKET.c_str(), 
        					   			  m_group->get_path_name(), 
        					   			  m_data, 
        					   			  m_part_num * AliConf::BLOCK_SIZE, 
        					   			  subobj_size);
        if (res < 0)
        {
        	log_error("file:[%s] get_object_data_with_range failed, range[%Zd-%Zd]", m_part_num * AliConf::BLOCK_SIZE, (subobj_size-1));
        	return 0;
        }        
	}
	
    m_read_pos = std::max(m_read_pos, (size_t)(offset + size));    
    memcpy(buf, m_data + offset, size);
    on_read_check_block();
    pthread_mutex_unlock(&m_mutex);
    return (int) size;
}


int OssSubObject::drop_cache(bool lock) {
    pthread_mutex_lock(&m_mutex);
    int res = 0;
    log_debug("tttt file_name %s, m_synced %d", m_group->get_file_name(), m_synced);
    SAFE_DELETE_ARRAY(m_data);
    res = m_buf_size;
    m_group->get_cloudfs()->decrease_cache(m_buf_size);
    log_debug("tttt decrease_cache: file_name: %s decrease_size = %zd", m_group->get_file_name(), m_buf_size);
	m_read_pos = 0;
	m_write_pos = 0;    
    m_buf_size = 0;
    pthread_mutex_unlock(&m_mutex);
    return res;
}

/*sync will include the drop cache*/
//pub_obj  true: ʹ��put_object�ϴ�����
//		   false: ʹ��upload part�ϴ�����
int OssSubObject::sync(bool put_obj) 
{

	//ע�� �����ȡ���С��Ҫ��������, �������pthread_mutex_lock(&m_mutex) ֮ǰ
	size_t subobj_size = m_group->get_subobject_size(m_part_num);
    pthread_mutex_lock(&m_mutex);
	log_debug("enter ...");
    int res = 0;
    
	log_debug("m_synced:%d", m_synced);
    if (!m_synced) 
	{
        m_synced = true;


		// �ύ Multipart ���ݵ��ڴ�
		if (put_obj)
		{
			OSS_FILE_META meta;

			if (m_group->get_stats()->size > m_buf_size)
			{
				log_error("m_buf_size[%Zd] is smaller than file size[%Zd]", m_buf_size, m_group->get_stats()->size);
			}
			m_group->get_stats()->to_meta(meta);
        	m_group->get_cloudfs()->get_oss()->put_object_data(AliConf::BUCKET.c_str(), 
															   m_group->get_path_name(), 
															   m_data, 
															   meta);
		}
		else
		{
			if (subobj_size > m_buf_size)
			{
				log_error("m_buf_size[%Zd] is smaller than sub size[%Zd]", m_buf_size, subobj_size);
			}
			string ret = m_group->get_cloudfs()->get_oss()->upload_part(AliConf::BUCKET.c_str(), 
	        				   m_group->get_path_name(),
	        				   m_group->get_uploadId().c_str(), 
	        				   m_part_num + 1, 
	        				   m_data, 
	        				   subobj_size);
	        if (ret == "") {
	        	log_error("upload_part failed, m_bucket[%s], objectname[%s], uploadid[%s], partnum[%d]", 
	        			   AliConf::BUCKET.c_str(),m_group->get_path_name(),m_group->get_uploadId().c_str(),(m_part_num + 1)); 
	        }
	        else {
	        	log_debug("upload_part succeed, m_bucket[%s], objectname[%s], uploadid[%s], partnum[%d]", 
	        			   AliConf::BUCKET.c_str(),m_group->get_path_name(),m_group->get_uploadId().c_str(),(m_part_num + 1));         
	        }
		}
		
        
    }


	//�ڴ��������ͷ�
	SAFE_DELETE_ARRAY(m_data);
	res = m_buf_size;
	m_group->get_cloudfs()->decrease_cache(m_buf_size);
	log_debug("tttt decrease_cache: file_name: %s decrease_size = %zd", m_group->get_file_name(), m_buf_size);
	m_read_pos = 0;
	m_write_pos = 0;
	m_buf_size = 0;
    
    pthread_mutex_unlock(&m_mutex);
    return res;
}

int OssSubObject::destory() {
    return 0;
}

//��������������ִ��upload part copy����, ���ڸò����ȽϷ�ʱ, д������߳��첽����
int OssSubObject::upload_part_copy()
{

	//ע�� �����ȡ���С��Ҫ��������, �������pthread_mutex_lock(&m_mutex) ֮ǰ
	size_t subobj_size = m_group->get_subobject_size(m_part_num);

	pthread_mutex_lock(&m_mutex);
	if (subobj_size > 0)
	{
		UploadPartCopy *pNode = new UploadPartCopy;
		pNode->bucket = AliConf::BUCKET;
		pNode->object = m_group->get_path_name();
		pNode->s_object = m_group->get_path_name();
		pNode->uploadid = m_group->get_uploadId();
		pNode->part_num = m_part_num + 1;
		pNode->start_pos = m_part_num * AliConf::BLOCK_SIZE;
		pNode->end_pos = pNode->start_pos + subobj_size - 1;
		pNode->oss = m_group->get_cloudfs()->get_oss();
		
		m_group->get_cloudfs()->threadpool_add_upload_part_copy_task(pNode);
	}	
	pthread_mutex_unlock(&m_mutex);

	return 0;
}


void OssSubObject::on_write_check_block()
{
	pthread_mutex_lock(&m_mutex);
	//���ж�write_pos�Ƿ�����, ���write_pos�Ѿ�����, ֱ������upload part
	if (m_write_pos == AliConf::BLOCK_SIZE)
	{
		smart_upload_part();
		pthread_mutex_unlock(&m_mutex);
		return;
	}

	pthread_mutex_unlock(&m_mutex);
	return;

}



void OssSubObject::on_read_check_block()
{
	pthread_mutex_lock(&m_mutex);

	//�ж�read_pos�Ƿ�����, ͬʱwrite_pos�Ƿ�Ϊ0, �����������, ֱ���ͷ��ڴ�
	if ((m_read_pos == AliConf::BLOCK_SIZE) && (m_write_pos == 0))
	{
		drop_cache(true);
		pthread_mutex_unlock(&m_mutex);
		return;
	}

	//����������ڱ���������
	pthread_mutex_unlock(&m_mutex);
	return;

}

//������
void OssSubObject::on_fclose_check_block(bool bGroupReadOnly)
{
	//Groupֻ��, ��ֱ�ӷ���
	pthread_mutex_lock(&m_mutex);
	if (bGroupReadOnly)
	{
		m_readonly = true;
		pthread_mutex_unlock(&m_mutex);
		return;
	}
	
	
	if (m_readonly)
	{
		//�鴦��ֻ��״̬, copyһ��
		upload_part_copy();
	}
	m_readonly = true;
	pthread_mutex_unlock(&m_mutex);
	return;

}

void OssSubObject::smart_upload_part()
{
	//����ÿ�ֻ��, ʲôҲ����, ֱ�ӷ���
	pthread_mutex_lock(&m_mutex);
	if (m_readonly)
	{
		pthread_mutex_unlock(&m_mutex);
		return;
	}
	
	if (m_group->get_cloudfs()->threadpool_is_busy())
	{
		//thread pool�Ѿ�����, �˴��ڱ��߳̽���upload part����
		sync(false);
	}
	else
	{
		//thread poolδ����, ��upload part ���͸�thread pool���в���
		UploadPart *pNode = new UploadPart;
		pNode->isDropCache = true;
		pNode->subObj = this;
		m_group->get_cloudfs()->threadpool_add_task(pNode);
	}
	pthread_mutex_unlock(&m_mutex);
}



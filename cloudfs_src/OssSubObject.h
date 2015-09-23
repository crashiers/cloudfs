

#ifndef OSSSUBOBJECT_H_
#define OSSSUBOBJECT_H_

#include "OssObject.h"
#include "OssGroupObject.h"
#include "AliConf.h"
#include <pthread.h>


/*
����ļ��������,write_data��һ��д��ʱ�����ļ�ȫ�����س���, ����POS��Ϊ���С

дpos   ��          ��              ��    
��pos   ��          δ��            0

���   write_data   write_data      write_data
        upload      upload          upload         
		
дpos   δ��         δ��            δ��                       
��pos   ��           δ��            0             
���   fclose        fclose          fclose       (upload�Ŀ�������posָ�ϴ��Ϊ׼)
       upload        upload          upload
	   

дpos   0            0                0
��pos   ��           δ��             0 	   
���:   read_data    fclose
        �ͷ��ڴ�     �ͷ��ڴ�         ʲô������


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
    

	//��ȡ��ǰ��Ĵ�С
	size_t subobject_size = get_size();
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
			return 0;							
										
		}
		
	}
*/



//class OssGroupObject;
//namespace afs {
//class OssSubObject: public OssObject {
class OssSubObject{
public:
    OssSubObject(OssFS *fs, Oss *oss, const char *bucket, const char *pathname,
            const char *filename, OssStats * stats, size_t part_num, OssGroupObject *group);
    virtual ~OssSubObject();
protected:
    bool m_synced;
    bool m_readonly;
    size_t m_buf_size;
    size_t m_read_pos;
    size_t m_write_pos;
	size_t m_part_num;
    char *m_data;

    pthread_mutex_t m_mutex;
    OssGroupObject *m_group;	
    int destory();
	
    
public:	
    int drop_cache(bool lock);
    bool is_write_ready() {
    	pthread_mutex_lock(&m_mutex);
        bool write_ready = (m_write_pos == AliConf::BLOCK_SIZE);
        pthread_mutex_unlock(&m_mutex);
        return write_ready;
    }

    //the flags of sub files should comes from the above group object
    int get_flags() {
        return ((OssObject *)m_group)->get_flags();
    }
    //the is readonly of sub files should comes from the above group object
    bool is_readonly() {
        return m_readonly;
    }

	const char *get_file_name() const {
		
		return ((OssObject *)m_group)->get_file_name();
	}
	const char *get_path_name() const {
		return ((OssObject *)m_group)->get_path_name();
	}

	size_t get_part_num() {
		return m_part_num;
	}
	
	inline size_t get_buf_size() {
		return m_buf_size;
	}

	void set_synced(bool bSynced) { m_synced = bSynced;}
		
    int read_data(off_t offset, size_t size, char *buf);
    int write_data(off_t offset, size_t size, const char *buf);
    int sync(bool dc = true);
    int upload_part_copy();
    void on_fclose_check_block(bool bGroupReadOnly);
	void smart_upload_part();
	void on_read_check_block();
	void on_write_check_block();
};
//}
#endif /* OSSSUBOBJECT_H_ */

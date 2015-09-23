
#include "OssSymObject.h"
#include "AliConf.h"
#include "oss_api.h"
#include "log.h"
#include <iostream>
//using namespace afs;
using namespace std;

//��OSS����symlink�ļ�ʱ���õĹ��캯��
OssSymObject::OssSymObject(OssFS *fs, Oss *oss, const char *bucket,
		const char *pathname, const char *filename, OssStats * stat) :
		OssObject(fs, oss, bucket, pathname, filename, stat) {
	// TODO Auto-generated constructor stub

	//����m_link_name��Ҫ��ʵ���ڴ泤��
	m_link_name = new char[stat->size + 1];

}


OssSymObject::~OssSymObject() {
	// TODO Auto-generated destructor stub
	SAFE_DELETE_ARRAY(m_link_name);
	destory();
}

void OssSymObject::set_link_obj(const char *link,size_t size){
	memcpy(m_link_name, link, size); 
	m_link_name[size] = 0;
	
	//������push��OSS�� 
	OSS_FILE_META meta;
	oss_object_desc_t object;
	
	m_stats->to_meta(meta);

	//����������OSS��̨�洢�������׺��
	object.name.assign(m_pathname);
	object.name = object.name + string(".") + AliConf::SYMLINK_TYPE_NAME;
	
	object.size = strlen(m_link_name);
	object.user_meta["x-oss-meta-type"] = meta["type"];
	object.user_meta["x-oss-meta-mtime"] = meta["mtime"];
	object.user_meta["x-oss-meta-mode"] = meta["mode"];

	if (0 != m_fs->get_oss()->put_object_data(AliConf::BUCKET.c_str(), object, m_link_name))
	{
		log_error("m_oss->put_object_data failed: [%s/%s]--%s", AliConf::BUCKET.c_str(), m_pathname, m_link_name);
	}
}


void OssSymObject::get_link_obj(char *link, size_t size){
	//��OSS�Ͻ����ݶ�������
	string sym_name = string(m_pathname) + string(".") + AliConf::SYMLINK_TYPE_NAME;
	m_fs->get_oss()->get_object_data(AliConf::BUCKET.c_str(), sym_name.c_str(), m_link_name, m_stats->size);
	memcpy(link,m_link_name,m_stats->size);
	link[m_stats->size] = '\0';
}


int OssSymObject::destory() {
	return 0;
}

int OssSymObject::delete_oss_object()
{
	string sym_name = string(m_pathname) + string(".") + AliConf::SYMLINK_TYPE_NAME;
	int res = m_fs->get_oss()->del_object(AliConf::BUCKET.c_str(), sym_name.c_str(), false);
	return res;	
}


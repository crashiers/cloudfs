
#include "OssDirObject.h"
//using namespace afs;
OssDirObject::OssDirObject(OssFS *fs, Oss *oss, const char *bucket,
        const char *pathname, const char *filename, OssStats * stat) :
    OssObject(fs, oss, bucket, pathname, filename, stat) {
    // TODO Auto-generated constructor stub

	// ��ʼ����д��
	if (AliConf::ONLINE_SYNC_CYCLE != 0)
		pthread_rwlock_init(&m_rwlock, NULL);

}

OssDirObject::~OssDirObject() {
    // TODO Auto-generated destructor stub
    destory();
}
int OssDirObject::destory() {
	//��Ŀ¼��������ʱ, ����ҪȥOSS������ش���
	/*
	if (0 == strcmp(m_pathname, "/"))
	{
		return 0;
	}
    int res = m_fs->get_oss()->del_object(AliConf::BUCKET.c_str(), m_pathname,true);
    return res;
    */
    return 0;
}


void OssDirObject::rdlock()
{
	if (AliConf::ONLINE_SYNC_CYCLE != 0)
		pthread_rwlock_rdlock(&m_rwlock);
}

void OssDirObject::wrlock()
{
	if (AliConf::ONLINE_SYNC_CYCLE != 0)
		pthread_rwlock_wrlock(&m_rwlock);
}

void OssDirObject::unlock()
{
	if (AliConf::ONLINE_SYNC_CYCLE != 0)
		pthread_rwlock_unlock(&m_rwlock);
}


int OssDirObject::delete_oss_object()
{
	if (0 == strcmp(m_pathname, "/"))
	{
		return 0;
	}
	
    int res = m_fs->get_oss()->del_object(AliConf::BUCKET.c_str(), m_pathname,true);
    return res;

}



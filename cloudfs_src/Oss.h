
#ifndef OSS_H_
#define OSS_H_
#include <map>
#include "oss_api.h"
#include "OssMime.h"
#include "OssHeader.h"


using namespace std;
typedef map<string, string> OSS_FILE_META;
typedef map<string, OSS_FILE_META> OSS_FILE_MAP;

#define MAX_PART_NUM 10000
#define MAX_ETAG_LENGTH 1024

//namespace ali {
class Oss {
public:
	Oss();
	virtual ~Oss();
public:
	int init(const char *host, const char *id, const char *key);
	int get_bucket(const char *bucket, const char *prefix, const char *delimiter, vector<oss_object_desc_t> &object_list);

	int get_object_list(const char *bucket, OSS_FILE_MAP &objects);
    int copy_object_data(const char *bucket, const char *old_name, const char *new_name);
	int put_object_data(const char *bucket, const char *name, const char *buf,
			OSS_FILE_META & meta);
	int put_object_data(const char *bucket, const char *name,
			OSS_FILE_META & meta);

	int put_object_data(const char *bucket, oss_object_desc_t &put_object_desc, const char *buf);
	
	int get_object_data(const char *bucket, const char *name, char *buf,
			size_t size);

	unsigned int get_object_data(const char *bucket, const char *name, char *buf,
			int start_pos, size_t size);
			
	int del_object(const char *bucket, const char *name, bool dir);
	
	int get_object_meta(const char *bucket, const char *name,
			OSS_FILE_META & meta);
			
	int get_object_meta(const char* bucket, const char* name,
			oss_object_desc_t & obj_desc);
			
	int put_object_meta(const char *bucket, const char *name,
			OSS_FILE_META & meta);

	//�ɹ���������uploadId,ʧ�ܷ��ؿ�("")uploadId
	string initiate_multipart_upload(const char *bucket, const char *name);

	//�ɹ���������etag,ʧ�ܷ��ؿ�("")etag
	string upload_part(const char *bucket, const char *name, const char *upload_id, 
		int part_num, char *buf, size_t data_len);

	//�ɹ���������etag,ʧ�ܷ��ؿ�("")etag
	//���end_posΪ0��copy����objectΪһ��part
	string upload_part_copy(const char *bucket, const char *name, const char* s_name, 
							const char *upload_id, int part_num, size_t start_pos, size_t end_pos);

	//�ɹ���������etag,ʧ�ܷ��ؿ�("")etag
	string complete_multipart_upload(const char *bucket, const char *name, const char *upload_id);

	//�ɹ���������multiupload���������,uploadId������upload_id_array��
	int list_multipart_upload(const char *bucket, const char *name, char *upload_id_array[]);

	//�ɹ�����part�ĸ���,part_num��etag�ֱ𱣴���part_num_array��part_etag��
	int list_part(const char *bucket, const char *name, const char *upload_id, 
				  map<int, string>& part_etag, map<int, long>& part_size);

	int get_object_data_with_range(const char *bucket, const char *name, char *buf,
										size_t startPos, size_t size);

	void abort_multipart_upload(const char *bucket, const char *name, const char *upload_id);


private:
	oss_address_t address;
	OssMime* m_mime;
	OssHeader* m_header;
};
//}
#endif /* OSS_H_ */

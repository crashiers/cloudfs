/*
 * =============================================================================
 *
 *       Filename:  oss_client.h
 *
 *    Description:  oss client.
 *
 *        Created:  09/03/2012 09:16:21 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_CLIENT_H
# error Never include <oss_client.h> directly, use <client.h> instead.
#endif

#ifndef OSS_CLIENT_H
#define OSS_CLIENT_H

#define _OSS_ABORT_MULTIPART_UPLOAD_REQUEST_H
#include <oss_abort_multipart_upload_request.h>
#undef _OSS_ABORT_MULTIPART_UPLOAD_REQUEST_H

#define _OSS_ACCESS_CONTROL_LIST_H
#include <oss_access_control_list.h>
#undef _oss_access_control_list_h

#define _OSS_BUCKET_H
#include <oss_bucket.h>
#undef _OSS_BUCKET_H

#define _OSS_CLIENT_H
#include <oss_client.h>
#undef _OSS_CLIENT_H

#define _OSS_COMPLETE_MULTIPART_UPLOAD_REQUEST_H
#include <oss_complete_multipart_upload_request.h>
#undef _oss_complete_multipart_upload_request_h

#define _OSS_COMPLETE_MULTIPART_UPLOAD_RESULT_H
#include <oss_complete_multipart_upload_result.h>
#undef _OSS_COMPLETE_MULTIPART_UPLOAD_RESULT_H

#define _OSS_COPY_OBJECT_REQUEST_H
#include <oss_copy_object_request.h>
#undef _OSS_COPY_OBJECT_REQUEST_H

#define _OSS_COPY_OBJECT_RESULT_H
#include <oss_copy_object_result.h>
#undef _OSS_COPY_OBJECT_RESULT_H

#define _OSS_DELETE_MULTIPLE_OBJECT_REQUEST_H
#include <oss_delete_multiple_object_request.h>
#undef _OSS_DELETE_MULTIPLE_OBJECT_REQUEST_H

#define _OSS_GENERATE_PRESIGNED_URL_REQUEST_H
#include <oss_generate_presigned_url_request.h>
#undef _OSS_GENERATE_PRESIGNED_URL_REQUEST_H

#define _OSS_GET_OBJECT_GROUP_INDEX_RESULT_H
#include <oss_get_object_group_index_result.h>
#undef _OSS_GET_OBJECT_GROUP_INDEX_RESULT_H

#define _OSS_GET_OBJECT_GROUP_REQUEST_H
#include <oss_get_object_group_request.h>
#undef _OSS_GET_OBJECT_GROUP_REQUEST_H

#define _OSS_GET_OBJECT_REQUEST_H
#include <oss_get_object_request.h>
#undef _OSS_GET_OBJECT_REQUEST_H

#define _OSS_GRANT_H
#include <oss_grant.h>
#undef _OSS_GRANT_H

#define _OSS_INITIATE_MULTIPART_UPLOAD_REQUEST_H
#include <oss_initiate_multipart_upload_request.h>
#undef _OSS_INITIATE_MULTIPART_UPLOAD_REQUEST_H

#define _OSS_INITIATE_MULTIPART_UPLOAD_RESULT_H
#include <oss_initiate_multipart_upload_result.h>
#undef _OSS_INITIATE_MULTIPART_UPLOAD_RESULT_H

#define _OSS_LIST_MULTIPART_UPLOADS_REQUEST_H
#include <oss_list_multipart_uploads_request.h>
#undef _OSS_LIST_MULTIPART_UPLOADS_REQUEST_H

#define _OSS_LIST_OBJECTS_REQUEST_H
#include <oss_list_objects_request.h>
#undef _OSS_LIST_OBJECTS_REQUEST_H

#define _OSS_LIST_PARTS_REQUEST_H
#include <oss_list_parts_request.h>
#undef _OSS_LIST_OBJECTS_REQUEST_H

#define _OSS_MULTIPART_OBJECT_GROUP_H
#include <oss_multipart_object_group.h>
#undef _OSS_MULTIPART_OBJECT_GROUP_H

#define _OSS_MULTIPART_UPLOAD_H
#include <oss_multipart_upload.h>
#undef _OSS_MULTIPART_UPLOAD_H

#define _OSS_MULTIPART_UPLOAD_LISTING_H
#include <oss_multipart_upload_listing.h>
#undef _OSS_MULTIPART_UPLOAD_LISTING_H

#define _OSS_OBJECT_H
#include <oss_object.h>
#define _OSS_OBJECT_H

#define _OSS_OBJECT_GROUP_ITEM_H
#include <oss_object_group_item.h>
#undef _OSS_OBJECT_GROUP_ITEM_H

#define _OSS_OBJECT_LISTING_H
#include <oss_object_listing.h>
#undef _OSS_OBJECT_LISTING_H

#define _OSS_OBJECT_METADATA_H
#include <oss_object_metadata.h>
#undef _OSS_OBJECT_METADATA_H

#define _OSS_OBJECT_SUMMARY_H
#include <oss_object_summary.h>
#undef _OSS_OBJECT_SUMMARY_H

#define _OSS_OWNER_H
#include <oss_owner.h>
#undef _OSS_OWNER_H

#define _OSS_PART_ETAG_H
#include <oss_part_etag.h>
#undef _OSS_PART_ETAG_H

#define _OSS_PART_LISTING_H
#include <oss_part_listing.h>
#undef _OSS_PART_LISTING_H

#define _OSS_PART_SUMMARY_H
#include <oss_part_summary.h>
#undef _OSS_PART_SUMMARY_H

#define _OSS_POST_OBJECT_GROUP_REQUEST_H
#include <oss_post_object_group_request.h>
#undef _OSS_POST_OBJECT_GROUP_REQUEST_H

#define _OSS_POST_OBJECT_GROUP_RESULT_H
#include <oss_post_object_group_result.h>
#undef _OSS_POST_OBJECT_GROUP_RESULT_H

#define _OSS_PUT_OBJECT_RESULT_H
#include <oss_put_object_result.h>
#undef _OSS_PUT_OBJECT_RESULT_H

#define _OSS_RESPONSE_HEADER_OVERRIDES_H
#include <oss_response_header_overrides.h>
#undef _OSS_RESPONSE_HEADER_OVERRIDES_H

#define _OSS_UPLOAD_PART_REQUEST_H
#include <oss_upload_part_request.h>
#undef _OSS_UPLOAD_PART_REQUEST_H

#define _OSS_UPLOAD_PART_RESULT_H
#include <oss_upload_part_result.h>
#undef _OSS_UPLOAD_PART_RESULT_H

#include <oss_ttxml.h>
#include <oss_tstring.h>

/**
 * @defgroup oss_client_t oss_client_t
 * @{
 */

/**
 * ���ʰ����ƿ��Ŵ洢����Open Storage Service�� OSS������ڡ�
 * �����ƴ洢����Open Storage Service�����OSS�����ǰ����ƶ����ṩ�ĺ�����
 * ��ȫ���ͳɱ��� �߿ɿ����ƴ洢�����û�����ͨ���򵥵�REST�ӿڣ�
 * ���κ�ʱ�䡢�κεص��ϴ����������ݣ� Ҳ����ʹ��WEBҳ������ݽ��й���
 * ����OSS���û����Դ�����ֶ�ý�������վ�����̡�������ҵ���ݱ��ݵ�
 * ���ڴ��ģ���ݵķ��� 
 */
typedef struct oss_client_s {
	char *endpoint;       /**< hostname */
	char *access_id;      /**< �û���OSS�����û��� */
	char *access_key;     /**< �û���OSS�������� */
}oss_client_t;

/**
 * struct curl_request_param_s �ڲ�ʹ�� \n
 * curl_request_param_t ������ʹ��
 */
typedef struct curl_request_param_s curl_request_param_t;

/**
 * param_buffer_t��buffer������
 */
struct param_buffer_s {
	char *ptr; /**< ��������ָ�� */
	FILE *fp; /**< �ļ�ָ�� */
	unsigned int left; /** ������ʣ���С */
	unsigned int allocated; /** �������ܴ�С */
	unsigned short code; /**������ */
};

/**
 * struct param_buffer_s �ڲ�ʹ�� \n
 * param_buffer_t ������ʹ��
 */
typedef struct param_buffer_s param_buffer_t;

/**
 * http��������ܵ�buffer����ṹ
 */
struct curl_request_param_s {
	param_buffer_t *send_buffer; /**< send buffer */
	param_buffer_t *recv_buffer; /**< receive buffer */
	param_buffer_t *header_buffer; /**< header buffer */
};

/**
 * oss_client_t �Ĺ��캯��
 * @param access_id [in] �û���OSS�����û���
 * @param access_key [in] �û���OSS��������
 * @return ����һ����ʶ���û���ݵĽṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_client_t *
client_initialize(
		const char *access_id,
		const char *access_key);

/**
 * oss_client_t ��endpoint�����Ĺ��캯��
 * @param access_id [in] �û���OSS�����û���
 * @param access_key [in] �û���OSS��������
 * @param endpoint [in] ��ʶhostname
 * @return ����һ����ʶ���û���ݵĽṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_client_t *
client_initialize_with_endpoint(
		const char *access_id,
		const char *access_key,
		const char *endpoint);

/**
 * oss_client_t ��������
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @retval void
 * @pre client ����ʹ��client_initialize�ķ���ֵ
 */
extern void 
client_finalize(oss_client_t *client);

/**
 * ��ֹһ�� Multipart �ϴ��¼�
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ��ʶһ��oss_abort_multipart_upload_request�Ľṹָ��
 * @param retcode [out] ���������ص�HTTP������
 * @retval void
 */
extern void
client_abort_multipart_upload(oss_client_t *client,
		oss_abort_multipart_upload_request_t *request,
		unsigned short *retcode);

/**
 * ���һ�� Multipart �ϴ��¼�
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ��ʶһ��oss_complete_multipart_upload_request_t�Ľṹָ��
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_complete_multipart_upload_result_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_complete_multipart_upload_result_t *
client_complete_multipart_upload(oss_client_t *client,
		oss_complete_multipart_upload_request_t *request,
		unsigned short *retcode);

/**
 * ����һ���� OSS ���Ѿ����ڵ� Object ������һ�� Object
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ��ʶһ��oss_copy_object_request_t�Ľṹָ��
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_copy_object_result_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_copy_object_result_t *
client_copy_object(oss_client_t *client,
		oss_copy_object_request_t *request,
		unsigned short *retcode);

/**
 * ����һ���� OSS ���Ѿ����ڵ� Object ������һ�� Object
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param source_bucket_name ��������Object���ڵ�Bucket������
 * @param source_key ��������Object������
 * @param destination_bucket_name Ŀ��Object���ڵ�Bucket������
 * @param destination_key Ŀ��Object������
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_copy_object_result_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_copy_object_result_t *
client_copy_object_ext(oss_client_t *client,
		const char *source_bucket_name,
		const char *source_key,
		const char *destination_bucket_name,
		const char *destination_key,
		unsigned short *retcode);

/**
 * ���� Bucket
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param bucket_name [in] Ҫ������Bucket������
 * @param retcode [out] ���������ص�HTTP������
 * @retval void
 */
extern void
client_create_bucket(oss_client_t *client,
		const char *bucket_name,
		unsigned short *retcode);

/**
 * ɾ�� Bucket
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param bucket_name [in] Ҫɾ����Bucket������
 * @param retcode [out] ���������ص�HTTP������
 * @retval void
 */
extern void 
client_delete_bucket(oss_client_t *client,
		const char *bucket_name,
		unsigned short *retcode);

/**
 * ɾ��ָ���� OSSObject
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param bucket_name [in] Ҫɾ��Object���ڵ�Bucket������
 * @param key [in] Ҫɾ��Object������
 * @param retcode [out] ���������ص�HTTP������
 * @retval void
 */
extern void
client_delete_object(oss_client_t *client,
		const char *bucket_name,
		const char *key,
		unsigned short *retcode);

/**
 * ɾ��ָ���Ķ�� OSSObject
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ɾ�����Object����
 * @param retcode [out] ���������ص�HTTP������
 * @retval oss_delete_multiple_object_request_t �ṹָ��
 */
oss_delete_multiple_object_request_t*
client_delete_multiple_object(oss_client_t *client,
		oss_delete_multiple_object_request_t *request,
		unsigned short *retcode);

#if 0
/**
 * ����һ������ǩ����Ϣ�����Է��� OSSObject �� URL
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ��ʶһ��oss_generate_presigned_url_request_t�Ľṹָ��
 * @param retcode [out] ���������ص�HTTP������
 * @return url�ַ���
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern char *
client_generate_presigned_url(oss_client_t *client,
		oss_generate_presigned_url_request_t *request);
#endif

/**
 * ����һ���� HTTP GET �������� OSSObject �� URL
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param bucket_name [in] Ҫ���ʵ�Object���ڵ�Bucket����
 * @param key [in] Ҫ���ʵ�Object������
 * @param expiration [in] ����ʱ��
 * @return url�ַ���
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern char *
client_generate_presigned_url_with_expiration(oss_client_t *client,
		const char *bucket_name,
		const char *key,
		const char *expiration);

/**
 * ����һ����ָ�� HTTP �������� OSSObject �� URL
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param bucket_name [in] Ҫ���ʵ�Object���ڵ�Bucket����
 * @param key [in] Ҫ���ʵ�Object������
 * @param expiration [in] ����ʱ��
 * @param method [in] http����
 * @return url�ַ���
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern char *
client_generate_presigned_url_with_method(oss_client_t *client,
		const char *bucket_name,
		const char *key,
		const char *expiration,
		const char *method);

/**
 * ���ظ��� Bucket �� Access Control List(oss_client_t *client, ACL)
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param bucket_name [in] Ҫ����acl��Bucket����
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_access_control_list_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_access_control_list_t *
client_get_bucket_acl(oss_client_t *client,
		const char *bucket_name,
		unsigned short *retcode);

/**
 * ���ط��ʵ�OSS Endpoint
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @return ��������hostname
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern const char *
client_get_endpoint(oss_client_t *client);

/**
 * �� OSS ָ���� Bucket �е���ָ���� OSSObject ���ڴ�
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ��ʶһ��oss_get_object_request_t�Ľṹָ��
 * @param output [in] Ҫ���Object���ڴ��ַ
 * @param output_len [out] output�ĳ���
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_object_metadata_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
oss_object_metadata_t *
client_get_object_to_buffer(oss_client_t *client,
		oss_get_object_request_t *request,
		void **output,
		unsigned int *output_len,
		unsigned short *retcode);

/**
 * �� OSS ָ���� Bucket �е���ָ���� OSSObject ���ڴ�
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ��ʶһ��oss_get_object_request_t�Ľṹָ��
 * @param output [in] Ҫ���Object���ڴ��ַ
 * @param output_len [out] output�ĳ���
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_object_metadata_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
oss_object_metadata_t *
client_get_object_to_buffer_2nd(oss_client_t *client,
		oss_get_object_request_t *request,
		void **output,
		unsigned int *output_len,
		unsigned short *retcode);
/**
 * �� OSS ָ���� Bucket �е���ָ����ѹ�� OSSObject ���ڴ棬
 * �����ڴ���ʵʱ��ѹ��
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ��ʶһ��oss_get_object_request_t�Ľṹָ��
 * @param output [in] Ҫ���Object���ڴ��ַ
 * @param output_len [out] output�ĳ���
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_object_metadata_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
oss_object_metadata_t *
client_get_compressed_object_to_buffer(oss_client_t *client,
		oss_get_object_request_t *request,
		void **output,
		unsigned int *output_len,
		unsigned short *retcode);

/**
 * �� OSS ָ���� Bucket �е���ָ���� OSSObject ��Ŀ���ļ�
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ��ʶһ��oss_get_object_request_t�Ľṹָ��
 * @param file [in] Ҫ���Object���ļ�ָ��
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_object_metadata_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_object_metadata_t *
client_get_object_to_file(oss_client_t *client,
		oss_get_object_request_t *request,
		FILE *file,
		unsigned short *retcode);

/**
 * �� OSS ָ���� Bucket �е���ָ����ѹ�� OSSObject ��Ŀ���ļ�
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ��ʶһ��oss_get_object_request_t�Ľṹָ��
 * @param file [in] Ҫ���Object���ļ�ָ��
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_object_metadata_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
oss_object_metadata_t *
client_get_compressed_object_to_file(oss_client_t *client,
		oss_get_object_request_t *request,
		FILE *file,
		unsigned short *retcode);

/**
 * �� OSS ָ���� Bucket �е��� OSSObject
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param bucket_name Ҫ������Object���ڵ�Bucket����
 * @param key Ҫ������Object����
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_object_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_object_t *
client_get_object_with_bucket_name(oss_client_t *client,
		const char *bucket_name,
		const char *key,
		unsigned short *retcode);

/**
 * ���� OSSObject ��Ԫ����
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param bucket_name Ҫ��ѯ��Object���ڵ�Bucket����
 * @param key Ҫ��ѯ��Object����
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_object_metadata_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_object_metadata_t *
client_get_object_metadata(oss_client_t *client,
		const char *bucket_name,
		const char *key,
		unsigned short *retcode);
/**
 * ��ʼ��һ�� Multipart �ϴ��¼�
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ��ʶһ��oss_initiate_multipart_upload_request_t�Ľṹָ��
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_initiate_multipart_upload_result_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_initiate_multipart_upload_result_t *
client_initiate_multipart_upload(oss_client_t *client,
		oss_initiate_multipart_upload_request_t *request,
		unsigned short *retcode);


/**
 * �жϸ��� Bucket �Ƿ����
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param bucket_name Ҫ��ѯ��Bucket����
 * @return ����
 * @retval true ��ʾ����
 * @retval false ��ʾ������
 */
extern bool
client_is_bucket_exist(oss_client_t *client,
		const char *bucket_name);

/**
 * ����������ӵ�е����� Bucket ���б�
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param buckets_number ����Bucket������
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_bucket_t��˫��ָ�룬��ͨ��buckets_number������
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_bucket_t **
client_list_buckets(oss_client_t *client,
		int *buckets_number,
		unsigned short *retcode);

/**
 * �г�����ִ���е� Multipart �ϴ��¼�
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ��ʶһ��oss_list_multipart_uploads_request_t�Ľṹָ��
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_multipart_upload_listing_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_multipart_upload_listing_t *
client_list_multipart_uploads(oss_client_t *client,
		oss_list_multipart_uploads_request_t *request,
		unsigned short *retcode);

/**
 * �г�ָ�� Bucket �µ� OSSObject
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ��ʶһ��oss_list_objects_request_t�Ľṹָ��
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_object_listing_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_object_listing_t *
client_list_objects(oss_client_t *client,
		oss_list_objects_request_t *request,
		unsigned short *retcode);

/**
 * �г�ָ�� Bucket �µ� OSSObject
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param bucket_name Ҫ��ѯ��Bucket������
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_object_listing_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_object_listing_t *
client_list_objects_with_bucket_name(oss_client_t *client,
		const char *bucket_name,
		unsigned short *retcode);

/**
 * �г�ָ�� Bucket �� key �Ը��� prefix ��ͷ�� OSSObject
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param bucket_name Ҫ��ѯ��Bucket������
 * @param prefix ����Ҫ��ѯ��Object��ǰ׺
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_object_listing_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_object_listing_t *
client_list_objects_with_prefix(oss_client_t *client,
		const char *bucket_name,
		const char *prefix,
		unsigned short *retcode);

/**
 * �г� multipart ���ϴ������� part ��Ϣ
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ��ʶһ��oss_list_parts_request_t�Ľṹָ��
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_part_listing_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_part_listing_t *
client_list_parts(oss_client_t *client,
		oss_list_parts_request_t *request,
		unsigned short *retcode);

/**
 * �ϴ�ָ���� OSSObject �� OSS ��ָ���� Bucket
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param bucket_name Ҫ�ϴ�����Bucket����
 * @param key Ҫ�ϴ�������������ʾ��Object������
 * @param input Ҫ�ϴ����ļ�ָ��
 * @param metadata ��ʶ���ݵ�һЩԪ��Ϣ��һ��oss_object_metadata_t�ṹָ��
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_put_object_result_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_put_object_result_t *
client_put_object_from_file(oss_client_t *client,
		const char *bucket_name,
		const char *key,
		void *input,
		oss_object_metadata_t *metadata,
		unsigned short *retcode);

/**
 * �ϴ�ָ���� OSSObject �� OSS ��ָ���� Bucket
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param bucket_name Ҫ�ϴ�����Bucket����
 * @param key Ҫ�ϴ�������������ʾ��Object������
 * @param input Ҫ�ϴ����ݵĻ�����
 * @param metadata ��ʶ���ݵ�һЩԪ��Ϣ��һ��oss_object_metadata_t�ṹָ��
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_put_object_result_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_put_object_result_t *
client_put_object_from_buffer(oss_client_t *client,
		const char *bucket_name,
		const char *key,
		void *input,
		oss_object_metadata_t *metadata,
		unsigned short *retcode);

/**
 * ѹ�����ϴ�ָ���� OSSObject �� OSS ��ָ���� Bucket
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param bucket_name Ҫ�ϴ�����Bucket����
 * @param key Ҫ�ϴ�������������ʾ��Object������
 * @param metadata ��ʶ���ݵ�һЩԪ��Ϣ��һ��oss_object_metadata_t�ṹָ��
 * @param input Ҫ�ϴ����ݵĻ�����
 * @param input_len Ҫ�ϴ����ݵĳ���
 * @param algorithm ѹ���㷨
 * @param flag ��־λ
 * @param level ��ѹ���㷨��ѹ���ȼ�
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_put_object_result_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */

extern oss_put_object_result_t *
client_put_compressed_object_from_buffer(oss_client_t *client,
		const char *bucket_name,
		const char *key,
		oss_object_metadata_t *metadata,
		void *input, 
		unsigned int input_len,
		char algorithm,
		char flag,
		char level,
		unsigned short *retcode);

/**
 * ѹ�����ϴ�ָ���� OSSObject �� OSS ��ָ���� Bucket
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param bucket_name Ҫ�ϴ�����Bucket����
 * @param key Ҫ�ϴ�������������ʾ��Object������
 * @param metadata ��ʶ���ݵ�һЩԪ��Ϣ��һ��oss_object_metadata_t�ṹָ��
 * @param input �ļ�ָ��
 * @param input_len Ҫ�ϴ����ݵĳ���
 * @param algorithm ѹ���㷨
 * @param flag ��־λ
 * @param level ��ѹ���㷨��ѹ���ȼ�
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_put_object_result_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
oss_put_object_result_t *
client_put_compressed_object_from_file(oss_client_t *client,
		const char *bucket_name,
		const char *key,
		oss_object_metadata_t *metadata,
		void *input, /**< �ļ�ָ�� */
		char algorithm,
		char flag,
		char level,
		unsigned short *retcode);

/**
 * ����ָ�� Bucket �� Access Control List(oss_client_t *client, ACL)
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param bucket_name Ҫ����Ȩ�޵�Bucket������
 * @param acl Ҫ���õ�Ȩ�ޣ�private, public-read, public-read-write�е�һ����
 * @param retcode [out] ���������ص�HTTP������
 * @retval void
 */
extern void
client_set_bucket_acl(oss_client_t *client,
		const char *bucket_name,
		const char *acl,
		unsigned short *retcode);

/**
 * �ϴ�һ���ֿ飨Part����ָ���ĵ� Multipart �ϴ��¼���
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ��ʶһ��oss_upload_part_request_t�Ľṹָ��
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_upload_part_result_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_upload_part_result_t *
client_upload_part(oss_client_t *client,
		oss_upload_part_request_t *request,
		unsigned short *retcode);

/**
 * copyĳ��objectĳ���ֵ�ָ���ĵ� Multipart �ϴ��¼���
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ��ʶһ��oss_upload_part_request_t�Ľṹָ��
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_upload_part_result_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_upload_part_result_t *
client_upload_part_copy(oss_client_t *client,
		oss_upload_part_request_t *request,
		const char* s_object_name, 
		size_t start,
		size_t end,
		unsigned short *retcode);

/**
 * Post Object Group �����������û��ṩ�� Object ��Ϣ,�� OSS �������˴�����һ���µ� Object Group.\n
 * �û���Ҫ�������� Object Group ����� Object Name, E-tag �Լ���ʶ�� Object ������ Group �����λ�õ� Part ID
 * ���չ涨�� XML ��ʽ���� OSS, Object �� E-tag ֵ����ͨ��list_object���ܻ��
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ��ʶһ��oss_post_object_group_request_t�Ľṹָ��
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_post_object_group_result_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_post_object_group_result_t *
client_post_object_group(oss_client_t *client,
		oss_post_object_group_request_t *request,
		unsigned short *retcode);

/**
 * Get Object Group To File ��������ȡ�û�ָ����Object Group�������ļ���
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ��ʶһ��oss_get_object_group_request_t�Ľṹָ��
 * @param file [in] �����ļ����ļ�ָ��
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_object_metadata_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_object_metadata_t *
client_get_object_group_to_file(oss_client_t *client,
		oss_get_object_group_request_t *request,
		FILE *file,
		unsigned short *retcode);

/**
 * Get Object Group To Buffer ��������ȡ�û�ָ����Object Group��Buffer��
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ��ʶһ��oss_get_object_group_request_t�Ľṹָ��
 * @param output [out] Buffer�ĵ�ַ
 * @param output_len [out] Buffer�ĳ���
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_object_metadata_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_object_metadata_t *
client_get_object_group_to_buffer(oss_client_t *client,
		oss_get_object_group_request_t *request,
		void **output,
		unsigned int *output_len,
		unsigned short *retcode);

/**
 * Get Object Group Index ���� Object Group �е� Object List ��Ϣ
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param bucket_name [in] Bucket ������
 * @param key [in] Object Group������
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_get_object_group_index_result_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_get_object_group_index_result_t *
client_get_object_group_index(
		oss_client_t *client,
		const char *bucket_name,
		const char *key,
		unsigned short *retcode);

/**
 * Head Object Group ���� ָ��Object Group �� Ԫ��Ϣ���������ļ����ݡ�
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param request [in] ��ʶһ��oss_get_object_group_request_t�ṹָ��
 * @param retcode [out] ���������ص�HTTP������
 * @return ����һ��oss_object_metadata_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_object_metadata_t *
client_head_object_group(oss_client_t *client,
		oss_get_object_group_request_t *request,
		unsigned short *retcode);

/**
 * Delete Object Group ���� ָ��Object Group �� Ԫ��Ϣ���������ļ����ݡ�
 * @param client [in] ��ʶһ��oss_client_t�Ľṹָ��
 * @param bucket_name [in] ��ɾ����Object Group���ڵ�Bucket������
 * @param key [in] Ҫɾ����Object Group������
 * @param retcode [out] ���������ص�HTTP������
 * @retval void
 */
extern void 
client_delete_object_group(oss_client_t *client,
		const char *bucket_name,
		const char *key,
		unsigned short *retcode);


/**@}*/

#endif // OSS_CLIENT_H

/*
 * =============================================================================
 *
 *       Filename:  oss_initiate_multipart_upload_request.h
 *
 *    Description:  initiate multipart upload request.
 *
 *        Created:  09/05/2012 02:32:01 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_INITIATE_MULTIPART_UPLOAD_REQUEST_H
# error Never include <oss_initiate_multipart_upload_request.h> directly
# error use <client.h> instead.
#endif

#ifndef OSS_INITIATE_MULTIPART_UPLOAD_REQUEST_H 
#define OSS_INITIATE_MULTIPART_UPLOAD_REQUEST_H

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _OSS_OBJECT_METADATA_H
#include <oss_object_metadata.h>
#undef _OSS_OBJECT_METADATA_H

/**
 * @defgroup oss_initiate_multipart_upload_request_t oss_initiate_multipart_upload_request_t
 * @{
 */

/**
 * struct oss_initiate_multipart_upload_request_s �ڲ�ʹ�� \n
 * oss_initiate_multipart_upload_request_t ������ʹ��
 */
typedef struct oss_initiate_multipart_upload_request_s oss_initiate_multipart_upload_request_t;

/**
 * ������ʼ��һ��Multipart�ϴ��¼����������
 */
struct oss_initiate_multipart_upload_request_s {
	char *bucket_name;       /**< Bucket���� */
	char *key;               /**< Object���� */
	oss_object_metadata_t *object_metadata;     /**< Object��Ԫ��Ϣ */

	/**
	 * ���Bucket����
	 * @param request [in] ��ʶһ��oss_initiate_multipart_upload_request_t�ṹָ��
	 * @return Bucket����
	 * @retval const char *
	 */
	const char * (*get_bucket_name)(oss_initiate_multipart_upload_request_t *request);

	/**
	 * ���Object����
	 * @param request [in] ��ʶһ��oss_initiate_multipart_upload_request_t�ṹָ��
	 * @return Object����
	 * @retval const char *
	 */
	const char * (*get_key)(oss_initiate_multipart_upload_request_t *request);

	/**
	 * ���Object��Ԫ��Ϣ
	 * @param request [in] ��ʶһ��oss_initiate_multipart_upload_request_t�ṹָ��
	 * @return Object��Ԫ��Ϣ
	 * @retval �ǿ� ��ʾ�ɹ�
	 * @retval NULL ��ʶʧ��
	 */
	oss_object_metadata_t * (*get_object_metadata)(oss_initiate_multipart_upload_request_t *request);

	/**
	 * ����Bucket����
	 * @param request [in] ��ʶһ��oss_initiate_multipart_upload_request_t�ṹָ��
	 * @param bucket_name [in] Bucket����
	 * @retval void
	 */
	void (*set_bucket_name)(oss_initiate_multipart_upload_request_t *request,
			const char *bucket_name);

	/**
	 * ����Object����
	 * @param request [in] ��ʶһ��oss_initiate_multipart_upload_request_t�ṹָ��
	 * @param key [in] Object����
	 * @retval void
	 */
	void (*set_key)(oss_initiate_multipart_upload_request_t *request,
			const char *key);

	/**
	 * ����Object��Ԫ��Ϣ
	 * @param request [in] ��ʶһ��oss_initiate_multipart_upload_request_t�ṹָ��
	 * @param object_metadata [in] Object��Ԫ��Ϣ
	 * @retval void
	 */
	void (*set_object_metadata)(oss_initiate_multipart_upload_request_t *request,
			oss_object_metadata_t *object_metadata);
};


/**
 * oss_initiate_multipart_upload_request_t���캯��
 * @param bucket_name [in] Bucket����
 * @param key [in] Object����
 * @return ����һ��oss_initiate_multipart_upload_request_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_initiate_multipart_upload_request_t *
initiate_multipart_upload_request_initialize(const char *bucket_name,
		const char *key);

/**
 * oss_initiate_multipart_upload_request_t��Ԫ��Ϣ�Ĺ��캯��
 * @param bucket_name [in] Bucket����
 * @param key [in] Object����
 * @param object_metadata [in] Object��Ԫ��Ϣ
 * @return ����һ��oss_initiate_multipart_upload_request_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_initiate_multipart_upload_request_t *
initiate_multipart_upload_request_initialize_with_metadata(const char *bucket_name,
		const char *key,
		oss_object_metadata_t *object_metadata);

/**
 * oss_initiate_multipart_upload_request_t��������
 * @param request [in] ��ʶһ��oss_initiate_multipart_upload_request_t�ṹָ��
 * @retval void
 * @pre request ����ʹ��initiate_multipart_upload_request_initialize�ķ���ֵ
 */
extern void
initiate_multipart_upload_request_finalize(
		oss_initiate_multipart_upload_request_t *request);
/**@}*/
#endif // OSS_INITIATE_MULTIPART_UPLOAD_REQUEST_H


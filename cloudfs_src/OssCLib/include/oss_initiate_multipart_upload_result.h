/*
 * =============================================================================
 *
 *       Filename:  oss_initiate_multipart_upload_result.h
 *
 *    Description:  initiate multipart upload result implementation.
 *
 *        Created:  09/05/2012 12:09:28 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_INITIATE_MULTIPART_UPLOAD_RESULT_H
# error Never include <oss_initiate_multipart_upload_result.h> directly
# error use <client.h> instead.
#endif

#ifndef OSS_INITIATE_MULTIPART_UPLOAD_RESULT_H 
#define OSS_INITIATE_MULTIPART_UPLOAD_RESULT_H

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @defgroup oss_initiate_multipart_upload_result_t oss_initiate_multipart_upload_result_t
 * @{
 */

/**
 * struct oss_initiate_multipart_upload_result_s �ڲ�ʹ�� \n
 * oss_initiate_multipart_upload_result_t ������ʹ��
 */
typedef struct oss_initiate_multipart_upload_result_s oss_initiate_multipart_upload_result_t;

/**
 * ������ʼ��һ��Multipart�ϴ��¼��Ľ������
 */
struct oss_initiate_multipart_upload_result_s {
	char *bucket_name;        /**< Bucket���� */
	char *key;                /**< Object���� */
	char *upload_id;          /** ��ʶMultipart�ϴ��¼���Upload ID */

	/**
	 * ���Bucket����
	 * @param result [in] ��ʶһ��oss_initiate_multipart_upload_result_t�ṹָ��
	 * @return Bucket����
	 * @retval const char *
	 */
	const char * (*get_bucket_name)(oss_initiate_multipart_upload_result_t *result);

	/**
	 * ���Object����
	 * @param result [in] ��ʶһ��oss_initiate_multipart_upload_result_t�ṹָ��
	 * @return Object����
	 * @retval const char *
	 */
	const char * (*get_key)(oss_initiate_multipart_upload_result_t *result);

	/**
	 * ���Upload ID
	 * @param result [in] ��ʶһ��oss_initiate_multipart_upload_result_t�ṹָ��
	 * @return Upload ID
	 * @retval const char *
	 */
	const char * (*get_upload_id)(oss_initiate_multipart_upload_result_t *result);

	/**
	 * ����Bucket����
	 * @param result [in] ��ʶһ��oss_initiate_multipart_upload_result_t�ṹָ��
	 * @param bucket_name [in] Bucket����
	 * @retval void
	 */
	void (*set_bucket_name)(oss_initiate_multipart_upload_result_t *result,
			const char *bucket_name);

	/**
	 * ����Object����
	 * @param result [in] ��ʶһ��oss_initiate_multipart_upload_result_t�ṹָ��
	 * @param key [in] Object����
	 * @retval void
	 */
	void (*set_key)(oss_initiate_multipart_upload_result_t *result,
			const char *key);

	/**
	 * ����Upload ID
	 * @param result [in] ��ʶһ��oss_initiate_multipart_upload_result_t�ṹָ��
	 * @param upload_id [in] Upload ID
	 * @retval void
	 */
	void (*set_upload_id)(oss_initiate_multipart_upload_result_t *result,
			const char *upload_id);
};

/**
 * oss_initiate_multipart_upload_result_t���캯��
 * @return ����һ��oss_initiate_multipart_upload_result_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_initiate_multipart_upload_result_t *
initiate_multipart_upload_result_initialize(void);

/**
 * oss_initiate_multipart_upload_result_t��������
 * @param result [in] ��ʶһ��oss_initiate_multipart_upload_result_t�ṹָ��
 * @retval void
 * @pre result ����ʹ��initiate_multipart_upload_result_initialize�ķ���ֵ
 */
extern void
initiate_multipart_upload_result_finalize(
		oss_initiate_multipart_upload_result_t *result);
/**@}*/
#endif // OSS_INITIATE_MULTIPART_UPLOAD_RESULT_H

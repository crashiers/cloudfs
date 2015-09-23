/*
 * =============================================================================
 *
 *       Filename:  oss_complete_multipart_upload_result.h
 *
 *    Description:  oss_complete_multipart_upload_result.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_COMPLETE_MULTIPART_UPLOAD_RESULT_H
# error Never include <oss_complete_multipart_upload_result.h> directly, use <client.h> instead.
#endif

#ifndef OSS_COMPLETE_MULTIPART_UPLOAD_RESULT_H
#define OSS_COMPLETE_MULTIPART_UPLOAD_RESULT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @defgroup oss_complete_multipart_upload_result_t oss_complete_multipart_upload_result_t
 * @{
 */

/**
 * struct oss_complete_multipart_upload_result_s �ڲ�ʹ�� \n
 * oss_complete_multipart_upload_result_t ������ʹ��
 */
typedef struct oss_complete_multipart_upload_result_s oss_complete_multipart_upload_result_t;


/**
 * �������һ��Multipart�ϴ��¼��ķ��ؽ��
 */
struct oss_complete_multipart_upload_result_s {
	char *bucket_name;  /**< Bucket ���� */
	char *etag;         /**< Object ��MD5ֵ */
	char *key;          /**< Object ���� */
	char *location;     /**< Object ��URL��ַ */

	/**
	 * ���Bucket������
	 * @param result [in] ��ʶһ��oss_complete_multipart_upload_result_t�Ľṹָ��
	 * @return Bucket������
	 * @retval const char *
	 */
	const char * (*get_bucket_name)(oss_complete_multipart_upload_result_t *result);

	/**
	 * ����Bucket������
	 * @param result [in] ��ʶһ��oss_complete_multipart_upload_result_t�Ľṹָ��
	 * @param bucket_name [in] Bucket������
	 * @retval void
	 */
	void (*set_bucket_name)(oss_complete_multipart_upload_result_t *result, const char *bucket_name);

	/**
	 * ���Object��MD5ֵ
	 * @param result [in] ��ʶһ��oss_complete_multipart_upload_result_t�Ľṹָ��
	 * @return Object��MD5ֵ
	 * @retval const char *
	 */
	const char * (*get_etag)(oss_complete_multipart_upload_result_t *result);

	/**
	 * ����Object��MD5ֵ
	 * @param result [in] ��ʶһ��oss_complete_multipart_upload_result_t�Ľṹָ��
	 * @param etag [in] Object��MD5ֵ
	 * @retval void
	 */
	void (*set_etag)(oss_complete_multipart_upload_result_t *result, const char * etag);

	/**
	 * ���Object������
	 * @param result [in] ��ʶһ��oss_complete_multipart_upload_result_t�Ľṹָ��
	 * @return Object������
	 * @retval const char *
	 */
	const char * (*get_key)(oss_complete_multipart_upload_result_t *result);

	/**
	 * ����Object������
	 * @param result [in] ��ʶһ��oss_complete_multipart_upload_result_t�Ľṹָ��
	 * @param key [in] Object������
	 * @retval void
	 */
	void (*set_key)(oss_complete_multipart_upload_result_t *result, const char *key);

	/**
	 * ���Object ��URL��ַ
	 * @param result [in] ��ʶһ��oss_complete_multipart_upload_result_t�Ľṹָ��
	 * @return Object ��URL��ַ
	 * @retval const char *
	 */
	const char * (*get_location)(oss_complete_multipart_upload_result_t *result);

	/**
	 * ����Object ��URL��ַ
	 * @param result [in] ��ʶһ��oss_complete_multipart_upload_result_t�Ľṹָ��
	 * @param location [in] Object ��URL��ַ
	 * @retval void
	 */
	void (*set_location)(oss_complete_multipart_upload_result_t *result, const char *location);
};

/**
 * oss_complete_multipart_upload_result_t ���캯��
 * @return ����һ��oss_complete_multipart_upload_result_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_complete_multipart_upload_result_t *
complete_multipart_upload_result_initialize(void);


/**
 * oss_complete_multipart_upload_result_t ��������
 * @param result [in] ��ʶһ��oss_complete_multipart_upload_result_t�Ľṹָ��
 * @retval void
 * @pre result ����ʹ��complete_multipart_upload_result_initialize�ķ���ֵ
 */
extern void 
complete_multipart_upload_result_finalize(oss_complete_multipart_upload_result_t *result);
/**@}*/
#endif

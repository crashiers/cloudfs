/*
 * =============================================================================
 *
 *       Filename:  oss_abort_multipart_upload_request.h
 *
 *    Description:  abort multipart upload request structure.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/* �ڲ�ʹ�õ�ͷ�ļ����û�����Ӧ����<client.h> */
#ifndef _OSS_ABORT_MULTIPART_UPLOAD_REQUEST_H
# error Never include <oss_abort_multipart_upload_request.h> directly
# error use <client.h> instead.
#endif

/* ͷ�ļ����� */
#ifndef OSS_ABORT_MULTIPART_UPLOAD_REQUEST_H 
#define OSS_ABORT_MULTIPART_UPLOAD_REQUEST_H

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * @defgroup oss_abort_multipart_upload_request_t oss_abort_multipart_upload_request_t
 * @{
 */

/** 
 *struct oss_abort_multipart_upload_request_s �ڲ�ʹ�� \n
 *oss_abort_multipart_upload_request_t ������ʹ��
 */
typedef struct oss_abort_multipart_upload_request_s oss_abort_multipart_upload_request_t;


/**
 *oss_abort_multipart_upload_request_t ������ֹһ�� Multipart �ϴ��¼����������
 */
struct oss_abort_multipart_upload_request_s {
	char *bucket_name;       /**< Bucket ���� */
	char *key;               /**< Object ���� */
	char *upload_id;         /**< ��ʶ Multipart �ϴ��¼���Upload ID */

	/**
	 * ���� Bucket ����
	 * @param request [in] ��ʶһ��oss_abort_multipart_upload_request_t ָ��
	 * @retval const char *
	 * @return Bucket ����
	 */
	const char * (*get_bucket_name)(oss_abort_multipart_upload_request_t
			*request);

	/**
	 * ���� Object ����
	 * @param request [in] ��ʶһ��oss_abort_multipart_upload_request_t ָ��
	 * @retval const char *
	 * @return Object ����
	 */
	const char * (*get_key)(oss_abort_multipart_upload_request_t
			*request);

	/**
	 * ���� ��ʶ Multipart �ϴ��¼���Upload ID
	 * @param request [in] ��ʶһ��oss_abort_multipart_upload_request_t ָ��
	 * @retval const char *
	 * @return Upload ID
	 */
	const char * (*get_upload_id)(oss_abort_multipart_upload_request_t
			*request);
	/**
	 * ���� Bucket ����
	 * @param request [in] ��ʶһ��oss_abort_multipart_upload_request_t ָ��
	 * @param bucket_name [in] Bucket ����
	 * @retval void
	 */
	void (*set_bucket_name)(oss_abort_multipart_upload_request_t *request,
			const char *bucket_name);

	/**
	 * ���� Object ����
	 * @param request [in] ��ʶһ��oss_abort_multipart_upload_request_t ָ��
	 * @param key [in] Object ����
	 * @retval void
	 */
	void (*set_key)(oss_abort_multipart_upload_request_t *request,
			const char *key);

	/**
	 * ���� ��ʶ Multipart �ϴ��¼���Upload ID
	 * @param request [in] ��ʶһ��oss_abort_multipart_upload_request_t ָ��
	 * @param upload_id [in] Upload ID ����
	 * @retval void
	 */
	void (*set_upload_id)(oss_abort_multipart_upload_request_t *request,
			const char *upload_id);
};

/**
 * abort_multipart_upload_request_t ���캯��
 * @param [in] bucket_name Bucket����
 * @param [in] key object����
 * @param [in] upload_id ��ʶ Multipart �ϴ��¼���Upload ID
 * @return ����һ��oss_abort_multipart_upload_request_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_abort_multipart_upload_request_t *
abort_multipart_upload_request_initialize(const char *bucket_name,
		const char *key,
		const char *upload_id);

/**
 * abort_multipart_upload_request_t ��������
 * @param request [in] ��ʶһ��oss_abort_multipart_upload_request_t�ṹָ��
 * @retval void
 * @pre request ����ʹ��abort_multipart_upload_request_initialize�ķ���ֵ
 */
extern void
abort_multipart_upload_request_finalize(
		oss_abort_multipart_upload_request_t *request);


/** @}*/


#endif // OSS_ABORT_MULTIPART_UPLOAD_REQUEST_H

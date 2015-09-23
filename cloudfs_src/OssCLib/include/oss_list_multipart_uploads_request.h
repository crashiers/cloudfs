/*
 * =============================================================================
 *
 *       Filename:  oss_list_multipart_uploads_request.h
 *
 *    Description:  list multipart uploads request implementation.
 *
 *        Created:  09/05/2012 11:31:02 AM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_LIST_MULTIPART_UPLOADS_REQUEST_H
# error Never include <oss_list_multipart_uploads_request_h> directly
# error use <client.h> instead.
#endif

#ifndef OSS_LIST_MULTIPART_UPLOADS_REQUEST_H
#define OSS_LIST_MULTIPART_UPLOADS_REQUEST_H

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @defgroup oss_list_multipart_uploads_request_t oss_list_multipart_uploads_request_t
 * @{
 */

/**
 * struct oss_list_multipart_uploads_request_s �ڲ�ʹ�� \n
 * oss_list_multipart_uploads_request_t ������ʹ��
 */
typedef struct oss_list_multipart_uploads_request_s oss_list_multipart_uploads_request_t;

/**
 * �����г�����ִ����Multipart�ϴ��¼����������
 */
struct oss_list_multipart_uploads_request_s {
	char *bucket_name;            /**< Bucket���� */
	char *delimiter;              /**< �ָ��� */
	char *key_marker;             /**< ��ʶ��ʾ�����ﷵ���б� */
	unsigned int max_uploads;     /**< ���Ƶ���󷵻ؼ�¼�� */
	char *prefix;                 /**< ǰ׺ */
	char *upload_id_marker;       /**< ��ʶ��ʾ�����ﷵ���б� */

	/**
	 * ���Bucket����
	 * @param request [in] ��ʶһ��oss_list_multipart_uploads_request_t�ṹָ��
	 * @return Bucket����
	 * @retval const char *
	 */
	const char * (*get_bucket_name)(oss_list_multipart_uploads_request_t *request);

	/**
	 * ��÷ָ���
	 * @param request [in] ��ʶһ��oss_list_multipart_uploads_request_t�ṹָ��
	 * @return delimiter
	 * @retval const char *
	 */
	const char * (*get_delimiter)(oss_list_multipart_uploads_request_t *request);

	/**
	 * ���key_marker
	 * @param request [in] ��ʶһ��oss_list_multipart_uploads_request_t�ṹָ��
	 * @return key_marker
	 * @retval const char *
	 */
	const char * (*get_key_marker)(oss_list_multipart_uploads_request_t *request);

	/**
	 * �����󷵻ؼ�¼��
	 * @param request [in] ��ʶһ��oss_list_multipart_uploads_request_t�ṹָ��
	 * @return ��󷵻ؼ�¼��
	 * @retval unsigned int
	 */
	unsigned int (*get_max_uploads)(oss_list_multipart_uploads_request_t *request);

	/**
	 * ���ǰ׺
	 * @param request [in] ��ʶһ��oss_list_multipart_uploads_request_t�ṹָ��
	 * @return ǰ׺
	 * @retval const char *
	 */
	const char * (*get_prefix)(oss_list_multipart_uploads_request_t *request);

	/**
	 * ���upload_id_marker
	 * @param request [in] ��ʶһ��oss_list_multipart_uploads_request_t�ṹָ��
	 * @return upload_id_marker
	 * @retval const char *
	 */
	const char * (*get_upload_id_marker)(oss_list_multipart_uploads_request_t *request);

	/**
	 * ����Bucket����
	 * @param request [in] ��ʶһ��oss_list_multipart_uploads_request_t�ṹָ��
	 * @param bucket_name [in] Bucket����
	 * @retval void
	 */
	void (*set_bucket_name)(oss_list_multipart_uploads_request_t *request,
			const char *bucket_name);

	/**
	 * ���÷ָ���
	 * @param request [in] ��ʶһ��oss_list_multipart_uploads_request_t�ṹָ��
	 * @param delimiter [in] �ָ���
	 * @retval void
	 */
	void (*set_delimiter)(oss_list_multipart_uploads_request_t *request,
			const char *delimiter);

	/**
	 * ����key_marker
	 * @param request [in] ��ʶһ��oss_list_multipart_uploads_request_t�ṹָ��
	 * @param key_marker [in] ��ʶ��ʾ�����ﷵ���б�
	 * @retval void
	 */
	void (*set_key_marker)(oss_list_multipart_uploads_request_t *request,
			const char *key_marker);

	/**
	 * ������󷵻ؼ�¼��
	 * @param request [in] ��ʶһ��oss_list_multipart_uploads_request_t�ṹָ��
	 * @param max_uploads [in] ��󷵻ؼ�¼��
	 * @retval void
	 */
	void (*set_max_uploads)(oss_list_multipart_uploads_request_t *request,
			unsigned int max_uploads);

	/**
	 * ����ǰ׺
	 * @param request [in] ��ʶһ��oss_list_multipart_uploads_request_t�ṹָ��
	 * @param prefix [in] ǰ׺
	 * @retval void
	 */
	void (*set_prefix)(oss_list_multipart_uploads_request_t *request,
			const char *prefix);

	/**
	 * ���� upload_id_marker
	 * @param request [in] ��ʶһ��oss_list_multipart_uploads_request_t�ṹָ��
	 * @param upload_id_marker [in] ��ʶ��ʾ�����ﷵ���б�
	 * @retval void
	 */
	void (*set_upload_id_marker)(oss_list_multipart_uploads_request_t *request,
			const char *upload_id_marker);
};

/**
 * oss_list_multipart_uploads_request_t���캯��
 * @param bucket_name [in] Bucket����
 * @return ����һ��oss_list_multipart_uploads_request_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_list_multipart_uploads_request_t *
list_multipart_uploads_request_initialize(const char *bucket_name);

/**
 * oss_list_multipart_uploads_request_t��������
 * @param request [in] ��ʶһ��oss_list_multipart_uploads_request_t�ṹָ��
 * @retval void
 * @pre request ����ʹ��list_multipart_uploads_request_initialize�ķ���ֵ
 */
extern void
list_multipart_uploads_request_finalize(
		oss_list_multipart_uploads_request_t *request);
/**@}*/

#endif // OSS_LIST_MULTIPART_UPLOADS_REQUEST_H 



/*
 * =============================================================================
 *
 *       Filename:  oss_list_parts_request.h
 *
 *    Description:  list parts request implementation.
 *
 *        Created:  09/05/2012 10:41:00 AM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_LIST_PARTS_REQUEST_H
# error Never include <oss_list_parts_request_h> directly
# error use <client.h> instead.
#endif

#ifndef OSS_LIST_PARTS_REQUEST_H
#define OSS_LIST_PARTS_REQUEST_H

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @defgroup oss_list_parts_request_t oss_list_parts_request_t
 * @{
 */

/**
 * struct oss_list_parts_request_s �ڲ�ʹ�� \n
 * oss_list_parts_request_t ������ʹ��
 */
typedef struct oss_list_parts_request_s oss_list_parts_request_t;


/**
 * �����г�Part���������
 */
struct oss_list_parts_request_s {
	char *bucket_name;         /**< Bucket���� */
	char *key;                 /**< Object���� */
	unsigned int max_parts;    /**< ��ʾ��󷵻ض�������¼*/
	unsigned int part_number_marker;    /**< ��ʾ���ĸ�Part���뿪ʼ��ȡ�б� */
	char *upload_id;           /** ��ʶMultipart�ϴ��¼���Upload ID */

	/**
	 * ���Bucket����
	 * @param request [in] ��ʶһ��oss_list_parts_request_t�ṹָ��
	 * @return Bucket����
	 * @retval const char *
	 */
	const char * (*get_bucket_name)(oss_list_parts_request_t *request);

	/**
	 * ���Object����
	 * @param request [in] ��ʶһ��oss_list_parts_request_t�ṹָ��
	 * @return Object����
	 * @retval const char *
	 */
	const char * (*get_key)(oss_list_parts_request_t *request);

	/**
	 * ���max_parts
	 * @param request [in] ��ʶһ��oss_list_parts_request_t�ṹָ��
	 * @return max_parts
	 * @retval unsigned int
	 */
	unsigned int (*get_max_parts)(oss_list_parts_request_t *request);

	/**
	 * ���part_number_marker
	 * @param request [in] ��ʶһ��oss_list_parts_request_t�ṹָ��
	 * @return part_number_marker
	 * @retval unsigned int
	 */
	unsigned int (*get_part_number_marker)(oss_list_parts_request_t *request);

	/**
	 * ���Upload ID
	 * @param request [in] ��ʶһ��oss_list_parts_request_t�ṹָ��
	 * @return Upload ID
	 * @retval const char *
	 */
	const char * (*get_upload_id)(oss_list_parts_request_t *request);

	/**
	 * ����Bucket����
	 * @param request [in] ��ʶһ��oss_list_parts_request_t�ṹָ��
	 * @param bucket_name [in] Bucket����
	 * @retval void
	 */
	void (*set_bucket_name)(oss_list_parts_request_t *request,
			const char *bucket_name);

	/**
	 * ����Object����
	 * @param request [in] ��ʶһ��oss_list_parts_request_t�ṹָ��
	 * @param key [in] Object����
	 * @retval void
	 */
	void (*set_key)(oss_list_parts_request_t *request,
			const char *key);

	/**
	 * ����max_parts
	 * @param request [in] ��ʶһ��oss_list_parts_request_t�ṹָ��
	 * @param max_parts [in] max_parts
	 * @retval void
	 */
	void (*set_max_parts)(oss_list_parts_request_t *request,
			unsigned int max_parts);

	/**
	 * ����part_number_marker
	 * @param request [in] ��ʶһ��oss_list_parts_request_t�ṹָ��
	 * @param part_number_marker [in] part_number_marker
	 * @retval void
	 */
	void (*set_part_number_marker)(oss_list_parts_request_t *request,
			unsigned int part_number_marker);

	/**
	 * ����Upload ID
	 * @param request [in] ��ʶһ��oss_list_parts_request_t�ṹָ��
	 * @param upload_id [in] Upload ID
	 * @retval void
	 */
	void (*set_upload_id)(oss_list_parts_request_t *request,
			const char *upload_id);
};

/**
 * oss_list_parts_request_t���캯��
 * @param bucket_name [in] Bucket����
 * @param key [in] Object����
 * @param upload_id [in] Upload ID
 * @return ����һ��oss_list_parts_request_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_list_parts_request_t *
list_parts_request_initialize(const char *bucket_name,
		const char *key,
		const char *upload_id);
/**
 * oss_list_parts_request_t��������
 * @param request [in] ��ʶһ��oss_list_parts_request_t�ṹָ��
 * @retval void
 * @pre request ����ʹ��list_parts_request_initialize�ķ���ֵ
 */
extern void
list_parts_request_finalize(
		oss_list_parts_request_t *request);

/**@}*/
#endif // OSS_LIST_PARTS_REQUEST_H 

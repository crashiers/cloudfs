/*
 * =============================================================================
 *
 *       Filename:  oss_list_objects_request.h
 *
 *    Description:  list object request implementation. 
 *
 *        Created:  09/04/2012 10:54:49 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_LIST_OBJECTS_REQUEST_H
# error Never include <oss_list_objects_request_h> directly
# error use <client.h> instead.
#endif

#ifndef OSS_LIST_OBJECTS_REQUEST_H
#define OSS_LIST_OBJECTS_REQUEST_H

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @defgroup oss_list_objects_request_t oss_list_objects_request_t
 * @{
 */

/**
 * struct oss_list_objects_request_s �ڲ�ʹ�� \n
 * oss_list_objects_request_t ������ʹ��
 */
typedef struct oss_list_objects_request_s oss_list_objects_request_t;

/**
 * ������ȡobject�б��������Ϣ
 */
struct oss_list_objects_request_s {
	char *bucket_name;          /**< Bucket���� */
	char *delimiter;            /**< �ָ��� */
	char *marker;               /**< ��ʶ��ʾ�����ﷵ���б� */
	unsigned int max_keys;      /**< ���Ƶ���󷵻ؼ�¼�� */
	char *prefix;               /**< ǰ׺ */

	/**
	 * ���Bucket����
	 * @param request [in] ��ʶһ��oss_list_objects_request_t�ṹָ��
	 * @return Bucket����
	 * @retval const char *
	 */
	const char * (*get_bucket_name)(oss_list_objects_request_t *request);

	/**
	 * ��÷ָ���
	 * @param request [in] ��ʶһ��oss_list_objects_request_t�ṹָ��
	 * @return delimiter
	 * @retval const char *
	 */
	const char * (*get_delimiter)(oss_list_objects_request_t *request);

	/**
	 * ���marker
	 * @param request [in] ��ʶһ��oss_list_objects_request_t�ṹָ��
	 * @return marker
	 * @retval const char *
	 */
	const char * (*get_marker)(oss_list_objects_request_t *request);

	/**
	 * �����󷵻ؼ�¼��
	 * @param request [in] ��ʶһ��oss_list_objects_request_t�ṹָ��
	 * @return max_keys
	 * @retval unsigned int
	 */
	unsigned int (*get_max_keys)(oss_list_objects_request_t *request);

	/**
	 * ���ǰ׺
	 * @param request [in] ��ʶһ��oss_list_objects_request_t�ṹָ��
	 * @return ǰ׺
	 * @retval const char *
	 */
	const char * (*get_prefix)(oss_list_objects_request_t *request);

	/**
	 * ����Bucket����
	 * @param request [in] ��ʶһ��oss_list_objects_request_t�ṹָ��
	 * @param bucket_name [in] Bucket����
	 * @retval void
	 */
	void (*set_bucket_name)(oss_list_objects_request_t *request,
			const char *bucket_name);

	/**
	 * ���÷ָ���
	 * @param request [in] ��ʶһ��oss_list_objects_request_t�ṹָ��
	 * @param delimiter [in] �ָ���
	 * @retval void
	 */
	void (*set_delimiter)(oss_list_objects_request_t *request,
			const char *delimiter);

	/**
	 * ����marker
	 * @param request [in] ��ʶһ��oss_list_objects_request_t�ṹָ��
	 * @param marker [in] marker
	 * @retval void
	 */
	void (*set_marker)(oss_list_objects_request_t *request,
			const char *marker);

	/**
	 * ����max_keys
	 * @param request [in] ��ʶһ��oss_list_objects_request_t�ṹָ��
	 * @param max_keys [in] max_keys
	 * @retval void
	 */
	void (*set_max_keys)(oss_list_objects_request_t *request,
			unsigned int max_keys);

	/**
	 * ����ǰ׺
	 * @param request [in] ��ʶһ��oss_list_objects_request_t�ṹָ��
	 * @param prefix [in] ǰ׺
	 * @retval void
	 */
	void (*set_prefix)(oss_list_objects_request_t *request,
			const char *prefix);
};

/**
 * oss_list_objects_request_t���캯��
 * @return ����һ��oss_list_objects_request_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_list_objects_request_t *
list_objects_request_initialize(void);

/**
 * oss_list_objects_request_t��bucket_name�Ĺ��캯��
 * @param bucket_name [in] Bucket����
 * @return ����һ��oss_list_objects_request_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_list_objects_request_t *
list_objects_request_initialize_with_bucket_name(const char *bucket_name);

/**
 * oss_list_objects_request_t��������Ĺ��캯��
 * @param bucket_name [in] Bucket����
 * @param prefix [in] ǰ׺
 * @param marker [in] ��ʶ��ʾ�����ﷵ���б�
 * @param delimiter [in] �ָ���
 * @param max_keys [in] ���Ƶ���󷵻ؼ�¼��
 * @return ����һ��oss_list_objects_request_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_list_objects_request_t *
list_objects_request_initialize_with_args(const char *bucket_name,
		const char *prefix,
		const char *marker,
		const char *delimiter,
		unsigned int max_keys);
/**
 * oss_list_objects_request_t��������
 * @param request [in] ��ʶһ��oss_list_objects_request_t�ṹָ��
 * @retval void
 * @pre request ����ʹ��list_objects_request_initialize�ķ���ֵ
 */
extern void
list_objects_request_finalize(
		oss_list_objects_request_t *request);

/**@}*/
#endif // OSS_LIST_OBJECTS_REQUEST_H 


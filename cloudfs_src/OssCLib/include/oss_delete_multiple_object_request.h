/*
 * =============================================================================
 *
 *       Filename:  oss_delete_multiple_object.h
 *
 *    Description:  oss_delete_multiple_object.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_DELETE_MULTIPLE_OBJECT_REQUEST_H
# error Never include <oss_delete_multiple_object.h> directly, use <client.h> instead.
#endif

#ifndef OSS_DELETE_MULTIPLE_OBJECT_REQUEST_H
#define OSS_DELETE_MULTIPLE_OBJECT_REQUEST_H 

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @defgroup oss_delete_multiple_object_request_t oss_delete_multiple_object_request_t
 * @{
 */

/**
 * struct oss_delete_multiple_object_request_s �ڲ�ʹ�� \n
 * oss_delete_multiple_object_request_t ������ʹ��
 */
typedef struct oss_delete_multiple_object_request_s oss_delete_multiple_object_request_t;

/**
 * ɾ��ָ��Bucket�Ķ��Object
 */
struct oss_delete_multiple_object_request_s{
	char *bucket_name;   /**< Bucket���� */
	char **keys;         /**< ���Object������ */
	bool mode;           /**< ����Ϊ true ��ʾ quiet ģʽ��false ��ʶ verbose ģʽ */
	int keynums;         /**< Ҫɾ��object�ĸ��� */

	/**
	 * ���Bucket����
	 * @param request [in] ��ʶһ��oss_delete_multiple_object_request_t�ṹָ��
	 * @return Bucket����
	 * @retval const char *
	 */
	const char * (*get_bucket_name)(oss_delete_multiple_object_request_t *request);

	/**
	 * ����Bucket����
	 * @param request [in] ��ʶһ��oss_delete_multiple_object_request_t�ṹָ��
	 * @param bucket_name [in] Bucket����
	 * @retval void
	 */
	void (*set_bucket_name)(oss_delete_multiple_object_request_t *request, const char *bucket_name);

	/**
	 * ��ö��Object������
	 * @param request [in] ��ʶһ��oss_delete_multiple_object_request_t�ṹָ��
	 * @param keynums [out] Ҫɾ��object�ĸ���
	 * @return ���Object������
	 * @retval const char **
	 */
	const char ** (*get_keys)(oss_delete_multiple_object_request_t *request, int *keynums);

	/**
	 * ���ö��Object������
	 * @param request [in] ��ʶһ��oss_delete_multiple_object_request_t�ṹָ��
	 * @param keys [in] ���Object������
	 * @param keynums [in] Ҫɾ��object�ĸ���
	 * @retval void
	 */
	void (*set_keys)(oss_delete_multiple_object_request_t *request, const char **keys, int keynums);

	/**
	 * ���ģʽ
	 * @param request [in] ��ʶһ��oss_delete_multiple_object_request_t�ṹָ��
	 * @return ģʽ
	 * @retval bool
	 */
	bool  (*get_mode)(oss_delete_multiple_object_request_t *request);

	/**
	 * ����ģʽ
	 * @param request [in] ��ʶһ��oss_delete_multiple_object_request_t�ṹָ��
	 * @param mode [in] ģʽ
	 * @retval void
	 */
	void (*set_mode)(oss_delete_multiple_object_request_t *request, bool mode);
};

/**
 * oss_delete_multiple_object_request_t ���캯��
 * @param bucket_name [in] Bucket����
 * @param key [in] ���Object������
 * @param keynums [in] Ҫɾ��object�ĸ���
 * @param mode [in] ģʽ
 * @return ����һ��oss_delete_multiple_object_request_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_delete_multiple_object_request_t *
delete_multiple_object_request_initialize(
		const char *bucket_name,
		const char **key,
		int keynums,
		bool mode);

/**
 * oss_delete_multiple_object_request_t ��������
 * @param request [in] ��ʶһ��oss_delete_multiple_object_request_t�ṹָ��
 * @retval void
 * @pre request ����ʹ��delete_multiple_object_request_initialize�ķ���ֵ
 */
extern void 
delete_multiple_object_request_finalize(
		oss_delete_multiple_object_request_t *request);
/**@}*/
#endif

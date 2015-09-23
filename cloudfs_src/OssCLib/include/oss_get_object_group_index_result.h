/*
 * =============================================================================
 *
 *       Filename:  oss_get_object_group_index_result.h
 *
 *    Description:  oss get_object_group_index_result
 *
 *        Created:  09/07/2012 03:22:02 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_GET_OBJECT_GROUP_INDEX_RESULT_H
# error Never include <oss_get_object_group_index_result.h> directly, use <client.h> instead.
#endif

#ifndef OSS_GET_OBJECT_GROUP_INDEX_RESULT_H
#define OSS_GET_OBJECT_GROUP_INDEX_RESULT_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define _OSS_MULTIPART_OBJECT_GROUP_H
#include <oss_multipart_object_group.h>
#undef _OSS_MULTIPART_OBJECT_GROUP_H

/**
 * @defgroup oss_get_object_group_index_result_t oss_get_object_group_index_result_t
 * @{
 */

/**
 * struct oss_get_object_group_index_result_s �ڲ�ʹ�� \n
 * oss_get_object_group_index_result_t ������ʹ��
 */
typedef struct oss_get_object_group_index_result_s oss_get_object_group_index_result_t;

/**
 * ���ڷ��� Object Group �е� Object List ��Ϣ
 */
struct oss_get_object_group_index_result_s {
	char *bucket_name;               /**< Bucket���� */
	char *key;                       /**< Object���� */
	char *etag;                      /**< Object��MD5ֵ */
	oss_multipart_object_group_t **group;  /**< object group�еĶ��object�б� */
	int part_number;                 /**< object group�еĶ��object�б�ĸ��� */
	unsigned int file_length;              /**< �ļ����� */

	/**
	 * ���Bucket����
	 * @param result [in] ��ʶһ��oss_get_object_group_index_result_t�ṹָ��
	 * @return Bucket����
	 * @retval const char *
	 */
	const char * (*get_bucket_name)(oss_get_object_group_index_result_t *result);

	/**
	 * ����Bucket����
	 * @param result [in] ��ʶһ��oss_get_object_group_index_result_t�ṹָ��
	 * @param bucket_name [in] Bucket����
	 * @retval void
	 */
	void (*set_bucket_name)(oss_get_object_group_index_result_t *result, const char *bucket_name);

	/**
	 * ���Object����
	 * @param result [in] ��ʶһ��oss_get_object_group_index_result_t�ṹָ��
	 * @return Object����
	 * @retval const char *
	 */
	const char * (*get_key)(oss_get_object_group_index_result_t *result);

	/**
	 * ����Object����
	 * @param result [in] ��ʶһ��oss_get_object_group_index_result_t�ṹָ��
	 * @param key [in] Object����
	 * @retval void
	 */
	void (*set_key)(oss_get_object_group_index_result_t *result, const char *key);

	/**
	 * ���Object��MD5ֵ
	 * @param result [in] ��ʶһ��oss_get_object_group_index_result_t�ṹָ��
	 * @return Object��MD5ֵ
	 * @retval const char *
	 */
	const char * (*get_etag)(oss_get_object_group_index_result_t *result);

	/**
	 * ����Object��MD5ֵ
	 * @param result [in] ��ʶһ��oss_get_object_group_index_result_t�ṹָ��
	 * @param etag [in] Object��MD5ֵ
	 * @retval void
	 */
	void (*set_etag)(oss_get_object_group_index_result_t *result, const char *etag);

	/**
	 * ���object group�еĶ��object�б�
	 * @param result [in] ��ʶһ��oss_get_object_group_index_result_t�ṹָ��
	 * @param part_number [out] object group�еĶ��object�б�ĸ���
	 * @return object group�еĶ��object�б�
	 * @retval �ǿ� ��ʾ�ɹ�
	 * @retval NULL ��ʾʧ��
	 */
	oss_multipart_object_group_t ** (*get_group)(oss_get_object_group_index_result_t *result, int *part_number);

	/**
	 * ����object group�еĶ��object�б�
	 * @param result [in] ��ʶһ��oss_get_object_group_index_result_t�ṹָ��
	 * @param group [in] object group�еĶ��object�б�
	 * @param part_number [in] object group�еĶ��object�б�ĸ���
	 * @retval void
	 */
	void (*set_group)(oss_get_object_group_index_result_t *result,
			oss_multipart_object_group_t **group, int part_number);
	
	/**
	 * ���Object���ļ�����
	 * @param result [in] ��ʶһ��oss_get_object_group_index_result_t�ṹָ��
	 * @return Object���ļ�����
	 * @retval unsigned int
	 */
	unsigned int (*get_file_length)(oss_get_object_group_index_result_t *result);

	/**
	 * ����Object���ļ�����
	 * @param result [in] ��ʶһ��oss_get_object_group_index_result_t�ṹָ��
	 * @param file_length [in] Object���ļ�����
	 * @retval void
	 */
	void (*set_file_length)(oss_get_object_group_index_result_t *result, unsigned int file_length);

};

/**
 * oss_get_object_group_index_result_t���캯��
 * @return ����һ��oss_get_object_group_index_result_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_get_object_group_index_result_t * get_object_group_index_result_initialize();

/**
 * oss_get_object_group_index_result_t��������
 * @param result [in] ��ʶһ��oss_get_object_group_index_result_t�ṹָ��
 * @retval void
 * @pre result ����ʹ��get_object_group_index_result_initialize�ķ���ֵ
 */
extern void get_object_group_index_result_finalize(oss_get_object_group_index_result_t *result);
/**@}*/
#endif // OSS_GET_OBJECT_GROUP_INDEX_RESULT_H


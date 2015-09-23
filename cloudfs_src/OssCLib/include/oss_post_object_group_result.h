/*
 * =============================================================================
 *
 *       Filename:  oss_post_object_group_result.h
 *
 *    Description:  oss post_object_group_result
 *
 *        Created:  09/07/2012 03:22:02 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_POST_OBJECT_GROUP_RESULT_H
# error Never include <oss_post_object_group_result.h> directly, use <client.h> instead.
#endif

#ifndef OSS_POST_OBJECT_GROUP_RESULT_H
#define OSS_POST_OBJECT_GROUP_RESULT_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**
 * @defgroup oss_post_object_group_result_t oss_post_object_group_result_t
 * @{
 */

/**
 * struct oss_post_object_group_result_s �ڲ�ʹ�� \n
 * oss_post_object_group_result_t ������ʹ��
 */
typedef struct oss_post_object_group_result_s oss_post_object_group_result_t;

/**
 * ���������飨Object Group�����صĽ��
 */
struct oss_post_object_group_result_s {
	char *bucket_name;      /**< Bucket���� */
	char *key;              /**< Object����*/
	char *etag;             /**< Object��etagֵ*/
	unsigned int size;            /**< Object�Ĵ�С*/

	/**
	 * ���Bucket����
	 * @param result [in] ��ʶһ��oss_post_object_group_result_t�ṹָ��
	 * @return Bucket����
	 * @retval const char *
	 */
	const char * (*get_bucket_name)(oss_post_object_group_result_t *result);

	/**
	 * ����Bucket����
	 * @param result [in] ��ʶһ��oss_post_object_group_result_t�ṹָ��
	 * @param bucket_name [in] Bucket����
	 * @retval void
	 */
	void (*set_bucket_name)(oss_post_object_group_result_t *result,
			const char *bucket_name);

	/**
	 * ���Object����
	 * @param result [in] ��ʶһ��oss_post_object_group_result_t�ṹָ��
	 * @return Object����
	 * @retval const char *
	 */
	const char * (*get_key)(oss_post_object_group_result_t *result);

	/**
	 * ����Object����
	 * @param result [in] ��ʶһ��oss_post_object_group_result_t�ṹָ��
	 * @param key [in] Object����
	 * @retval void
	 */
	void (*set_key)(oss_post_object_group_result_t *result,
			const char *key);

	/**
	 * ���Object��etagֵ
	 * @param result [in] ��ʶһ��oss_post_object_group_result_t�ṹָ��
	 * @return Object��etagֵ
	 * @retval const char *
	 */
	const char * (*get_etag)(oss_post_object_group_result_t *result);

	/**
	 * ����Object��etagֵ
	 * @param result [in] ��ʶһ��oss_post_object_group_result_t�ṹָ��
	 * @param etag [in] Object��etagֵ
	 * @retval void
	 */
	void (*set_etag)(oss_post_object_group_result_t *result, const char *etag);

	/**
	 * ���Object�Ĵ�С
	 * @param result [in] ��ʶһ��oss_post_object_group_result_t�ṹָ��
	 * @return Object�Ĵ�С
	 * @retval unsigned int
	 */
	unsigned int (*get_size)(oss_post_object_group_result_t *result);

	/**
	 * ����Object�Ĵ�С
	 * @param result [in] ��ʶһ��oss_post_object_group_result_t�ṹָ��
	 * @param size [in] Object�Ĵ�С
	 * @retval void
	 */
	void (*set_size)(oss_post_object_group_result_t *result, unsigned int size);

};


/**
 * oss_post_object_group_result_t���캯��
 * @return ����һ��oss_post_object_group_result_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_post_object_group_result_t *
post_object_group_result_initialize();

/**
 * oss_post_object_group_result_t��������
 * @param result [in] ��ʶһ��oss_post_object_group_result_t�ṹָ��
 * @retval void
 * @pre result ����ʹ��post_object_group_result_initialize�ķ���ֵ
 */
extern void
post_object_group_result_finalize(oss_post_object_group_result_t *result);

/**@}*/
#endif // OSS_POST_OBJECT_GROUP_RESULT_H


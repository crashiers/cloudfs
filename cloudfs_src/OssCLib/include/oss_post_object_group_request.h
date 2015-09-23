/*
 * =============================================================================
 *
 *       Filename:  oss_post_object_group_request.h
 *
 *    Description:  oss post object group request.
 *
 *        Created:  09/07/2012 03:22:02 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_POST_OBJECT_GROUP_REQUEST_H
# error Never include <oss_post_object_group_request.h> directly,
# error use <client.h> instead.
#endif

#ifndef OSS_POST_OBJECT_GROUP_REQUEST_H 
#define OSS_POST_OBJECT_GROUP_REQUEST_H 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define _OSS_OBJECT_GROUP_ITEM_H
#include "oss_object_group_item.h"
#undef _OSS_OBJECT_GROUP_ITEM_H 

/**
 * @defgroup oss_post_object_group_request_t oss_post_object_group_request_t
 * @{
 */

/**
 * struct oss_post_object_group_request_s �ڲ�ʹ�� \n
 * oss_post_object_group_request_t ������ʹ��
 */
typedef struct oss_post_object_group_request_s oss_post_object_group_request_t;

/**
 * Object Group ����һ������ Object ��ɵ���ɢ�ļ���,�������ݳ�������
 * ���� Object �����ݳ��ȵ��ܺ͡��û�����ָ����ͬһ�� Bucket �µ�һ������Object,
 * ������ OSS �������ϴ�����һ�� Object Group��һ�� Object Group �����ɹ�,
 * �û������������ͨ Object һ��ȥ���� Object Group,��Щ�������� get,range query,
 * delete,list,�� Object Group �����ݺ������� Object �����ݲ��ǽ�����ϵ�ġ�
 * ͨ�� Object Group,�û�����ʵ�� Object ��������,�����ļ��Ķ��̲߳���,�Լ��ϵ������ȹ��ܡ�
 *
 */

/**
 * Post Object Group �����������û��ṩ�� Object ��Ϣ,�� OSS �������˴�
 * ����һ���µ� Object Group���û���Ҫ�������� Object Group ����� Object Name,
 * E-tag �Լ���ʶ�� Object ������ Group �����λ�õ� Part ID ���չ涨�� XML ��ʽ���� OSS��
 *
 */
struct oss_post_object_group_request_s {
	char *bucket_name;      /**< Bucket ����*/
	char *key;              /**< Oject ����*/
	oss_object_group_item_t **items;  /**< һ������ Object ��ɵ���ɢ�ļ���*/
	unsigned int itemnums;        /**< һ������ Object ��ɵ���ɢ�ļ��ϵ���Ŀ*/

	/**
	 * ��� Bucket ����
	 * @param request [in] ��ʶһ��oss_post_object_group_request_t�ṹָ��
	 * @return Bucket ����
	 * @retval const char *
	 */
	const char * (*get_bucket_name)(oss_post_object_group_request_t *request);

	/**
	 * ���� Bucket ����
	 * @param request [in] ��ʶһ��oss_post_object_group_request_t�ṹָ��
	 * @param bucket_name [in] Bucket ����
	 * @retval void
	 */
	void (*set_bucket_name)(oss_post_object_group_request_t *request,
			const char *bucket_name);

	/**
	 * ��� Object ����
	 * @param request [in] ��ʶһ��oss_post_object_group_request_t�ṹָ��
	 * @return Object ����
	 * @retval const char *
	 */
	const char * (*get_key)(oss_post_object_group_request_t *request);

	/**
	 * ����Object ����
	 * @param request [in] ��ʶһ��oss_post_object_group_request_t�ṹָ��
	 * @param key [in] Object ����
	 * @retval void
	 */
	void (*set_key)(oss_post_object_group_request_t *request,
			const char *key);

	/**
	 * ���һ������ Object ��ɵ���ɢ�ļ���
	 * @param request [in] ��ʶһ��oss_post_object_group_request_t�ṹָ��
	 * @param itemnums [out]  Object ��ɵ���ɢ�ļ��ϵĸ���
	 * @return ����һ��oss_object_group_item_t�ṹָ��
	 * @retval �ǿ� ��ʾ�ɹ�
	 * @retval NULL ��ʾʧ��
	 */
	oss_object_group_item_t ** (*get_items)(oss_post_object_group_request_t *request,
			int *itemnums);

	/**
	 * ����һ������ Object ��ɵ���ɢ�ļ���
	 * @param request [in] ��ʶһ��oss_post_object_group_request_t�ṹָ��
	 * @param item  [in] һ������ Object ��ɵ���ɢ�ļ���
	 * @param itemnums [in] һ������ Object ��ɵ���ɢ�ļ�������Ŀ�ĸ���
	 */
	void (*set_items)(oss_post_object_group_request_t *request,
			oss_object_group_item_t **item, int itemnums);
	
};

/**
 * oss_post_object_group_request_t ���캯��
 * @return oss_post_object_group_request_t *ָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_post_object_group_request_t *
post_object_group_request_initialize(const char *bucket_name, const char *key,
		oss_object_group_item_t **items, int itemnums);

/**
 * oss_post_object_group_request_t ��������
 * @param request [in] ��ʶһ��oss_post_object_group_request_t�ṹָ��
 * @retval void
 * @pre request ����ʹ��post_object_group_request_initialize�ķ���ֵ
 */
extern void post_object_group_request_finalize(oss_post_object_group_request_t *request);
/**@}*/
#endif // OSS_POST_OBJECT_GROUP_REQUEST_H


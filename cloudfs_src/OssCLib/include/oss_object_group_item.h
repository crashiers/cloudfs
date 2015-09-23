/*
 * =============================================================================
 *
 *       Filename:  oss_object_group_item.h
 *
 *    Description:  oss object_group_item
 *
 *        Created:  09/07/2012 03:22:02 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _OSS_OBJECT_GROUP_ITEM_H
# error Never include <oss_object_group_item.h> directly, use <client.h> instead.
#endif

#ifndef OSS_OBJECT_GROUP_ITEM_H 
#define OSS_OBJECT_GROUP_ITEM_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**
 * @defgroup oss_object_group_item_t oss_object_group_item_t
 * @{
 */

/**
 * struct oss_object_group_item_s �ڲ�ʹ�� \n
 * oss_object_group_item_t ������ʹ��
 */
typedef struct oss_object_group_item_s oss_object_group_item_t;

/**
 * post object group ��Ҫ�ṩ�� Object ��Ϣ
 */
struct oss_object_group_item_s {
	char *etag;            /**< Object��etag */
	char *part_name;       /**< Object��name */
	int part_number;       /**< Object��number */

	/**
	 * ���Object��etag
	 * @param item [in] ��ʶһ��oss_object_group_item_t�ṹָ��
	 * @return Object��etag
	 * @retval const char *
	 */
	const char * (*get_etag)(oss_object_group_item_t *item);

	/**
	 * ����Object��etag
	 * @param item [in] ��ʶһ��oss_object_group_item_t�ṹָ��
	 * @param etag [in] Object��etag
	 * @retval void
	 */
	void (*set_etag)(oss_object_group_item_t *item, const char *etag);

	/**
	 * ���Object��name
	 * @param item [in] ��ʶһ��oss_object_group_item_t�ṹָ��
	 * @return Object��name
	 * @retval const char *
	 */
	const char * (*get_part_name)(oss_object_group_item_t *item);

	/**
	 * ����Object��name
	 * @param item [in] ��ʶһ��oss_object_group_item_t�ṹָ��
	 * @param part_name [in] Object��name
	 * @retval void
	 */
	void (*set_part_name)(oss_object_group_item_t *item, const char *part_name);

	/**
	 * ���Object��number
	 * @param item [in] ��ʶһ��oss_object_group_item_t�ṹָ��
	 * @return Object��number
	 * @retval int
	 */
	int (*get_part_number)(oss_object_group_item_t *item);

	/**
	 * ����Object��number
	 * @param item [in] ��ʶһ��oss_object_group_item_t�ṹָ��
	 * @param part_name [in] Object��number
	 * @retval void
	 */
	void (*set_part_number)(oss_object_group_item_t *item, int part_number);
};

/**
 * oss_object_group_item_t���캯��
 * @return ����һ��oss_object_group_item_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_object_group_item_t * object_group_item_initialize();

/**
 * oss_object_group_item_t��������
 * @param item [in] ��ʶһ��oss_object_group_item_t�ṹָ��
 * @retval void
 * @pre item ����ʹ��object_group_item_initialize�ķ���ֵ
 */
extern void object_group_item_finalize(oss_object_group_item_t *item);
/**@}*/
#endif // OSS_OBJECT_GROUP_ITEM_H 


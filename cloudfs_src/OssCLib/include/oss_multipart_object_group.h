/*
 * =============================================================================
 *
 *       Filename:  oss_multipart_object_group.h
 *
 *    Description:  oss multipart_object_group
 *
 *        Created:  09/07/2012 03:22:02 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _OSS_MULTIPART_OBJECT_GROUP_H
# error Never include <oss_multipart_object_group.h> directly, use <client.h> instead.
#endif

#ifndef OSS_MULTIPART_OBJECT_GROUP_H
#define OSS_MULTIPART_OBJECT_GROUP_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**
 * @defgroup oss_multipart_object_group_t oss_multipart_object_group_t
 * @{
 */

/**
 * struct oss_multipart_object_group_s �ڲ�ʹ�� \n
 * oss_multipart_object_group_t ������ʹ��
 */
typedef struct oss_multipart_object_group_s oss_multipart_object_group_t;

/**
 * object group��ÿ��object����Ϣ
 */
struct oss_multipart_object_group_s {
	char *etag;              /**< Object��etag */
	char *part_name;         /**< Object��name */
	int part_number;         /**< Object��number */
	unsigned int part_size;        /**< Object��size */

	/**
	 * ���Object��etag
	 * @param group [in] ��ʶһ��oss_multipart_object_group_t�ṹָ��
	 * @return Object��etag
	 * @retval const char *
	 */
	const char * (*get_etag)(oss_multipart_object_group_t *group);

	/**
	 * ����Object��etag
	 * @param group [in] ��ʶһ��oss_multipart_object_group_t�ṹָ��
	 * @param etag [in] Object��etag
	 * @retval void
	 */
	void (*set_etag)(oss_multipart_object_group_t *group, const char *etag);

	/**
	 * ���Object��name
	 * @param group [in] ��ʶһ��oss_multipart_object_group_t�ṹָ��
	 * @return Object��name
	 * @retval const char *
	 */
	const char * (*get_part_name)(oss_multipart_object_group_t *group);

	/**
	 * ����Object��name
	 * @param group [in] ��ʶһ��oss_multipart_object_group_t�ṹָ��
	 * @param part_name [in] Object��name
	 * @retval void
	 */
	void (*set_part_name)(oss_multipart_object_group_t *group, const char *part_name);

	/**
	 * ���Object��number
	 * @param group [in] ��ʶһ��oss_multipart_object_group_t�ṹָ��
	 * @return Object��number
	 * @retval int
	 */
	int (*get_part_number)(oss_multipart_object_group_t *group);

	/**
	 * ����Object��number
	 * @param group [in] ��ʶһ��oss_multipart_object_group_t�ṹָ��
	 * @param part_number [in] Object��number
	 * @retval void
	 */
	void (*set_part_number)(oss_multipart_object_group_t *group, int part_number);

	/**
	 * ���Object��size
	 * @param group [in] ��ʶһ��oss_multipart_object_group_t�ṹָ��
	 * @return Object��size
	 * @retval unsigned int
	 */
	unsigned int (*get_part_size)(oss_multipart_object_group_t *group);

	/**
	 * ����Object��size
	 * @param group [in] ��ʶһ��oss_multipart_object_group_t�ṹָ��
	 * @param part_size [in] Object��size
	 * @retval void
	 */
	void (*set_part_size)(oss_multipart_object_group_t *group, unsigned int part_size);

};

/**
 * oss_multipart_object_group_t���캯��
 * @return ����һ��oss_multipart_object_group_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_multipart_object_group_t * multipart_object_group_initialize();

/**
 * oss_multipart_object_group_t��������
 * @param group [in] ��ʶһ��oss_multipart_object_group_t�ṹָ��
 * @retval void
 * @pre group ����ʹ��multipart_object_group_initialize�ķ���ֵ
 */
extern void multipart_object_group_finalize(oss_multipart_object_group_t *group);
/**@}*/
#endif // OSS_MULTIPART_OBJECT_GROUP_H


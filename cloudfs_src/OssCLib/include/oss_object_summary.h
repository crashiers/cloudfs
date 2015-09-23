/*
 * =============================================================================
 *
 *       Filename:  oss_object_summary.h
 *
 *    Description:  oss_object_summary.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_OBJECT_SUMMARY_H
# error Never include <oss_object_summary.h> directly, use <client.h> instead.
#endif

#ifndef OSS_OBJECT_SUMMARY_H
#define OSS_OBJECT_SUMMARY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define _OSS_OWNER_H
#include  <oss_owner.h>
#undef _OSS_OWNER_H

/**
 * @defgroup oss_object_summary_t oss_object_summary_t
 * @{
 */

/**
 * struct oss_object_summary_s �ڲ�ʹ�� \n
 * oss_object_summary_t ������ʹ��
 */
typedef struct oss_object_summary_s oss_object_summary_t;

/**
 * OSSObjectժҪ��Ϣ
 */
struct oss_object_summary_s {
	char *type;               /**< Object����� */
	char *etag;               /**< Object��etag */
	char *key;                /**< Object������ */
	char *last_modified;      /**< Object�ϴ��޸ĵ�ʱ�� */
	oss_owner_t *owner;       /**< Object�������� */
	long size;                /**< Object�Ĵ�С */
	char *storage_class;      /**< Object�Ĵ洢��� */

	/**
	 * ���Object�����
	 * @param summary [in] ��ʶһ��oss_object_summary_t�ṹָ��
	 * @return Object�����
	 * @retval const char *
	 */
	const char * (*get_type)(oss_object_summary_t *summary);

	/**
	 * ����Object�����
	 * @param summary [in] ��ʶһ��oss_object_summary_t�ṹָ��
	 * @param type [in] Object�����
	 * @retval void
	 */
	void (*set_type)(oss_object_summary_t *summary, const char *type);

	/**
	 * ���Object��etag
	 * @param summary [in] ��ʶһ��oss_object_summary_t�ṹָ��
	 * @return Object��etag
	 * @retval const char *
	 */
	const char * (*get_etag)(oss_object_summary_t *summary);

	/**
	 * ����Object��etag
	 * @param summary [in] ��ʶһ��oss_object_summary_t�ṹָ��
	 * @param etag [in] Object��etag
	 * @retval void
	 */
	void (*set_etag)(oss_object_summary_t *summary, const char * etag);

	/**
	 * ���Object������
	 * @param summary [in] ��ʶһ��oss_object_summary_t�ṹָ��
	 * @return Object������
	 * @retval const char *
	 */
	const char * (*get_key)(oss_object_summary_t *summary);

	/**
	 * ����Object������
	 * @param summary [in] ��ʶһ��oss_object_summary_t�ṹָ��
	 * @param key [in] Object������
	 * @retval void
	 */
	void (*set_key)(oss_object_summary_t *summary, const char *key);

	/**
	 * ���Object�ϴ��޸ĵ�ʱ��
	 * @param summary [in] ��ʶһ��oss_object_summary_t�ṹָ��
	 * @return Object�ϴ��޸ĵ�ʱ��
	 * @retval const char *
	 */
	const char * (*get_last_modified)(oss_object_summary_t *summary);

	/**
	 * ����Object�ϴ��޸ĵ�ʱ��
	 * @param summary [in] ��ʶһ��oss_object_summary_t�ṹָ��
	 * @param last_modified [in] bject�ϴ��޸ĵ�ʱ��
	 * @retval void
	 */
	void (*set_last_modified)(oss_object_summary_t *summary, const char *last_modified);

	/**
	 * ���Object��������
	 * @param summary [in] ��ʶһ��oss_object_summary_t�ṹָ��
	 * @return ����һ��oss_owner_t�ṹָ��
	 * @retval �ǿ� ��ʾ�ɹ�
	 * @retval NULL ��ʾʧ��
	 */
	oss_owner_t * (*get_owner)(oss_object_summary_t *summary);

	/**
	 * ����Object��������
	 * @param summary [in] ��ʶһ��oss_object_summary_t�ṹָ��
	 * @param owner [in] Object��������
	 * @retval void
	 */
	void (*set_owner)(oss_object_summary_t *summary, oss_owner_t *owner);
	
	/**
	 * ���Object�Ĵ�С
	 * @param summary [in] ��ʶһ��oss_object_summary_t�ṹָ��
	 * @return Object�Ĵ�С
	 * @retval long
	 */
	long  (*get_size)(oss_object_summary_t *summary);

	/**
	 * ����Object�Ĵ�С
	 * @param summary [in] ��ʶһ��oss_object_summary_t�ṹָ��
	 * @param size [in] Object�Ĵ�С
	 * @retval void
	 */
	void (*set_size)(oss_object_summary_t *summary, long size);

	/**
	 * ���Object�Ĵ洢���
	 * @param summary [in] ��ʶһ��oss_object_summary_t�ṹָ��
	 * @return Object�Ĵ洢���
	 * @retval const char *
	 */
	const char * (*get_storage_class)(oss_object_summary_t *summary);

	/**
	 * ����Object�Ĵ洢���
	 * @param summary [in] ��ʶһ��oss_object_summary_t�ṹָ��
	 * @param storage_class [in] bject�Ĵ洢���
	 * @retval void
	 */
	void (*set_storage_class)(oss_object_summary_t *summary, const char *storage_class);
};

/**
 * oss_object_summary_t���캯��
 * @return ����һ��oss_object_summary_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_object_summary_t *
object_summary_initialize(void);

/**
 * oss_object_summary_t��������
 * @param summary [in] ��ʶһ��oss_object_summary_t�ṹָ��
 * @retval void
 * @pre summary ����ʹ��object_summary_initialize�ķ���ֵ
 */
extern void 
object_summary_finalize(oss_object_summary_t *summary);
/**@}*/
#endif

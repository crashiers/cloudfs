/*
 * =============================================================================
 *
 *       Filename:  oss_part_listing.h
 *
 *    Description:  oss_part_listing.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_PART_LISTING_H
# error Never include <oss_part_listing.h> directly, use <client.h> instead.
#endif

#ifndef OSS_PART_LISTING_H
#define OSS_PART_LISTING_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define _OSS_OWNER_H
#include  <oss_owner.h>
#undef _OSS_OWNER_H

#define _OSS_PART_SUMMARY_H
#include <oss_part_summary.h>
#undef _OSS_PART_SUMMARY_H

#include <ossc-config.h>

#ifdef HAVE_STDBOOL_H
#include <stdbool.h>
#endif
/**
 * @defgroup oss_part_listing_t oss_part_listing_t
 * @{
 */

/**
 * struct oss_part_listing_s �ڲ�ʹ�� \n
 * oss_part_listing_t ������ʹ��
 */
typedef struct oss_part_listing_s oss_part_listing_t;

/**
 * ����Multipart�ϴ�Part�ı�ʾ
 */
struct oss_part_listing_s {
	char *bucket_name;                  /**< Bucket���� */
	oss_owner_t *initiator;             /**< Object�ĵĳ�ʼ���� */
	bool is_truncated;                  /**< ��ʶ����Ƿ񱻽�ȡ */
	char *key;                          /**< Object������ */
	int max_parts;                      /**< ������ָ������Part�������� */
	int next_part_number_marker;        /**< ������ؽ������ȡ����ô��һ��Part�ĺ����Ƕ��� */
	oss_owner_t *owner;                 /**< Object�������� */
	int part_number_marker;             /**< ��ʶ��������ʾ */
	oss_part_summary_t **parts;         /**< PartSummary���б� */
	int parts_number;                   /**< PartSummary���б����Ŀ */
	char *storage_class;                /**< Object�Ĵ洢��� */
	char *upload_id;                    /**< ��ʶMultipart�ϴ��¼���Upload ID */

	/**
	 * ���Bucket����
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @return Bucket����
	 * @retval const char *
	 */
	const char * (*get_bucket_name)(oss_part_listing_t *listing);

	/**
	 * ����Bucket����
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @param bucket_name [in] Bucket����
	 * @retval void
	 */
	void (*set_bucket_name)(oss_part_listing_t *listing, const char *bucket_name);

	/**
	 * ���Object������
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @return Object������
	 * @retval const char *
	 */
	const char * (*get_key)(oss_part_listing_t *listing);

	/**
	 * ����Object������
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @param key [in] Object������
	 * @retval void
	 */
	void (*set_key)(oss_part_listing_t *listing, const char *key);

	/**
	 * ���Upload ID
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @return Upload ID
	 * @retval const char *
	 */
	const char * (*get_upload_id)(oss_part_listing_t *listing);

	/**
	 * ����Upload ID
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @param upload_id [in] Upload ID
	 * @retval void
	 */
	void (*set_upload_id)(oss_part_listing_t *listing, const char *upload_id);

	/**
	 * ���Object�Ĵ洢���
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @return Object�Ĵ洢���
	 * @retval const char *
	 */
	const char * (*get_storage_class)(oss_part_listing_t *listing);

	/**
	 * ����Object�Ĵ洢���
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @param storage_class [in] Object�Ĵ洢���
	 * @retval void
	 */
	void (*set_storage_class)(oss_part_listing_t *listing, const char *storage_class);

	/**
	 * ���Object�ĵĳ�ʼ����
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @return Object�ĵĳ�ʼ����
	 * @return ����һ�� oss_owner_t�ṹָ��
	 * @retval �ǿ� ��ʾ�ɹ�
	 * @retval NULL ��ʾʧ��
	 */
	oss_owner_t * (*get_initiator)(oss_part_listing_t *listing);

	/**
	 * ����Object�ĵĳ�ʼ����
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @param initiator [in] Object�ĵĳ�ʼ����
	 * @retval void
	 */
	void (*set_initiator)(oss_part_listing_t *listing, oss_owner_t *initiator);

	/**
	 * ���������ָ������Part��������
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @return ������ָ������Part��������
	 * @retval int
	 */
	int (*get_max_parts)(oss_part_listing_t *listing);

	/**
	 * ����������ָ������Part��������
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @param max_parts [in] ������ָ������Part��������
	 * @retval void
	 */
	void (*set_max_parts)(oss_part_listing_t *listing, int max_parts);

	/**
	 * ���is_truncated
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @return is_truncated
	 * @retval bool
	 */
	bool (*get_is_truncated)(oss_part_listing_t *listing);

	/**
	 * ����is_truncated
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @param is_truncated [in] is_truncated
	 * @retval void
	 */
	void (*set_is_truncated)(oss_part_listing_t *listing, bool is_truncated);

	/**
	 * ���PartSummary���б�
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @param parts_number [out] PartSummary���б�ĸ���
	 * @return ����һ��oss_part_summary_t�ṹָ��
	 * @retval �ǿ� ��ʾ�ɹ�
	 * @retval NULL ��ʾʧ��
	 */
	oss_part_summary_t ** (*get_parts)(oss_part_listing_t *listing, int *parts_number);

	/**
	 * ����PartSummary���б�
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @param parts [in] PartSummary���б�
	 * @param parts_number [in] PartSummary���б�ĸ���
	 * @retval void
	 */
	void (*set_parts)(oss_part_listing_t *listing, oss_part_summary_t **parts, int parts_number);

	/**
	 * ���next_part_number_marker
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @return next_part_number_marker
	 * @retval int
	 */
	int (*get_next_part_number_marker)(oss_part_listing_t *listing);

	/**
	 * ����next_part_number_marker
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @param next_part_number_marker [in] next_part_number_marker
	 * @retval void
	 */
	void (*set_next_part_number_marker)(oss_part_listing_t *listing, int next_part_number_marker);

	/**
	 * ���Object��������
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @return ����һ��oss_owner_t�ṹָ��
	 * @retval �ǿ� ��ʾ�ɹ�
	 * @retval NULL ��ʾʧ��
	 */
	oss_owner_t * (*get_owner)(oss_part_listing_t *listing);

	/**
	 * ����Object��������
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @param owner [in] bject��������
	 * @retval void
	 */
	void (*set_owner)(oss_part_listing_t *listing, oss_owner_t *owner);
	
	/**
	 * ���part_number_marker
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @return part_number_marker
	 * @retval int
	 */
	int (*get_part_number_marker)(oss_part_listing_t *listing);

	/**
	 * ����part_number_marker
	 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
	 * @param part_number_marker [in] part_number_marker
	 * @retval void
	 */
	void (*set_part_number_marker)(oss_part_listing_t *listing, int part_number_marker);



};

/**
 * oss_part_listing_t���캯��
 * @return ����һ��oss_part_listing_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_part_listing_t *
part_listing_initialize(void);

/**
 * oss_part_listing_t��������
 * @param listing [in] ��ʶһ��oss_part_listing_t�ṹָ��
 * @retval void
 * @pre listing ����ʹ��part_listing_initialize�ķ���ֵ
 */
extern void 
part_listing_finalize(oss_part_listing_t *listing);
/**@}*/
#endif

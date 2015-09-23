/*
 * =============================================================================
 *
 *       Filename:  oss_object_listing.h
 *
 *    Description:  oss_object_listing.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_OBJECT_LISTING_H
# error Never include <oss_object_listing.h> directly, use <client.h> instead.
#endif

#ifndef OSS_OBJECT_LISTING_H
#define OSS_OBJECT_LISTING_H
#define _OSS_OBJECT_SUMMARY_H
#include <oss_object_summary.h>
#undef _OSS_OBJECT_SUMMARY_H
#include <ossc-config.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#ifdef HAVE_STDBOOL_H
#include <stdbool.h>
#endif

/**
 * @defgroup oss_object_listing_t oss_object_listing_t
 * @{
 */

/**
 * struct oss_object_listing_s �ڲ�ʹ�� \n
 * oss_object_listing_t ������ʹ��
 */
typedef struct oss_object_listing_s oss_object_listing_t;

/**
 * һ��Bucket�����е�Object��Ϣ
 */
struct oss_object_listing_s {
	char *bucket_name;       /**< Bucket���� */
	char *next_marker;       /**< �����Ϊ max-keys ���趨�޷�һ����� listing,���ؽ���ḽ��һ��NextMarker */
	char *prefix;            /**< ǰ׺ */
	char *marker;            /**< ��ʶ��ʾ�����ﷵ���б� */
	int max_keys;            /**< ���� object ������� */
	char * delimiter;        /**< �ָ��� */
	bool is_truncated;       /**< ��ʶ�Ƿ���δ��ʾ��Object */

	oss_object_summary_t **summaries;      /**< ���е�Object��Ϣ */
	unsigned int _counts_summaries;        /**< Object����Ŀ */

	char **common_prefixes;                 /**< ���ְ���ָ����ǰ׺�ҵ�һ�γ��� delimiter �ַ�֮��� object */
	unsigned int _counts_common_prefixes;   /**< common_prefixes����Ŀ */

	/**
	 * ���Bucket����
	 * @param listing [in] ��ʶһ��oss_object_listing_t�ṹָ��
	 * @return Bucket����
	 * @retval const char *
	 */
	const char * (*get_bucket_name)(oss_object_listing_t *listing);

	/**
	 * ����Bucket����
	 * @param listing [in] ��ʶһ��oss_object_listing_t�ṹָ��
	 * @param bucket_name [in] Bucket����
	 * @retval void
	 */
	void (*set_bucket_name)(oss_object_listing_t *listing, const char *bucket_name);

	/**
	 * ���next_marker
	 * @param listing [in] ��ʶһ��oss_object_listing_t�ṹָ��
	 * @return next_marker
	 * @retval const char *
	 */
	const char * (*get_next_marker)(oss_object_listing_t *listing);

	/**
	 * ����next_marker
	 * @param listing [in] ��ʶһ��oss_object_listing_t�ṹָ��
	 * @param next_marker [in] next_marker
	 * @retval void
	 */
	void (*set_next_marker)(oss_object_listing_t *listing, const char *next_marker);

	/**
	 * ���ǰ׺
	 * @param listing [in] ��ʶһ��oss_object_listing_t�ṹָ��
	 * @return ǰ׺
	 * @retval const char *
	 */
	const char * (*get_prefix)(oss_object_listing_t *listing);

	/**
	 * ����ǰ׺
	 * @param listing [in] ��ʶһ��oss_object_listing_t�ṹָ��
	 * @param prefix [in] ǰ׺
	 * @retval void
	 */
	void (*set_prefix)(oss_object_listing_t *listing, const char *prefix);

	/**
	 * ���marker
	 * @param listing [in] ��ʶһ��oss_object_listing_t�ṹָ��
	 * @return marker
	 * @retval const char *
	 */
	const char * (*get_marker)(oss_object_listing_t *listing);

	/**
	 * ����marker
	 * @param listing [in] ��ʶһ��oss_object_listing_t�ṹָ��
	 * @param marker [in] marker
	 * @retval void
	 */
	void (*set_marker)(oss_object_listing_t *listing, const char *marker);

	/**
	 * ���max_keys
	 * @param listing [in] ��ʶһ��oss_object_listing_t�ṹָ��
	 * @return max_keys
	 * @retval int
	 */
	int (*get_max_keys)(oss_object_listing_t *listing);

	/**
	 * ����max_keys
	 * @param listing [in] ��ʶһ��oss_object_listing_t�ṹָ��
	 * @param max_keys [in] max_keys
	 * @retval void
	 */
	void (*set_max_keys)(oss_object_listing_t *listing, int max_keys);

	/**
	 * ��÷ָ���
	 * @param listing [in] ��ʶһ��oss_object_listing_t�ṹָ��
	 * @return �ָ���
	 * @retval const char *
	 */
	const char * (*get_delimiter)(oss_object_listing_t *listing);

	/**
	 * ���÷ָ���
	 * @param listing [in] ��ʶһ��oss_object_listing_t�ṹָ��
	 * @param delimiter [in] �ָ���
	 * @retval void
	 */
	void (*set_delimiter)(oss_object_listing_t *listing, const char *delimiter);

	/**
	 * ���is_truncated
	 * @param listing [in] ��ʶһ��oss_object_listing_t�ṹָ��
	 * @return is_truncated
	 * @retval bool
	 */
	bool (*get_is_truncated)(oss_object_listing_t *listing);

	/**
	 * ����is_truncated
	 * @param listing [in] ��ʶһ��oss_object_listing_t�ṹָ��
	 * @param is_truncated [in] is_truncated
	 * @retval void
	 */
	void (*set_is_truncated)(oss_object_listing_t *listing, bool is_truncated);

	/**
	 * ���common_prefixes
	 * @param listing [in] ��ʶһ��oss_object_listing_t�ṹָ��
	 * @param counts [out] common_prefixes����Ŀ
	 * @return common_prefixes
	 * @retval const char **
	 */
	const char ** (*get_common_prefixes)(oss_object_listing_t *listing,
			unsigned int *counts);

	/**
	 * ����common_prefixes
	 * @param listing [in] ��ʶһ��oss_object_listing_t�ṹָ��
	 * @param common_prefixes [in] common_prefixes
	 * @param counts [in] common_prefixes����Ŀ
	 * @retval void
	 */
	void (*set_common_prefixes)(oss_object_listing_t *listing,
			const char **common_prefixes,
			unsigned int counts);

	/**
	 * ������е�Object��Ϣ
	 * @param listing [in] ��ʶһ��oss_object_listing_t�ṹָ��
	 * @param counts [out] ���е�Object��Ϣ����Ŀ
	 * @return ����һ��oss_object_summary_t�ṹָ��
	 * @retval �ǿ� ��ʾ�ɹ�
	 * @retval NULL ��ʾʧ��
	 */
	oss_object_summary_t ** (*get_summaries)(oss_object_listing_t *listing,
			unsigned int *counts);
};

/**
 * oss_object_listing_t���캯��
 * @return ����һ��oss_object_listing_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_object_listing_t *
object_listing_initialize(void);

/**
 * oss_object_listing_t��������
 * @param listing [in] ��ʶһ��oss_object_listing_t�ṹָ��
 * @retval void
 * @pre listing ����ʹ��object_listing_initialize�ķ���ֵ
 */
extern void 
object_listing_finalize(oss_object_listing_t *listing);
/**@}*/
#endif

/*
 * =============================================================================
 *
 *       Filename:  oss_multipart_upload_listing.h
 *
 *    Description:  oss_multipart_upload_listing.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_MULTIPART_UPLOAD_LISTING_H
# error Never include <oss_multipart_upload_listing.h> directly, use <client.h> instead.
#endif

#ifndef OSS_MULTIPART_UPLOAD_LISTING_H
#define OSS_MULTIPART_UPLOAD_LISTING_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define _OSS_MULTIPART_UPLOAD_H
#include <oss_multipart_upload.h>
#undef _OSS_MULTIPART_UPLOAD_H
#include <ossc-config.h>

#ifdef HAVE_STDBOOL_H
#include <stdbool.h>
#endif
/**
 * @defgroup oss_multipart_upload_listing_t oss_multipart_upload_listing_t
 * @{
 */

/**
 * struct oss_multipart_upload_listing_s �ڲ�ʹ�� \n
 * oss_multipart_upload_listing_t ������ʹ��
 */
typedef struct oss_multipart_upload_listing_s oss_multipart_upload_listing_t;

/**
 * ����Multipart�ϴ��¼����б�
 */
struct oss_multipart_upload_listing_s {
	char *bucket_name;               /**< Bucket���� */
	char **common_prefixs;           /**< ����ָ����ǰ׺�ҵ�һ�γ��� delimiter �ַ�֮���object */
	unsigned int _counts_common_prefixs; /**< common_prefixs�ĸ��� */
	
	char *key_marker;             /**< ��ʶ��ʾ�����ﷵ���б� */
	char *upload_id_marker;       /**< ��ʶ��ʾ�����ﷵ���б� */
	char *next_key_marker;        /**< ��ʶ�����б�������ֹ */
	char *next_upload_id_marker;  /**< ��ʶ�����б�������ֹ */
	char *max_uploads;            /**< ���� Multipart Uploads �¼��������Ŀ */

	oss_multipart_upload_t **multipart_uploads;    /**< ����multipart upload ����Ϣ */
	unsigned int _counts_multipart_uploads;        /**< multipart upload �ĸ���*/
	
	bool is_truncated;            /**< ��ʶ�Ƿ�������multipart upload */
	char *delimiter;              /**< �ָ���*/
	char *prefix;                 /**< ǰ׺ */

	/**
	 * ���Bucket����
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @return Bucket����
	 * @retval const char *
	 */
	const char * (*get_bucket_name)(oss_multipart_upload_listing_t *listing);

	/**
	 * ����Bucket����
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @param bucket_name [in] Bucket����
	 * @retval void
	 */
	void (*set_bucket_name)(oss_multipart_upload_listing_t *listing, const char *bucket_name);

	/**
	 * ���key_marker
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @return key_marker
	 * @retval const char *
	 */
	const char * (*get_key_marker)(oss_multipart_upload_listing_t *listing);

	/**
	 * ����key_marker
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @param key_marker [in] ��ʶ��ʾ�����ﷵ���б�
	 * @retval void
	 */
	void (*set_key_marker)(oss_multipart_upload_listing_t *listing, const char *key_marker);

	/**
	 * ���upload_id_marker
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @return upload_id_marker
	 * @retval const char *
	 */
	const char * (*get_upload_id_marker)(oss_multipart_upload_listing_t *listing);

	/**
	 * ����upload_id_marker
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @param upload_id_marker [in] ��ʶ��ʾ�����ﷵ���б�
	 * @retval void
	 */
	void (*set_upload_id_marker)(oss_multipart_upload_listing_t *listing, const char *upload_id_marker);

	/**
	 * ���next_key_marker
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @return next_key_marker
	 * @retval const char *
	 */
	const char * (*get_next_key_marker)(oss_multipart_upload_listing_t *listing);

	/**
	 * ����next_key_marker
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @param next_key_marker [in] ��ʶ�����б�������ֹ
	 * @retval void
	 */
	void (*set_next_key_marker)(oss_multipart_upload_listing_t *listing, const char *next_key_marker);

	/**
	 * ���next_upload_id_marker
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @return next_upload_id_marker
	 * @retval const char *
	 */
	const char * (*get_next_upload_id_marker)(oss_multipart_upload_listing_t *listing);

	/**
	 * ����next_upload_id_marker
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @param next_upload_id_marker [in] ��ʶ�����б�������ֹ
	 * @retval void
	 */
	void (*set_next_upload_id_marker)(oss_multipart_upload_listing_t *listing, const char *next_upload_id_marker);

	/**
	 * ���max_uploads
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @return Multipart Uploads �¼��������Ŀ
	 * @retval const char *
	 */
	const char * (*get_max_uploads)(oss_multipart_upload_listing_t *listing);

	/**
	 * ����max_uploads
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @param max_uploads [in] Multipart Uploads �¼��������Ŀ
	 * @retval void
	 */
	void (*set_max_uploads)(oss_multipart_upload_listing_t *listing, const char *max_uploads);

	/**
	 * ���is_truncated
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @return is_truncated
	 * @retval bool
	 */
	bool (*get_is_truncated)(oss_multipart_upload_listing_t *listing);

	/**
	 * ����is_truncated
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @param is_truncated [in] ��ʶ�Ƿ�������multipart upload
	 * @retval void
	 */
	void (*set_is_truncated)(oss_multipart_upload_listing_t *listing, bool is_truncated);

	/**
	 * ��ø���multipart upload ����Ϣ
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @param counts [out] ����multipart upload ����Ϣ����Ŀ
	 * @return ����һ��oss_multipart_upload_t�ṹָ��
	 * @retval �ǿ� ��ʶ�ɹ�
	 * @retval NULL ��ʶʧ��
	 */
	oss_multipart_upload_t ** (*get_multipart_uploads)(oss_multipart_upload_listing_t *listing,
			unsigned int *counts);

	/**
	 * ���ø���multipart upload ����Ϣ
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @param multipart_uploads [in] ����multipart upload ����Ϣ
	 * @param counts [in] ����multipart upload ����Ϣ����Ŀ
	 * @retval void
	 */
	void (*set_multipart_uploads)(oss_multipart_upload_listing_t *listing,
			oss_multipart_upload_t **multipart_uploads,
			unsigned int counts);

	/**
	 * ���common_prefixs
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @param counts [out] common_prefixs�ĸ���
	 * @return const char **
	 */
	const char ** (*get_common_prefixs)(oss_multipart_upload_listing_t *listing,
			unsigned int *counts);

	/**
	 * ����common_prefixs
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @param common_prefixs [in] common_prefixs
	 * @param counts [in] common_prefixs�ĸ���
	 * @retval void
	 */
	void (*set_common_prefixs)(oss_multipart_upload_listing_t *listing,
			const char **common_prefixs,
			unsigned int counts);

	/**
	 * ��÷ָ���
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @return �ָ���
	 * @return const char *
	 */
	const char * (*get_delimiter)(oss_multipart_upload_listing_t *listing);

	/**
	 * ���÷ָ���
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @param delimiter [in] �ָ���
	 * @retval void
	 */
	void (*set_delimiter)(oss_multipart_upload_listing_t *listing, const char *delimiter);

	/**
	 * ���ǰ׺
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @return ǰ׺
	 * @return const char *
	 */
	const char * (*get_prefix)(oss_multipart_upload_listing_t *listing);

	/**
	 * ����ǰ׺
	 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
	 * @param prefix [in] ǰ׺
	 * @retval void
	 */
	void (*set_prefix)(oss_multipart_upload_listing_t *listing, const char *prefix);
};

/**
 * oss_multipart_upload_listing_t���캯��
 * @return ����һ��oss_multipart_upload_listing_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_multipart_upload_listing_t *
multipart_upload_listing_initialize(void);

/**
 * oss_multipart_upload_listing_t��������
 * @param listing [in] ��ʶһ��oss_multipart_upload_listing_t�ṹָ��
 * @retval void
 * @pre listing ����ʹ��multipart_upload_listing_initialize�ķ���ֵ
 */
extern void 
multipart_upload_listing_finalize(oss_multipart_upload_listing_t *listing);
/**@}*/
#endif

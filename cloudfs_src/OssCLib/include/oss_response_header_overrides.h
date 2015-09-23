/*
 * =============================================================================
 *
 *       Filename:  oss_response_header_overrides.h
 *
 *    Description:  oss_response_header_overrides.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
//#ifndef _OSS_RESPONSE_HEADER_OVERRIDES_H
//# error Never include <oss_response_header_overrides.h> directly, use <client.h> instead.
//#endif

#ifndef OSS_RESPONSE_HEADER_OVERRIDES_H
#define OSS_RESPONSE_HEADER_OVERRIDES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define _OSS_CONSTANTS_H
#include "oss_constants.h"
#undef _OSS_CONSTANTS_H

/**
 * @defgroup oss_response_header_overrides_t oss_response_header_overrides_t
 * @{
 */

/**
 * struct oss_response_header_overrides_s �ڲ�ʹ�� \n
 * oss_response_header_overrides_t ������ʹ��
 */
typedef struct oss_response_header_overrides_s oss_response_header_overrides_t;

/**
 * oss_response_header_overrides_t �������ڷ���OSS GET����ʱ�������صķ�������ͷ
 */
struct oss_response_header_overrides_s {
	char *cache_control;  /**< ���ص�cacheControl��������ͷ*/
	char *content_disposition;  /**< ���ص�contentDisposition��������ͷ*/
	char *content_encoding;  /**< ���ص�contentEncoding��������ͷ*/
	char *content_language; /**< ���ص�content language��������ͷ*/
	char *content_type;  /**< ���ص�content type��������ͷ*/
	char * expires; /**< ���ص�expires��������ͷ*/

	/**
	 * ������ص�cacheControl��������ͷ
	 * @param overrides [in] ��ʶһ��oss_response_header_overrides_t�ṹָ��
	 * @return ���ص�cacheControl��������ͷ
	 * @retval const char *
	 */
	const char * (*get_cache_control)(oss_response_header_overrides_t *overrides);

	/**
	 * �������ص�cacheControl��������ͷ
	 * @param overrides [in] ��ʶһ��oss_response_header_overrides_t�ṹָ��
	 * @param cache_control [in] ���ص�cacheControl��������ͷ
	 * @retval void
	 */
	void (*set_cache_control)(oss_response_header_overrides_t *overrides,
			const char *cache_control);

	/**
	 * ������ص�contentDisposition��������ͷ
	 * @param overrides [in] ��ʶһ��oss_response_header_overrides_t�ṹָ��
	 * @return �������ص�contentDisposition��������ͷ
	 * @retval const char *
	 */
	const char * (*get_content_disposition)(oss_response_header_overrides_t *overrides);

	/**
	 * �������ص�contentDisposition��������ͷ
	 * @param overrides [in] ��ʶһ��oss_response_header_overrides_t�ṹָ��
	 * @param content_disposition [in] ���ص�contentDisposition��������ͷ
	 * @retval void
	 */
	void (*set_content_disposition)(oss_response_header_overrides_t *overrides,
			const char *content_disposition);

	/**
	 * ������ص�contentEncoding��������ͷ
	 * @param overrides [in] ��ʶһ��oss_response_header_overrides_t�ṹָ��
	 * @return ���ص�contentEncoding��������ͷ
	 * @retval const char *
	 */
	const char * (*get_content_encoding)(oss_response_header_overrides_t *overrides);

	/**
	 * �������ص�contentEncoding��������ͷ
	 * @param overrides [in] ��ʶһ��oss_response_header_overrides_t�ṹָ��
	 * @param content_encoding [in] ���ص�contentEncoding��������ͷ
	 * @retval void
	 */
	void (*set_content_encoding)(oss_response_header_overrides_t *overrides,
			const char *content_encoding);

	/**
	 * ������ص�content language��������ͷ
	 * @param overrides [in] ��ʶһ��oss_response_header_overrides_t�ṹָ��
	 * @return �������ص�content language��������ͷ
	 * @retval const char *
	 */
	const char * (*get_content_language)(oss_response_header_overrides_t *overrides);

	/**
	 * �������ص�content language��������ͷ
	 * @param overrides [in] ��ʶһ��oss_response_header_overrides_t�ṹָ��
	 * @param content_language [in] ���ص�content language��������ͷ
	 * @retval void
	 */
	void (*set_content_language)(oss_response_header_overrides_t *overrides,
			const char *content_language);

	/**
	 * ������ص�content type��������ͷ
	 * @param overrides [in] ��ʶһ��oss_response_header_overrides_t�ṹָ��
	 * @return ���ص�content type��������ͷ
	 * @retval const char *
	 */
	const char * (*get_content_type)(oss_response_header_overrides_t *overrides);

	/**
	 * �������ص�content type��������ͷ
	 * @param overrides [in] ��ʶһ��oss_response_header_overrides_t�ṹָ��
	 * @param content_type [in] ���ص�content type��������ͷ
	 * @retval void
	 */
	void (*set_content_type)(oss_response_header_overrides_t *overrides,
			const char *content_type);

	/**
	 * ������ص�expires��������ͷ
	 * @param overrides [in] ��ʶһ��oss_response_header_overrides_t�ṹָ��
	 * @return ���ص�expires��������ͷ
	 * retval const char *
	 */
	const char * (*get_expires)(oss_response_header_overrides_t *overrides);

	/**
	 * �������ص�expires��������ͷ
	 * @param overrides [in] ��ʶһ��oss_response_header_overrides_t�ṹָ��
	 * @param expires  [in] �������ص�expires��������ͷ
	 * @retval void
	 */
	void (*set_expires)(oss_response_header_overrides_t *overrides,
			const char *expires);
};

/**
 * oss_response_header_overrides_t ���캯��
 * @return ����һ��oss_response_header_overrides_t �ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_response_header_overrides_t *
response_header_overrides_initialize(void);

/**
 * oss_response_header_overrides_t ��������
 * @param overrides [in] ��ʶһ��oss_response_header_overrides_t�ṹָ��
 * @retval void
 * @pre overrides ����ʹ��response_header_overrides_initialize�ķ���ֵ
 */
extern void 
response_header_overrides_finalize(oss_response_header_overrides_t *overrides);

/**@}*/
#endif

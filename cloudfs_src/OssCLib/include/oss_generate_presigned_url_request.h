/*
 * =============================================================================
 *
 *       Filename:  oss_generate_presigned_url_request.h
 *
 *    Description:  oss_generate_presigned_url_request.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_GENERATE_PRESIGNED_URL_REQUEST_H
# error Never include <oss_generate_presigned_url_request.h> directly, use <client.h> instead.
#endif

#ifndef OSS_GENERATE_PRESIGNED_URL_REQUEST_H
#define OSS_GENERATE_PRESIGNED_URL_REQUEST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define _OSS_RESPONSE_HEADER_OVERRIDES_H
#include "oss_response_header_overrides.h"
#undef _OSS_RESPONSE_HEADER_OVERRIDES_H

#include <oss_map.h>

/**
 * @defgroup oss_generate_presigned_url_request_t oss_generate_presigned_url_request_t
 * @{
 */

/**
 * struct oss_generate_presigned_url_request_s �ڲ�ʹ�� \n
 * oss_generate_presigned_url_request_t ������ʹ��
 */
typedef struct oss_generate_presigned_url_request_s oss_generate_presigned_url_request_t;

/**
 * ���ɴ���ǩ����Ϣ��URL������
 */
struct oss_generate_presigned_url_request_s {
	char *bucket_name;      /**< Bucket���� */
	char *expiration;       /**< ����ʱ�� */
	char *key;              /**< Object���� */
	char *method;           /**< HTTP���� */
	oss_response_header_overrides_t *response_headers;   /**< Ҫ���صķ�������ͷ */
	oss_map_t *user_metadata;      /**< �û��Զ����Ԫ���� */

	/**
	 * �����û��Զ����Ԫ����
	 * @param request [in] ��ʶһ��oss_generate_presigned_url_request_t�ṹָ��
	 * @param key [in] Ԫ���ݵ�key
	 * @param value [in] Ԫ���ݵ�value
	 * @retval void
	 */
	void (*add_user_metadata)(oss_generate_presigned_url_request_t *request,
			const char *key, const char *value);

	/**
	 * ���Bucket����
	 * @param request [in] ��ʶһ��oss_generate_presigned_url_request_t�ṹָ��
	 * @return Bucket����
	 * @retval const char *
	 */
	const char * (*get_bucket_name)(oss_generate_presigned_url_request_t *request);

	/**
	 * ����Bucket����
	 * @param request [in] ��ʶһ��oss_generate_presigned_url_request_t�ṹָ��
	 * @param bucket_name [in] Bucket����
	 * @retval void
	 */
	void (*set_bucket_name)(oss_generate_presigned_url_request_t *request, const char *bucket_name);
	
	/**
	 * ��ù���ʱ��
	 * @param request [in] ��ʶһ��oss_generate_presigned_url_request_t�ṹָ��
	 * @return ����ʱ��
	 * @retval const char *
	 */
	const char * (*get_expiration)(oss_generate_presigned_url_request_t *request);

	/**
	 * ���ù���ʱ��
	 * @param request [in] ��ʶһ��oss_generate_presigned_url_request_t�ṹָ��
	 * @param expiration [in] ����ʱ��
	 * @retval void
	 */
	void (*set_expiration)(oss_generate_presigned_url_request_t *request, const char *expiration);

	/**
	 * ���Object����
	 * @param request [in] ��ʶһ��oss_generate_presigned_url_request_t�ṹָ��
	 * @return Object����
	 * @retval const char *
	 */
	const char * (*get_key)(oss_generate_presigned_url_request_t *request);

	/**
	 * ����Object����
	 * @param request [in] ��ʶһ��oss_generate_presigned_url_request_t�ṹָ��
	 * @param key [in] Object����
	 * @retval void
	 */
	void (*set_key)(oss_generate_presigned_url_request_t *request, const char *key);

	/**
	 * ���HTTP����
	 * @param request [in] ��ʶһ��oss_generate_presigned_url_request_t�ṹָ��
	 * @return HTTP����
	 * @retval const char *
	 */
	const char * (*get_method)(oss_generate_presigned_url_request_t *request);

	/**
	 * ����HTTP����
	 * @param request [in] ��ʶһ��oss_generate_presigned_url_request_t�ṹָ��
	 * @param method [in] HTTP����
	 * @retval void
	 */
	void (*set_method)(oss_generate_presigned_url_request_t *request, const char *method);

	/**
	 * ���Ҫ���صķ�������ͷ
	 * @param request [in] ��ʶһ��oss_generate_presigned_url_request_t�ṹָ��
	 * @return Ҫ���صķ�������ͷ
	 * @retval �ǿ� ��ʾ�ɹ�
	 * @retval NULL ��ʾʧ��
	 */
	oss_response_header_overrides_t * (*get_response_headers)(oss_generate_presigned_url_request_t *request);

	/**
	 * ����Ҫ���صķ�������ͷ
	 * @param request [in] ��ʶһ��oss_generate_presigned_url_request_t�ṹָ��
	 * @param response_headers [in] Ҫ���صķ�������ͷ
	 * @retval void
	 */
	void (*set_response_headers)(oss_generate_presigned_url_request_t *request, oss_response_header_overrides_t *response_headers);

	/**
	 * ����û��Զ����Ԫ����
	 * @param request [in] ��ʶһ��oss_generate_presigned_url_request_t�ṹָ��
	 * @return �û��Զ����Ԫ����
	 * @retval �ǿ� ��ʾ�ɹ�
	 * @retval NULL ��ʾʧ��
	 */
	oss_map_t * (*get_user_metadata)(oss_generate_presigned_url_request_t *request);

	/**
	 * �����û��Զ����Ԫ����
	 * @param request [in] ��ʶһ��oss_generate_presigned_url_request_t�ṹָ��
	 * @param user_metadata [in] �û��Զ����Ԫ����
	 * @retval void
	 */
	void (*set_user_metadata)(oss_generate_presigned_url_request_t *request,
			oss_map_t *user_metadata);


};

/**
 * oss_generate_presigned_url_request_t ���캯��
 * @param bucket_name [in] Bucket����
 * @param key [in] Object����
 * @return ����һ��oss_generate_presigned_url_request_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_generate_presigned_url_request_t *
generate_presigned_url_request_initialize(const char *bucket_name, const char *key);

/**
 * oss_generate_presigned_url_request_t��http�����Ĺ��캯��
 * @param bucket_name [in] Bucket����
 * @param key [in] Object����
 * @param method [in] http����
 * @return ����һ��oss_generate_presigned_url_request_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_generate_presigned_url_request_t *
generate_presigned_url_request_initialize_with_method(const char *bucket_name, const char *key, const char *method);

/**
 * oss_generate_presigned_url_request_t��������
 * @param request [in] ��ʶһ��oss_generate_presigned_url_request_t�ṹָ��
 * @retval void
 * @pre request ����ʹ��delete_multiple_object_request_initialize�ķ���ֵ
 */
extern void 
generate_presigned_url_request_finalize(oss_generate_presigned_url_request_t *request);

/**@}*/
#endif

/*
 * =============================================================================
 *
 *       Filename:  oss_get_object_request.h
 *
 *    Description:  oss_get_object_request.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_GET_OBJECT_REQUEST_H
# error Never include <oss_get_object_request.h> directly, use <client.h> instead.
#endif

#ifndef OSS_GET_OBJECT_REQUEST_H
#define OSS_GET_OBJECT_REQUEST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define _OSS_RESPONSE_HEADER_OVERRIDES_H
#include <oss_response_header_overrides.h>
#undef _OSS_RESPONSE_HEADER_OVERRIDES_H

/**
 * @defgroup oss_get_object_request_t oss_get_object_request_t
 * @{
 */

/**
 * struct oss_get_object_request_s �ڲ�ʹ�� \n
 * oss_get_object_request_t ������ʹ��
 */
typedef struct oss_get_object_request_s oss_get_object_request_t;

/**
 * ָ����OSS����Object���������
 */
struct oss_get_object_request_s {
	char *bucket_name;                   /**< Bucket���� */
	char *key;                           /**< Object���� */
	char *modified_since_constraint;     /**< һ��ʱ�䣬���ԴObject�ԴӸ�ʱ���Ժ��޸Ĺ�����ִ�п��������� �����׳��쳣 */
	long start;                         /**< Object���ݵ���ʼλ�� */
	long length;                        /**< Object���ݵĳ��� */
	oss_response_header_overrides_t *response_headers;  /**< Ҫ���صķ�������ͷ */
	char *unmodified_since_constraint;    /**< һ��ʱ�䣬�����ʱ����ڻ��������ļ�ʵ���޸�ʱ�䣬�����������ļ��� �����׳��쳣 */
	char **matching_etag_constraints;     /**< ETag�޶�ֵ���б� */
	char **no_matching_etag_constraints;  /**< �޶�Object��ETag�޶����벻ƥ�����ֵ���б� */

	unsigned int _counts_matching_etag_constraints;  /**< ETag�޶�ֵ���б�ĸ��� */
	unsigned int _counts_no_matching_etag_constraints; /**< �޶�Object��ETag�޶����벻ƥ�����ֵ���б�ĸ��� */

	/**
	 * ���Bucket����
	 * @param request [in] ��ʶһ��oss_get_object_request_t�ṹָ��
	 * @return Bucket����
	 * @retval const char *
	 */
	const char * (*get_bucket_name)(oss_get_object_request_t *request);

	/**
	 * ����Bucket����
	 * @param request [in] ��ʶһ��oss_get_object_request_t�ṹָ��
	 * @param bucket_name [in] Bucket����
	 * @retval void
	 */
	void (*set_bucket_name)(oss_get_object_request_t *request, const char *bucket_name);

	/**
	 * ���Object����
	 * @param request [in] ��ʶһ��oss_get_object_request_t�ṹָ��
	 * @return Object����
	 * @retval const char *
	 */
	const char * (*get_key)(oss_get_object_request_t *request);

	/**
	 * ����Object����
	 * @param request [in] ��ʶһ��oss_get_object_request_t�ṹָ��
	 * @param key [in] Object����
	 * @retval void
	 */
	void (*set_key)(oss_get_object_request_t *request, const char *key);

	/**
	 * ���modified_since_constraintʱ��
	 * @param request [in] ��ʶһ��oss_get_object_request_t�ṹָ��
	 * @return modified_since_constraintʱ��
	 * @retval const char *
	 */
	const char * (*get_modified_since_constraint)(oss_get_object_request_t *request);

	/**
	 * ����modified_since_constraintʱ��
	 * @param request [in] ��ʶһ��oss_get_object_request_t�ṹָ��
	 * @param modified_since_constraint [in] modified_since_constraintʱ��
	 * @retval void
	 */
	void (*set_modified_since_constraint)(oss_get_object_request_t *request, const char *modified_since_constraint);

	/**
	 * ���Object���ݵ�start��length
	 * @param request [in] ��ʶһ��oss_get_object_request_t�ṹָ��
	 * @param start [out] Object���ݵ���ʼλ��
	 * @param length [out] Object���ݵĳ���
	 * @retval void
	 */
	void (*get_range)(oss_get_object_request_t *request, long *start, long *length);

	/**
	 * ����Object���ݵ�start��length
	 * @param request [in] ��ʶһ��oss_get_object_request_t�ṹָ��
	 * @param start [in] Object���ݵ���ʼλ��
	 * @param length [in] Object���ݵĳ���
	 * @retval void
	 */
	void (*set_range)(oss_get_object_request_t *request, long start, long length);

	/**
	 * ���Ҫ���صķ�������ͷ
	 * @param request [in] ��ʶһ��oss_get_object_request_t�ṹָ��
	 * @return Ҫ���صķ�������ͷ
	 * @retval �ǿ� ��ʾ�ɹ�
	 * @retval NULL ��ʾʧ��
	 */
	oss_response_header_overrides_t * (*get_response_headers)(oss_get_object_request_t *request);

	/**
	 * ����Ҫ���صķ�������ͷ
	 * @param request [in] ��ʶһ��oss_get_object_request_t�ṹָ��
	 * @param response_headers [in] Ҫ���صķ�������ͷ
	 * @retval void
	 */
	void (*set_response_headers)(oss_get_object_request_t *request, oss_response_header_overrides_t *response_headers);

	/**
	 * ���unmodified_since_constraintʱ��
	 * @param request [in] ��ʶһ��oss_get_object_request_t�ṹָ��
	 * @return unmodified_since_constraintʱ��
	 * @retval const char *
	 */
	const char * (*get_unmodified_since_constraint)(oss_get_object_request_t *request);

	/**
	 * ����unmodified_since_constraintʱ��
	 * @param request [in] ��ʶһ��oss_get_object_request_t�ṹָ��
	 * @param unmodified_since_constraint[in] unmodified_since_constraintʱ��
	 * @retval void
	 */
	void (*set_unmodified_since_constraint)(oss_get_object_request_t *request, const char *unmodified_since_constraint);

	/**
	 * ���ETag�޶�ֵ���б�
	 * @param request [in] ��ʶһ��oss_get_object_request_t�ṹָ��
	 * @param counts [out] ETag�޶�ֵ���б�ĸ���
	 * @return ETag�޶�ֵ���б�
	 * @retval const char **
	 */
	const char ** (*get_matching_etag_constraints)(oss_get_object_request_t *object,
			unsigned int *counts);

	/**
	 * ����ETag�޶�ֵ���б�
	 * @param request [in] ��ʶһ��oss_get_object_request_t�ṹָ��
	 * @param matching_etag_constraints [in] ����ETag�޶�ֵ���б�
	 * @param counts [in] ETag�޶�ֵ���б�ĸ���
	 * @retval void
	 */
	void (*set_matching_etag_constraints)(oss_get_object_request_t *object,
			const char **matching_etag_constraints, unsigned int counts);

	/**
	 * ����޶�Object��ETag�޶����벻ƥ�����ֵ���б�
	 * @param request [in] ��ʶһ��oss_get_object_request_t�ṹָ��
	 * @param counts [out] �޶�Object��ETag�޶����벻ƥ�����ֵ���б�ĸ���
	 * @return �޶�Object��ETag�޶����벻ƥ�����ֵ���б�
	 * @retval const char **
	 */
	const char ** (*get_no_matching_etag_constraints)(oss_get_object_request_t *object,
			unsigned int *counts);

	/**
	 * �����޶�Object��ETag�޶����벻ƥ�����ֵ���б�
	 * @param request [in] ��ʶһ��oss_get_object_request_t�ṹָ��
	 * @param no_matching_etag_constraints [in] �޶�Object��ETag�޶����벻ƥ�����ֵ���б�
	 * @param counts [in] �޶�Object��ETag�޶����벻ƥ�����ֵ���б�ĸ���
	 * @retval void
	 */
	void (*set_no_matching_etag_constraints)(oss_get_object_request_t *object,
			const char **no_matching_etag_constraints, unsigned counts);
};

/**
 * oss_get_object_request_t���캯��
 * @param bucket_name [in] Bucket����
 * @param key [in] Object����
 * @return ����oss_get_object_request_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_get_object_request_t *
get_object_request_initialize(const char *bucket_name, const char *key);

/**
 * oss_get_object_request_t��������
 * @param request [in] ��ʶһ��oss_get_object_request_t�ṹָ��
 * @retval void
 * @pre request ����ʹ��get_object_request_initialize�ķ���ֵ
 */
extern void 
get_object_request_finalize(oss_get_object_request_t *request);
/**@}*/
#endif

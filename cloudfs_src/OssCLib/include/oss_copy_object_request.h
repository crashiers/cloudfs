/*
 * =============================================================================
 *
 *       Filename:  oss_copy_object_request.h
 *
 *    Description:  oss copy object request.
 *
 *        Created:  09/07/2012 03:22:02 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _OSS_COPY_OBJECT_REQUEST_H
# error Never include <oss_copy_object_result.h> directly, use <client.h> instead.
#endif

#ifndef OSS_COPY_OBJECT_REQUEST_H
#define OSS_COPY_OBJECT_REQUEST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define _OSS_OBJECT_METADATA_H
#include <oss_object_metadata.h>
#undef _OSS_OBJECT_METADATA_H

/**
 * @defgroup oss_copy_object_request_t oss_copy_object_request_t
 * @{
 */
/**
 * struct oss_copy_object_request_s �ڲ�ʹ�� \n
 * oss_copy_object_request_t ������ʹ��
 */
typedef struct oss_copy_object_request_s oss_copy_object_request_t;

/**
 * ����һ����OSS���Ѿ����ڵ�Object������һ��Object���������
 */
struct oss_copy_object_request_s {
	char *destination_bucket_name;    /**< Ŀ��Bucket������ */
	char *destination_key;            /**< Ŀ��Object������ */
	char **matching_etag_constraints; /**< ETag�޶�ֵ���б� */
	char *modified_since_constraints; /**< һ��ʱ�䣬���ԴObject�ԴӸ�ʱ���Ժ��޸Ĺ�����ִ�п��������� �����׳��쳣 */
	oss_object_metadata_t *object_metadata; /**< Ŀ��Object��ObjectMetadata��Ϣ */
	char **no_matching_etag_constraints; /**< �޶�Object��ETag�޶����벻ƥ�����ֵ���б� */
	char *source_bucket_name; /**< ԴBucket������ */
	char *source_key;         /**< ԴObject������ */
	char *unmodified_since_constraints;   /**< һ��ʱ�䣬�����ʱ����ڻ��������ļ�ʵ���޸�ʱ�䣬�����������ļ��� �����׳��쳣 */

	unsigned int _counts_matching_etag_constraints;  	 /**< ETag�޶�ֵ���б�ĸ��� */
	unsigned int _counts_no_matching_etag_constraints;   /**< �޶�Object��ETag�޶����벻ƥ�����ֵ���б�ĸ��� */

	/**
	 * ���Ŀ��Bucket������
	 * @param request ��ʶһ��oss_copy_object_request_t�Ľṹָ��
	 * @return Ŀ��Bucket������
	 * @retval const char *
	 */
	const char * (*get_destination_bucket_name)(oss_copy_object_request_t *request);

	/**
	 * ���Ŀ��Object������
	 * @param request [in] ��ʶһ��oss_copy_object_request_t�Ľṹָ��
	 * @return Ŀ��Object������
	 * @retval const char *
	 */
	const char * (*get_destination_key)(oss_copy_object_request_t *request);

	/**
	 * ���ETag�޶�ֵ���б�
	 * @param request [in] ��ʶһ��oss_copy_object_request_t�Ľṹָ��
	 * @return ETag�޶�ֵ���б�
	 * @retval const char **
	 */
	const char ** (*get_matching_etag_constraints)(oss_copy_object_request_t *request,
			unsigned int *counts);

	/**
	 * ���modified_since_constraintsʱ��
	 * @param request [in] ��ʶһ��oss_copy_object_request_t�Ľṹָ��
	 * @return modified_since_constraintsʱ��
	 * @retval const char *
	 */
	const char * (*get_modified_since_constraints)(oss_copy_object_request_t *request);

	/**
	 * ���Ŀ��Object��ObjectMetadata��Ϣ
	 * @param request [in] ��ʶһ��oss_copy_object_request_t�Ľṹָ��
	 * @return Ŀ��Object��ObjectMetadata��Ϣ
	 * @retval ����һ��oss_object_metadata_t�Ľṹָ��
	 * @retval �ǿ� ��ʾ�ɹ�
	 * @retval NULL ��ʾʧ��
	 */
	oss_object_metadata_t * (*get_object_metadata)(oss_copy_object_request_t *request);

	/**
	 * ����޶�Object��ETag�޶����벻ƥ�����ֵ���б�
	 * @param request [in] ��ʶһ��oss_copy_object_request_t�Ľṹָ��
	 * @return �޶�Object��ETag�޶����벻ƥ�����ֵ���б�
	 * @retval const char **
	 */
	const char ** (*get_no_matching_etag_constraints)(oss_copy_object_request_t *request,
			unsigned int *counts);

	/**
	 * ���ԴBucket������
	 * @param request [in] ��ʶһ��oss_copy_object_request_t�Ľṹָ��
	 * @return ԴBucket������
	 * @retval const char *
	 */
	const char * (*get_source_bucket_name)(oss_copy_object_request_t *request);

	/**
	 * ���ԴObject������
	 * @param request [in] ��ʶһ��oss_copy_object_request_t�Ľṹָ��
	 * @return ԴObject������
	 * @retval const char *
	 */
	const char * (*get_source_key)(oss_copy_object_request_t *request);

	/**
	 * ���unmodified_since_constraintsʱ��
	 * @param request [in] ��ʶһ��oss_copy_object_request_t�Ľṹָ��
	 * @return unmodified_since_constraintsʱ��
	 * @retval const char *
	 */
	const char * (*get_unmodified_since_constraints)(oss_copy_object_request_t *request);


	/**
	 * ����Ŀ��Bucket������
	 * @param request [in] ��ʶһ��oss_copy_object_request_t�Ľṹָ��
	 * @param destination_bucket_name [in] Ŀ��Bucket������
	 * @retval void
	 */
	void (*set_destination_bucket_name)(oss_copy_object_request_t *request,
			const char * destination_bucket_name);

	/**
	 * ����Ŀ��Object������
	 * @param request [in] ��ʶһ��oss_copy_object_request_t�Ľṹָ��
	 * @param destination_key [in] Ŀ��Object������
	 * @retval void
	 */
	void (*set_destination_key)(oss_copy_object_request_t *request,
			const char *destination_key);

	/**
	 * ����ETag�޶�ֵ���б�
	 * @param request [in] ��ʶһ��oss_copy_object_request_t�Ľṹָ��
	 * @param matching_etag_constraints [in] ETag�޶�ֵ���б�
	 * @param counts [in] ETag�޶�ֵ���б�ĸ���
	 * @retval void
	 */
	void (*set_matching_etag_constraints)(oss_copy_object_request_t *request,
			const char **matching_etag_constraints, unsigned int counts);

	/**
	 * ����modified_since_constraintsʱ��
	 * @param request [in] ��ʶһ��oss_copy_object_request_t�Ľṹָ��
	 * @param modified_since_constraints [in] modified_since_constraintsʱ��
	 * @retval void
	 */
	void (*set_modified_since_constraints)(oss_copy_object_request_t *request,
			const char *modified_since_constraints);

	/**
	 * ����Ŀ��Object��ObjectMetadata��Ϣ
	 * @param request [in] ��ʶһ��oss_copy_object_request_t�Ľṹָ��
	 * @param object_metadata [in] Ŀ��Object��ObjectMetadata��Ϣ
	 * @retval void
	 */
	void (*set_new_object_metadata)(oss_copy_object_request_t *request,
			oss_object_metadata_t *object_metadata);

	/**
	 * �����޶�Object��ETag�޶����벻ƥ�����ֵ���б�
	 * @param request [in] ��ʶһ��oss_copy_object_request_t�Ľṹָ��
	 * @param no_matching_etag_constraints [in] �޶�Object��ETag�޶����벻ƥ�����ֵ���б�
	 * @param counts �޶�Object��ETag�޶����벻ƥ�����ֵ���б�ĸ���
	 * @retval void
	 */
	void (*set_no_matching_etag_constraints)(oss_copy_object_request_t *request,
			const char **no_matching_etag_constraints, unsigned counts);

	/**
	 * ����ԴBucket������
	 * @param request [in] ��ʶһ��oss_copy_object_request_t�Ľṹָ��
	 * @param source_bucket_name [in] ԴBucket������
	 * @retval void
	 */
	void (*set_source_bucket_name)(oss_copy_object_request_t *request,
			const char *source_bucket_name);

	/**
	 * ����ԴObject������
	 * @param request [in] ��ʶһ��oss_copy_object_request_t�Ľṹָ��
	 * @param source_key [in] ԴObject������
	 * @retval void
	 */
	void (*set_source_key)(oss_copy_object_request_t *request,
			const char *source_key);

	/**
	 * ����unmodified_since_constraintsʱ��
	 * @param request [in] ��ʶһ��oss_copy_object_request_t�Ľṹָ��
	 * @param unmodified_since_constraints [in] unmodified_since_constraintsʱ��
	 * @retval void
	 */
	void (*set_unmodified_since_constraints)(oss_copy_object_request_t *request,
			const char *unmodified_since_constraints);
};

/**
 * oss_copy_object_request_t ���캯��
 * @param source_bucket_name [in] ԴBucket������
 * @param source_key [in] ԴObject������
 * @param destination_bucket_name [in] Ŀ��Bucket������
 * @param destination_key [in] Ŀ��Object������
 * @return ����һ��oss_copy_object_request_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_copy_object_request_t *
copy_object_request_initialize(const char *source_bucket_name,
		const char *source_key,
		const char *destination_bucket_name,
		const char *destination_key);

/**
 * oss_copy_object_request_t ��������
 * @param request [in] ��ʶһ��oss_copy_object_request_t�Ľṹָ��
 * @retval void
 * @pre request ����ʹ��copy_object_request_initialize�ķ���ֵ
 */
extern void copy_object_request_finalize(oss_copy_object_request_t *request);
/**@}*/
#endif // OSS_COPY_OBJECT_REQUEST_H 


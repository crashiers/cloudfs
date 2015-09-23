/*
 * =============================================================================
 *
 *       Filename:  oss_complete_multipart_upload_request.h
 *
 *    Description:  oss_complete_multipart_upload_request.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_COMPLETE_MULTIPART_UPLOAD_REQUEST_H
# error Never include <oss_complete_multipart_upload_request.h> directly, use <client.h> instead.
#endif

#ifndef OSS_COMPLETE_MULTIPART_UPLOAD_REQUEST_H
#define OSS_COMPLETE_MULTIPART_UPLOAD_REQUEST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define _OSS_PART_ETAG_H
#include <oss_part_etag.h>
#undef _OSS_PART_ETAG_H
/**
 * @defgroup oss_complete_multipart_upload_request_t oss_complete_multipart_upload_request_t
 * @{
 */

/**
 * struct oss_complete_multipart_upload_request_s �ڲ�ʹ�� \n
 * oss_complete_multipart_upload_request_t ������ʹ��
 */
typedef struct oss_complete_multipart_upload_request_s oss_complete_multipart_upload_request_t;

/**
 * �������һ��Multipart�ϴ��¼����������
 */
struct oss_complete_multipart_upload_request_s {
	char *bucket_name;      /**< Bucket ���� */
	char *key;              /**< Object ���� */
	oss_part_etag_t **part_etags;     /**< ��ʶ�ϴ�Part�����PartETag�б� */
	char *upload_id;         /** ��ʶMultipart�ϴ��¼���Upload ID */
	int part_etags_number;    /** part_etags* �ĸ��� */

	/**
	 * ���Bucket������
	 * @param [in] request ��ʶһ��oss_complete_multipart_upload_request_t�Ľṹָ��
	 * @return Bucket������
	 * @retval const char *
	 */
	const char * (*get_bucket_name)(oss_complete_multipart_upload_request_t *request);

	/**
	 * ����Bucket������
	 * @param request [in] ��ʶһ��oss_complete_multipart_upload_request_t�Ľṹָ��
	 * @param bucket_name [in] Bucket������
	 * @retval void
	 */
	void (*set_bucket_name)(oss_complete_multipart_upload_request_t *request, const char *bucket_name);

	/**
	 * ���Object������
	 * @param request [in] ��ʶһ��oss_complete_multipart_upload_request_t�Ľṹָ��
	 * @return Object������
	 * @retval const char *
	 */
	const char * (*get_key)(oss_complete_multipart_upload_request_t *request);

	/**
	 * ����Object������
	 * @param request [in] ��ʶһ��oss_complete_multipart_upload_request_t�Ľṹָ��
	 * @param key [in] Object������
	 * @retval void
	 */
	void (*set_key)(oss_complete_multipart_upload_request_t *request, const char *key);

	/**
	 * ���PartETag�б�����
	 * @param request [in] ��ʶһ��oss_complete_multipart_upload_request_t�Ľṹָ��
	 * @param part_etags_number [in] part_etags* �ĸ���
	 * @return ����һ��oss_part_etag_t��˫��ָ�룬��ͨ��part_etags_number������
	 * @retval �ǿ� ��ʾ�ɹ�
	 * @retval NULL ��ʾʧ��
	 */
	oss_part_etag_t ** (*get_part_etags)(oss_complete_multipart_upload_request_t *request, int *part_etags_number);

	/**
	 * ����PartETag�б�����
	 * @param request [in] ��ʶһ��oss_complete_multipart_upload_request_t�Ľṹָ��
	 * @param part_etags [in] ��ʶһ��oss_part_etag_t��˫��ָ��
	 * @param part_etags_number [in] part_etags* �ĸ���
	 * retval void
	 */
	void (*set_part_etags)(oss_complete_multipart_upload_request_t *request, oss_part_etag_t **part_etags, int part_etags_number);

	/**
	 * ���Upload ID������
	 * @param request [in] ��ʶһ��oss_complete_multipart_upload_request_t�Ľṹָ��
	 * @return Upload ID������
	 * @retval const char *
	 */
	const char * (*get_upload_id)(oss_complete_multipart_upload_request_t *request);

	/**
	 * ����Upload ID������
	 * @param request [in] ��ʶһ��oss_complete_multipart_upload_request_t�Ľṹָ��
	 * @param upload_id [in] Upload ID������
	 * @retval void
	 */
	void (*set_upload_id)(oss_complete_multipart_upload_request_t *request, const char *upload_id);
};


/**
 * oss_complete_multipart_upload_request_t ���캯��
 * @param bucket_name [in] Bucket������
 * @param key [in] Object������
 * @param upload_id [in] Upload ID������
 * @param part_etags [in] ��ʶһ��oss_part_etag_t��˫��ָ��
 * @param part_etags_number [in] part_etags* �ĸ���
 * @return ����һ��oss_complete_multipart_upload_request_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_complete_multipart_upload_request_t *
complete_multipart_upload_request_initialize(const char *bucket_name,
		const char *key,
		const char *upload_id,
		oss_part_etag_t **part_etags,
		int part_etags_number);

/**
 * oss_complete_multipart_upload_request_t ��������
 * @param request [in] ��ʶһ��oss_complete_multipart_upload_request_t�Ľṹָ��
 * @retval void
 * @pre request ����ʹ��complete_multipart_upload_request_initialize�ķ���ֵ
 */
extern void 
complete_multipart_upload_request_finalize(oss_complete_multipart_upload_request_t *request);
/**@}*/
#endif

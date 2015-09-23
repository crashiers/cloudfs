/*
 * =============================================================================
 *
 *       Filename:  oss_upload_part_request.h
 *
 *    Description:  oss_upload_part_request.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_UPLOAD_PART_REQUEST_H
# error Never include <oss_upload_part_request.h> directly, use <client.h> instead.
#endif

#ifndef OSS_UPLOAD_PART_REQUEST_H
#define OSS_UPLOAD_PART_REQUEST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @defgroup oss_upload_part_request_t oss_upload_part_request_t
 * @{
 */

/**
 * struct oss_upload_part_request_s �ڲ�ʹ�� \n
 * oss_upload_part_request_t ������ʹ��
 */
typedef struct oss_upload_part_request_s oss_upload_part_request_t;

/**
 * �����ϴ�Multipart�ֿ飨Part������
 */
struct oss_upload_part_request_s {

	char *bucket_name; /**< Bucket����*/
	char *input_stream; /**< �����ϴ��ֿ����ݵ�������*/
	size_t input_stream_len; /**< �����ϴ��ֿ����ݵ��������ĳ���*/
	char *key; /**< OSSObject key*/
	char *md5_digest; /**< �ֿ飨Part�����ݵ�MD5У��ֵ*/
	int part_number; /**< �ϴ��ֿ飨Part���ı�ʶ���루Part Number��*/
	size_t part_size; /**< �ֿ飨Part�����ݵ��ֽ���*/
	char *upload_id; /**< ��ʶMultipart�ϴ��¼���Upload ID*/

	/**
	 * ���Bucket����
	 * @param request [in] ��ʶһ��oss_upload_part_request_t�ṹָ��
	 * @return ����Bucket����
	 * @retval const char *
	 */
	const char * (*get_bucket_name)(oss_upload_part_request_t *request);

	/**
	 * ����Bucket����
	 * @param request [in] ��ʶһ��oss_upload_part_request_t�ṹָ��
	 * @param bucket_name [in] Bucket����
	 * @retval void
	 */
	void (*set_bucket_name)(oss_upload_part_request_t *request,
			const char *bucket_name);

	/**
	 * ���OSSObject key
	 * @param request [in] ��ʶһ��oss_upload_part_request_t�ṹָ��
	 * @return OSSObject key
	 * @retval const char *
	 */
	const char * (*get_key)(oss_upload_part_request_t *request);

	/**
	 * ����OSSObject key
	 * @param request [in] ��ʶһ��oss_upload_part_request_t�ṹָ��
	 * @param key [in] OSSObject key
	 * @retval void
	 */
	void (*set_key)(oss_upload_part_request_t *request, const char *key);

	/**
	 * ��÷ֿ飨Part�����ݵ�MD5У��ֵ
	 * @param request [in] ��ʶһ��oss_upload_part_request_t�ṹָ��
	 * @return  �ֿ飨Part�����ݵ�MD5У��ֵ
	 * @retval const char *
	 */
	const char * (*get_md5_digest)(oss_upload_part_request_t *request);

	/**
	 * ���÷ֿ飨Part�����ݵ�MD5У��ֵ
	 * @param request [in] ��ʶһ��oss_upload_part_request_t�ṹָ��
	 * @param md5_digest [in] �ֿ飨Part�����ݵ�MD5У��ֵ
	 * @retval void
	 */
	void (*set_md5_digest)(oss_upload_part_request_t *request, const char *md5_digest);

	/**
	 * ��ð����ϴ��ֿ����ݵ�������
	 * @param request [in] ��ʶһ��oss_upload_part_request_t�ṹָ��
	 * @param input_stream_len [out] �ϴ��ֿ����ݵ��������ĳ���
	 * @return �����ϴ��ֿ����ݵ�������
	 * @retval const char *
	 */
	const char * (*get_input_stream)(oss_upload_part_request_t *request, size_t *input_stream_len);

	/**
	 * ���ð����ϴ��ֿ����ݵ�������
	 * @param request [in] ��ʶһ��oss_upload_part_request_t�ṹָ��
	 * @param input_stream [in] �����ϴ��ֿ����ݵ�������
	 * @param input_stream_len [in] �����ϴ��ֿ����ݵ��������ĳ���
	 * @retval void
	 */
	void (*set_input_stream)(oss_upload_part_request_t *request,
			const char *input_stream, size_t input_stream_len);

	/**
	 * ��ñ�ʶMultipart�ϴ��¼���Upload ID
	 * @param request [in] ��ʶһ��oss_upload_part_request_t�ṹָ��
	 * @return ��ʶMultipart�ϴ��¼���Upload ID
	 * @retval const char *
	 */
	const char * (*get_upload_id)(oss_upload_part_request_t *request);

	/**
	 * ���ñ�ʶMultipart�ϴ��¼���Upload ID
	 * @param request [in] ��ʶһ��oss_upload_part_request_t�ṹָ��
	 * @param upload_id [in] ��ʶMultipart�ϴ��¼���Upload ID
	 * @retval void
	 */
	void (*set_upload_id)(oss_upload_part_request_t *request, const char *upload_id);

	/**
	 * ����ϴ��ֿ飨Part���ı�ʶ���루Part Number��
	 * @param request [in] ��ʶһ��oss_upload_part_request_t�ṹָ��
	 * @return �ϴ��ֿ飨Part���ı�ʶ���루Part Number��
	 * @retval const char *
	 */
	int (*get_part_number)(oss_upload_part_request_t *request);

	/**
	 * �����ϴ��ֿ飨Part���ı�ʶ���루Part Number��
	 * @param request [in] ��ʶһ��oss_upload_part_request_t�ṹָ��
	 * @param part_number [in] �ϴ��ֿ飨Part���ı�ʶ���루Part Number��
	 * @retval void
	 */
	void (*set_part_number)(oss_upload_part_request_t *request, int part_number);

	/**
	 * ���طֿ飨Part�����ݵ��ֽ���
	 * @param request [in] ��ʶһ��oss_upload_part_request_t�ṹָ��
	 * @return �ֿ飨Part�����ݵ��ֽ���
	 * @retval long
	 */
	long (*get_part_size)(oss_upload_part_request_t *request);

	/**
	 * ���÷��طֿ飨Part�����ݵ��ֽ���
	 * @param request [in] ��ʶһ��oss_upload_part_request_t�ṹָ��
	 * @param part_size [in] �ֿ飨Part�����ݵ��ֽ���
	 * @retval void
	 */
	void (*set_part_size)(oss_upload_part_request_t *request, size_t part_size);
};


/**
 * oss_upload_part_request_t ���캯��
 * @return ����һ��oss_upload_part_request_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_upload_part_request_t *
upload_part_request_initialize(void);

/**
 * oss_upload_part_request_t ��������
 * @param request [in] ��ʶһ��oss_upload_part_request_t�ṹָ��
 * @retval void
 * @pre request ����ʹ��upload_part_request_initialize�ķ���ֵ
 */
extern void 
upload_part_request_finalize(oss_upload_part_request_t *request);

/**@}*/
#endif

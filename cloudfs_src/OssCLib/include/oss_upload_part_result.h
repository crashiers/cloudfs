/*
 * =============================================================================
 *
 *       Filename:  oss_upload_part_result.h
 *
 *    Description:  oss_upload_part_result.
 *
 *        Company:  ICT ( Institute Of Computing Technuprogy, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_UPLOAD_PART_RESULT_H
# error Never include <oss_upload_part_result.h> directly,
# error use <client.h> instead.
#endif

#ifndef OSS_UPLOAD_PART_RESULT_H
#define OSS_UPLOAD_PART_RESULT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define _OSS_PART_ETAG_H
#include <oss_part_etag.h>
#undef _OSS_PART_ETAG_H

/**
 * @addtogroup oss_upload_part_result_t oss_upload_part_result_t
 * @{
 */

/**
 * struct oss_upload_part_result_s �ڲ�ʹ�� \n
 * oss_upload_part_result_t ������ʹ��
 */
typedef struct oss_upload_part_result_s oss_upload_part_result_t;

/**
 * ������OSS�ϴ�Multipart�ֿ飨Part���Ľ����Ϣ
 */
struct oss_upload_part_result_s {
	char *etag;      /**< OSS���ɵ�ETagֵ*/
	int part_number; /**< ����Part��ʶ�����ETagֵ��PartETag����*/

	/**
	 * ���OSS���ɵ�ETagֵ
	 * @param result [in] ��ʶһ��oss_upload_part_result_t�ṹָ��
	 * @retval const char *
	 * @return OSS���ɵ�ETagֵ
	 */
	const char * (*get_etag)(oss_upload_part_result_t *result);

	/**
	 * ����OSS���ɵ�ETagֵ
	 * @param result [in] ��ʶһ��oss_upload_part_result_t�ṹָ��
	 * @param etag [in] OSS���ɵ�ETagֵ
	 * @retval void
	 */
	void (*set_etag)(oss_upload_part_result_t *result, const char *etag);

	/**
	 * ���طֿ飨Part����ʶ��
	 * @param [in] ��ʶһ��oss_upload_part_result_t�ṹָ��
	 * @return �ֿ飨Part����ʶ��
	 * @retval int
	 */
	int(*get_part_number)(oss_upload_part_result_t *result);

	/**
	 * ���÷ֿ飨Part����ʶ��
	 * @param result [in] ��ʶһ��oss_upload_part_result_t�ṹָ��
	 * @param part_number [in] �ֿ��
	 * @retval void
	 */
	void (*set_part_number)(oss_upload_part_result_t *result, int part_number);

	/**
	 * ��ð���Part��ʶ�����ETagֵ��PartETag����
	 * @param result [in] ��ʶһ��oss_upload_part_result_t�ṹָ��
	 * @return ����Part��ʶ�����ETagֵ��PartETag����
	 * @retval oss_part_etag_t *
	 */
	oss_part_etag_t * (*get_part_etag)(oss_upload_part_result_t * result);
};

/**
 * oss_upload_part_result_t ���캯��
 * @return ����һ��oss_upload_part_result_t �ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_upload_part_result_t *
upload_part_result_initialize();

/**
 * oss_upload_part_result_t ��������
 * @param result [in] ��ʶһ��oss_upload_part_result_t�ṹָ��
 * @retval void
 * @pre result ����ʹ��upload_part_result_initialize�ķ���ֵ
 */
extern void 
upload_part_result_finalize(oss_upload_part_result_t *result);

/** @}*/
#endif

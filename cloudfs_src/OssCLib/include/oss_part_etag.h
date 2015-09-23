/*
 * =============================================================================
 *
 *       Filename:  oss_part_etag.h
 *
 *    Description:  oss_part_etag.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_PART_ETAG_H
# error Never include <oss_part_etag.h> directly, use <client.h> instead.
#endif

#ifndef OSS_PART_ETAG_H
#define OSS_PART_ETAG_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @defgroup oss_part_etag_t oss_part_etag_t
 * @{
 */

/**
 * struct oss_part_etag_s �ڲ�ʹ�� \n
 * oss_part_etag_t ������ʹ��
 */
typedef struct oss_part_etag_s oss_part_etag_t;

/**
 * ����Multipart�ϴ���Part�ķ��ؽ����Ϣ
 */
struct oss_part_etag_s {
	char *etag;             /**< Part��ETagֵ */
	int part_number;        /**< Part��ʶ���� */

	/**
	 * ���Part��ETagֵ
	 * @param etag [in] ��ʶһ��oss_part_etag_t�ṹָ��
	 * @return Part��ETagֵ
	 * @retval const char *
	 */
	const char * (*get_etag)(oss_part_etag_t *etag);

	/**
	 * ����Part��ETagֵ
	 * @param pe [in] ��ʶһ��oss_part_etag_t�ṹָ��
	 * @param etag [in] Part��ETagֵ
	 * @retval void
	 */
	void (*set_etag)(oss_part_etag_t *pe, const char *etag);

	/**
	 * ���Part��ʶ����
	 * @param etag [in] ��ʶһ��oss_part_etag_t�ṹָ��
	 * @return Part��ʶ����
	 * @retval int
	 */
	int (*get_part_number)(oss_part_etag_t *etag);

	/**
	 * ����Part��ʶ����
	 * @param etag [in] ��ʶһ��oss_part_etag_t�ṹָ��
	 * @param part_number [in] Part��ʶ����
	 * @retval void
	 */
	void (*set_part_number)(oss_part_etag_t *etag, int part_number);
};

/**
 * oss_part_etag_t���캯��
 * @param part_number [in] Part��ʶ����
 * @param etag [in] Part��ETagֵ
 * @return ����һ��oss_part_etag_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_part_etag_t *
part_etag_initialize(int part_number, const char *etag);

/**
 * oss_part_etag_t��������
 * @param etag [in] ��ʶһ��oss_part_etag_t�ṹָ��
 * @retval void
 * @pre etag ����ʹ��part_etag_initialize�ķ���ֵ
 */
extern void 
part_etag_finalize(oss_part_etag_t *etag);
/**@}*/
#endif

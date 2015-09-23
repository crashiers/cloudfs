/*
 * =============================================================================
 *
 *       Filename:  oss_part_summary.h
 *
 *    Description:  oss_part_summary.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_PART_SUMMARY_H
# error Never include <oss_part_summary.h> directly, use <client.h> instead.
#endif

#ifndef OSS_PART_SUMMARY_H
#define OSS_PART_SUMMARY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @defgroup oss_part_summary_t oss_part_summary_t
 * @{
 */

/**
 * struct oss_part_summary_s �ڲ�ʹ�� \n
 * oss_part_summary_t ������ʹ��
 */
typedef struct oss_part_summary_s oss_part_summary_t;

/**
 * ����ͨ��Multipart�ϴ�ģʽ�ϴ���Part��ժҪ��Ϣ
 */
struct oss_part_summary_s {
	char *etag;                   /**< Part��etagֵ */
	char *last_modified;          /**< Part�ϴ��޸ĵ�ʱ�� */
	int part_number;              /**< Part�����number */
	long size;                    /**< Part�Ĵ�С */

	/**
	 * ���Part��etagֵ
	 * @param summary [in] ��ʶһ��oss_part_summary_t�ṹָ��
	 * @return Part��etagֵ
	 * @retval const char *
	 */
	const char * (*get_etag)(oss_part_summary_t *summary);

	/**
	 * ����Part��etagֵ
	 * @param summary [in] ��ʶһ��oss_part_summary_t�ṹָ��
	 * @param etag [in] Part��etagֵ
	 * @retval void
	 */
	void (*set_etag)(oss_part_summary_t *summary, const char *etag);

	/**
	 * ���Part�ϴ��޸ĵ�ʱ��
	 * @param summary [in] ��ʶһ��oss_part_summary_t�ṹָ��
	 * @return Part�ϴ��޸ĵ�ʱ��
	 * @retval const char *
	 */
	const char * (*get_last_modified)(oss_part_summary_t *summary);

	/**
	 * ����Part�ϴ��޸ĵ�ʱ��
	 * @param summary [in] ��ʶһ��oss_part_summary_t�ṹָ��
	 * @param lastmodified [in] Part�ϴ��޸ĵ�ʱ��
	 * @retval void
	 */
	void (*set_last_modified)(oss_part_summary_t *summary, const char *lastmodified);

	/**
	 * ���Part�����number
	 * @param summary [in] ��ʶһ��oss_part_summary_t�ṹָ��
	 * @return Part�����number
	 * @retval int
	 */
	int (*get_part_number)(oss_part_summary_t *summary);

	/**
	 * ����Part�����number
	 * @param summary [in] ��ʶһ��oss_part_summary_t�ṹָ��
	 * @param part_number [in] Part�����number
	 * @retval void
	 */
	void (*set_part_number)(oss_part_summary_t *summary, int part_number);

	/**
	 * ���Part�Ĵ�С
	 * @param summary [in] ��ʶһ��oss_part_summary_t�ṹָ��
	 * @return Part�Ĵ�С
	 * @retval long
	 */
	long (*get_size)(oss_part_summary_t *summary);

	/**
	 * ����Part�Ĵ�С
	 * @param summary [in] ��ʶһ��oss_part_summary_t�ṹָ��
	 * @param size [in] Part�Ĵ�С
	 * @retval void
	 */
	void (*set_size)(oss_part_summary_t *summary, long size);
};

/**
 * oss_part_summary_t���캯��
 * @return ����һ��oss_part_summary_t �ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_part_summary_t *
part_summary_initialize(void);

/**
 * oss_part_summary_t��������
 * @param summary [in] ��ʶһ��oss_part_summary_t�ṹָ��
 * @retval void
 * @pre summary ����ʹ��part_summary_initialize�ķ���ֵ
 */
extern void 
part_summary_finalize(oss_part_summary_t *summary);
/**@}*/
#endif

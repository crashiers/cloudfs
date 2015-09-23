/*
 * =============================================================================
 *
 *       Filename:  oss_copy_object_result.h
 *
 *    Description:  oss_copy_object_result.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_COPY_OBJECT_RESULT_H
# error Never include <oss_copy_object_result.h> directly, use <client.h> instead.
#endif

#ifndef OSS_COPY_OBJECT_RESULT_H
#define OSS_COPY_OBJECT_RESULT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @defgroup oss_copy_object_result_t oss_copy_object_result_t
 * @{
 */

/**
 * struct oss_copy_object_result_s �ڲ�ʹ�� \n
 * oss_copy_object_result_t ������ʹ��
 */
typedef struct oss_copy_object_result_s oss_copy_object_result_t;

/**
 * ����һ����OSS���Ѿ����ڵ�Object������һ��Object��������
 */
struct oss_copy_object_result_s {
	char *etag;       /**< ��Object��ETagֵ */
	char *last_modified;   /**< ��Object������޸�ʱ�� */

	/**
	 * �����Object��ETagֵ
	 * @param result [in] ��ʶһ��oss_copy_object_result_t�Ľṹָ��
	 * @return ��Object��ETagֵ
	 * @retval const char *
	 */
	const char * (*get_etag)(oss_copy_object_result_t *result);

	/**
	 * ������Object��ETagֵ
	 * @param result [in] ��ʶһ��oss_copy_object_result_t�Ľṹָ��
	 * @param etag [in] ��Object��ETagֵ
	 * @retval void
	 */
	void (*set_etag)(oss_copy_object_result_t *result, const char * etag);

	/**
	 * �����Object������޸�ʱ��
	 * @param result [in] ��ʶһ��oss_copy_object_result_t�Ľṹָ��
	 * @return ��Object������޸�ʱ��
	 * @retval const char *
	 */
	const char * (*get_last_modified)(oss_copy_object_result_t *result);

	/**
	 * ������Object������޸�ʱ��
	 * @param result [in] ��ʶһ��oss_copy_object_result_t�Ľṹָ��
	 * @param last_modified [in] ��Object������޸�ʱ��
	 * @retval void
	 */
	void (*set_last_modified)(oss_copy_object_result_t *result, const char *last_modified);

};

/**
 * oss_copy_object_result_t ���캯��
 * @return ����һ��oss_copy_object_result_t�Ľṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_copy_object_result_t *
copy_object_result_initialize(void);

/**
 * oss_copy_object_result_t ��������
 * @param result [in] ��ʶһ��oss_copy_object_result_t�Ľṹָ��
 * @retval void
 * @pre result ����ʹ��copy_object_result_initialize�ķ���ֵ
 */
extern void 
copy_object_result_finalize(oss_copy_object_result_t *result);
/**@}*/
#endif

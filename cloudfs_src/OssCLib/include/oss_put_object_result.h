/*
 * =============================================================================
 *
 *       Filename:  oss_put_object_result.h
 *
 *    Description:  oss_put_object_result.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_PUT_OBJECT_RESULT_H
# error Never include <oss_put_object_result.h> directly, use <client.h> instead.
#endif

#ifndef OSS_PUT_OBJECT_RESULT_H
#define OSS_PUT_OBJECT_RESULT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @defgroup oss_put_object_result_t oss_put_object_result_t
 * @{
 */

/**
 * struct oss_put_object_result_s �ڲ�ʹ�� \n
 * oss_put_object_result_t ������ʹ��
 */
typedef struct oss_put_object_result_s oss_put_object_result_t;

/**
 * �ϴ�object�����ķ��ؽ��
 */
struct oss_put_object_result_s {
	char *etag; /**< �´�����OSSObject��ETagֵ*/

	/**
	 * ����´�����OSSObject��ETagֵ
	 * @param result [in] ��ʶһ��oss_put_object_result_t�ṹָ��
	 * @return �´�����OSSObject��ETagֵ
	 * @retval const char *
	 */
	const char * (*get_etag)(oss_put_object_result_t *result);

	/**
	 * �����´�����OSSObject��ETagֵ
	 * @param result [in] ��ʶһ��oss_put_object_result_t�ṹָ��
	 * @param etag [in] �´�����OSSObject��ETagֵ
	 * @retval void
	 */
	void (*set_etag)(oss_put_object_result_t *result, const char *etag);
};

/**
 * oss_put_object_result_t ���캯��
 * @return ����һ��oss_put_object_result_t �ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_put_object_result_t *
put_object_result_initialize();

/**
 * oss_put_object_result_t ��������
 * @param  result [in] ��ʶһ��oss_put_object_result_t�ṹָ��
 * @retval void
 * @pre result ����ʹ��put_object_result_initialize�ķ���ֵ
 */
extern void 
put_object_result_finalize(oss_put_object_result_t *result);
/**@}*/
#endif

/*
 * =============================================================================
 *
 *       Filename:  oss_object.h
 *
 *    Description:  oss object
 *
 *        Created:  09/07/2012 03:22:02 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _OSS_OBJECT_H
# error Never include <oss_object.h> directly, use <client.h> instead.
#endif
#ifndef OSS_OBJECT_H
#define OSS_OBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define _OSS_OBJECT_METADATA_H
#include <oss_object_metadata.h>
#undef _OSS_OBJECT_METADATA_H

/**
 * @defgroup oss_object_t oss_object_t
 * @{
 */

/**
 * struct oss_object_s �ڲ�ʹ�� \n
 * oss_object_t ������ʹ��
 */
typedef struct oss_object_s oss_object_t;

/**
 * ��ʾOSS�е�Object\n
 *
 * �� OSS �У��û���ÿ���ļ�����һ�� Object��ÿ���ļ���С�� 5G�� Object����key��data��user meta�����У�key��Object �����֣� data��Object �����ݣ�user meta���û��Ը�object��������
 *
 * Object �����淶:
 *
 * - ʹ��UTF-8����
 * - ���򳤶ȱ����� 1-1023�ֽ�֮��
 */
struct oss_object_s {
	char *bucket_name;                       /**< Object������Bucket������ */
	char *key;                               /**< Object������ */
	char *object_content;                    /**< Object������ */
	oss_object_metadata_t *object_metadata;  /**< Object��Ԫ���� */
	unsigned int object_content_len;               /**< Object�����ݳ��� */

	/**
	 * ���Object������Bucket������
	 * @param object [in]  ��ʶһ��oss_object_t�ṹָ��
	 * @return Object������Bucket������
	 * @retval const char *
	 */
	const char * (*get_bucket_name)(oss_object_t *object);

	/**
	 * ���Object������
	 * @param object [in]  ��ʶһ��oss_object_t�ṹָ��
	 * @return Object������
	 * @retval const char *
	 */
	const char * (*get_key)(oss_object_t *object);

	/**
	 * ���Object������
	 * @param object [in]  ��ʶһ��oss_object_t�ṹָ��
	 * @param object_content_len [out] Object�����ݳ���
	 * @return Object������
	 * @retval const char *
	 */
	const char * (*get_object_content)(oss_object_t *object, unsigned int *object_content_len);

	/**
	 * ���Object��Ԫ����
	 * @param object [in]  ��ʶһ��oss_object_t�ṹָ��
	 * @return ����һ��oss_object_metadata_t�ṹָ��
	 * @retval �ǿ� ��ʾ�ɹ�
	 * @retval NULL ��ʾʧ��
	 */
	oss_object_metadata_t * (*get_object_metadata)(oss_object_t *object);

	/**
	 * ����Object������Bucket������
	 * @param object [in] ��ʶһ��oss_object_t�ṹָ��
	 * @param bucket_name [in] Object������Bucket������
	 * @retval void
	 */
	void (*set_bucket_name)(oss_object_t *object, const char *bucket_name);

	/**
	 * ����Object������
	 * @param object [in] ��ʶһ��oss_object_t�ṹָ��
	 * @param key [in] Object������
	 * @retval void
	 */
	void (*set_key)(oss_object_t *object, const char *key);

	/**
	 * ����Object������
	 * @param object [in] ��ʶһ��oss_object_t�ṹָ��
	 * @param object_content [in] Object������
	 * @param object_content_len [in] Object�����ݳ���
	 * @retval void
	 */
	void (*set_object_content)(oss_object_t *object,
			const char *object_content,
			unsigned int object_content_len);

	/**
	 * ����Object��Ԫ����
	 * @param object [in] ��ʶһ��oss_object_t�ṹָ��
	 * @param object_metadata [in] Object��Ԫ����
	 * @retval void
	 */
	void (*set_object_metadata)(oss_object_t *object,
			oss_object_metadata_t *object_metadata);
};

/**
 * oss_object_t���캯��
 * @return ����һ��oss_object_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_object_t * object_initialize();

/**
 * oss_object_t��������
 * @param object [in] ��ʶһ��oss_object_t�ṹָ��
 * @retval void
 * @pre object ����ʹ��object_initialize�ķ���ֵ
 */
extern void object_finalize(oss_object_t *object);
/**@}*/
#endif // OSS_OBJECT_H


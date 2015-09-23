/*
 * =============================================================================
 *
 *       Filename:  oss_multipart_upload.h
 *
 *    Description:  oss_multipart_upload.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_MULTIPART_UPLOAD_H
# error Never include <oss_multipart_upload.h> directly, use <client.h> instead.
#endif

#ifndef OSS_MULTIPART_UPLOAD_H
#define OSS_MULTIPART_UPLOAD_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
/**
 * @defgroup oss_multipart_upload_t oss_multipart_upload_t
 * @{
 */

/**
 * struct oss_multipart_upload_s �ڲ�ʹ�� \n
 * oss_multipart_upload_t ������ʹ��
 */
typedef struct oss_multipart_upload_s oss_multipart_upload_t;

/**
 * multipart upload����Ϣ
 */
struct oss_multipart_upload_s {
	char *initiated;           /**< ��ʼ����ʱ�� */
	char *storage_class;       /**< Object������ */
	char *upload_id;           /**< Upload ID */
	char *key;                 /**< Object���� */

	/**
	 * ��ó�ʼ����ʱ��
	 * @param uploads [in] ��ʶһ��oss_multipart_upload_t�ṹָ��
	 * @return ��ʼ����ʱ��
	 * @retval const char *
	 */
	const char * (*get_initiated)(oss_multipart_upload_t *uploads);

	/**
	 * ���ó�ʼ����ʱ��
	 * @param uploads [in] ��ʶһ��oss_multipart_upload_t�ṹָ��
	 * @param initiated [in] ��ʼ����ʱ��
	 * @retval void
	 */
	void (*set_initiated)(oss_multipart_upload_t *uploads, const char *initiated);

	/**
	 * ���Object������
	 * @param uploads [in] ��ʶһ��oss_multipart_upload_t�ṹָ��
	 * @return Object������
	 * @retval const char *
	 */
	const char * (*get_storage_class)(oss_multipart_upload_t *uploads);

	/**
	 * ����Object������
	 * @param uploads [in] ��ʶһ��oss_multipart_upload_t�ṹָ��
	 * @param storage_class [in] Object������
	 * @retval void
	 */
	void (*set_storage_class)(oss_multipart_upload_t *uploads, const char *storage_class);

	/**
	 * ���Upload ID
	 * @param uploads [in] ��ʶһ��oss_multipart_upload_t�ṹָ��
	 * @return Upload ID
	 * @retval const char *
	 */
	const char * (*get_upload_id)(oss_multipart_upload_t *uploads);

	/**
	 * ����Upload ID
	 * @param uploads [in] ��ʶһ��oss_multipart_upload_t�ṹָ��
	 * @param upload_id [in]
	 * @retval void
	 */
	void (*set_upload_id)(oss_multipart_upload_t *uploads, const char *upload_id);

	/**
	 * ���Object����
	 * @param uploads [in] ��ʶһ��oss_multipart_upload_t�ṹָ��
	 * @return Object����
	 * @retval const char *
	 */
	const char * (*get_key)(oss_multipart_upload_t *uploads);

	/**
	 * ����Object����
	 * @param uploads [in] ��ʶһ��oss_multipart_upload_t�ṹָ��
	 * @param key Object����
	 * @retval void
	 */
	void (*set_key)(oss_multipart_upload_t *uploads, const char *key);
};

/**
 * oss_multipart_upload_t���캯��
 * @return ����һ��oss_multipart_upload_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_multipart_upload_t *
multipart_upload_initialize(void);

/**
 * oss_multipart_upload_t��������
 * @param uploads [in] ��ʶһ��oss_multipart_upload_t�ṹָ��
 * @retval void
 * @pre uploads ����ʹ��multipart_upload_initialize�ķ���ֵ
 */
extern void 
multipart_upload_finalize(oss_multipart_upload_t *uploads);
/**@}*/
#endif

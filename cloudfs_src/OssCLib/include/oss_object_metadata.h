/*
 * =============================================================================
 *
 *       Filename:  oss_object_metadata.h
 *
 *    Description:  object metadata structure and implementation.
 *
 *        Created:  09/05/2012 02:45:05 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_OBJECT_METADATA_H
# error Never include <oss_object_metadata.h> directly, use <client.h> instead.
#endif

#ifndef OSS_OBJECT_METADATA_H
#define OSS_OBJECT_METADATA_H

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <oss_map.h>

#define _OSS_CONSTANTS_H
#include <oss_constants.h>
#undef _OSS_CONSTANTS_H

/**
 * @defgroup oss_object_metadata_t oss_object_metadata_t
 * @{
 */

/**
 * struct oss_object_metadata_s �ڲ�ʹ�� \n
 * oss_object_metadata_t ������ʹ��
 */
typedef struct oss_object_metadata_s oss_object_metadata_t;

/**
 * OSS��Object��Ԫ����.�������û��Զ����Ԫ����,Ҳ������OSS���͵ı�׼HTTPͷ(��Content-Length, ETag�ȣ�
 */
struct oss_object_metadata_s {
	oss_map_t *metadata;             /**< Http ��׼ͷ�� */
	oss_map_t *user_metadata;        /**< Http �û��Զ���ͷ�� */

	/**
	 * ����һ���û��Զ���ͷ����ֵ��
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @param key [in] �û��Զ���ͷ����
	 * @param value [in] �û��Զ���ͷ��ֵ
	 * @retval void
	 */
	void (*add_user_metadata)(oss_object_metadata_t *metadata,
			const char *key,
			const char *value);

	/**
	 * ����һ����׼ͷ����ֵ��
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @param key [in] ��׼ͷ���ļ�
	 * @param value [in] ��׼ͷ����ֵ
	 * @retval void
	 */
	void (*add_default_metadata)(oss_object_metadata_t *metadata,
			const char *key,
			const char *value);

	/**
	 * ��ȡCache-Control����ͷ����ʾ�û�ָ����HTTP����/�ظ����Ļ�����Ϊ
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @return Cache-Control����ͷ
	 * @retval const char *
	 */
	const char * (*get_cache_control)(oss_object_metadata_t *metadata);

	/**
	 * ��ȡContent-Disposition����ͷ����ʾMIME�û����������ʾ���ӵ��ļ�
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @return Content-Disposition����ͷ
	 * @retval const char *
	 */
	const char * (*get_content_disposition)(oss_object_metadata_t *metadata);

	/**
	 * ��ȡContent-Encoding����ͷ����ʾObject���ݵı��뷽ʽ
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @return Content-Encoding����ͷ
	 * @retval const char *
	 */
	const char * (*get_content_encoding)(oss_object_metadata_t *metadata);

	/**
	 * ��ȡContent-Length����ͷ����ʾObject���ݵĴ�С
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @return Content-Length����ͷ
	 * @retval long
	 */
	long (*get_content_length)(oss_object_metadata_t *metadata);

	/**
	 * ��ȡContent-Type����ͷ����ʾObject���ݵ����ͣ�Ϊ��׼��MIME����
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @return Content-Type����ͷ
	 * @retval const char *
	 */
	const char * (*get_content_type)(oss_object_metadata_t *metadata);

	/**
	 * ��ȡһ��ֵ��ʾ��Object��ص�hex�����128λMD5ժҪ
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @return Object��etagֵ
	 * @retval const char *
	 */

	const char * (*get_etag)(oss_object_metadata_t *metadata);

	/**
	 * ��ȡExpires����ͷ
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @return Expires����ͷ
	 * @retval const char *
	 */
	const char * (*get_expiration_time)(oss_object_metadata_t *metadata);

	/**
	 * ��ȡLast-Modified����ͷ��ֵ����ʾObject���һ���޸ĵ�ʱ��
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @return Last-Modified����ͷ
	 * @retval const char *
	 */
	const char * (*get_last_modified)(oss_object_metadata_t *metadata);

	/**
	 * �����ڲ����������ͷ��Ԫ���ݣ��ڲ�ʹ�ã�
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @return ����һ��oss_map_t�ṹָ��
	 * @retval �ǿ� ��ʾ�ɹ�
	 * @retval NULL ��ʾʧ��
	 */
	oss_map_t * (*get_raw_metadata)(oss_object_metadata_t *metadata);

	/**
	 * ��ȡ�û��Զ����Ԫ����
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @return ����һ��oss_map_t�ṹָ��
	 * @retval �ǿ� ��ʾ�ɹ�
	 * @retval NULL ��ʾʧ��
	 */
	oss_map_t * (*get_user_metadata)(oss_object_metadata_t *metadata);

	/**
	 * ����Cache-Control����ͷ����ʾ�û�ָ����HTTP����/�ظ����Ļ�����Ϊ
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @param cache_control [in] Cache-Control����ͷ
	 * @retval void
	 */
	void (*set_cache_control)(oss_object_metadata_t *metadata, 
			const char *cache_control);

	/**
	 * ����Content-Disposition����ͷ����ʾMIME�û����������ʾ���ӵ��ļ�
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @param disposition [in] Content-Disposition����ͷ
	 * @retval void
	 */
	void (*set_content_disposition)(oss_object_metadata_t *metadata,
			const char *disposition);

	/**
	 * ����Content-Encoding����ͷ����ʾObject���ݵı��뷽ʽ
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @param encoding [in]Content-Encoding����ͷ
	 * @retval void
	 */
	void (*set_content_encoding)(oss_object_metadata_t *metadata,
			const char *encoding);

	/**
	 * ����Content-Length����ͷ����ʾObject���ݵĴ�С
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @param content_length [in] Content-Length����ͷ
	 * @retval void
	 */
	void (*set_content_length)(oss_object_metadata_t *metadata,
			long content_length);

	/**
	 * ��ȡContent-Type����ͷ����ʾObject���ݵ����ͣ�Ϊ��׼��MIME����
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @param content_type [in] Content-Type����ͷ
	 * @retval void
	 */
	void (*set_content_type)(oss_object_metadata_t *metadata,
			const char *content_type);

	/**
	 * ����Expires����ͷ
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @param expiration_time [in]Expires����ͷ
	 * @retval void
	 */
	void (*set_expiration_time)(oss_object_metadata_t *metadata,
			const char *expiration_time);

	/**
	 * ����Object��etag
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @param etag [in] Object��etag
	 * @retval void
	 */
	void (*set_etag)(oss_object_metadata_t *metadata, const char *etag);

	/**
	 * ��������ͷ���ڲ�ʹ�ã�
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @param key [in] ����ͷ�ļ�
	 * @param value [in] ����ͷ��ֵ
	 * @retval void
	 */
	void (*set_header)(oss_object_metadata_t *metadata,
			const char *key,
			const char *value);

	/**
	 * ����Last-Modified����ͷ��ֵ����ʾObject���һ���޸ĵ�ʱ�䣨�ڲ�ʹ�ã�
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @param last_modified [in] Last-Modified����ͷ
	 * @retval void
	 */
	void (*set_last_modified)(oss_object_metadata_t *metadata,
			const char *last_modified);

	/**
	 * �����û��Զ����Ԫ���ݣ���ʾ��x-oss-meta-Ϊǰ׺������ͷ
	 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
	 * @param user_metadata ��ʶһ��oss_map_t�ṹָ��
	 * @retval void
	 */
	void (*set_user_metadata)(oss_object_metadata_t *metadata,
			oss_map_t *user_metadata);
};

/**
 * oss_object_metadata_t���캯��
 * @return ����һ��oss_object_metadata_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_object_metadata_t *
object_metadata_initialize();

/**
 * oss_object_metadata_t��������
 * @param metadata [in] ��ʶһ��oss_object_metadata_t�ṹָ��
 * @retval void
 * @pre metadata ����ʹ��object_metadata_initialize�ķ���ֵ
 */
extern void
object_metadata_finalize(oss_object_metadata_t *metadata);
/**@}*/
#endif // OSS_OBJECT_METADATA_H


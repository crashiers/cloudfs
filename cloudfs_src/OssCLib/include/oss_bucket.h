/*
 * =============================================================================
 *
 *       Filename:  oss_bucket.h
 *
 *    Description:  oss_bucket.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _OSS_BUCKET_H
# error Never include <oss_bucket.h> directly, use <client.h> instead.
#endif

#ifndef OSS_BUCKET_H
#define OSS_BUCKET_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define _OSS_OWNER_H
#include  "oss_owner.h"
#undef _OSS_OWNER_H

/**
 * @defgroup oss_bucket_t oss_bucket_t
 * @{
 */

/**
 * struct oss_bucket_s �ڲ�ʹ�� \n
 * oss_bucket_t ������ʹ��
 */
typedef struct oss_bucket_s oss_bucket_t;

/**
 * Bucket��OSS�ϵ������ռ� \n
 * Bucket�������� OSS �о���ȫ��Ψһ��,�Ҳ����޸ģ�
 * �洢��OSS�ϵ�ÿ��Object���붼������ĳ��Bucket�С�
 * һ��Ӧ�ã�����ͼƬ������վ�����Զ�Ӧһ������ Bucket��
 * һ���û����ɴ��� 10 ��Bucket, ��ÿ��Bucket�д�ŵ�Object�������ʹ�С�ܺ�û������,
 * �û�����Ҫ�������ݵĿ���չ�ԡ�\n
 * Bucket �����淶
 * - ֻ�ܰ���Сд��ĸ�����֣��»��ߣ�_���Ͷ̺��ߣ�-��
 * - ������Сд��ĸ�������ֿ�ͷ
 * - ���ȱ����� 3-255 �ֽ�֮��
 */
struct oss_bucket_s {
	char *create_date;  /**< Bucket�Ĵ���ʱ�� */
	char *name;         /**< Bucket������ */
	oss_owner_t *owner; /**< Bucket�������� */

	/**
	 * ����Bucket�Ĵ���ʱ��
	 * @param bucket [in] oss_bucket_t ָ��
	 * @retval const char *
	 * @return Bucket�Ĵ���ʱ��
	 */
	const char * (*get_create_date)(oss_bucket_t *bucket);

	/**
	 * ����Bucket�Ĵ���ʱ��
	 * @param bucket [in] oss_bucket_t ָ��
	 * @param create_date [in] Bucket�Ĵ���ʱ��
	 * @retval void
	 */
	void (*set_create_date)(oss_bucket_t *bucket, const char *create_date);

	/**
	 * ����Bucket������
	 * @param bucket [in] oss_bucket_t ָ��
	 * @retval const char *
	 * @return Bucket������
	 */
	const char * (*get_name)(oss_bucket_t *bucket);

	/**
	 * ����Bucket������
	 * @param bucket [in] oss_bucket_t ָ��
	 * @param name [in] Bucket������
	 * @retval void
	 */
	void (*set_name)(oss_bucket_t *bucket, const char * name);

	/**
	 * ����Bucket��������
	 * @param bucket [in] oss_bucket_t ָ��
	 * @retval oss_owner_t *
	 * @return Bucket��������
	 */
	oss_owner_t * (*get_owner)(oss_bucket_t *bucket);

	/**
	 * ����Bucket��������
	 * @param bucket [in] oss_bucket_t ָ��
	 * @param owner [in] Bucket��������
	 * @retval void
	 */
	void (*set_owner)(oss_bucket_t *bucket, oss_owner_t *owner);
};

/**
 * oss_bucket_t ���캯��
 * @return ����һ����ʶBucket�Ľṹָ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_bucket_t *
bucket_initialize(void);

/**
 * oss_bucket_t ��bucket_name�����Ĺ��캯��
 * @return ����һ����ʶBucket�Ľṹָ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 */
extern oss_bucket_t *
bucket_initialize_with_name(const char *name);

/**
 * oss_bucket_t ��������
 * @param bucket [in] ��ʶһ��ACL�Ľṹָ��
 * @retval void
 * @pre bucket ����ʹ��bucket_initialize�ķ���ֵ
 */
extern void 
bucket_finalize(oss_bucket_t *bucket);

/**@}*/

#endif

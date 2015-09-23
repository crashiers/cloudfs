/*
 * =============================================================================
 *
 *       Filename:  oss_owner.h
 *
 *    Description:  oss owner.
 *
 *        Created:  09/05/2012 09:55:06 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_OWNER_H
# error Never include <oss_owner.h> directly, use <client.h> instead.
#endif

#ifndef OSS_OWNER_H
#define OSS_OWNER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @defgroup oss_owner_t oss_owner_t
 * @{
 */

/**
 * struct oss_owner_s �ڲ�ʹ�� \n
 * oss_owner_t ������ʹ��
 */
typedef struct oss_owner_s oss_owner_t;

/**
 * ��ʾOSS Bucket��������
 */
struct oss_owner_s {
	char *id;                /**< �����ߵ�ID */
	char *display_name;      /**< �����ߵ���ʾ���� */

	/**
	 * ��������ߵ�ID
	 * @param owner [in] ��ʶһ��oss_owner_t�ṹָ��
	 * @return �����ߵ�ID
	 * @retval const char *
	 */
	const char * (*get_id)(oss_owner_t *owner);

	/**
	 * ��������ߵ���ʾ����
	 * @param owner [in] ��ʶһ��oss_owner_t�ṹָ��
	 * @return �����ߵ���ʾ����
	 * @retval const char *
	 */
	const char * (*get_display_name)(oss_owner_t *owner);

	/**
	 * ���������ߵ�ID
	 * @param owner [in] ��ʶһ��oss_owner_t�ṹָ��
	 * @param id [in] �����ߵ�ID
	 * @retval void
	 */
	void (*set_id)(oss_owner_t *owner, const char *id);

	/**
	 * ���������ߵ���ʾ����
	 * @param owner [in] ��ʶһ��oss_owner_t�ṹָ��
	 * @param name [in] �����ߵ���ʾ����
	 * @retval void
	 */
	void (*set_display_name)(oss_owner_t *owner, const char *name);
};

/**
 * oss_owner_t���캯��
 * @return ����һ��oss_owner_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_owner_t *
owner_initialize(void);

/**
 * oss_owner_t��ID ��display name�Ĺ��캯��
 * @param id [in] �����ߵ�ID
 * @param name [in] �����ߵ���ʾ����
 * @return ����һ��oss_owner_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_owner_t *
owner_initialize_with_id(const char *id,
		const char *name);

/**
 * oss_owner_t��������
 * @param owner [in] ��ʶһ��oss_owner_t�ṹָ��
 * @retval void
 * @pre owner ����ʹ��owner_initialize�ķ���ֵ
 */
extern void
owner_finalize(oss_owner_t *owner);
/**@}*/
#endif

/*
 * =============================================================================
 *
 *       Filename:  oss_grant.h
 *
 *    Description:  oss_grant.
 *
 *        Created:  09/04/2012 08:57:48 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 *
 * =============================================================================
 */
#ifndef _OSS_GRANT_H
# error Never include <oss_grant.h> directly, use <client.h> instead.
#endif

#ifndef OSS_GRANT_H
#define OSS_GRANT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @defgroup oss_grant_t oss_grant_t
 * @{
 */

/**
 * struct oss_grant_s �ڲ�ʹ�� \n
 * oss_grant_t ������ʹ��
 */
typedef struct oss_grant_s oss_grant_t;

/**
 * ���ʿ��Ƶ���Ȩ��Ϣ
 */
struct oss_grant_s {
	char *identifier;            /**< ����Ȩ����Ϣ */
	char *permission;            /**< ����Ȩ��Ȩ�� */
	struct oss_grant_s *next;    /**< ����ָ��    */

	/**
	 * ��ñ���Ȩ����Ϣ
	 * @param grant [in] ��ʶһ��oss_grant_t�ṹָ��
	 * @return ����Ȩ����Ϣ
	 * @retval const char *
	 */
	const char * (*get_identifier)(oss_grant_t *grant);

	/**
	 * ���ñ���Ȩ����Ϣ
	 * @param grant [in] ��ʶһ��oss_grant_t�ṹָ��
	 * @param identifier [in] ����Ȩ����Ϣ
	 * @retval void
	 */
	void (*set_identifier)(oss_grant_t *grant, const char * identifier);

	/**
	 * ��ñ���Ȩ��Ȩ��
	 * @param grant [in] ��ʶһ��oss_grant_t�ṹָ��
	 * @return ����Ȩ��Ȩ��
	 * @retval const char *
	 */
	const char * (*get_permission)(oss_grant_t *grant);

	/**
	 * ���ñ���Ȩ��Ȩ��
	 * @param grant [in] ��ʶһ��oss_grant_t�ṹָ��
	 * @param permission [in] ����Ȩ��Ȩ��
	 * @retval void
	 */
	void (*set_permission)(oss_grant_t *grant, const char *permission);

};

/**
 * oss_grant_t���캯��
 * @param identifier [in] ����Ȩ����Ϣ
 * @param permission [in] ����Ȩ��Ȩ��
 * @return ����һ��oss_grant_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 */
extern oss_grant_t *
grant_initialize(const char *identifier, const char *permission);

/**
 * oss_grant_t��������
 * @param grant [in] ��ʶһ��oss_grant_t�ṹָ��
 * @retval void
 * @pre grant ����ʹ��grant_initialize�ķ���ֵ
 */
extern void 
grant_finalize(oss_grant_t *grant);
/**@}*/
#endif

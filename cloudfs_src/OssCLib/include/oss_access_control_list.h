/*
 * =============================================================================
 *
 *       Filename:  oss_access_control_list.h
 *
 *    Description:  oss_access_control_list.
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

 /* �ڲ�ʹ�õ�ͷ�ļ����û�����Ӧ����<client.h> */
#ifndef _OSS_ACCESS_CONTROL_LIST_H
# error Never include <oss_access_control_list.h> directly, use <client.h> instead.
#endif

/* ͷ�ļ����� */
#ifndef OSS_ACCESS_CONTROL_LIST_H
#define OSS_ACCESS_CONTROL_LIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define _OSS_OWNER_H
#include "oss_owner.h"
#undef _OSS_OWNER_H

#define _OSS_GRANT_H
#include "oss_grant.h"
#undef _OSS_GRANT_H

/**
 * @defgroup oss_access_control_list_t oss_access_control_list_t
 * @{
 */
 
/** 
 *struct oss_access_control_list_s �ڲ�ʹ�� \n
 *oss_access_control_list_t ������ʹ��
 */
typedef struct oss_access_control_list_s oss_access_control_list_t;

/**
 * ��ʾOSS�ķ��ʿ����б�Access Control List, ACL),
 * ������һ��Ϊָ������Ȩ��(Grantee)�����ض�Ȩ��(Permission)�ļ���
 */
struct oss_access_control_list_s {
	oss_owner_t *owner;     /**< Bucket ������*/
	//oss_grant_t *grants;
	//int grant_number_count;
	char *grant;            /**< ��Ȩ��Ϣ*/

	/**
	 * ���������� Owner
	 * @param acl [in] ��ʶһ��oss_access_control_list_t ָ��
	 * @retval �ǿ� ��ʾ�ɹ�
	 * @retval NULL ��ʾʧ��
	 * @return ����һ��oss_owner_t�ṹָ��
	 */
	oss_owner_t * (*get_owner)(oss_access_control_list_t 
	        *acl);

	/**
	 * ����������Owner
	 * @param acl [in] ��ʶһ��oss_access_control_list_t ָ��
	 * @param owner [in] ������Owner�ṹ
	 * @retval void
	 */
	void (*set_owner)(oss_access_control_list_t *acl,
	        oss_owner_t * owner);

	/**
	 * ���ظ�AccessControlList�а�����������Ȩ��ϢGrant
	 * @param acl [in] ��ʶһ��oss_access_control_list_t ָ��
	 * @retval const char *
	 * @return AccessControlList�а�����������Ȩ��ϢGrant
	 */
	const char * (*get_grant)(oss_access_control_list_t 
	        *acl);

	/**
	 * ����������Ȩ��ϢGrant
	 * @param acl [in] ��ʶһ��oss_access_control_list_t ָ��
	 * @param grant [in] ������Ȩ��Ϣ����
	 * @retval void
	 */
	void (*set_grant)(oss_access_control_list_t *acl,
	        const char *grant);

	//void (*grant_permission)(oss_access_control_list_t *acl, 
	//const char *identifier, const char *permission);
	//void (*revoke_all_permissions)(oss_access_control_list_t* acl,
	//const char *identifier);
	//oss_grant_t * (*get_grants)(oss_access_control_list_t *acl);

};

/**
 * oss_access_control_list_t ���캯��
 * @return ����һ��oss_access_control_list_t�ṹָ��
 * @retval �ǿ� ��ʾ�ɹ�
 * @retval NULL ��ʾʧ��
 * @note �û�����Ҫ�����Ҫ������Ӧ��finalize�����ͷſռ�
 * @code
 * oss_owner_t *owner = owner_initialize();
 * oss_access_control_list_t * acl = access_control_list_initialize();
 * acl->set_owner(acl, owner);
 * @endcode
 */
extern oss_access_control_list_t *
access_control_list_initialize(void);

/**
 * oss_access_control_list_t ��������
 * @param acl [in] ��ʶһ��oss_access_control_list_t�Ľṹָ��
 * @retval void
 * @pre acl ����ʹ��access_control_list_initialize�ķ���ֵ
 */
extern void 
access_control_list_finalize(oss_access_control_list_t *acl);

/** @} */

#endif

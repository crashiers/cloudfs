/*
 * =============================================================================
 *
 *       Filename:  generate_authentication.h
 *
 *    Description:  generate authentication
 *
 *        Created:  09/06/2012 06:09:49 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef GENERATE_AUTHENTICATION_H
#define GENERATE_AUTHENTICATION_H

/* *
 * ����ǩ��ֵ����������ֱ�Ϊ��
 * @access_key��      �û���
 * @method��          ���󷽷�
 * @default_headers�� Ĭ������ͷ��
 * @user_headers��    �û��Զ���ͷ��
 * @resource��        �������Դ
 * 
 * �ú�����������ֵ����һ������ֵΪǩ��������ɺ���ֱ�ӷ��أ�
 * �ڶ�������ֵΪ sign_len�������һ������ sign_len ���ء�
 * */
extern char *
generate_authentication(const char *access_key, const char *method,
		oss_map_t *default_headers, oss_map_t *user_headers,
		const char *resource, unsigned int *sign_len);

extern void oss_auth_init();
extern void oss_auth_destroy();


#endif // GENERATE_AUTHENTICATION_H

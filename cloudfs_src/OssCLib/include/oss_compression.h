/*
 * =============================================================================
 *
 *       Filename:  oss_compression.h
 *
 *    Description:  oss compression utility.
 *
 *        Created:  09/21/2012 04:36:10 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef OSS_COMPRESSION_H
#define OSS_COMPRESSION_H
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OSS_COMPRESSION_MAGIC "OSSC" /**< (OSS-C)ompression */
#define OSS_COMPRESSION_MAGIC_LEN (strlen(OSS_COMPRESSION_MAGIC))
#define OSS_COMPRESSION_VERSION 0x01 /**< Ŀǰѹ���ļ���ʽ�汾Ϊ 1  */

#define OSS_CHUNK_SIZE (8 * 1024 * 1024)

enum oss_compression_algorithm_e {
	OSS_LZ4 = 0x01,
	OSS_LZO = 0x02,
	OSS_QLZ = 0x03, /** QuickLZ compression algorithm not implemented right now */
	OSS_SNAPPY = 0x04 /** Google Snappy compression algorithm not implemented right now */
};

typedef enum oss_compression_algorithm_e oss_compression_algorithm_t;

struct oss_compression_header_s {
	char magic[4];  /**< 4 Bytes��ħ����"OSSC"��\117\123\123\103 */
	char version;   /**< 1 Byte��ѹ���ļ���ʽ�汾��ĿǰΪ 1 */
	char algorithm; /**< 1 Bytes��ѹ���㷨��1��LZ4��2��LZO��3��QLZ��4��Snappy */
	char flag;      /**< 1 Bytes����־λ */
	char length;    /**< 1 Bytes���ײ����ȣ��255�ֽ�, ���ֶα��ڽ����չ�ײ� */
	char md5[16];   /**< 16 Bytes��ԭʼ�ļ���MD5ֵ */
	void *optional; /**< 4 Bytes����ѡ����������ܻ����ø��ֶ� */
};

typedef struct oss_compression_header_s oss_compression_header_t;

extern void
oss_write_compression_header(FILE *fp, char algorithm, char flag, char md5[]);

extern void oss_compress_file(
		const char *infile,
		const char *outfile,
		char algorithm,
		char flag,      /** 0: ��д��Դ�ļ���У��ֵ��1:д��Դ�ļ���У��ֵ */
		int level);

extern int oss_compress_block(
		char *inbuf, unsigned int inbuf_len, /** �������������Ԥ�ȷ���ռ� */
		char *outbuf, unsigned int outbuf_len,/** �������������Ԥ�ȷ���ռ� */
		char algorithm, /**< ѹ���㷨  */
		int level /**< ��ѹ���㷨��ѹ���ȼ�*/);

extern int oss_compress_block_2nd(
		char *inbuf, unsigned int inbuf_len, /** �������������Ԥ�ȷ���ռ� */
		char *outbuf, unsigned int outbuf_len,/** �������������Ԥ�ȷ���ռ� */
		char algorithm, /**< ѹ���㷨  */
		char flag, /**< ��ʶλ��0 �����ԭ�ļ�MD5��1 ���ԭ�ļ�MD5ֵ */
		int level /**< ��ѹ���㷨��ѹ���ȼ�*/);

#endif // OSS_COMPRESSION_H

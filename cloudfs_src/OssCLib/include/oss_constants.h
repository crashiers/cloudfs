/*
 * =============================================================================
 *
 *       Filename:  oss_constants.h
 *
 *    Description: oss constants definition. 
 *
 *        Created:  09/04/2012 03:21:26 PM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#ifndef _OSS_CONSTANTS_H
# error Never include <oss_constants.h> directly, use <client.h> instead.
#endif

#ifndef OSS_CONSTANTS_H
#define OSS_CONSTANTS_H

typedef enum _OSS_ERROR_CODE {
	/* 0 ���سɹ� */
	OK,
	/* 1 ɾ���ɹ� */
	NO_CONTENT,
	/* �ܾ����� */
	ACCESS_DENIED,
	/* Bucket �Ѿ����� */
	BUCKET_ALREADY_EXISTS,
	/* Bucket ��Ϊ�� */
	BUCKET_NOT_EMPTY,
	/* ʵ����� */
	ENTITY_TOO_LARGE,
	/* ʵ���С */
	ENTITY_TOO_SMALL,
	/* �ļ������ */
	FILE_GROUP_TOO_LARGE,
	/* �ļ�part������ */
	FILE_PART_NOT_EXIST,
	/* �ļ�Part��ʱ */
	FILE_PART_STALE,
	/* OSS �ڲ��������� */
	INTERNAL_ERROR,
	/* Access ID������ */
	INVALID_ACCESS_KEY_ID,
	/* ������ʽ���� */
	INVALID_ARGUMENT,
	/* ��Ч�� Bucket ���� */
	INVALID_BUCKET_NAME,
	/* ��Ч��ժҪ */
	INVALID_DIGEST,
	/* ��Ч�� Object ���� */
	INVALID_OBJECT_NAME,
	/* ��Ч�� Part */
	INVALID_PART,
	/* ��Ч�� Part˳�� */
	INVALID_PART_ORDER,
	/* XML��ʽ�Ƿ� */
	MALFORMED_XML,
	/* ��֧�ֵķ��� */
	METHOD_NOT_ALLOWED,
	/* ȱ�ٲ��� */
	MISSING_ARGUMENT,
	/* ȱ�����ݳ��� */
	MISSING_CONTENT_LENGTH,
	/* Bucket ������ */
	NO_SUCH_BUCKET,
	/* �ļ������� */
	NO_SUCH_KEY,
	/* Multipart Upload ID ������ */
	NO_SUCH_UPLOAD,
	/* �޷�����ķ��� */
	NOT_IMPLEMENTED,
	/* Ԥ������� */
	PRECONDITION_FAILED,
	/* ���������ʱ��ͷ�����ʱ�䳬��15���� */
	REQUEST_TIME_TOO_SKEWED,
	/* ����ʱ */
	REQUEST_TIMEOUT,
	/* ǩ������ */
	SIGNATURE_DOES_NOT_MATCH,
	/* �û��� Bucket ��Ŀ�������� */
	TOO_MANY_BUCKETS,
	/* �ļ������� */
	FILE_PART_INTERITY,
	/* �ļ��Ҳ��� */
	FILE_NOT_FOUND,
	/* û�б��޸� */
	NOT_MODIFIED,
	/* �ļ����� */
	FILE_TOO_LARGE,
	/* IO ���� */
	IO_ERROR,
	/* �������Ӵ��� */
	NETWORK_NOT_AVAILABLE, 

	OSSCLIB_INTERNAL_ERROR,
	NGINX_NOT_AVAILABLE, 
}OSS_ERROR_CODE;

typedef enum _OSS_PERMISSION {
	FULLCONTROL,
	READ
}OSS_PERMISSION;

#define DEFAULT_OSS_HOST            "oss.aliyuncs.com"
#define VERSION                     "0.1.6"
#define NAME                        "OSS-C-SDK"

#define OSS_BUCKET                  "bucket"
#define OSS_OBJECT                  "object"
#define OSS_HEADERS                 "headers"
#define OSS_METHOD                  "method"
#define OSS_QUERY                   "query"
#define OSS_BASENAME                "basename"
#define OSS_MAX_KEYS                "max-keys"
#define OSS_UPLOAD_ID               "uploadId"
#define OSS_MAX_KEYS_VALUE          100
#define OSS_MAX_OBJECT_GROUP_VALUE  1000
#define OSS_FILE_SLICE_SIZE         8192
#define OSS_PREFIX                  "prefix"
#define OSS_DELIMITER               "delimiter"
#define OSS_MARKER                  "marker"
#define OSS_CONTENT_MD5             "Content-Md5"
#define OSS_CONTENT_TYPE            "Content-Type"
#define OSS_CONTENT_LENGTH          "Content-Length"
#define OSS_IF_MODIFIED_SINCE       "If-Modified-Since"
#define OSS_IF_UNMODIFIED_SINCE     "If-Unmodified-Since"
#define OSS_IF_MATCH                "If-Match"
#define OSS_IF_NONE_MATCH           "If-None-Match"
#define OSS_CACHE_CONTROL           "Cache-Control"
#define OSS_EXPIRES                 "Expires"
#define OSS_PREAUTH                 "preauth"
#define OSS_CONTENT_ENCOING         "Content-Encoding"
#define OSS_CONTENT_DISPOSITION     "Content-Disposition"
#define OSS_RANGE                   "Range"
#define OS_CONTENT_RANGE            "Content-Range"
#define OSS_CONTENT                 "content"
#define OSS_BODY                    "body"
#define OSS_LENGTH                  "length"
#define OSS_HOST                    "Host"
#define OSS_DATE                    "Date"
#define OSS_AUTHORIZATION           "Authorization"
#define OSS_LAST_MODIFIED           "Last-Modified"

#define OSS_FILE_DOWNLOAD           "fileDownload"
#define OSS_FILE_UPLOAD             "fileUpload"
#define OSS_PART_SIZE               "partSize"
#define OSS_SEEK_TO                 "seekTo"
#define OSS_SIZE                    "size"
#define OSS_QUERY_STRING            "query_string"
#define OSS_SUB_RESOURCE            "sub_resource"
#define OSS_DEFAULT_PREFIX          "x-oss-"

#define OSS_URL_ACCESS_KEY_ID  "OSSAccessKeyId"
#define OSS_URL_EXPIRES        "Expires"
#define OSS_URL_SIGNATURE      "Signature"

//HTTP����
#define OSS_HTTP_GET     "GET"
#define OSS_HTTP_PUT     "PUT"
#define OSS_HTTP_HEAD    "HEAD"
#define OSS_HTTP_POST    "POST"
#define OSS_HTTP_DELETE  "DELETE"

//��������
#define OSS_ACL                         "x-oss-acl"
#define OSS_OBJECT_GROUP                "x-oss-file-group"
#define OSS_COPY_SOURCE					"x-oss-copy-source"
#define OSS_MULTI_PART                  "uploads"
#define OSS_MULTI_DELETE                "delete"
#define OSS_OBJECT_COPY_SOURCE          "x-oss-copy-source"
#define OSS_ACL_TYPE_PRIVATE            "private"
#define OSS_ACL_TYPE_PUBLIC_READ        "public-read"
#define OSS_ACL_TYPE_PUBLIC_READ_WRITE  "public-read-write"

//ResponseHeaderOverrides
#define RESPONSE_HEADER_CACHE_CONTROL        "RESPONSE_HEADER_CACHE_CONTROL"
#define RESPONSE_HEADER_CONTENT_DISPOSITION  "RESPONSE_HEADER_CONTENT_DISPOSITION"
#define RESPONSE_HEADER_CONTENT_ENCODING     "RESPONSE_HEADER_CONTENT_ENCODING"
#define RESPONSE_HEADER_CONTENT_LANGUAGE     "RESPONSE_HEADER_CONTENT_LANGUAGE"
#define RESPONSE_HEADER_CONTENT_TYPE         "RESPONSE_HEADER_CONTENT_TYPE"
#define RESPONSE_HEADER_EXPIRES              "RESPONSE_HEADER_EXPIRES"
//
//���ͻ����������ջ�������ͷ����������С
#define MAX_SEND_BUFFER_SIZE			(2 * 1024 * 1024)
#define MAX_RECV_BUFFER_SIZE			(2 * 1024 * 1024)
#define MAX_HEADER_BUFFER_SIZE			(128 * 1024)

#endif // OSS_CONSTANTS_H

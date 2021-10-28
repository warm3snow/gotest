/* ====================================================================
 * Copyright (c) 2015 - 2016 The GmSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the GmSSL Project.
 *    (http://gmssl.org/)"
 *
 * 4. The name "GmSSL Project" must not be used to endorse or promote
 *    products derived from this software without prior written
 *    permission. For written permission, please contact
 *    guanzhi1980@gmail.com.
 *
 * 5. Products derived from this software may not be called "GmSSL"
 *    nor may "GmSSL" appear in their names without prior written
 *    permission of the GmSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the GmSSL Project
 *    (http://gmssl.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE GmSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE GmSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 */

#ifndef HEADER_GMSDF_H
#define HEADER_GMSDF_H

#include <openssl/opensslconf.h>
#ifndef OPENSSL_NO_SDF

#include <stdio.h>
#include <openssl/sgd.h>
#include <openssl/sdf.h>
#include <openssl/bio.h>

#define SDF_MIN_KEY_INDEX	  1 /* defined by GM/T 0018 */
#define SDF_MAX_KEY_INDEX	 32 /* defined by GmSSL */
#define SDF_MIN_PASSWORD_LENGTH	  8 /* defined by GM/T 0018 */
#define SDF_MAX_PASSWORD_LENGTH	255 /* defined by GmSSL */
#define SDF_MAX_FILE_SIZE	(256 * 1024)

#ifdef __cplusplus
extern "C" {
#endif

int SDF_LoadLibrary(char *so_path, char *vendor);
int SDF_UnloadLibrary(void);
int SDF_ImportKey(void *hSessionHandle, unsigned char *pucKey,
	unsigned int uiKeyLength, void **phKeyHandle);

int SDF_PrintDeviceInfo(BIO *out, DEVICEINFO *devInfo);
int SDF_PrintRSAPublicKey(BIO *out, RSArefPublicKey *ref);
int SDF_PrintRSAPrivateKey(BIO *out, RSArefPrivateKey *ref);
int SDF_PrintECCPublicKey(BIO *out, ECCrefPublicKey *ref);
int SDF_PrintECCPrivateKey(BIO *out, ECCrefPrivateKey *ref);
int SDF_NewECCCipher(ECCCipher **cipher, size_t ulDataLen);
int SDF_FreeECCCipher(ECCCipher *cipher);
int SDF_PrintECCCipher(BIO *out, ECCCipher *cipher);
int SDF_PrintECCSignature(BIO *out, ECCSignature *sig);
int SDF_GetErrorString(int err, char **str);


/* BEGIN ERROR CODES */
/*
 * The following lines are auto generated by the script mkerr.pl. Any changes
 * made after this point may be overwritten when the script is next run.
 */

int ERR_load_SDF_strings(void);

/* Error codes for the SDF functions. */

/* Function codes. */
# define SDF_F_SANSEC_DECODE_ECCCIPHER                    100
# define SDF_F_SANSEC_ENCODE_ECCCIPHER                    101
# define SDF_F_SDF_CALCULATEMAC                           102
# define SDF_F_SDF_CLOSEDEVICE                            103
# define SDF_F_SDF_CLOSESESSION                           104
# define SDF_F_SDF_CREATEFILE                             105
# define SDF_F_SDF_DECRYPT                                106
# define SDF_F_SDF_DELETEFILE                             107
# define SDF_F_SDF_DESTROYKEY                             108
# define SDF_F_SDF_ENCRYPT                                109
# define SDF_F_SDF_EXCHANGEDIGITENVELOPEBASEONECC         110
# define SDF_F_SDF_EXCHANGEDIGITENVELOPEBASEONRSA         111
# define SDF_F_SDF_EXPORTENCPUBLICKEY_ECC                 112
# define SDF_F_SDF_EXPORTENCPUBLICKEY_RSA                 113
# define SDF_F_SDF_EXPORTSIGNPUBLICKEY_ECC                114
# define SDF_F_SDF_EXPORTSIGNPUBLICKEY_RSA                115
# define SDF_F_SDF_EXTERNALENCRYPT_ECC                    116
# define SDF_F_SDF_EXTERNALPUBLICKEYOPERATION_RSA         117
# define SDF_F_SDF_EXTERNALVERIFY_ECC                     118
# define SDF_F_SDF_GENERATEAGREEMENTDATAANDKEYWITHECC     119
# define SDF_F_SDF_GENERATEAGREEMENTDATAWITHECC           120
# define SDF_F_SDF_GENERATEKEYPAIR_ECC                    121
# define SDF_F_SDF_GENERATEKEYPAIR_RSA                    122
# define SDF_F_SDF_GENERATEKEYWITHECC                     123
# define SDF_F_SDF_GENERATEKEYWITHEPK_ECC                 124
# define SDF_F_SDF_GENERATEKEYWITHEPK_RSA                 125
# define SDF_F_SDF_GENERATEKEYWITHIPK_ECC                 126
# define SDF_F_SDF_GENERATEKEYWITHIPK_RSA                 127
# define SDF_F_SDF_GENERATEKEYWITHKEK                     128
# define SDF_F_SDF_GENERATERANDOM                         129
# define SDF_F_SDF_GETDEVICEINFO                          130
# define SDF_F_SDF_GETPRIVATEKEYACCESSRIGHT               131
# define SDF_F_SDF_HASHFINAL                              132
# define SDF_F_SDF_HASHINIT                               133
# define SDF_F_SDF_HASHUPDATE                             134
# define SDF_F_SDF_IMPORTKEY                              135
# define SDF_F_SDF_IMPORTKEYWITHISK_ECC                   136
# define SDF_F_SDF_IMPORTKEYWITHISK_RSA                   137
# define SDF_F_SDF_IMPORTKEYWITHKEK                       138
# define SDF_F_SDF_INTERNALDECRYPT_ECC                    139
# define SDF_F_SDF_INTERNALENCRYPT_ECC                    140
# define SDF_F_SDF_INTERNALPRIVATEKEYOPERATION_RSA        141
# define SDF_F_SDF_INTERNALPUBLICKEYOPERATION_RSA         142
# define SDF_F_SDF_INTERNALSIGN_ECC                       143
# define SDF_F_SDF_INTERNALVERIFY_ECC                     144
# define SDF_F_SDF_LOADLIBRARY                            145
# define SDF_F_SDF_METHOD_LOAD_LIBRARY                    146
# define SDF_F_SDF_NEWECCCIPHER                           147
# define SDF_F_SDF_OPENDEVICE                             148
# define SDF_F_SDF_OPENSESSION                            149
# define SDF_F_SDF_READFILE                               150
# define SDF_F_SDF_RELEASEPRIVATEKEYACCESSRIGHT           151
# define SDF_F_SDF_WRITEFILE                              152

/* Reason codes. */
# define SDF_R_ALGORITHM_MODE_NOT_SUPPORTED               100
# define SDF_R_ALGORITHM_NOT_SUPPORTED                    101
# define SDF_R_BUFFER_TOO_SMALL                           102
# define SDF_R_COMMUNICATION_FAILURE                      103
# define SDF_R_DSO_LOAD_FAILURE                           104
# define SDF_R_ENCRYPT_DATA_ERROR                         105
# define SDF_R_ERROR                                      106
# define SDF_R_FILE_ALREADY_EXIST                         107
# define SDF_R_FILE_NOT_EXIST                             108
# define SDF_R_HARDWARE_ERROR                             109
# define SDF_R_INVALID_FILE_OFFSET                        110
# define SDF_R_INVALID_FILE_SIZE                          111
# define SDF_R_INVALID_INPUT_ARGUMENT                     112
# define SDF_R_INVALID_KEY                                113
# define SDF_R_INVALID_KEY_TYPE                           114
# define SDF_R_INVALID_OUTPUT_ARGUMENT                    115
# define SDF_R_INVALID_SANSEC_ECCCIPHER_LENGTH            116
# define SDF_R_INVALID_SM2_CIPHERTEXT_LENGTH              117
# define SDF_R_KEY_NOT_EXIST                              118
# define SDF_R_LOAD_LIBRARY_FAILURE                       119
# define SDF_R_MAC_ERROR                                  120
# define SDF_R_MULTI_STEP_OPERATION_ERROR                 121
# define SDF_R_NOT_IMPLEMENTED                            122
# define SDF_R_NOT_INITIALIZED                            123
# define SDF_R_NOT_SUPPORTED_CIPHER_ALGOR                 124
# define SDF_R_NOT_SUPPORTED_DIGEST_ALGOR                 125
# define SDF_R_NOT_SUPPORTED_ECC_ALGOR                    126
# define SDF_R_NOT_SUPPORTED_PKEY_ALGOR                   127
# define SDF_R_NO_PRIVATE_KEY_ACCESS_RIGHT                128
# define SDF_R_OPEN_DEVICE_FAILURE                        129
# define SDF_R_OPEN_SESSION_FAILURE                       130
# define SDF_R_OPERATION_NOT_SUPPORTED                    131
# define SDF_R_PRIVATE_KEY_OPERATION_FAILURE              132
# define SDF_R_PRKERR                                     133
# define SDF_R_PUBLIC_KEY_OPERATION_FAILURE               134
# define SDF_R_RANDOM_GENERATION_ERROR                    135
# define SDF_R_SANSEC_BASE                                136
# define SDF_R_SANSEC_CARD_ALGOR_NOT_SUPPORTED            137
# define SDF_R_SANSEC_CARD_ALG_MODE_NOT_SUPPORTED         138
# define SDF_R_SANSEC_CARD_BASE                           139
# define SDF_R_SANSEC_CARD_BUFFER_TOO_SMALL               140
# define SDF_R_SANSEC_CARD_COMMMUCATION_FAILED            141
# define SDF_R_SANSEC_CARD_CRYPTO_NOT_INITED              142
# define SDF_R_SANSEC_CARD_DATA_PADDING_ERROR             143
# define SDF_R_SANSEC_CARD_DATA_SIZE                      144
# define SDF_R_SANSEC_CARD_DEVICE_STATUS_ERROR            145
# define SDF_R_SANSEC_CARD_DEVICE_STATUS_ERROR_05         146
# define SDF_R_SANSEC_CARD_FILE_NOT_EXIST                 147
# define SDF_R_SANSEC_CARD_FILE_OFFSET_ERROR              148
# define SDF_R_SANSEC_CARD_FILE_SIZE_ERROR                149
# define SDF_R_SANSEC_CARD_HARDWARE_FAILURE               150
# define SDF_R_SANSEC_CARD_KEY_ERROR                      151
# define SDF_R_SANSEC_CARD_KEY_NOT_EXIST                  152
# define SDF_R_SANSEC_CARD_KEY_TYPE_ERROR                 153
# define SDF_R_SANSEC_CARD_LOGIN_ERROR                    154
# define SDF_R_SANSEC_CARD_LOGIN_ERROR_05                 155
# define SDF_R_SANSEC_CARD_MANAGEMENT_DENYED              156
# define SDF_R_SANSEC_CARD_MANAGEMENT_DENYED_05           157
# define SDF_R_SANSEC_CARD_NOT_SUPPORTED                  158
# define SDF_R_SANSEC_CARD_OPEN_DEVICE_FAILED             159
# define SDF_R_SANSEC_CARD_OPEN_SESSION_FAILED            160
# define SDF_R_SANSEC_CARD_OPERATION_DENYED               161
# define SDF_R_SANSEC_CARD_OPERATION_DENYED_05            162
# define SDF_R_SANSEC_CARD_PARAMENT_ERROR                 163
# define SDF_R_SANSEC_CARD_PARAMENT_ERROR_05              164
# define SDF_R_SANSEC_CARD_PRIVATE_KEY_ACCESS_DENYED      165
# define SDF_R_SANSEC_CARD_PRIVATE_KEY_OPERATION_ERROR    166
# define SDF_R_SANSEC_CARD_PUBLIC_KEY_OPERATION_ERROR     167
# define SDF_R_SANSEC_CARD_READER_BASE                    168
# define SDF_R_SANSEC_CARD_READER_CARD_INSERT             169
# define SDF_R_SANSEC_CARD_READER_CARD_INSERT_TYPE        170
# define SDF_R_SANSEC_CARD_READER_NO_CARD                 171
# define SDF_R_SANSEC_CARD_READER_PIN_ERROR               172
# define SDF_R_SANSEC_CARD_SIGN_ERROR                     173
# define SDF_R_SANSEC_CARD_STEP_ERROR                     174
# define SDF_R_SANSEC_CARD_SYMMETRIC_ALGOR_ERROR          175
# define SDF_R_SANSEC_CARD_UNKNOW_ERROR                   176
# define SDF_R_SANSEC_CARD_USERID_ERROR                   177
# define SDF_R_SANSEC_CARD_USERID_ERROR_05                178
# define SDF_R_SANSEC_CARD_VERIFY_ERROR                   179
# define SDF_R_SANSEC_CONFIG_ERROR                        180
# define SDF_R_SANSEC_CONNECT_ERROR                       181
# define SDF_R_SANSEC_FILE_ALREADY_EXIST                  182
# define SDF_R_SANSEC_INVALID_AUTHENCODE                  183
# define SDF_R_SANSEC_INVALID_COMMAND                     184
# define SDF_R_SANSEC_INVALID_PARAMETERS                  185
# define SDF_R_SANSEC_INVALID_USER                        186
# define SDF_R_SANSEC_NO_AVAILABLE_CSM                    187
# define SDF_R_SANSEC_NO_AVAILABLE_HSM                    188
# define SDF_R_SANSEC_PROTOCOL_VERSION_ERROR              189
# define SDF_R_SANSEC_SEM_TIMEOUT                         190
# define SDF_R_SANSEC_SET_SOCKET_OPTION_ERROR             191
# define SDF_R_SANSEC_SOCKET_RECV_0                       192
# define SDF_R_SANSEC_SOCKET_RECV_ERROR                   193
# define SDF_R_SANSEC_SOCKET_SEND_ERROR                   194
# define SDF_R_SANSEC_SOCKET_TIMEOUT                      195
# define SDF_R_SANSEC_SYNC_ERROR                          196
# define SDF_R_SANSEC_SYNC_LOGIN_ERROR                    197
# define SDF_R_SIGNING_FAILURE                            198
# define SDF_R_SUCCESS                                    199
# define SDF_R_SYMMETRIC_OPERATION_FAILURE                200
# define SDF_R_UNNOWN_ERROR                               201
# define SDF_R_VERIFICATION_FAILURE                       202
# define SDF_R_WRITE_FILE_FAILURE                         203

#  ifdef  __cplusplus
}
#  endif
# endif
#endif
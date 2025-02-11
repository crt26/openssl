/*
 * Copyright 2017-2018 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <oqs/oqs.h>

/*
 * Certificate table information. NB: table entries must match SSL_PKEY indices
 */
static const SSL_CERT_LOOKUP ssl_cert_info [] = {
    {EVP_PKEY_RSA, SSL_aRSA}, /* SSL_PKEY_RSA */
    {EVP_PKEY_RSA_PSS, SSL_aRSA}, /* SSL_PKEY_RSA_PSS_SIGN */
    {EVP_PKEY_DSA, SSL_aDSS}, /* SSL_PKEY_DSA_SIGN */
    {EVP_PKEY_EC, SSL_aECDSA}, /* SSL_PKEY_ECC */
    {NID_id_GostR3410_2001, SSL_aGOST01}, /* SSL_PKEY_GOST01 */
    {NID_id_GostR3410_2012_256, SSL_aGOST12}, /* SSL_PKEY_GOST12_256 */
    {NID_id_GostR3410_2012_512, SSL_aGOST12}, /* SSL_PKEY_GOST12_512 */
    {EVP_PKEY_ED25519, SSL_aECDSA}, /* SSL_PKEY_ED25519 */
    {EVP_PKEY_ED448, SSL_aECDSA}, /* SSL_PKEY_ED448 */
///// OQS_TEMPLATE_FRAGMENT_GIVE_SSL_CERT_INFO_START
    {EVP_PKEY_DILITHIUM2, SSL_aDILITHIUM2}, /* SSL_PKEY_DILITHIUM2 */
    {EVP_PKEY_P256_DILITHIUM2, SSL_aP256_DILITHIUM2}, /* SSL_PKEY_P256_DILITHIUM2 */
    {EVP_PKEY_RSA3072_DILITHIUM2, SSL_aRSA3072_DILITHIUM2}, /* SSL_PKEY_RSA3072_DILITHIUM2 */
    {EVP_PKEY_DILITHIUM3, SSL_aDILITHIUM3}, /* SSL_PKEY_DILITHIUM3 */
    {EVP_PKEY_P384_DILITHIUM3, SSL_aP384_DILITHIUM3}, /* SSL_PKEY_P384_DILITHIUM3 */
    {EVP_PKEY_DILITHIUM5, SSL_aDILITHIUM5}, /* SSL_PKEY_DILITHIUM5 */
    {EVP_PKEY_P521_DILITHIUM5, SSL_aP521_DILITHIUM5}, /* SSL_PKEY_P521_DILITHIUM5 */
    {EVP_PKEY_FALCON512, SSL_aFALCON512}, /* SSL_PKEY_FALCON512 */
    {EVP_PKEY_P256_FALCON512, SSL_aP256_FALCON512}, /* SSL_PKEY_P256_FALCON512 */
    {EVP_PKEY_RSA3072_FALCON512, SSL_aRSA3072_FALCON512}, /* SSL_PKEY_RSA3072_FALCON512 */
    {EVP_PKEY_FALCON1024, SSL_aFALCON1024}, /* SSL_PKEY_FALCON1024 */
    {EVP_PKEY_P521_FALCON1024, SSL_aP521_FALCON1024}, /* SSL_PKEY_P521_FALCON1024 */
    {EVP_PKEY_SPHINCSSHA2128FSIMPLE, SSL_aSPHINCSSHA2128FSIMPLE}, /* SSL_PKEY_SPHINCSSHA2128FSIMPLE */
    {EVP_PKEY_P256_SPHINCSSHA2128FSIMPLE, SSL_aP256_SPHINCSSHA2128FSIMPLE}, /* SSL_PKEY_P256_SPHINCSSHA2128FSIMPLE */
    {EVP_PKEY_RSA3072_SPHINCSSHA2128FSIMPLE, SSL_aRSA3072_SPHINCSSHA2128FSIMPLE}, /* SSL_PKEY_RSA3072_SPHINCSSHA2128FSIMPLE */
    {EVP_PKEY_SPHINCSSHA2128SSIMPLE, SSL_aSPHINCSSHA2128SSIMPLE}, /* SSL_PKEY_SPHINCSSHA2128SSIMPLE */
    {EVP_PKEY_P256_SPHINCSSHA2128SSIMPLE, SSL_aP256_SPHINCSSHA2128SSIMPLE}, /* SSL_PKEY_P256_SPHINCSSHA2128SSIMPLE */
    {EVP_PKEY_RSA3072_SPHINCSSHA2128SSIMPLE, SSL_aRSA3072_SPHINCSSHA2128SSIMPLE}, /* SSL_PKEY_RSA3072_SPHINCSSHA2128SSIMPLE */
    {EVP_PKEY_SPHINCSSHA2192FSIMPLE, SSL_aSPHINCSSHA2192FSIMPLE}, /* SSL_PKEY_SPHINCSSHA2192FSIMPLE */
    {EVP_PKEY_P384_SPHINCSSHA2192FSIMPLE, SSL_aP384_SPHINCSSHA2192FSIMPLE}, /* SSL_PKEY_P384_SPHINCSSHA2192FSIMPLE */
    {EVP_PKEY_SPHINCSSHAKE128FSIMPLE, SSL_aSPHINCSSHAKE128FSIMPLE}, /* SSL_PKEY_SPHINCSSHAKE128FSIMPLE */
    {EVP_PKEY_P256_SPHINCSSHAKE128FSIMPLE, SSL_aP256_SPHINCSSHAKE128FSIMPLE}, /* SSL_PKEY_P256_SPHINCSSHAKE128FSIMPLE */
    {EVP_PKEY_RSA3072_SPHINCSSHAKE128FSIMPLE, SSL_aRSA3072_SPHINCSSHAKE128FSIMPLE}, /* SSL_PKEY_RSA3072_SPHINCSSHAKE128FSIMPLE */
///// OQS_TEMPLATE_FRAGMENT_GIVE_SSL_CERT_INFO_END
};

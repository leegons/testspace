#include <string>
#include <memory>
#include <iostream>
#include <assert.h>
#include <openssl/evp.h>
#include <openssl/hmac.h>

int main() {

    std::string str = "testOpenssl";

    EVP_MD_CTX mdctx;
    EVP_MD_CTX_init(&mdctx);

    unsigned char mdValue[EVP_MAX_MD_SIZE] = {0};
    unsigned int mdLen = 0;

    const EVP_MD* md = EVP_sha256();
    assert(md != nullptr);
    EVP_DigestInit_ex(&mdctx, md, nullptr);
    EVP_DigestUpdate(&mdctx, str.c_str(), str.size());
    EVP_DigestFinal_ex(&mdctx, mdValue, &mdLen);
    EVP_MD_CTX_cleanup(&mdctx);

    printf("sha256(%s) is ", str.c_str());
    for (int i = 0; i < mdLen; ++i) {
        printf("%02X", mdValue[i]);
    }
    printf("\n");

    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */

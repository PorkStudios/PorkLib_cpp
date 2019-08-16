#include "sha1.h"

using namespace porklib::crypto::digest;

#ifdef DSI

extern void swiSHA1InitTWL(swiSHA1context_t* ctx);
extern void swiSHA1UpdateTWL(swiSHA1context_t* ctx, const void* data, size_t len);
extern void swiSHA1FinalTWL(void* digest, swiSHA1context_t* ctx);
extern void swiSHA1CalcTWL(void* digest, const void* data, size_t len);
extern void swiSHA1VerifyTWL(const void* digest1, const void* digest2);

void SHA1::init() {
    swiSHA1Init(&this->context);
}

void SHA1::update(const void* data, size_t length) {
    swiSHA1Update(&this->context, data, length);
}

void SHA1::finish() {
    swiSHA1Final(&this->hash, &this->context);
}
#else

void SHA1::init() final {
    this->buf[0] = 0x67452301;
    this->buf[1] = 0xEFCDAB89;
    this->buf[2] = 0x98BADCFE;
    this->buf[3] = 0x10325476;
    this->buf[4] = 0x67452301;
}

void SHA1::update(u8* data, size_t length) final {
}

void SHA1::finish() final {
}

#endif

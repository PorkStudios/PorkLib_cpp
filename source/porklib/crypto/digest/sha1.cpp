#include "sha1.h"

using namespace porklib::crypto::digest;

#ifdef DSI
void swiSHA1InitTWL(swiSHA1context_t* ctx);
void swiSHA1UpdateTWL(swiSHA1context_t* ctx, const void* data, size_t len);
void swiSHA1FinalTWL(void* digest, swiSHA1context_t* ctx);
void swiSHA1CalcTWL(void* digest, const void* data, size_t len);
void swiSHA1VerifyTWL(const void* digest1, const void* digest2);

virtual inline void SHA1::init() final {
    swiSHA1InitTWL(&this->context);
}

inline void SHA1::update(const void* data, size_t length) final {
    swiSHA1UpdateTWL(&this->context, data, length);
}

inline void SHA1::finish() final {
    swiSHA1FinalTWL(&this->hash, &this->context);
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

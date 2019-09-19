#ifndef PORKLIB_CPP_DIGEST_H
#define PORKLIB_CPP_DIGEST_H

#include "porklib/common/common.h"
#include "porklib/encoding/encoding.h"

namespace porklib::crypto {
    struct Digest {
        Digest() = default;
        virtual ~Digest() = 0;

        virtual void init() = 0;
        virtual void update(const void* data, size_t length) = 0;
        virtual void finish() = 0;
        virtual size_t size() = 0;
    };

    //Digest* createDigest(const char* name);
    //Digest* createDigest(char* name);
}

//implementations
#include "digest/sha1.h"

#endif //PORKLIB_CPP_DIGEST_H

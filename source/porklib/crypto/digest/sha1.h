#ifndef PORKLIB_CPP_SHA1_H
#define PORKLIB_CPP_SHA1_H

#include "porklib/crypto/digest.h"

#ifdef NDS
#ifdef DSI
#include <nds/sha1.h>
#else
#error SHA1 not supported on DS lite!
#endif
#endif

namespace porklib::crypto::digest {
    struct SHA1 final:
    #ifdef DSI
            Digest<20> {
        swiSHA1context_t context = swiSHA1context();
        #else
        BlockDigest<20, u32, 5> {
        u64 ml;
        #endif

        SHA1() = default;
        ~SHA1() final = default;

        virtual void init() final;
        virtual void update(const void* data, size_t length) final;
        virtual void finish() final;
    };
}

#endif //PORKLIB_CPP_SHA1_H

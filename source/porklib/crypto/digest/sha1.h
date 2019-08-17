#ifndef PORKLIB_CPP_SHA1_H
#define PORKLIB_CPP_SHA1_H

#include "../digest.h"

#ifdef NDS
#ifdef DSI
//#include <nds/sha1.h>
#else
#error SHA1 not supported on DS lite!
#endif
#endif

namespace porklib::crypto::digest {
    #ifdef DSI
    struct nds_SHA1context final {
        u32 state[5];
        u32 total[2];
        u8  buffer[64];
        u32 fragment_size;
        void (*sha_block)(struct nds_SHA1context *ctx, const void *src, size_t len);
    };
    #endif

    struct SHA1 final: Digest<20> {
        #ifdef DSI
        //swiSHA1context_t context = swiSHA1context();
        nds_SHA1context context = nds_SHA1context();
        #else
        u64 ml;
        #endif

        SHA1() = default;
        ~SHA1() final = default;

        void init() final;
        void update(const void* data, size_t length) final;
        void finish() final;
    };
}

#endif //PORKLIB_CPP_SHA1_H

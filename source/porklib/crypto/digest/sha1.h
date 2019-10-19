#ifndef PORKLIB_CPP_SHA1_H
#define PORKLIB_CPP_SHA1_H

#if NDS && !DSI
#error SHA1 not supported on DS lite!
#endif

#include <porklib/crypto/digest.h>
#include <porklib/math/math.h>

namespace porklib::crypto::digest {
    #ifdef DSI
    struct nds_SHA1context final {
        u32 state[5];
        u32 total[2];
        u8 buffer[64];
        u32 fragment_size;
        void (* sha_block)(struct nds_SHA1context* ctx, const void* src, size_t len);
    };
    #endif

    struct SHA1: Digest {
        #ifdef DSI
        nds_SHA1context context = nds_SHA1context();

        void init() final;
        void update(const void* data, u_size length) final;
        void finish(void* dst) final;
        #else
        u32 h[5];
        u64 ml;
        u8 buffer[64];
        uword fragment_size;

        void init() final {
            this->h[0] = 0x67452301;
            this->h[1] = 0xEFCDAB89;
            this->h[2] = 0x98BADCFE;
            this->h[3] = 0x10325476;
            this->h[4] = 0xC3D2E1F0;
            this->ml = 0;
            this->fragment_size = 0;
        }

        void update(const void* data, u_size length) final {
            //TODO: implement this
            this->ml += length * 8;
            uword fragment_size = this->fragment_size;
            if (fragment_size != 0 && fragment_size + length >= 0x40)   {
                length -= fragment_size;
                porklib::copy(data, &this->buffer[fragment_size], 0x40 - fragment_size);
                data += fragment_size;
                fragment_size = 0;
            }
        }

        void sha1_round(const u8* data, u_size length) {
            for (uword j = length >> 6; j--;)   {
                u32 w[80];
                copy(data, &w, 64);
                for (uword i = 16; i < 80; i++) {
                    w[i] = math::rol(w[i - 3] ^ w[i - 8] ^ w[i - 14] ^ w[i - 16], (u32) 1);
                }

                u32 a = this->h[0];
                u32 b = this->h[1];
                u32 c = this->h[2];
                u32 d = this->h[3];
                u32 e = this->h[4];
                for (uword i = 0; i < 80; i++)    {
                    if (i <= 19)    {

                    }
                }
            }
        }

        void finish(void* dst) final {
        }
        #endif

        u_size size() final { return 20; }

        SHA1() = default;
        ~SHA1() = default;
    };
}

#endif //PORKLIB_CPP_SHA1_H

#ifndef PORKLIB_CPP_DIGEST_H
#define PORKLIB_CPP_DIGEST_H

#include "porklib/common/common.h"

namespace porklib::crypto {
    template<size_t SIZE>
    struct Digest {
        u8 hash[SIZE] = {0};

        Digest() = default;
        virtual ~Digest() = default;

        virtual void init() = 0;
        virtual void update(const void* data, size_t length) = 0;
        virtual void finish() = 0;

        char* asHex() {
            static const char* hex = "0123456789abcdef";

            auto text = new char[SIZE * 2 + 1];
            for (size_t i = SIZE; i--;) {
                u8 val = this->hash[i];
                text[i << 1] = hex[val & 0xF];
                text[(i << 1) + 1] = hex[val >> 4];
            }
            return text;
        };

        inline size_t size() { return SIZE; };
    };

    template<size_t SIZE, typename BLOCK_TYPE, size_t BLOCK_SIZE>
    struct BlockDigest: Digest<SIZE> {
        BLOCK_TYPE buf[BLOCK_SIZE];

        BlockDigest() = default;
        virtual ~BlockDigest() = 0;
    };

    //Digest* createDigest(const char* name);
    //Digest* createDigest(char* name);
}

#endif //PORKLIB_CPP_DIGEST_H

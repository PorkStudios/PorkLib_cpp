#ifndef PORKLIB_CPP_DIGEST_H
#define PORKLIB_CPP_DIGEST_H

#include "porklib/common/common.h"
#include "porklib/encoding/encoding.h"

namespace porklib::crypto {
    template<size_t SIZE>
    struct Digest {
        u8 hash[SIZE] = {0};

        Digest() = default;
        virtual ~Digest() = default;

        virtual void init() = 0;
        virtual void update(const void* data, size_t length) = 0;
        virtual void finish() = 0;

        const char* asHex() {
            return encoding::toHex(SIZE, this->hash);
        }

        inline size_t size() { return SIZE; };
    };

    //Digest* createDigest(const char* name);
    //Digest* createDigest(char* name);
}

#endif //PORKLIB_CPP_DIGEST_H

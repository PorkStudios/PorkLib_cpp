#ifndef PORKLIB_CPP_DIGEST_H
#define PORKLIB_CPP_DIGEST_H

#include <porklib/binary/binary.h>

namespace porklib::crypto {
    struct Digest {
        Digest() = default;
        virtual ~Digest() = default;

        virtual void init() = 0;
        virtual void update(const void* data, u_size length) = 0;
        virtual void finish(void* dst) = 0;
        virtual u_size size() = 0;
    };

    //Digest* createDigest(const char* name);
    //Digest* createDigest(char* name);
}

#endif //PORKLIB_CPP_DIGEST_H

#ifndef PORKLIB_CPP_DIGEST_H
#define PORKLIB_CPP_DIGEST_H

#include "porklib/common/common.h"

namespace porklib::crypto {
    template<size_t SIZE>
    struct Digest {
        const size_t size = SIZE;
        char hash[SIZE];

        virtual Digest() = 0;
        virtual ~Digest() = 0;

        virtual void init() = 0;

        virtual void update(char(& block)[SIZE]) = 0;
        virtual void update(char(* block)[SIZE]) = 0;

        virtual void finish() = 0;

        virtual void get(char(& out)[SIZE]) = 0;
        virtual void get(char(* out)[SIZE]) = 0;
        virtual char* get() { return this->hash; }
    };

    Digest* createDigest(const char* name);
    Digest* createDigest(char* name);
}

#endif //PORKLIB_CPP_DIGEST_H

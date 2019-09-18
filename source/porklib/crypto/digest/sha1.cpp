#include "sha1.h"

namespace porklib::crypto::digest {
#ifdef DSI
#if false
    __attribute__((fastcall, noinline)) void swiSHA1Init_asm(nds_SHA1context* ctx) { __asm("swi 0x24"); }

    __attribute__((fastcall, noinline)) void swiSHA1Update_asm(nds_SHA1context* ctx, const void* data, size_t len) { __asm("swi 0x25"); }

    __attribute__((fastcall, noinline)) void swiSHA1Final_asm(void* digest, nds_SHA1context* ctx) { __asm("swi 0x26"); }

    __attribute__((fastcall, noinline)) void swiSHA1Calc_asm(void* digest, const void* data, size_t len) { __asm("swi 0x27"); }

    __attribute__((fastcall, noinline)) void swiSHA1Verify_asm(const void* digest1, const void* digest2) { __asm("swi 0x28"); }
#else
    __attribute__((noinline)) void swiSHA1Init_asm(nds_SHA1context* ctx) { __asm("swi 0x24"); }

    __attribute__((noinline)) void swiSHA1Update_asm(nds_SHA1context* ctx, const void* data, size_t len) { __asm("swi 0x25"); }

    __attribute__((noinline)) void swiSHA1Final_asm(void* digest, nds_SHA1context* ctx) { __asm("swi 0x26"); }

    __attribute__((noinline)) void swiSHA1Calc_asm(void* digest, const void* data, size_t len) { __asm("swi 0x27"); }

    __attribute__((noinline)) void swiSHA1Verify_asm(const void* digest1, const void* digest2) { __asm("swi 0x28"); }
#endif

    void SHA1::init() {
        swiSHA1Init_asm(&this->context);
        /*nds_SHA1context* s_context = &this->context;
        register nds_SHA1context* r_context asm("r0") = s_context;
        asm volatile(
        "swi 0x24"
        :
        : "r" (r_context)
        );*/
    }

    void SHA1::update(const void* data, size_t length) {
        swiSHA1Update_asm(&this->context, data, length);
        /*nds_SHA1context* s_context = &this->context;
        const void* s_data = data;
        size_t s_length = length;
        register nds_SHA1context* r_context asm("r0") = s_context;
        register const void* r_data asm("r1") = s_data;
        register size_t r_length asm("r2") = s_length;
        asm volatile(
        "swi 0x25"
        :
        : "r" (r_context), "r" (r_data), "r" (r_length)
        );*/
    }

    void SHA1::finish() {
        swiSHA1Final_asm(&this->hash, &this->context);
        /*register void* s_hash asm("r2") = &this->hash;
        register nds_SHA1context* s_context asm("r3") = &this->context;
        register void* r_hash asm("r0") = s_hash;
        register nds_SHA1context* r_context asm("r1") = s_context;
        asm volatile(
        "swi 0x26\n\t"
        "bx lr"
        :
        : "r" (r_hash), "r" (r_context)
        );*/
    }
#else
    void SHA1::init() {
    }
    void SHA1::update(const void* data, size_t length) {
    }
    void SHA1::finish() {
    }
#endif

    size_t SHA1::size() {
        return 20;
    }
}

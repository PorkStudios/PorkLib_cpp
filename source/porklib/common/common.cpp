#include "common.h"

#include <cstdarg>
#include <cstdio>

namespace porklib {
    u_size lengthOf(const char* text) {
        u_size i = 0;
        while (text[i++]);
        return i - 1;
    }

    char* strCopy(const char* original) {
        u_size len = lengthOf(original) + 1;
        char* dst = new char[len];
        copy(original, dst, len);
        return dst;
    }

    const char* fmt(const char* format, ...) {
        va_list args;
        va_start(args, format);
        char* result = new char[snprintf(nullptr, 0, format, args) + 1];
        sprintf(result, format, args);
        return result;
    }

    void zero(void* const ptr, u_size bytes) {
        //TODO: fast assembly implementations for various platforms
        while (bytes--) {
            ((u8* const) ptr)[bytes] = 0;
        }
    }

    void copy(const void* const src, void* const dst, u_size bytes) {
        //TODO: fast assembly implementations for various platforms
        while (bytes--) {
            ((u8* const) dst)[bytes] = ((u8* const) src)[bytes];
        }
    }
}

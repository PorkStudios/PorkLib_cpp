#include "common.h"

#include <cstring>
#include <cstdarg>
#include <cstdio>

namespace porklib {
    word lengthOf(const char* text) {
        word i = 0;
        while (text[i] != 0) {
            i++;
        }
        return i;
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

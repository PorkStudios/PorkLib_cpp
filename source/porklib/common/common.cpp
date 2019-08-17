#include "common.h"

#include <cstring>
#include <cstdarg>
#include <cstdio>

word porklib::lengthOf(const char* text) {
    word i = 0;
    while (text[i] != 0)    {
        i++;
    }
    return i;
}

const char* porklib::fmt(const char* format, ...) {
    va_list args;
    va_start(args, format);
    char *result = new char[snprintf(nullptr, 0, format, args) + 1];
    sprintf(result, format, args);
    return result;
}
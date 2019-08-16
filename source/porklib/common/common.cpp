#include "common.h"

using namespace porklib;

word strlen(const char* text) {
    word i = 0;
    while (text[i] != 0)    {
        i++;
    }
    return i;
}

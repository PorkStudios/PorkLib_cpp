#include "encoding.h"

using namespace porklib::encoding;

static auto HEX = "0123456789abcdef";

const char* porklib::encoding::toHex(u_size size, const u8* input) {
    auto out = new char[(size << 1) + 1];
    out[size << 1] = 0;
    while (size--)  {
        u8 byte = input[size];
        out[size << 1] = HEX[byte >> 4];
        out[(size << 1) + 1] = HEX[byte & 0xF];
    }
    return out;
}

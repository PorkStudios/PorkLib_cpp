#ifndef PORKLIB_CPP_ENCODING_H
#define PORKLIB_CPP_ENCODING_H

#include "porklib/common/common.h"

namespace porklib::encoding {
    /**
     * Encodes the given binary data into hexadecimal.
     * @param size the size (in bytes) of the input data
     * @param input the input data
     * @return a heap pointer to a NUL-terminated hex string. This must be freed once no longer needed!
     */
    const char* toHex(u_size size, const u8* input);
}

#endif //PORKLIB_CPP_ENCODING_H

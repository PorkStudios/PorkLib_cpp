#ifndef PORKLIB_CPP_DEV_COMMON_H
#define PORKLIB_CPP_DEV_COMMON_H

#include "porklib/types.h"

namespace porklib {
    /**
     * Checks whether a type inherits from another type.
     *
     * @tparam B the requested type
     * @tparam T the type to check
     * @param ptr a pointer to an instance of the type to check
     * @return whether or not the type inherits from the other type
     */
    template<typename B, typename T>
    inline bool instanceof(const T* ptr) { return dynamic_cast<const B*>(ptr) != nullptr; };

    /**
     * Computes the length (in chars) of the given text.
     *
     * @param text the text
     * @return the length of the text
     */
    word lengthOf(const char* text);

    /**
     * Formats the given string with the given arguments into a single NUL-terminated output string.
     * @param format the base format
     * @param ... arguments to the formatter
     * @return the formatted, NUL-terminated message. This must be freed once no longer needed!
     */
    const char* fmt(const char* format, ...);
}

#endif //PORKLIB_CPP_DEV_COMMON_H

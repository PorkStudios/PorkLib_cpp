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
    inline bool instanceof(const T* ptr) { return dynamic_cast<const B *>(ptr) != nullptr; };

    /**
     * Computes the length (in chars) of the given text.
     *
     * @param text the text
     * @return the length of the text
     */
    word strlen(const char* text);

    template<typename T, size_t S>
    struct array {
        private:
            size_t length = S;
            T data[S];
        public:
            void fill(T& val) {
                for (size_t i = S; i--;)    {
                    this->data[i] = val;
                }
            }

            T& operator [](size_t i)  {
                return this->data[i];
            }
    };
}

#endif //PORKLIB_CPP_DEV_COMMON_H

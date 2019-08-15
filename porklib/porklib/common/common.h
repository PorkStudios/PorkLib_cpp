#ifndef PORKLIB_CPP_DEV_COMMON_H
#define PORKLIB_CPP_DEV_COMMON_H

#include "porklib/types.h"

/**
 * Checks whether a type inherits from another type.
 *
 * @tparam B the requested type
 * @tparam T the type to check
 * @param ptr a pointer to an instance of the type to check
 * @return whether or not the type inherits from the other type
 */
template<typename B, typename T>
inline bool instanceof(const T* ptr);

/**
 * Computes the length (in chars) of the given text.
 *
 * @param text the text
 * @return the length of the text
 */
word strlen(const char* text);

template<size_t N> struct _unroll_uint_ {
};

template<size_t N, typename Callback, typename IterT>
inline void unroll(const Callback &f, const IterT &iter, _unroll_uint_<N>);

#endif //PORKLIB_CPP_DEV_COMMON_H

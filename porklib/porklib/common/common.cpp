#include "common.h"

template<typename B, typename T>
inline bool instanceof(const T *ptr) {
    return dynamic_cast<const B *>(ptr) != nullptr;
}

word strlen(const char* text) {
    word i = 0;
    while (text[i] != 0)    {
        i++;
    }
    return i;
}

template <size_t N, typename Callback, typename IterT>
inline void unroll(const Callback& f, const IterT& iter, _unroll_uint_<N>) {
    unroll(f, iter, _unroll_uint_<N-1>());
    f(iter + N);
}

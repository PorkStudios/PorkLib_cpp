#ifndef PORKLIB_CPP_MATH_H
#define PORKLIB_CPP_MATH_H

#include <porklib/common/common.h>

namespace porklib::math {
    template<typename P, typename R = P> inline R sqrt(P value) {
        static_assert(sizeof(P) == 1 || sizeof(P) == 2 || sizeof(P) == 4 || sizeof(P) == 8);

        switch (sizeof(P)) { //switch should be totally shortened away at compile time
            case 1:
            case 2:
            case 4:
                return static_cast<R>(__builtin_sqrtf(static_cast<f32>(value)));
            case 8:
                return static_cast<R>(__builtin_sqrtl(static_cast<f64>(value)));
        }
    };

    template<typename P, typename E = P, typename R = P> inline R pow(P value, E exponent) {
        static_assert(sizeof(P) == 1 || sizeof(P) == 2 || sizeof(P) == 4 || sizeof(P) == 8);
        static_assert(sizeof(E) == 1 || sizeof(E) == 2 || sizeof(E) == 4 || sizeof(E) == 8);

        switch (sizeof(P)) { //switch should be totally shortened away at compile time
            case 1:
            case 2:
            case 4:
                switch (sizeof(E)) {
                    case 1:
                    case 2:
                    case 4:
                        return static_cast<R>(__builtin_powf(static_cast<f32>(value), static_cast<f32>(exponent)));
                    case 8:
                        return static_cast<R>(__builtin_powl(static_cast<f64>(value), static_cast<f64>(exponent)));
                }
            case 8:
                return static_cast<R>(__builtin_powl(static_cast<f64>(value), static_cast<f64>(exponent)));
        }
    };

    template<typename T> T max(T a, T b) { return a > b ? a : b; }
    template<typename T> T min(T a, T b) { return a < b ? a : b; }
    template<typename T> T clamp(T val, T min, T max) { return min(max(val, min), max); }

    template<typename T> inline T ror(T value, T amount) {
        const unsigned int mask = (sizeof(T) * 8 - 1);
        amount &= mask;
        return (value << amount) | (value >> ((-amount) & mask));
    }

    template<typename T> inline T rol(T value, T amount) {
        return ror(value, -amount);
    }
}

#include <porklib/math/vectors.h>

#endif //PORKLIB_CPP_MATH_H

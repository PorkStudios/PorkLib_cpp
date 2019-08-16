#include "funcs.h"
#include "porklib/hacks.h"

#include <cmath>

using namespace porklib::math;

template<typename R, typename A>
inline R porklib::math::sqrt(A val) {
#if __WORDSIZE == 64
    return static_cast<R>(std::sqrt(static_cast<f64>(val)));
#else
    return static_cast<R>(std::sqrtf(static_cast<f32>(val)));
#endif
}
#define SQRT_THING(r, a) template r porklib::math::sqrt<r, a>(a);
FOR_EACH_PRIMITIVE_2D(SQRT_THING);

template<typename R, typename A>
inline R porklib::math::pow(A val, A amount) {
    return static_cast<R>(std::pow(static_cast<flt>(val), static_cast<flt>(amount)));
}
#define POW_THING(r, a) template r porklib::math::pow<r, a>(a, a);
FOR_EACH_PRIMITIVE_2D(POW_THING);


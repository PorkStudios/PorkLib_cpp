#ifndef PORKLIB_CPP_FUNCS_H
#define PORKLIB_CPP_FUNCS_H

#include "porklib/common/common.h"

namespace porklib::math {
    template<typename R = flt, typename A = R>
    R sqrt(A val);

    template<typename R = flt, typename A = R>
    R pow(A val, A amount);
}

#endif //PORKLIB_CPP_FUNCS_H

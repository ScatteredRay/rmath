#ifndef _RMATH_VECTOR_GENERIC_INL_H_
#define _RMATH_VECTOR_GENERIC_INL_H_

#include "rm/vector_generic.h"

namespace rm {
    template<typename t>
    t add(const t& l, const t& r) {
        typeof(t::d) d;
        for(size_t i = 0; i < t::size; i++) {
            d[i] = l[i] + r[i];
        }
        return t(d);
    }


    template<typename t>
    t sub(const t& l, const t& r) {
        typeof(t::d) d;
        for(size_t i = 0; i < t::size; i++) {
            d[i] = l[i] - r[i];
        }
        return t(d);
    }
}

#endif //_RMATH_VECTOR_GENERIC_INL_H_
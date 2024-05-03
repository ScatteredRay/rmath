#ifndef _RMATH_VECTOR_GENERIC_H_
#define _RMATH_VECTOR_GENERIC_H_

#include "rm/vector.h"

namespace rm {
    template<typename t, size_t length>
    struct vector {
    };

    template<>
    struct vector<float, 3> : public vector3 {
        vector(float _xyz);
        vector(const vector<float, 3>& _xyz);
        vector(float _x, float _y, float _z);
        vector(float _xyz[size]);
    };

    template<typename t>
    t add(const t& l, const t& r);

    template<typename t>
    t sub(const t& l, const t& r);
}

#endif //_RMATH_VECTOR_GENERIC_H_

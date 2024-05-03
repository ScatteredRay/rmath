#ifndef _RMATH_VECTOR_GENERIC_H_
#define _RMATH_VECTOR_GENERIC_H_

#include "rm/vector.h"

#include <stdint.h>

namespace rm {
    template<typename t, size_t s>
    struct vector {
        static const size_t size = s;
        using element_type = t;

        vector(t _d);
        vector(t _d[size]);
    };

    template<typename t>
    struct vector<t, 2> {
        static const size_t size = 2;
        using element_type = t;
        union {
            struct {
                t x;
                t y;
            };
            t d[size];
        };
        vector(t _xy);
        vector(const vector<t, 2>& _xy);
        vector(t _x, t _y);
        vector(t _xy[size]);

        t& operator[](int i);
        t operator[](int i) const;
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

    using vector2i = vector<int32_t, 2>;
    using vector2ui = vector<uint32_t, 2>;
}

#endif //_RMATH_VECTOR_GENERIC_H_

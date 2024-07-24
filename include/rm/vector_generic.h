#ifndef _RMATH_VECTOR_GENERIC_H_
#define _RMATH_VECTOR_GENERIC_H_

#include "rm/defs.h"
#include "rm/vector.h"

#include <stdint.h>

namespace rm {
    template<typename t, size_t s>
    struct vector {
        static const size_t size = s;
        using element_type = t;

        RM_FN vector() = default; // TODO: zero-initialize
        RM_FN vector(t _d);
        // defaulted so is_trivially_copyable
        RM_FN vector(const vector<t, s>&) = default;
        RM_FN vector(t _d[size]);
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

        RM_FN vector();
        RM_FN vector(t _xy);
        // defaulted so is_trivially_copyable
        RM_FN vector(const vector<t, 2>&) = default;
        RM_FN vector(t _x, t _y);
        RM_FN vector(t _d[size]);

        RM_FN t& operator[](int i);
        RM_FN t operator[](int i) const;
    };

    template<typename t>
    struct vector<t, 3> {
        static const size_t size = 3;
        using element_type = t;
        union {
            struct {
                t x;
                t y;
                t z;
            };
            t d[size];
        };

        RM_FN vector();
        RM_FN vector(t _xyz);
        // defaulted so is_trivially_copyable
        RM_FN vector(const vector<t, 3>&) = default;
        RM_FN vector(t _x, t _y, t _z);
        RM_FN vector(t _d[size]);

        RM_FN t& operator[](int i);
        RM_FN t operator[](int i) const;
    };

    template<>
    struct vector<float, 3> : public vector3 {
        RM_FN vector();
        RM_FN vector(float _xyz);
        // defaulted so is_trivially_copyable
        RM_FN vector(const vector<float, 3>& _xyz) = default;
        RM_FN vector(float _x, float _y, float _z);
        RM_FN vector(float _xyz[size]);
    };

    template<typename t>
    RM_FN t add(const t& l, const t& r);

    template<typename t>
    RM_FN t sub(const t& l, const t& r);

    using vector2i = vector<int32_t, 2>;
    using vector2ui = vector<uint32_t, 2>;
    using vector3i = vector<int32_t, 3>;
    using vector3ui = vector<uint32_t, 3>;
}

#endif //_RMATH_VECTOR_GENERIC_H_

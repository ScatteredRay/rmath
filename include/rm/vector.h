#ifndef _RMATH_VECTOR_H_
#define _RMATH_VECTOR_H_

#include <stddef.h> //size_t

#include "rm/defs.h"

namespace rm {
    struct vector2;
    struct vector3;
    struct vector4;

    struct vector2 {
        static const size_t size = 2;
        using element_type = float;
        union {
            struct {
                float x;
                float y;
            };
            float d[size];
        };

        RM_FN vector2();
        RM_FN vector2(float _xy);
        // defaulted so is_trivially_copyable
        RM_FN vector2(const vector2& _xy) = default;
        RM_FN vector2(float _x, float _y);
        RM_FN vector2(float _xy[size]);

        RM_FN float& operator[](int i);
        RM_FN float operator[](int i) const;
    };

    struct vector3 {
        static const size_t size = 3;
        using element_type = float;
        union {
            struct {
                float x;
                float y;
                float z;
            };
            float d[size];
        };

        RM_FN vector3();
        RM_FN vector3(float _xyz);
        // defaulted so is_trivially_copyable
        RM_FN vector3(const vector3& _xyz) = default;
        RM_FN vector3(const vector2& _xy, float _z);
        RM_FN vector3(const vector4&);
        RM_FN vector3(float _x, const vector2& _yz);
        RM_FN vector3(float _x, float _y, float _z);
        RM_FN vector3(float _xyz[size]);

        RM_FN float& operator[](int i);
        RM_FN float operator[](int i) const;
    };

    // I'm not sure there is really a way around at least having a vector4 type as an
    // intermediate if we are going to support generic matrix multiplication.
    struct vector4 {
        static const size_t size = 4;
        using element_type = float;
        union {
            struct {
                float x;
                float y;
                float z;
                float w;
            };
            float d[size];
        };

        RM_FN vector4();
        RM_FN vector4(float _xyzw);
        RM_FN vector4(const vector4& _xyz) = default;
        RM_FN vector4(const vector3& _xyz, float _w = 0.0f);
        RM_FN vector4(float _x, float _y, float _z, float _w);
        RM_FN vector4(float _xyzw[size]);

        RM_FN float& operator[](int i);
        RM_FN float operator[](int i) const;
    };

    RM_FN vector2 add(const vector2&, const vector2&);
    RM_FN vector2 sub(const vector2&, const vector2&);

    RM_FN vector3 add(const vector3&, const vector3&);
    RM_FN vector3 sub(const vector3&, const vector3&);

    // Does this become ambigious with a vector product? should this be scale()?
    RM_FN vector2 mul(const vector2&, float);
    RM_FN vector3 mul(const vector3&, float);
    RM_FN vector4 mul(const vector4&, float);

    RM_FN float dot(const vector2&, const vector2&);
    RM_FN float dot(const vector3&, const vector3&);
    RM_FN float dot(const vector4&, const vector4&);

    // TODO: replace with general outer product, and dualization.
    RM_FN vector3 cross(const vector3&, const vector3&);

    RM_FN float lengthSqr(const vector2&);
    RM_FN float length(const vector2&);
    RM_FN vector2 normalize(const vector2&);

    RM_FN float lengthSqr(const vector3&);
    RM_FN float length(const vector3&);
    RM_FN vector3 normalize(const vector3&);

    RM_FN float lengthSqr(const vector4&);
    RM_FN float length(const vector4&);
    RM_FN vector4 normalize(const vector4&);

    RM_FN float sum(const vector2&);
    RM_FN float sum(const vector3&);
    RM_FN float sum(const vector4&);

    RM_FN vector2 lerp(const vector2&, const vector2&, float t);
    RM_FN vector2 slerp(const vector2&, const vector2&, float t);

    RM_FN bool equal(const vector2&, const vector2&);
    RM_FN bool equal(const vector3&, const vector3&);

    RM_FN vector2 operator+(const vector2&, const vector2&);
    RM_FN vector2 operator-(const vector2&, const vector2&);
    RM_FN vector2 operator*(const vector2&, float);

    RM_FN vector3 operator+(const vector3&, const vector3&);
    RM_FN vector3 operator-(const vector3&, const vector3&);
    RM_FN vector3 operator*(const vector3&, float);
    RM_FN vector4 operator*(const vector4&, float);

    RM_FN bool operator==(const vector2&, const vector2&);
    RM_FN bool operator==(const vector3&, const vector3&);
    RM_FN bool operator==(const vector4&, const vector4&);

    // What of these aliases do we like?
    using vec2 = vector2;
    using vec3 = vector3;
    using vec4 = vector4;
    //using vector = vector3;
}

#endif //_RMATH_VECTOR_H_

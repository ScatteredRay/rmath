#ifndef _RMATH_VECTOR_H_
#define _RMATH_VECTOR_H_

#include <stddef.h> //size_t

#include "rm/defs.h"

// I don't really love these swizzles, but
// for compat with 
#define RM_WITH_SWIZZLES 1

namespace rm {
    struct vector2;
    struct vector3;
    struct vector4;

#if RM_WITH_SWIZZLES
    template<typename t, int n0>
    struct VectorSwizzle {
        operator t() {
            t* d = reinterpret_cast<t*>(this);
            return d[n0];
        }
    };

    template<typename t, int n0, int n1>
    struct VectorSwizzle2 {
        operator t() {
            typename t::element_type* d = reinterpret_cast<typename t::element_type*>(this);
            return t(d[n0], d[n1]);
        }
    };

    template<typename t, int n0, int n1, int n2>
    struct VectorSwizzle3 {
        operator t() {
            typename t::element_type* d = reinterpret_cast<typename t::element_type*>(this);
            return t(d[n0], d[n1], d[n2]);
        }
    };
#endif

    struct vector2 {
        static const size_t size = 2;
        using element_type = float;
        union {
            struct {
                float x;
                float y;
            };
            float d[size];
#if RM_WITH_SWIZZLES
            VectorSwizzle<float, 0> r;
            VectorSwizzle<float, 1> g;
            VectorSwizzle2<vector2, 0, 1> rg;
            VectorSwizzle2<vector2, 1, 0> gr;
            VectorSwizzle2<vector2, 0, 1> xy;
            VectorSwizzle2<vector2, 1, 0> yx;
#endif
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
#if RM_WITH_SWIZZLES
            VectorSwizzle<float, 0> r;
            VectorSwizzle<float, 1> g;
            VectorSwizzle<float, 1> b;
            VectorSwizzle2<vector2, 0, 1> rg;
            VectorSwizzle2<vector2, 1, 0> gr;
            VectorSwizzle2<vector2, 1, 2> gb;
            VectorSwizzle2<vector2, 2, 1> bg;
            VectorSwizzle2<vector2, 0, 2> rb;
            VectorSwizzle2<vector2, 0, 1> xy;
            VectorSwizzle2<vector2, 1, 0> yx;
            VectorSwizzle2<vector2, 1, 2> yz;
            VectorSwizzle2<vector2, 2, 1> zy;
            VectorSwizzle2<vector2, 0, 2> xz;
            VectorSwizzle2<vector2, 2, 0> zx;
            VectorSwizzle3<vector3, 0, 1, 2> rgb;
            VectorSwizzle3<vector3, 2, 1, 0> bgr;
#endif
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
#if RM_WITH_SWIZZLES
            VectorSwizzle<float, 0> r;
            VectorSwizzle<float, 1> g;
            VectorSwizzle<float, 1> b;
            VectorSwizzle2<vector2, 0, 1> rg;
            VectorSwizzle2<vector2, 1, 0> gr;
            VectorSwizzle2<vector2, 1, 2> gb;
            VectorSwizzle2<vector2, 2, 1> bg;
            VectorSwizzle2<vector2, 0, 2> rb;
            VectorSwizzle2<vector2, 0, 1> xy;
            VectorSwizzle2<vector2, 1, 0> yx;
            VectorSwizzle2<vector2, 1, 2> yz;
            VectorSwizzle2<vector2, 2, 1> zy;
            VectorSwizzle2<vector2, 0, 2> xz;
            VectorSwizzle2<vector2, 2, 0> zx;
            VectorSwizzle3<vector3, 0, 1, 2> rgb;
            VectorSwizzle3<vector3, 2, 1, 0> bgr;
#endif
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

    RM_FN vector4 add(const vector4&, const vector4&);
    RM_FN vector4 sub(const vector4&, const vector4&);

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

    RM_FN vector4 operator+(const vector4&, const vector4&);
    RM_FN vector4 operator-(const vector4&, const vector4&);
    RM_FN vector4 operator*(const vector4&, float);

    RM_FN bool operator==(const vector2&, const vector2&);
    RM_FN bool operator==(const vector3&, const vector3&);
    RM_FN bool operator==(const vector4&, const vector4&);

    RM_FN vector2& operator+=(vector2&, const vector2&);
    RM_FN vector2& operator-=(vector2&, const vector2&);
    RM_FN vector2& operator*=(vector2&, float);

    RM_FN vector3& operator+=(vector3&, const vector3&);
    RM_FN vector3& operator-=(vector3&, const vector3&);
    RM_FN vector3& operator*=(vector3&, float);

    RM_FN vector4& operator+=(vector4&, const vector4&);
    RM_FN vector4& operator-=(vector4&, const vector4&);
    RM_FN vector4& operator*=(vector4&, float);

    // What of these aliases do we like?
    using vec2 = vector2;
    using vec3 = vector3;
    using vec4 = vector4;
    //using vector = vector3;
}

#endif //_RMATH_VECTOR_H_

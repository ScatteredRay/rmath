#ifndef _RMATH_VECTOR_H_
#define _RMATH_VECTOR_H_

#include <stddef.h> //size_t

namespace rm {
    struct vector2 {
        static const size_t size = 2;
        union {
            struct {
                float x;
                float y;
            };
            float d[size];
        };

        vector2(float _xy);
        vector2(const vector2& _xy);
        vector2(float _x, float _y);
        vector2(float _xy[size]);

        float& operator[](int i);
        float operator[](int i) const;
    };

    struct vector3 {
        static const size_t size = 3;
        union {
            struct {
                float x;
                float y;
                float z;
            };
            float d[3];
        };

        vector3(float _xyz);
        vector3(const vector3& _xyz);
        vector3(const vector2& _xy, float _z);
        vector3(float _x, const vector2& _yz);
        vector3(float _x, float _y, float _z);
        vector3(float _xyz[size]);

        float& operator[](int i);
        float operator[](int i ) const;
    };

    // Do we actually want a `vector4` shouldn't the w component be implied?

    vector2 add(const vector2&, const vector2&);
    vector2 sub(const vector2&, const vector2&);

    vector3 add(const vector3&, const vector3&);
    vector3 sub(const vector3&, const vector3&);

    // Does this become ambigious with a vector product? should this be scale()?
    vector2 mul(const vector2&, float);
    vector3 mul(const vector3&, float);

    float dot(const vector2&, const vector2&);

    float lengthSqr(const vector2&);
    float length(const vector2&);
    vector2 normalize(const vector2&);

    float sum(const vector2&);

    vector2 lerp(const vector2&, const vector2&, float t);
    vector2 slerp(const vector2&, const vector2&, float t);

    vector2 operator+(const vector2&, const vector2&);
    vector2 operator-(const vector2&, const vector2&);
    vector2 operator*(const vector2&, float);
    vector2 operator/(const vector2&, float);

    vector3 operator+(const vector3&, const vector3&);
    vector3 operator-(const vector3&, const vector3&);
    vector3 operator*(const vector3&, float);
    vector3 operator/(const vector3&, float);

    // What of these aliases do we like?
    using vec2 = vector2;
    using vec3 = vector3;
    //using vector = vector3;
}

#endif //_RMATH_VECTOR_H_

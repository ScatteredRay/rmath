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
            float d[2];
        };

        vector2(float _xy);
        vector2(const vector2& _xy);
        vector2(float _x, float _y);
        vector2(float _xy[2]);

        float& operator[](int i);
    };

    vector2 add(const vector2&, const vector2&);
    vector2 sub(const vector2&, const vector2&);

    // Does this become ambigious with a vector product? should this be scale()?
    vector2 mul(const vector2&, float);

    float dot(const vector2&, const vector2&);

    float lengthSqr(const vector2&);
    float length(const vector2&);
    vector2 normalize(const vector2&);

    //using vec2 = vector2;
}

#endif //_RMATH_VECTOR_H_

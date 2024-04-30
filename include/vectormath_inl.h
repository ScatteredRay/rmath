#ifndef RMATH_VECTORMATH_INL_H
#define RMATH_VECTORMATH_INL_H

namespace rm {

    struct point3;
    struct float3;
    struct quaternion;

    // point3

    point3 origin();

    point3 add(const point3&, const float3&);
    float3 sub(const point3&, const point3&);

    point3 lerp(const point3&, const point3&, float t);

    point3 operator+(const point3&, const float3&);
    float3 operator-(const point3&, const point3&);

    // TODO: The primary other consideration for getting the most out of integer
    // positions is that we should take care when we create our matricies.
    // We'll gain much by creating our model->view by skipping world space
    // alone, but we may get additional wins by going model->projection and
    // taking the far/near into account.

    // float3

    float3 add(const float3&, const float3&);
    float3 sub(const float3&, const float3&);
    float3 mul(const float3&, float);
    float3 div(const float3&, float);

    float dot(const float3&, const float3&);
    float3 cross(const float3&, const float3&);

    float3 normalize(const float3&);
    float lengthSqr(const float3&);
    float length(const float3&);
    float sum(const float3&);

    float3 lerp(const float3&, const float3&, float t);
    float3 slerp(const float3&, const float3&, float t);

    float3 operator+(const float3&, const float3&);
    float3 operator-(const float3&, const float3&);
    float3 operator*(const float3&, float);
    float3 operator/(const float3&, float);
}

#endif //RMATH_VECTORMATH_INL_H

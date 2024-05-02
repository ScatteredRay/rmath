#ifndef RMATH_VECTORMATH_INL_H
#define RMATH_VECTORMATH_INL_H

namespace rm {

    struct point3;
    struct vector3;

    // point3

    point3 origin();

    point3 add(const point3&, const vector3&);
    vector3 sub(const point3&, const point3&);

    point3 lerp(const point3&, const point3&, float t);

    point3 operator+(const point3&, const vector3&);
    vector3 operator-(const point3&, const point3&);

    // TODO: The primary other consideration for getting the most out of integer
    // positions is that we should take care when we create our matricies.
    // We'll gain much by creating our model->view by skipping world space
    // alone, but we may get additional wins by going model->projection and
    // taking the far/near into account.
}

#endif //RMATH_VECTORMATH_INL_H

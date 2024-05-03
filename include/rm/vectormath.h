#ifndef RMATH_VECTORMATH_H
#define RMATH_VECTORMATH_H

namespace rm {

    struct point3;
    struct vector3;

    struct point3
    {
        int x;
        int y;
        int z;

        // Used for conversion into floating point.
        static unsigned int decimalPrecision;

        // Convert to floating point, this will have floating point error.
        float estimateX();
        float estimateY();
        float estimateZ();

        // Round to the nearest in world units, taking decimal precision into account.
        int roundWorldX();
        int roundWorldY();
        int roundWorldZ();

        point3(int _x, int _y, int _z);
        // Convienience, be wary of usage.
        point3(float _x, float _y, float _z);
        point3(vector3 _xyz);

        int operator[](int);
    };

    typedef point3 point;
}

#endif //RMATH_VECTORMATH_H

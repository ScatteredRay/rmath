#include "vectormath.h"
#include "vectormath_inl.h"

// This is where all of our precision comes from, it's the amount of bits we
// spend on the decimal component on conversion to floating point.
//
// If our units are cm, 6 bits of precision would give us precision of
// 156.3 micrometers (Which is just about enough to address a 4k pixel on a 27"
// monitor intrestinglly enough)
//
// This also gets us about 671 kilometers of range. If we were to use 64 bit
// integers we could also get 19,267 AU of precision.
unsigned int rm::point3::decimalPrecision = 6;


namespace rm {

    float3::float3(float _x, float _y, float _z) {
        this->x = _x;
        this->y = _y;
        this->z = _z;
    }

    float3 add(const float3& l, const float3& r) {
        return float3(
            l.x+r.x,
            l.y+r.y,
            l.z+r.z);
    }
}
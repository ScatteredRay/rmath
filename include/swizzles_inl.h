#ifndef RMATH_SWIZZLES_INL_H
#define RMATH_SWIZZLES_INL_H

namespace rmath {

    template<int a, int b, int c, int d> float4 swizzle(const float3 vec)
    {
        return float3(vec[a], vec[b], vec[c], vec[d]);
    }

    template<int a, int b, int c> float3 swizzle(const float3 vec)
    {
        return float3(vec[a], vec[b], vec[c]);
    }

    template<int a, int b> float2 swizzle(const float3 vec)
    {
        return float2(vec[a], vec[b]);
    }

    template<int a> float swizzle(const float3 vec)
    {
        return vec[a];
    }

    // TODO: consider `xxy(myvec)` as a possible swizzle notation.
}

#endif //RMATH_SWIZZLES_INL_H

#ifndef RMATH_VECTORMATH_H
#define RMATH_VECTORMATH_H

namespace rm {

    struct point3;
    struct float2;
    struct float3;
    struct float4;

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
        point3(float3 _xyz);

        int operator[](int);
    };

    typedef point3 point;

    struct float2
    {
        float x;
        float y;

        float2(float _xy);
        float2(const float2& _xy);
        float2(float _x, float _y);

        float operator[](int);
    };

    struct float3
    {
        float x;
        float y;
        float z;

        float3(float _xyz);
        float3(const float3& _xyz);
        float3(const float2& _xy, float _z);
        float3(float _x, const float2& _yz);
        float3(float _x, float _y, float _z);

        float operator[](int);
    };

    struct float4
    {
        float x;
        float y;
        float z;
        float w;

        float4(float _xyzw);
        float4(const float4& _xyzw);
        float4(const float3& _xyz, float _w);
        float4(float _x, const float3& _yzw);
        float4(const float2& _xy, const float2& _zw);
        float4(const float2& _xy, float _z, float _w);
        float4(float _x, float _y, const float2& _zw);
        float4(float _x, const float2& _yz, float _w);
        float4(float _x, float _y, float _z, float _w);

        float operator[](int);
    };
}



#endif //RMATH_VECTORMATH_H

#include "vectormath.h"
#include "vectormath_inl.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

using namespace rm;

TEST_CASE("vector sum")
{
    float3 a(1, 2, 3);
    float3 b(4, 5, 6);

    float3 c = add(a, b);

    CHECK(c.x == 5);
    CHECK(c.y == 7);
    CHECK(c.z == 9);
}



#include "vector.h"
#include "vectormath.h"
#include "vectormath_inl.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

using namespace rm;

TEST_CASE("vector access") {
    SUBCASE("vector2") {
        vector2 a(3, 4);

        CHECK(a.x == 3);
        CHECK(a.y == 4);

        CHECK(a[0] == 3);
        CHECK(a[1] == 4);
        CHECK(a.d[0] == 3);
        CHECK(a.d[1] == 4);

        a.x = 5;
        a[1] = 6;
        CHECK(a[0] == 5);
        CHECK(a.y == 6);

        a.d[0] = 7;
        a.y = 8;
        CHECK(a[0] == 7);
        CHECK(a.d[1] == 8);

        const vector2 b(a);
        CHECK(b[0] == a[0]);
        CHECK(b[1] == a[1]);

        vector2 c(9);
        CHECK(c.x == 9);
        CHECK(c.y == 9);
    }

    SUBCASE("vector3") {
        vector3 a(3, 4, 5);

        CHECK(a.x == 3);
        CHECK(a.y == 4);
        CHECK(a.z == 5);

        CHECK(a[0] == 3);
        CHECK(a[1] == 4);
        CHECK(a[2] == 5);

        CHECK(a.d[0] == 3);
        CHECK(a.d[1] == 4);
        CHECK(a.d[2] == 5);

        a.x = 6;
        a[1] = 7;
        a.d[2] = 8;
        CHECK(a[0] == 6);
        CHECK(a.d[1] == 7);
        CHECK(a.z == 8);

        vector3 c(9);
        CHECK(c.x == 9);
        CHECK(c.y == 9);
        CHECK(c.z == 9);
    }
}

TEST_CASE("vector sum")
{
    SUBCASE("vector2") {
        vector2 a(1, 2);
        vector2 b(3, 4);
        vector2 c = add(a, b);

        CHECK(c.x == 4);
        CHECK(c.y == 6);

        vector2 d = sub(c, a);
        CHECK(d.x == 3);
        CHECK(d.y == 4);
    }

    SUBCASE("vector3") {
        vector3 a(1, 2, 3);
        vector3 b(4, 5, 6);

        vector3 c = add(a, b);

        CHECK(c.x == 5);
        CHECK(c.y == 7);
        CHECK(c.z == 9);

        vector3 d = sub(c, a);
        CHECK(d.x == 4);
        CHECK(d.y == 5);
        CHECK(d.z == 6);
    }
}



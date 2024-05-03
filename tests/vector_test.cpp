#include "rw/vector.h"
#include "rw/vector_generic.h"

#include <doctest.h>
#include <cmath>

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

    SUBCASE("generic vector3") {
        vector<float, 3> a(3, 4, 5);

        CHECK(a.x == 3);
        CHECK(a.y == 4);
        CHECK(a.z == 5);
    }
}

TEST_CASE("vector sum") {
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

TEST_CASE("vector mul") {
    SUBCASE("vector2") {
        vector2 a(2, 3);
        vector2 b = mul(a, 2.0f);
        CHECK(b.x == 4.0f);
        CHECK(b.y == 6.0f);
    }

    SUBCASE("vector3") {
        vector3 a(2, 3, 4);
        vector3 b = mul(a, 2.0f);
        CHECK(b.x == 4.0f);
        CHECK(b.y == 6.0f);
        CHECK(b.z == 8.0f);
    }
}

TEST_CASE("vector dot") {
    SUBCASE("vector2") {
        vector2 a(2, 0);
        vector2 b(0, 1);

        CHECK(dot(a, a) == 4.0f);
        CHECK(dot(a, b) == 0.0f);
    }

    SUBCASE("vector2") {
        vector3 a(0.2, 0.5, 0.8);
        vector3 b(1, 0, 0);
        vector3 c(0, 1, 0);
        vector3 d(0, 0, 1);

        CHECK(dot(a, b) == 0.2f);
        CHECK(dot(a, c) == 0.5f);
        CHECK(dot(a, d) == 0.8f);
    }
}

TEST_CASE("vector length mag") {
    SUBCASE("vector2") {
        vector2 a(1, 2);
        CHECK(lengthSqr(a) == 5.0f);
        CHECK(abs(length(a) - sqrt(5.0f)) < 0.01f); // REVIST: why isn't this exact?
        vector2 n = normalize(a);
        CHECK(abs(n.x - 0.447f) < 0.01f);
        CHECK(abs(n.y - 0.894f) < 0.01f);
        CHECK(sum(a) == 3.0f);
    }

    SUBCASE("vector3") {
        vector3 a(1, 2, 1);
        CHECK(lengthSqr(a) == 6.0f);
        CHECK(abs(length(a) - sqrt(6.0f)) < 0.01f);
        vector3 n = normalize(a);
        CHECK(abs(n.x - 0.408f) < 0.01f);
        CHECK(abs(n.y - 0.816f)< 0.01f);
        CHECK(abs(n.z - 0.408f) < 0.01f);
        CHECK(sum(a) == 4.0f);
    }
}

TEST_CASE("vector cross") {
    SUBCASE("vector3") {
        vector3 a(1, 0, 0);
        vector3 b(0, 1, 0);
        vector3 c(0, 0, 1);

        CHECK(equal(cross(a, b), c));
        CHECK(equal(cross(b, c), a));
        CHECK(equal(cross(c, b), mul(a, -1.0f)));
    }
}
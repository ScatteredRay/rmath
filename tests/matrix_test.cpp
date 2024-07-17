#include "rm/matrix.h"
#include "rm/vector.h"

#include <doctest.h>
#include <string.h>
#include <type_traits>
#include <new>

using namespace rm;

TEST_CASE("matrix value construction") {
    SUBCASE("default construction") {
        matrix44 a;

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                CHECK(a.d[i][j] == 0);
            }
        }
    }

    SUBCASE("default placement") {
        char buf[sizeof(matrix44)];
        memset(&buf, 0xFF, sizeof(matrix44));
        matrix44* a = new (&buf) matrix44;

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                CHECK(a->d[i][j] == 0);
            }
        }
    }

    SUBCASE("element construction") {
        matrix44 a(
            1.0f, 2.0f, 3.0f, 4.0f,
            5.0f, 6.0f, 7.0f, 8.0f,
            9.0f, 10.0f, 11.0f, 12.0f,
            13.0f, 14.0f, 15.0f, 16.0f);

        CHECK(a(0, 1) == 2.0f);
        CHECK(a(1, 0) == 5.0f);
        int n = 1;
        for(int r = 0; r < 4; r++) {
            for(int c = 0; c < 4; c++) {
                CHECK(a(r, c) == float(n++));
            }
        }
    }

    SUBCASE("vector construction") {
        matrix44 a = matrix44::fromColumns(
            vector4(1, 2, 3, 4),
            vector4(5, 6, 7, 8),
            vector4(9, 10, 11, 12),
            vector4(13, 14, 15, 16));

        CHECK(a(1, 0) == 2);
        int n = 1;
        for(int c = 0; c < 4; c++) {
            for(int r = 0; r < 4; r++) {
                CHECK(a(r, c) == float(n++));
            }
        }
    }

    SUBCASE("constant") {
        matrix44 a(5.0f);

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                CHECK(a.d[i][j] == 5.0f);
            }
        }
    }
}

TEST_CASE("matrix geometry construction") {
    SUBCASE("identity") {
        matrix44 a = matrix44::identity();

        for(int c = 0; c < 4; c++) {
            for(int r = 0; r < 4; r++) {
                if(r == c) {
                    CHECK(a(r, c) == 1.0f);
                }
                else {
                    CHECK(a(r, c) == 0.0f);
                }
            }
        }
    }

    SUBCASE("scale vec4") {
        matrix44 a = matrix44::scale(vector4(2, 3, 4, 5));
        CHECK(a * vector4(2) == vector4(4, 6, 8, 10));
    }

    SUBCASE("scale multi-dimensional") {
        matrix44 a = matrix44::scale(2, 3, 4, 5);
        CHECK(a * vector4(2) == vector4(4, 6, 8, 10));
    }

    SUBCASE("scale uniform") {
        matrix44 a = matrix44::scale(3);
        vector4 v = a * vector4(3, 4, 5, 6);
        CHECK(v == vector4(9, 12, 15, 6));
    }

    SUBCASE("translate") {
        matrix44 a = matrix44::translate(vector3(3, 2, 5));
        vector4 v = a * vector4(vector3(1), 1);
        v = v * (1.0f/v.w);
        CHECK(v == vector4(4, 3, 6, 1));
    }
}

TEST_CASE("matrix layout") {
    SUBCASE("column-major") {
        matrix44 a(
            1.0f, 2.0f, 3.0f, 4.0f,
            5.0f, 6.0f, 7.0f, 8.0f,
            9.0f, 10.0f, 11.0f, 12.0f,
            13.0f, 14.0f, 15.0f, 16.0f);

        int n = 1;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                CHECK(a.d[j][i] == float(n++));
            }
        }
    }
}

TEST_CASE("matrix tranpose") {
    matrix44 a(
        1.0f, 2.0f, 3.0f, 4.0f,
        5.0f, 6.0f, 7.0f, 8.0f,
        9.0f, 10.0f, 11.0f, 12.0f,
        13.0f, 14.0f, 15.0f, 16.0f);

    matrix44 b = transpose(a);

    int n = 1;
    for(int r = 0; r < 4; r++) {
        for(int c = 0; c < 4; c++) {
            CHECK(b(c, r) == float(n++));
        }
    }
}

TEST_CASE("matrix multiply") {
    SUBCASE("mat mat") {
        matrix44 a(
            1.0f, 1.0f, 1.0f, 1.0f,
            2.0f, 2.0f, 2.0f, 2.0f,
            3.0f, 3.0f, 3.0f, 3.0f,
            4.0f, 4.0f, 4.0f, 4.0f);

        matrix44 b(
            1.0f, 2.0f, 3.0f, 4.0f,
            1.0f, 2.0f, 3.0f, 4.0f,
            1.0f, 2.0f, 3.0f, 4.0f,
            1.0f, 2.0f, 3.0f, 4.0f);

        matrix44 c = mul(a, b);

        CHECK(c(0, 0) == 4.0f);
        CHECK(c(1, 1) == 16.0f);
        CHECK(c(2, 2) == 36.0f);
        CHECK(c(3, 3) == 64.0f);
        CHECK(c(0, 1) == 8.0f);
        CHECK(c(1, 0) == 8.0f);
        CHECK(c(0, 2) == 12.0f);
        CHECK(c(2, 0) == 12.0f);
        CHECK(c(0, 3) == 16.0f);
        CHECK(c(1, 2) == 24.0f);
        CHECK(c(2, 1) == 24.0f);
        CHECK(c(1, 3) == 32.0f);
        CHECK(c(3, 1) == 32.0f);
        CHECK(c(2, 3) == 48.0f);
        CHECK(c(3, 2) == 48.0f);
    }

    SUBCASE("scalar") {
        matrix44 a(
            1.0f, 2.0f, 3.0f, 4.0f,
            5.0f, 6.0f, 7.0f, 8.0f,
            9.0f, 10.0f, 11.0f, 12.0f,
            13.0f, 14.0f, 15.0f, 16.0f);

        matrix44 b = mul(2.0f, a);

        int n = 1;
        for(int r = 0; r < 4; r++) {
            for(int c = 0; c < 4; c++) {
                CHECK(b(r, c) == float(n++) * 2.0f);
            }
        }
    }
}

TEST_CASE("vector multiply") {
    SUBCASE("vector4") {
        matrix44 a(
            0, 0, 2, 0,
            0, 0, 0, 3,
            0, 4, 0, 0,
            5, 0, 0, 0);

        vector4 x(1, 0, 0, 0);
        vector4 y(0, 1, 0, 0);
        vector4 z(0, 0, 1, 0);
        vector4 w(0, 0, 0, 1);

        CHECK(mul(a, x) == vector4(0, 0, 0, 5));
        CHECK(a * x == vector4(0, 0, 0, 5));

        CHECK(mul(a, y) == vector4(0, 0, 4, 0));
        CHECK(a * y == vector4(0, 0, 4, 0));

        CHECK(mul(a, z) == vector4(2, 0, 0, 0));
        CHECK(a * z == vector4(2, 0, 0, 0));

        CHECK(mul(a, w) == vector4(0, 3, 0, 0));
        CHECK(a * w == vector4(0, 3, 0, 0));
    }

    SUBCASE("vector3") {
        matrix44 a(
            0, 0, 2, 0,
            5, 0, 0, 0,
            0, 4, 0, 0,
            0, 0, 0, 0);

        vector3 x(1, 0, 0);
        vector3 y(0, 1, 0);
        vector3 z(0, 0, 1);

        CHECK(mul(a, x) == vector3(0, 5, 0));
        CHECK(a * x == vector3(0, 5, 0));

        CHECK(mul(a, y) == vector3(0, 0, 4));
        CHECK(a * y == vector3(0, 0, 4));

        CHECK(mul(a, z) == vector3(2, 0, 0));
        CHECK(a * z == vector3(2, 0, 0));

    }
}

TEST_CASE_TEMPLATE("matrix conversion", T, float/*, double*/) {
    SUBCASE("from 44") {
        T d[16] = {
            1.0, 2.0, 3.0, 4.0,
            5.0, 6.0, 7.0, 8.0,
            9.0, 10.0, 11.0, 12.0,
            13.0, 14.0, 15.0, 16.0
        };

        SUBCASE("column_major column") {
            matrix44 m = matrix44::convertFrom44<T, MatrixLayout::column_major, VectorLayout::column>(d);

            SUBCASE("layout untransposed") {
                for(int i = 0; i < 16; i++) {
                    CHECK(m.d[0][i] == d[i]);
                }
            }

            int n = 1;
            for(int c = 0; c < 4; c++) {
                for(int r = 0; r < 4; r++) {
                    CHECK(m(r, c) == float(n++));
                }
            }
        }

        SUBCASE("column_major row") {
            matrix44 m = matrix44::convertFrom44<T, MatrixLayout::column_major, VectorLayout::row>(d);

            int n = 1;
            for(int r = 0; r < 4; r++) {
                for(int c = 0; c < 4; c++) {
                    CHECK(m(r, c) == float(n++));
                }
            }
        }

        SUBCASE("row_major row") {
            matrix44 m = matrix44::convertFrom44<T, MatrixLayout::row_major, VectorLayout::row>(d);

            int n = 1;
            for(int c = 0; c < 4; c++) {
                for(int r = 0; r < 4; r++) {
                    CHECK(m(r, c) == float(n++));
                }
            }
        }

        SUBCASE("row_major column") {
            matrix44 m = matrix44::convertFrom44<T, MatrixLayout::row_major, VectorLayout::column>(d);

            int n = 1;
            for(int r = 0; r < 4; r++) {
                for(int c = 0; c < 4; c++) {
                    CHECK(m(r, c) == float(n++));
                }
            }
        }
    }

    SUBCASE("to 44") {
        matrix44 a(
            1.0f, 2.0f, 3.0f, 4.0f,
            5.0f, 6.0f, 7.0f, 8.0f,
            9.0f, 10.0f, 11.0f, 12.0f,
            13.0f, 14.0f, 15.0f, 16.0f);

        SUBCASE("column_major column") {
            T d[4][4];

            a.convertTo44<T, MatrixLayout::column_major, VectorLayout::column>(&d[0][0]);

            SUBCASE("layout untransposed") {
                for(int i = 0; i < 16; i++) {
                    CHECK(a.d[0][i] == d[0][i]);
                }
            }

            int n = 1;
            for(int c = 0; c < 4; c++) {
                for(int r = 0; r < 4; r++) {
                    CHECK(d[r][c] == float(n++));
                }
            }
        }

        SUBCASE("column_major row") {
            T d[4][4];

            a.convertTo44<T, MatrixLayout::column_major, VectorLayout::row>(&d[0][0]);

            int n = 1;
            for(int r = 0; r < 4; r++) {
                for(int c = 0; c < 4; c++) {
                    CHECK(d[r][c] == float(n++));
                }
            }
        }

        SUBCASE("row_major row") {
            T d[4][4];

            a.convertTo44<T, MatrixLayout::row_major, VectorLayout::row>(&d[0][0]);

            int n = 1;
            for(int c = 0; c < 4; c++) {
                for(int r = 0; r < 4; r++) {
                    CHECK(d[r][c] == float(n++));
                }
            }
        }

        SUBCASE("row_major column") {
            T d[4][4];

            a.convertTo44<T, MatrixLayout::row_major, VectorLayout::column>(&d[0][0]);

            int n = 1;
            for(int r = 0; r < 4; r++) {
                for(int c = 0; c < 4; c++) {
                    CHECK(d[r][c] == float(n++));
                }
            }
        }
    }
}


#include "rm/matrix.h"
#include "rm/vector.h"

#include <type_traits>

namespace rm {
    RM_FN matrix44::matrix44() {
        for(int r = 0; r < size_rows; r++) {
            for(int c = 0; c < size_columns; c++) {
                d[r][c] = 0.0f;
            }
        }
    }

    RM_FN matrix44::matrix44(
        float _m11, float _m12, float _m13, float _m14,
        float _m21, float _m22, float _m23, float _m24,
        float _m31, float _m32, float _m33, float _m34,
        float _m41, float _m42, float _m43, float _m44) {
        d[0][0] = _m11;
        d[0][1] = _m21;
        d[0][2] = _m31;
        d[0][3] = _m41;
        d[1][0] = _m12;
        d[1][1] = _m22;
        d[1][2] = _m32;
        d[1][3] = _m42;
        d[2][0] = _m13;
        d[2][1] = _m23;
        d[2][2] = _m33;
        d[2][3] = _m43;
        d[3][0] = _m14;
        d[3][1] = _m24;
        d[3][2] = _m34;
        d[3][3] = _m44;
    }

    RM_FN matrix44::matrix44(float _m) {
        for(int r = 0; r < size_rows; r++) {
            for(int c = 0; c < size_columns; c++) {
                d[r][c] = _m;
            }
        }
    }

    RM_FN matrix44 matrix44::fromColumns(const vector4& x, const vector4& y, const vector4& z, const vector4& w) {
        return matrix44(
            x.x, y.x, z.x, w.x,
            x.y, y.y, z.y, w.y,
            x.z, y.z, z.z, w.z,
            x.w, y.w, z.w, w.w);
    }

    RM_FN matrix44 matrix44::identity() {
        matrix44 m;
        for(int r = 0; r < size_rows; r++) {
            for(int c = 0; c < size_columns; c++) {
                m.d[r][c] = r == c ? 1.0f : 0.0f;
            }
        }
        return m;
    }

    RM_FN matrix44 matrix44::scale(const vector4& scale) {
        matrix44 m;
        for(int r = 0; r < size_rows; r++) {
            for(int c = 0; c < size_columns; c++) {
                m.d[r][c] = r == c ? scale[r] : 0.0f;
            }
        }
        return m;
    }

    RM_FN matrix44 matrix44::scale(float _x, float _y, float _z, float _w) {
        return matrix44::scale(vector4(_x, _y, _z, _w));
    }

    RM_FN matrix44 matrix44::scale(float _xyz) {
        return matrix44::scale(_xyz, _xyz, _xyz, 1.0f);
    }

    RM_FN matrix44 matrix44::translate(const vector3& t) {
        return matrix44(
            1.0f, 0.0f, 0.0f, t.x,
            0.0f, 1.0f, 0.0f, t.y,
            0.0f, 0.0f, 1.0f, t.z,
            0.0f, 0.0f, 0.0f, 1.0f);
    }

    // Is this confusing, should access be row-major???
    RM_FN float& matrix44::operator()(int r, int c) {
        return d[c][r];
    }

    RM_FN float matrix44::operator()(int r, int c) const {
        return d[c][r];
    }

    RM_FN matrix44 transpose(const matrix44& m) {
        matrix44 t;
        for(int r = 0; r < matrix44::size_rows; r++) {
            for(int c = 0; c < matrix44::size_columns; c++) {
                t(r, c) = m(c, r);
            }
        }
        return t;
    }

    RM_FN matrix44 mul(const matrix44& l, const matrix44& r) {
        // l::size_columns
        const size_t l_size = matrix44::size_columns;
        // r::size_rows
        const size_t r_size = matrix44::size_rows;
        // l::size_rows/r::size_columns
        const size_t s_size = matrix44::size_columns;

        matrix44 o;
        for(int i = 0; i < r_size; i++) {
            for(int j = 0; j < l_size; j++) {
                o(i, j) = 0.0f;
                for(int k = 0; k < s_size; k++) {
                    o(i, j) += l(i, k) * r(k, j);
                }
            }
        }
        return o;
    }

    RM_FN matrix44 mul(float s, const matrix44& m) {
        matrix44 o;
        for(int r = 0; r < matrix44::size_rows; r++) {
            for(int c = 0; c < matrix44::size_columns; c++) {
                o(r, c) = s * m(r, c);
            }
        }
        return o;
    }

    RM_FN vector3 mul(const matrix44& m, const vector3& v) {
        return vector3(
            v.x * m(0, 0) + v.y * m(0, 1) + v.z * m(0, 2),
            v.x * m(1, 0) + v.y * m(1, 1) + v.z * m(1, 2),
            v.x * m(2, 0) + v.y * m(2, 1) + v.z * m(2, 2));
    }

    RM_FN vector4 mul(const matrix44& m, const vector4& v) {
        return vector4(
            v.x * m(0, 0) + v.y * m(0, 1) + v.z * m(0, 2) + v.w * m(0, 3),
            v.x * m(1, 0) + v.y * m(1, 1) + v.z * m(1, 2) + v.w * m(1, 3),
            v.x * m(2, 0) + v.y * m(2, 1) + v.z * m(2, 2) + v.w * m(2, 3),
            v.x * m(3, 0) + v.y * m(3, 1) + v.z * m(3, 2) + v.w * m(3, 3));
    }

    RM_FN matrix44 operator*(const matrix44& l, const matrix44& r) {
        return mul(l, r);
    }

    RM_FN matrix44 operator*(float s, const matrix44& m) {
        return mul(s, m);
    }

    RM_FN vector3 operator*(const matrix44& m, const vector3& v) {
        return mul(m, v);
    }

    RM_FN vector4 operator*(const matrix44& m, const vector4& v) {
        return mul(m, v);
    }

    static_assert(std::is_trivially_copyable<matrix44>::value);
    static_assert(matrix44::basis_major == true);
}

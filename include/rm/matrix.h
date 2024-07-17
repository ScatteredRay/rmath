#ifndef _RMATH_MATRIX_H_
#define _RMATH_MATRIX_H_

#include <stddef.h>

#include "rm/defs.h"

// It seems everyone uses vectors that match the majority of their matrices, so if we use column-major and
// column-vectors here the memory layout should match.

// Conventions
//
// So, by convention, matrices are constructed row-major, and vectors are treated as column vectors.
// however storage is laid out column-major, access is [row][column].
//
// This is nice, as then the math is transcribed matching the literature, which should be less error-prone.
// storage being column major, allows for transpose free casts from the major other libraries we interact
// with. This does mean debugging and visualization will suffer, since C's conventions are row-major,
// so anything viewing the native memory, in standard layout will show the system as transposed.
// But additionally, the codegen ends up being a bit nicer, and requires fewer shuffles, and basis
// construction and access are linear in memory.
//
// An additional quirk, is that matrices are declared rowsXcolumns or heightXwidth which means that a
// matrix3x4 or matrix<3,4> has 3 rows, and 4 columns, this is to match the standard defs just about everywhere.

namespace rm {
    struct vector3;
    struct vector4;

    enum class MatrixLayout {
        row_major,
        column_major
    };

    enum class VectorLayout {
        row,
        column
    };

    constexpr bool isBasisMajor(MatrixLayout m, VectorLayout v) {
        if(
            (m == MatrixLayout::row_major && v == VectorLayout::row) ||
            (m == MatrixLayout::column_major && v == VectorLayout::column))
            return true;
        else
            return false;
    }

    struct matrix44 {
        static const size_t size_rows = 4;
        static const size_t size_columns = 4;
        static const MatrixLayout matrix_layout = MatrixLayout::column_major;
        static const VectorLayout vector_layout = VectorLayout::column;
        static const bool basis_major = isBasisMajor(matrix_layout, vector_layout);
        using element_type = float;
        union {
            float d[size_rows][size_columns];
            struct {
                float m11, m21, m31, m41;
                float m12, m22, m32, m42;
                float m13, m23, m33, m43;
                float m14, m24, m34, m44;
            };
        };

        RM_FN matrix44();
        RM_FN matrix44(const matrix44&) = default;
        RM_FN matrix44(
            float _m11, float _m12, float _m13, float _m14,
            float _m21, float _m22, float _m23, float _m24,
            float _m31, float _m32, float _m33, float _m34,
            float _m41, float _m42, float _m43, float _m44);
        RM_FN matrix44(float _m);

        RM_FN static matrix44 fromColumns(const vector4& x, const vector4& y, const vector4& z, const vector4& w);
        RM_FN static matrix44 identity();
        RM_FN static matrix44 scale(const vector4& scale);
        RM_FN static matrix44 scale(float _x, float _y, float _z, float _w = 1.0f);
        RM_FN static matrix44 scale(float _xyx);
        RM_FN static matrix44 translate(const vector3& translate);

        template<typename T, MatrixLayout srcLayout, VectorLayout srcVector>
        RM_FN static matrix44 convertFrom44(const T* data);

        template<typename T, MatrixLayout dstLayout, VectorLayout dstVector>
        RM_FN void convertTo44(T* data);

        RM_FN float& operator()(int r, int c);
        RM_FN float operator()(int r, int c) const;
    };

    RM_FN matrix44 transpose(const matrix44& m);
    RM_FN matrix44 mul(const matrix44&, const matrix44&);
    RM_FN matrix44 mul(float, const matrix44&);
    RM_FN vector3 mul(const matrix44&, const vector3&);
    RM_FN vector4 mul(const matrix44&, const vector4&);

    RM_FN matrix44 operator*(const matrix44&, const matrix44&);
    RM_FN matrix44 operator*(float, const matrix44&);
    RM_FN vector3 operator*(const matrix44&, const vector3&);
    RM_FN vector4 operator*(const matrix44&, const vector4&);

    template<typename T, MatrixLayout srcLayout, VectorLayout srcVector>
    RM_FN matrix44 matrix44::convertFrom44(const T* data) {
        const bool needsTranspose = isBasisMajor(srcLayout, srcVector) != basis_major;
        matrix44 m;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                int idx = needsTranspose ? i+j*4 : i*4+j;
                m.d[i][j] = data[idx];
            }
        }
        return m;
    }

    template<typename T, MatrixLayout dstLayout, VectorLayout dstVector>
    RM_FN void matrix44::convertTo44(T* data) {
        const bool needsTranspose = isBasisMajor(dstLayout, dstVector) != basis_major;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                int idx = needsTranspose ? i+j*4 : i*4+j;
                data[idx] = d[i][j];
            }
        }
    }


    using matrix4 = matrix44;
    using mat4 = matrix44;
}

#endif //_RMATH_MATRIX_H

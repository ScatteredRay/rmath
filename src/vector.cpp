#include "rm/vector.h"

#include <stdint.h>
#include <assert.h>
#include <cmath>

namespace rm {
    RM_FN vector2::vector2() : x(0), y(0) {}

    RM_FN vector2::vector2(float _xy) {
        this->x = this->y = _xy;
    }

    RM_FN vector2::vector2(const vector2& _xy) {
        this->x = _xy.x;
        this->y = _xy.y;
    }

    RM_FN vector2::vector2(float _x, float _y) {
        this->x = _x;
        this->y = _y;
    }

    RM_FN vector2::vector2(float _xy[2]) {
        this->d[0] = _xy[0];
        this->d[1] = _xy[1];
    }

    RM_FN float& vector2::operator[](int i) {
        RM_ASSERT(i < this->size);
        return this->d[i];
    }

    RM_FN float vector2::operator[](int i) const {
        RM_ASSERT(i < this->size);
        return this->d[i];
    }

    RM_FN vector3::vector3() : x(0), y(0), z(0) {}

    RM_FN vector3::vector3(float _xyz) {
        this->x = this->y = this->z = _xyz;
    }

    RM_FN vector3::vector3(const vector3& _xyz) {
        this->x = _xyz.x;
        this->y = _xyz.y;
        this->z = _xyz.z;
    }

    RM_FN vector3::vector3(const vector2& _xy, float _z) {
        this->x = _xy.x;
        this->y = _xy.y;
        this->z = _z;
    }

    RM_FN vector3::vector3(float _x, const vector2& _yz) {
        this->x = _x;
        this->y = _yz.x;
        this->z = _yz.y;
    }

    RM_FN vector3::vector3(float _x, float _y, float _z) {
        this->x = _x;
        this->y = _y;
        this->z = _z;
    }

    RM_FN vector3::vector3(float _xyz[size]) {
        this->d[0] = _xyz[0];
        this->d[1] = _xyz[1];
        this->d[2] = _xyz[2];
    }

    RM_FN float& vector3::operator[](int i) {
        RM_ASSERT(i < this->size);
        return this->d[i];
    }

    RM_FN float vector3::operator[](int i) const {
        RM_ASSERT(i < this->size);
        return this->d[i];
    }

    RM_FN vector2 add(const vector2& l, const vector2& r) {
        // Sort-of want to think about if I prefer a generic implementation, for algorithmic consistency...
        return vector2(
            l.x+r.x,
            l.y+r.y);
    }

    RM_FN vector2 sub(const vector2& l, const vector2& r) {
        return vector2(
            l.x-r.x,
            l.y-r.y);
    }

    RM_FN vector3 add(const vector3& l, const vector3& r) {
        return vector3(
            l.x+r.x,
            l.y+r.y,
            l.z+r.z);
    }

    RM_FN vector3 sub(const vector3& l, const vector3& r) {
        return vector3(
            l.x-r.x,
            l.y-r.y,
            l.z-r.z);
    }

    RM_FN vector2 mul(const vector2& v, float s) {
        return vector2(
            v.x*s,
            v.y*s);
    }

    RM_FN vector3 mul(const vector3& v, float s) {
        return vector3(
            v.x*s,
            v.y*s,
            v.z*s);
    }

    RM_FN float dot(const vector2& l, const vector2& r) {
        return l.x*r.x + l.y*r.y;
    }

    RM_FN float dot(const vector3& l, const vector3& r) {
        return l.x*r.x + l.y*r.y + l.z*r.z;
    }

    RM_FN vector3 cross(const vector3& l, const vector3& r) {
        return vector3(
            l.y*r.z - l.z*r.y,
            l.z*r.x - l.x*r.z,
            l.x*r.y - l.y*r.x);
    }

    RM_FN float lengthSqr(const vector2& v) {
        return dot(v, v);
    }

    RM_FN float length(const vector2& v) {
        return sqrt(lengthSqr(v));
    }

    RM_FN vector2 normalize(const vector2& v) {
        return mul(v, 1.0f/length(v));
    }

    RM_FN float lengthSqr(const vector3& v) {
        return dot(v, v);
    }

    RM_FN float length(const vector3& v) {
        return sqrt(lengthSqr(v));
    }

    RM_FN vector3 normalize(const vector3& v) {
        return mul(v, 1.0f/length(v));
    }

    RM_FN float sum(const vector2& v) {
        return dot(v, vector2(1.0f));
    }

    RM_FN float sum(const vector3& v) {
        return dot(v, vector3(1.0f));
    }

    RM_FN bool equal(const vector2& l, const vector2& r) {
        return l.x == r.x && l.y == r.y;
    }

    RM_FN bool equal(const vector3& l, const vector3& r) {
        return l.x == r.x && l.y == r.y && l.z == r.z;
    }
}
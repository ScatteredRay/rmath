#include "vector.h"

#include <stdint.h>
#include <assert.h>

namespace rm {
    vector2::vector2(float _xy) {
        this->x = this->y = _xy;
    }

    vector2::vector2(const vector2& _xy) {
        this->x = _xy.x;
        this->y = _xy.y;
    }

    vector2::vector2(float _x, float _y) {
        this->x = _x;
        this->y = _y;
    }

    vector2::vector2(float _xy[2]) {
        this->d[0] = _xy[0];
        this->d[1] = _xy[1];
    }

    float& vector2::operator[](int i) {
        assert(i < this->size);
        return this->d[i];
    }

    float vector2::operator[](int i) const {
        assert(i < this->size);
        return this->d[i];
    }

    vector3::vector3(float _xyz) {
        this->x = this->y = this->z = _xyz;
    }

    vector3::vector3(const vector3& _xyz) {
        this->x = _xyz.x;
        this->y = _xyz.y;
        this->z = _xyz.z;
    }

    vector3::vector3(const vector2& _xy, float _z) {
        this->x = _xy.x;
        this->y = _xy.y;
        this->z = _z;
    }

    vector3::vector3(float _x, const vector2& _yz) {
        this->x = _x;
        this->y = _yz.x;
        this->z = _yz.y;
    }

    vector3::vector3(float _x, float _y, float _z) {
        this->x = _x;
        this->y = _y;
        this->z = _z;
    }

    vector3::vector3(float _xyz[size]) {
        this->d[0] = _xyz[0];
        this->d[1] = _xyz[1];
        this->d[2] = _xyz[2];
    }

    float& vector3::operator[](int i) {
        assert(i < this->size);
        return this->d[i];
    }

    float vector3::operator[](int i) const {
        assert(i < this->size);
        return this->d[i];
    }

    template<typename t>
    t add(const t& l, const t& r) {
        typeof(t::d) d;
        for(size_t i = 0; i < t::size; i++) {
            d[i] = l[i] + r[i];
        }
        return t(d);
    }

    template<typename t>
    t sub(const t& l, const t& r) {
        typeof(t::d) d;
        for(size_t i = 0; i < t::size; i++) {
            d[i] = l[i] - r[i];
        }
        return t(d);
    }

    vector2 add(const vector2& l, const vector2& r) {
        // Sort-of want to think about if I prefer a generic implementation, for algorithmic consistency...
        return add<vector2>(l, r);
        // return vector2(
        //     l.x+r.x,
        //     l.y+r.y);
    }

    vector2 sub(const vector2& l, const vector2& r) {
        return vector2(
            l.x-r.x,
            l.y-r.y);
    }

    vector3 add(const vector3& l, const vector3& r) {
        return add<vector3>(l, r);
    }

    vector3 sub(const vector3& l, const vector3& r) {
        return vector3(
            l.x-r.x,
            l.y-r.y,
            l.z-r.z);
    }
}
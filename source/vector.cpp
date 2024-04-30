#include "vector.h"

#include <stdint.h>

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
        return this->d[i];
    }

    float vector2::operator[](int i) const {
        return this->d[i];
    }

    template<typename t>
    t add(const t& l, const t& r) {
        typeof(t::d) d;
        for(uint32_t i = 0; i < t::size; i++) {
            d[i] = l[i] + r[i];
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
}
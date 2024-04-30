#include "vector.h"

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

    // template<typename t>
    // t add(const t& l, t& r) {
    //     return 
    // }

    vector2 add(const vector2& l, const vector2& r) {
        return vector2(
            l.x+r.x,
            l.y+r.y);
    }

    vector2 sub(const vector2& l, const vector2& r) {
        return vector2(
            l.x-r.x,
            l.y-r.y);
    }
}
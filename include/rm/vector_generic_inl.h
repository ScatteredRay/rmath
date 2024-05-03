#ifndef _RMATH_VECTOR_GENERIC_INL_H_
#define _RMATH_VECTOR_GENERIC_INL_H_

#include "rm/vector_generic.h"

#include <assert.h>

namespace rm {

    template<typename t>
    vector<t, 2>::vector(t _d) {
        for(size_t i = 0; i < 2; i++) {
            this->d[i] = _d;
        }
    }

    template<typename t>
    vector<t, 2>::vector(t _d[2]) {
        for(size_t i = 0; i < 2; i++) {
            this->d[i] = _d[i];
        }
    }

    template<typename t>
    vector<t, 2>::vector(const vector<t, 2>& _xy) {
        this->x = _xy.x;
        this->y = _xy.y;
    }

    template<typename t>
    vector<t, 2>::vector(t _x, t _y) {
        this->x = _x;
        this->y = _y;
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

    template<typename t>
    t& vector<t, 2>::operator[](int i) {
        assert(i < this->size);
        return this->d[i];
    }

    template<typename t>
    t vector<t, 2>::operator[](int i) const {
        assert(i < this->size);
        return this->d[i];
    }
}

#endif //_RMATH_VECTOR_GENERIC_INL_H_
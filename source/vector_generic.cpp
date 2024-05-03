#include "rw/vector_generic.h"

#include "rw/vector_generic_inl.h"

namespace rm {
    vector<float, 3>::vector(float _xyz) : vector3(_xyz) {}
    vector<float, 3>::vector(const vector<float, 3>& _xyz) : vector3(_xyz) {}
    vector<float, 3>::vector(float _x, float _y, float _z) : vector3(_x, _y, _z) {}
    vector<float, 3>::vector(float _xyz[size]) : vector3(_xyz) {}
}
#include "rm/defs.h"
#include "rm/vector_generic.h"
#include "rm/vector_generic_inl.h"

#include <stdint.h>
#include <type_traits>

namespace rm {
    RM_FN vector<float, 2>::vector() : vector2() {}
    RM_FN vector<float, 2>::vector(float _xy) : vector2(_xy) {}
    RM_FN vector<float, 2>::vector(float _x, float _y) : vector2(_x, _y) {}
    RM_FN vector<float, 2>::vector(float _xy[size]) : vector2(_xy) {}

    RM_FN vector<float, 3>::vector() : vector3() {}
    RM_FN vector<float, 3>::vector(float _xyz) : vector3(_xyz) {}
    //RM_FN vector<float, 3>::vector(const vector<float, 3>& _xyz) : vector3(_xyz) {}
    RM_FN vector<float, 3>::vector(float _x, float _y, float  _z) : vector3(_x, _y, _z) {}
    RM_FN vector<float, 3>::vector(float _xyz[size]) : vector3(_xyz) {}

    RM_FN vector<float, 4>::vector() : vector4() {}
    RM_FN vector<float, 4>::vector(float _xyzw) : vector4(_xyzw) {}
    RM_FN vector<float, 4>::vector(float _x, float _y, float  _z, float _w) : vector4(_x, _y, _z, _w) {}
    RM_FN vector<float, 4>::vector(float _xyzw[size]) : vector4(_xyzw) {}

    // Explicit template instantiation.
    template class vector<uint32_t, 2>;
    template class vector<int32_t, 2>;
    //template vector<uint32_t, 2>::vector(t _d);
    //template vector<uint32_t, 2>::vector(const vector<t, 2>& _xy);
    //template vector<uint32_t, 2>::vector(t _x, t _y);
    //template<> vector<uint32_t, 2>::vector(uint32_t _d[2]);

    template RM_FN vector<int32_t, 2> add(const vector<int32_t, 2>&, const vector<int32_t, 2>&);
    template RM_FN vector<uint32_t, 2> add(const vector<uint32_t, 2>&, const vector<uint32_t, 2>&);
    template RM_FN vector<float, 2> add(const vector<float, 2>&, const vector<float, 2>&);
    template RM_FN vector<float, 3> add(const vector<float, 3>&, const vector<float, 3>&);
    template RM_FN vector<float, 4> add(const vector<float, 4>&, const vector<float, 4>&);

    template RM_FN vector<int32_t, 2> sub(const vector<int32_t, 2>&, const vector<int32_t, 2>&);
    template RM_FN vector<uint32_t, 2> sub(const vector<uint32_t, 2>&, const vector<uint32_t, 2>&);
    template RM_FN vector<float, 2> sub(const vector<float, 2>&, const vector<float, 2>&);
    template RM_FN vector<float, 3> sub(const vector<float, 3>&, const vector<float, 3>&);
    template RM_FN vector<float, 4> sub(const vector<float, 4>&, const vector<float, 4>&);

    static_assert(std::is_trivially_copyable<vector<float, 2>>::value);
    static_assert(std::is_trivially_copyable<vector<float, 3>>::value);
    static_assert(std::is_trivially_copyable<vector<float, 4>>::value);

    static_assert(std::is_trivially_copyable<vector<int32_t, 2>>::value);
    static_assert(std::is_trivially_copyable<vector<int32_t, 3>>::value);
    static_assert(std::is_trivially_copyable<vector<int32_t, 4>>::value);

    static_assert(std::is_trivially_copyable<vector<uint32_t, 2>>::value);
    static_assert(std::is_trivially_copyable<vector<uint32_t, 3>>::value);
    static_assert(std::is_trivially_copyable<vector<uint32_t, 4>>::value);
}

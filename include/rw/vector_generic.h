#include "rw/vector.h"

namespace rm {
    template<typename t, size_t length>
    struct vector {
    };

    template<>
    struct vector<float, 3> : public vector3 {
        vector(float _xyz);
        vector(const vector<float, 3>& _xyz);
        vector(float _x, float _y, float _z);
        vector(float _xyz[size]);
    };
}
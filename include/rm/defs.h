#ifndef _RMATH_DEFS_H_
#define _RMATH_DEFS_H_


// We want RMath to be usable in hip/cuda.
#ifdef __HIPCC__
#define RM_FN __device__ __host__
#define RM_ASSERT(...)
#else
#define RM_FN
#define RM_ASSERT assert
#endif

#endif //_RMATH_DEFS_H_
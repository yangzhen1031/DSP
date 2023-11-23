#ifndef DSP_MATH_TYPE_H_
#define DSP_MATH_TYPE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <math.h>
#include <float.h>
#include <limits.h>

/**
 * @brief 16-bit fractional data type in 1.15 format
 * 
 */
typedef int16_t q15_t;

/**
 * @brief 32-bit fractional data type in 1.31 format
 * 
 */
typedef int32_t q31_t;

/**
 * @brief 32-bit floating-point type definition
 * 
 */
typedef float float32_t;

/**
 * @brief 64-bit floating-point type definition
 * 
 */
typedef double float64_t;


#define Q15_MAX ((q15_t) (0x7FFF))
#define Q31_MAX ((q31_t) (0x7FFFFFFFL))

#define Q15_MIN ((q15_t) (0x8000))
#define Q31_MIN ((q31_t) (0x80000000L))

#define Q15_ABS_MAX ((q15_t) (0x7FFF))
#define Q31_ABS_MAX ((q31_t) (0x7FFFFFFFL))

#define Q15_ABS_MIN ((q15_t) 0)
#define Q31_ABS_MIN ((q31_t) 0)

#define F32_MAX ((float32_t) FLT_MAX)
#define F64_MAX ((float64_t) DBL_MAX)

#define F32_MIN ((float32_t) -FLT_MAX)
#define F64_MIN ((float64_t) -DBL_MAX)

#define F32_ABS_MAX ((float32_t) FLT_MAX)
#define F64_ABS_MAX ((float64_t) DBL_MAX)

#define F32_ABS_MIN ((float32_t) 0.0)
#define F64_ABS_MIN ((float64_t) 0.0)

typedef enum {
    DSP_MATH_SUCCESS = 0,
    DSP_MATH_LENGTH_ERROR = 1,
} DspStatus;


#ifdef __cplusplus
}
#endif


#endif

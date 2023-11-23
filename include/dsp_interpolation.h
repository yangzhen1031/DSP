#ifndef DSP_INTERPOLATION_FUNC_H_
#define DSP_INTERPOLATION_FUNC_H_

#include "dsp_math_types.h"

typedef struct {
    uint32_t n_values;
    float32_t x1;
    float32_t x_spacing;
    const float32_t* p_y;
} DspLinearInterpInsF32;


typedef enum {
    DSP_SPLINE_NATURAL = 0,
    DSP_SPLINE_PARABOLIC_RUNOUT = 1
} DspSplineType;

typedef struct {    
    DspSplineType type;
    const float32_t* p_x;
    const float32_t* p_y;
    uint32_t n_x;
    float32_t* coeffs;
} DspSplineInsF32;

float32_t DspLinearInterpF32(DspLinearInterpInsF32* p_interp, float32_t x);

void DspSplineF32Init(DspSplineInsF32* p_interp, 
DspSplineType type, 
const float32_t* x, 
const float32_t* y,
uint32_t n,
float32_t* coeffs, 
float32_t* temp_buffer);

void DspSplineF32(DspSplineInsF32* p_interp, 
const float32_t* p_src,
float32_t* p_dst,
uint32_t block_size);

#endif
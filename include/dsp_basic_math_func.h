#ifndef DSP_MATH_BASIC_MATH_FUNC_H_
#define DSP_MATH_BASIC_MATH_FUNC_H_

#include "dsp_math_types.h"
#include "dsp_math_utils.h"

// float32 basic math functions
void DspAbsF32(float32_t* p_dst, const float32_t* p_src, uint32_t size);
void DspAddF32(float32_t* p_dst, const float32_t* p_src1, const float32_t* p_src2, uint32_t size);
void DspClipF32(float32_t* p_dst, const float32_t* p_src, float32_t low, float32_t high, uint32_t size);
void DspDotProdF32(const float32_t* p_src1, const float32_t* p_src2, uint32_t size, float32_t* p_res);
void DspMultF32(float32_t* pst, const float32_t* p_src1, const float32_t* p_src2, uint32_t size);
void DspNegateF32(float32_t* pst, const float32_t* p_src, uint32_t size);
void DspOffsetF32(float32_t* p_dst, const float32_t* p_src, float32_t offset, uint32_t size);
void DspScaleF32(float32_t* p_dst, const float32_t* p_src, float32_t scale, uint32_t size);
void DspSubF32(float32_t* p_dst, const float32_t* p_src1, const float32_t* p_src2, uint32_t size);



#endif
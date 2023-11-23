#ifndef DSP_MATH_BASIC_MATH_FUNC_H_
#define DSP_MATH_BASIC_MATH_FUNC_H_

#include "dsp_math_types.h"
#include "dsp_math_utils.h"

// float32 basic math functions
void DspAbsF32(const float32_t* p_src, float32_t* p_dst, uint32_t block_size);
void DspAddF32(const float32_t* p_src1, const float32_t* p_src2, float32_t* p_dst, uint32_t block_size);
void DspClipF32(const float32_t* p_src, float32_t* p_dst, float32_t low, float32_t high, uint32_t block_size);
void DspDotProdF32(const float32_t* p_src1, const float32_t* p_src2, uint32_t block_size, float32_t* p_res);
void DspMultF32(const float32_t* p_src1, const float32_t* p_src2, float32_t* pst, uint32_t block_size);
void DspNegateF32(const float32_t* p_src, float32_t* p_dst, uint32_t block_size);
void DspOffsetF32(const float32_t* p_src, float32_t offset, float32_t* p_dst, uint32_t block_size);
void DspScaleF32(const float32_t* p_src,  float32_t scale, float32_t* p_dst, uint32_t block_size);
void DspSubF32(const float32_t* p_src1, const float32_t* p_src2, float32_t* p_dst, uint32_t block_size);


#endif
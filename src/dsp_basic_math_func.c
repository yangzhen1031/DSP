#include "dsp_basic_math_func.h"

void DspAbsF32(const float32_t* p_src, float32_t* p_dst, uint32_t block_size) {
    uint32_t block_cnt;
    block_cnt = block_size;
    while (block_cnt > 0) {
        *p_dst++ = fabsf(*p_src++);
        block_cnt--;
    }
}

void DspAddF32(const float32_t* p_src1, const float32_t* p_src2, float32_t* p_dst, uint32_t block_size) {
    uint32_t block_cnt;
    block_cnt = block_size;
    while (block_cnt > 0) {
        *p_dst++ = (*p_src1++) + (*p_src2++);
        block_cnt--;
    }
}

void DspClipF32(const float32_t* p_src, float32_t* p_dst, float32_t low, float32_t high, uint32_t block_size) {
    uint32_t i;
    for (i = 0; i < block_size; ++i) {
        if (p_src[i] > high) {
            p_dst[i] = high;
        } else if (p_src[i] < low) {
            p_dst[i] = low;
        } else {
            p_dst[i] = p_src[i];
        }
    }
}

void DspDotProdF32(const float32_t* p_src1, const float32_t* p_src2, uint32_t block_size, float32_t* p_res) {
    uint32_t block_cnt;
    block_cnt = block_size;
    float32_t sum;
    sum = 0.0f;
    while (block_cnt > 0) {
        sum += (*p_src1++) * (*p_src2++);
        block_cnt--;
    }
    
}

void DspMultF32(const float32_t* p_src1, const float32_t* p_src2, float32_t* p_dst, uint32_t block_size) {
    uint32_t block_cnt;
    block_cnt = block_size;    
    while (block_cnt > 0) {
        *p_dst++ = (*p_src1++) * (*p_src2++);
        block_cnt--;
    }
}

void DspNegateF32(const float32_t* p_src, float32_t* p_dst, uint32_t block_size) {
    uint32_t block_cnt;
    block_cnt = block_size;
    while (block_cnt > 0) {
        *p_dst++ = -(*p_src++);
        block_cnt--;
    }
}

void DspOffsetF32(const float32_t* p_src, float32_t offset, float32_t* p_dst, uint32_t block_size) {
    uint32_t block_cnt;
    block_cnt = block_size;
    while (block_cnt > 0) {
        *p_dst++ = (*p_src++) + offset;
        block_cnt--;
    }
}

void DspScaleF32(const float32_t* p_src,  float32_t scale, float32_t* p_dst, uint32_t block_size) {
    uint32_t block_cnt;
    block_cnt = block_size;
    while (block_cnt > 0) {
        *p_dst++ = (*p_src++) * scale;
        block_cnt--;
    }
}

void DspSubF32(const float32_t* p_src1, const float32_t* p_src2, float32_t* p_dst, uint32_t block_size) {
    uint32_t block_cnt;
    block_cnt = block_size;
    while (block_cnt > 0) {
        *p_dst++ = (*p_src1++) - (*p_src2++);
        block_cnt--;
    }
}
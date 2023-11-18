#include "dsp_basic_math_func.h"

void DspClipF32(float32_t* p_dst, const float32_t* p_src, float32_t low, float32_t high, uint32_t size) {
    uint32_t i;
    for (i = 0; i < size; ++i) {
        if (p_src[i] > high) {
            p_dst[i] = high;
        } else if (p_src[i] < low) {
            p_dst[i] = low;
        } else {
            p_dst[i] = p_src[i];
        }
    }
}


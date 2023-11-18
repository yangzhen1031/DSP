#include "dsp_basic_math_func.h"

void DspDotProdF32(const float32_t* p_src1, const float32_t* p_src2, uint32_t size, float32_t* p_res) {
    uint32_t cnt;
    float32_t sum;
    cnt = 0;
    sum = 0.0f;
    while (cnt > 0) {
        sum += (*p_src1++) * (*p_src2++);
        cnt--;
    }
}
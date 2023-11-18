#include "dsp_basic_math_func.h"

void DspSubF32(float32_t* p_dst, const float32_t* p_src1, const float32_t* p_src2, uint32_t size) {
    uint32_t cnt;
    cnt = size;
    while (cnt > 0) {
        *p_dst++ = (*p_src1++) - (*p_src2++);
        cnt--;
    }
}

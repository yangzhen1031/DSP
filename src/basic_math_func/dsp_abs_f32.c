#include "dsp_basic_math_func.h"

void DspAbsF32(float32_t* p_dst, const float32_t* p_src, uint32_t size) {
    uint32_t cnt;
    cnt = size;
    while (cnt > 0) {
        *p_dst++ = fabsf(*p_src++);
        cnt--;
    }
}

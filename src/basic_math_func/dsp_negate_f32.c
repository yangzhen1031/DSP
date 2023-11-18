#include "dsp_basic_math_func.h"

void DspNegateF32(float32_t* pst, const float32_t* p_src, uint32_t size) {
    uint32_t cnt;
    cnt = size;
    while (cnt > 0) {
        *pst++ = -(*p_src++);
        cnt--;
    }
}

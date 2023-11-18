#include "dsp_basic_math_func.h"

void DspScaleF32(float32_t* p_dst, const float32_t* p_src, float32_t scale, uint32_t size) {
    uint32_t cnt = 0;
    cnt = size;
    while (cnt > 0) {
        *p_dst++ = (*p_src++) * scale;
        cnt--;
    }
}

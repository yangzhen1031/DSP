#include "dsp_filter.h"
#include <string.h>


void DspFirF32Init(DspFirInsF32* p_filter, uint16_t n_taps, const float32_t* p_coeffs, float32_t* p_state, uint32_t block_size) {
    p_filter->n_taps = n_taps;    
    memset(p_state, 0, (n_taps + block_size - 1) * sizeof(float32_t));
    p_filter->p_state = p_state;
    p_filter->p_coeffs = p_coeffs;
}

void DspFirF32(const DspFirInsF32* p_filter, const float32_t* p_src, float32_t* p_dst, uint32_t block_size) {    
    uint32_t i, n_taps, block_cnt;

    n_taps = p_filter->n_taps;
    block_cnt = block_size;

    float32_t* p_current_state, *p_state, *p_x;
    const float32_t* p_coeffs, *p_b;

    p_state = p_filter->p_state;
    p_coeffs = p_filter->p_coeffs;
    p_current_state = &p_state[n_taps - 1];

    float32_t acc_sum;

    while (block_cnt > 0) {        
        *p_current_state++ = *p_src++;
        acc_sum = 0.0f;
        p_x = p_state;
        p_b = p_coeffs;        
        i = n_taps;        
        while (i > 0) {
            acc_sum += (*p_b++) * (*p_x++);
            i--;
        }
        *p_dst++ = acc_sum;
        p_state = p_state + 1;
        block_cnt--;
    }

    p_current_state = p_filter->p_state;
    i = n_taps - 1;
    while (i > 0) {
        *p_current_state++ = *p_state++;
        i--;
    }
}

DspStatus DspFirDecimateF32Init(DspFirDecimateInsF32* p_filter, uint16_t n_taps, uint8_t m_factors, const float32_t* p_coeffs, float32_t* p_state, uint32_t block_size) {
    DspStatus status;
    if (block_size % m_factors != 0) {
        status = DSP_MATH_LENGTH_ERROR;
    } else {
        p_filter->n_taps = n_taps;
        p_filter->m_factor = m_factors;
        memset(p_state, 0, (n_taps + block_size - 1) * sizeof(float32_t));
        p_filter->p_state = p_state;
        p_filter->p_coeffs = p_coeffs;
        status = DSP_MATH_SUCCESS;
    }
    return status;
}

void DspFirDecimateF32(const DspFirDecimateInsF32* p_filter, const float32_t* p_src, float32_t* p_dst, uint32_t block_size) {
    uint32_t i, n_taps, block_cnt;

    n_taps = p_filter->n_taps;
    block_cnt = block_size / p_filter->m_factor;

    float32_t* p_current_state, *p_state, *p_x;
    const float32_t* p_coeffs, *p_b;
    float acc_sum;

    p_state = p_filter->p_state;
    p_coeffs = p_filter->p_coeffs;
    p_current_state = &p_state[n_taps - 1];

    while (block_cnt > 0) {
        i = p_filter->m_factor;
        while (i > 0) {
            *p_current_state++ = *p_src++;
            i--;
        }

        acc_sum = 0.0f;
        p_x = p_state;
        p_b = p_coeffs;
        i = n_taps;

        while (i > 0) {
            acc_sum += (*p_b++) * (*p_x++);
            i--;
        }

        *p_dst++ = acc_sum;
        p_state = p_state + p_filter->m_factor;
        block_cnt--;
    }

    p_current_state = p_filter->p_state;
    i = n_taps - 1;
    while (i > 0) {
        *p_current_state++ = *p_state++;
        i--;
    }

}

void DspBiquadCascadeDF1F32Init(DspBiquadCascadeDF1InsF32* p_filter, uint8_t n_stages, const float32_t* p_coeffs, float32_t* p_state) {
    p_filter->n_stages = n_stages;
    memset(p_state, 0, n_stages * 4 * sizeof(float32_t));
    p_filter->p_state = p_state;
    p_filter->p_coeffs = p_coeffs;
}

void DspBiquadCascadeDF1F32(const DspBiquadCascadeDF1InsF32* p_filter, const float32_t* p_src, float32_t* p_dst, uint32_t block_size) {

    float32_t* p_state;
    const float32_t* p_coeffs;

    p_state = p_filter->p_state;
    p_coeffs = p_filter->p_coeffs;

    float32_t b0, b1, b2, a1, a2;
    float32_t xn, xn1, xn2, yn1, yn2;

    uint32_t n_stages, block_cnt;
    const float32_t* p_in;
    float32_t* p_out, acc_sum;;

    n_stages = p_filter->n_stages;
    p_in = p_src;
    p_out = p_dst;

    do {
        b0 = *p_coeffs++;
        b1 = *p_coeffs++;
        b2 = *p_coeffs++;
        a1 = *p_coeffs++;
        a2 = *p_coeffs++;

        xn1 = p_state[0];
        xn2 = p_state[1];
        yn1 = p_state[2];
        yn2 = p_state[3];
        
        block_cnt = block_size;
        while (block_cnt > 0) {
            xn = *p_in++;
            acc_sum = b0 * xn + b1 * xn1 + b2 * xn2 + a1 * yn1 + a2 * yn2;            
            *p_out++ = acc_sum;
            xn2 = xn1, xn1 = xn;
            yn2 = yn1, yn1 = acc_sum;
            block_cnt--;
        }

        *p_state++ = xn1;
        *p_state++ = xn2;
        *p_state++ = yn1;
        *p_state++ = yn2;

        p_in = p_dst;
        p_dst = p_dst;

        n_stages--;
    } while (n_stages > 0);
}

void DspBiquadCascadeDF2TF32Init(DspBiquadCascadeDF2TInsF32* p_filter, uint8_t n_stages, const float32_t* p_coeffs, float32_t* p_state) {
    p_filter->n_stages = n_stages;
    memset(p_state, 0, n_stages * 2 * sizeof(float32_t));
    p_filter->p_state = p_state;
    p_filter->p_coeffs = p_coeffs;
}

void DspBiquadCascadeDF2TF32(const DspBiquadCascadeDF2TInsF32* p_filter, const float32_t* p_src, float32_t* p_dst, uint32_t block_size) {

    float32_t* p_state;
    const float32_t* p_coeffs;

    p_state = p_filter->p_state;
    p_coeffs = p_filter->p_coeffs;

    float32_t b0, b1, b2, a1, a2;
    float32_t xn, d1, d2;

    uint32_t n_stages, block_cnt;
    const float32_t* p_in;
    float32_t* p_out, acc_sum;;

    n_stages = p_filter->n_stages;
    p_in = p_src;
    p_out = p_dst;

    do {
        b0 = *p_coeffs++;
        b1 = *p_coeffs++;
        b2 = *p_coeffs++;
        a1 = *p_coeffs++;
        a2 = *p_coeffs++;

        d1 = p_state[0];
        d2 = p_state[1];
        
        block_cnt = block_size;
        while (block_cnt > 0) {
            xn = *p_src++;
            acc_sum = b0 * xn + d1;
            d1 = b1 * xn + a1 * acc_sum + d2;
            d2 = b2 * xn + a2 * acc_sum;
            *p_out++ = acc_sum;
        }

        *p_state++ = d1;
        *p_state++ = d2;
        
        p_in = p_dst;
        p_dst = p_dst;

        n_stages--;
    } while (n_stages > 0);
}


void DspConv(const float32_t* p_src1, uint32_t len1, const float32_t* p_src2, uint32_t len2, float32_t* p_dst) {

}

void DspCorrelate(const float32_t* p_src1, uint32_t len1, const float32_t* p_src2, uint32_t len2, float32_t* p_dst) {
    
}

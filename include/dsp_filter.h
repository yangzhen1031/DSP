#ifndef DSP_FILTER_FUNC_H_
#define DSP_FILTER_FUNC_H_

#include "dsp_math_types.h"

typedef struct {
    uint16_t n_taps;                 // number of filter coefficients
    float32_t* p_state;              // state variable array length = n_taps + block_size - 1   x[n-n_taps+1] x[n-n_taps+2] ... x[n-1] x[n] x[n+1] ... x[n+block_size-1]
    const float32_t* p_coeffs;      // filter coefficients  length = n_taps                    b[n_taps-1]   b[n_taps-2]   ... b[1]   b[0]            
} DspFirInsF32;

typedef struct {
    uint8_t m_factor;
    uint16_t n_taps;
    float32_t* p_state;
    const float32_t* p_coeffs;
} DspFirDecimateInsF32;

typedef struct {
    uint8_t n_stages;
    float32_t* p_state;
    const float32_t* p_coeffs;
} DspBiquadCascadeDF1InsF32;

typedef struct {
    uint8_t n_stages;
    float32_t* p_state;
    const float32_t* p_coeffs;
} DspBiquadCascadeDF2TInsF32;


void DspFirF32Init(DspFirInsF32* p_filter, uint16_t n_taps, const float32_t* p_coeffs, float32_t* p_state, uint32_t block_size);

void DspFirF32(const DspFirInsF32* p_filter, const float32_t* p_src, float32_t* p_dst, uint32_t block_size);

DspStatus DspFirDecimateF32Init(DspFirDecimateInsF32* p_filter, uint16_t n_taps, uint8_t m_factors, const float32_t* p_coeffs, float32_t* p_state, uint32_t block_size);

void DspFirDecimateF32(const DspFirDecimateInsF32* p_filter, const float32_t* p_src, float32_t* p_dst, uint32_t block_size);

void DspBiquadCascadeDF1F32Init(DspBiquadCascadeDF1InsF32* p_filter, uint8_t n_stages, const float32_t* p_coeffs, float32_t* p_state);

void DspBiquadCascadeDF1F32(const DspBiquadCascadeDF1InsF32* p_filter, const float32_t* p_src, float32_t* p_dst, uint32_t block_size);

void DspBiquadCascadeDF2TF32Init(DspBiquadCascadeDF2TInsF32* p_filter, uint8_t n_stages, const float32_t* p_coeffs, float32_t* p_state);

void DspBiquadCascadeDF2TF32(const DspBiquadCascadeDF2TInsF32* p_filter, const float32_t* p_src, float32_t* p_dst, uint32_t block_size);

void DspConv(const float32_t* p_src1, uint32_t len1, 
             const float32_t* p_src2, uint32_t len2, 
             float32_t* p_dst);

void DspCorrelate(const float32_t* p_src1, uint32_t len1, 
                  const float32_t* p_src2, uint32_t len2,
                  float32_t* p_dst);


#endif
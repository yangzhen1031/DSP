#include "dsp_interpolation.h"


float32_t DspLinearInterpF32(DspLinearInterpInsF32* p_interp, float32_t x) {

    float32_t x0, x1;
    float32_t y0, y1;
    float32_t y;
    
    const float32_t* p_y;
    float32_t spacing;    
    int32_t i;

    p_y = p_interp->p_y;
    spacing = p_interp->x_spacing;    
    i = (int32_t) ((x - p_interp->x1) / spacing);

    if (x < p_interp->x1) {
        y = p_y[0];
    } else if (i >= p_interp->n_values - 1) {
        y = p_y[p_interp->n_values - 1];
    } else {

        x0 = p_interp->x1 + i * spacing;
        x1 = p_interp->x1 + (i + 1) * spacing;

        y0 = p_y[i];
        y1 = p_y[i + 1];

        y = y0 + (x - x0) * (y1 - y0) / (x1 - x0);
    }
    return y;
}


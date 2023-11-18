cmake_minimum_required(VERSION 3.12)

set(SRCF32 dsp_abs_f32.c
dsp_add_f32.c
dsp_clip_f32.c
dsp_dot_prod_f32.c
dsp_dot_mult_f32.c
dsp_negate_f32.c
dsp_offset_f32.c
dsp_scale_f32.c
dsp_sub_f32.c)

target_sources(DSP private ${SRCF32})

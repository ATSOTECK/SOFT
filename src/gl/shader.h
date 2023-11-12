//
// Created by Skyler on 11/11/23.
//

#ifndef SOFT_SHADER_H
#define SOFT_SHADER_H

#include "common.h"

u32 newVertexShader(const char *source);
u32 newFragmentShader(const char *source);

u32 newShaderProgramFromSource(const char *vertex, const char *fragment);

#endif //SOFT_SHADER_H

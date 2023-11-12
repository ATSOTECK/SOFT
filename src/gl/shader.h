//
// Created by Skyler on 11/11/23.
//

#ifndef SOFT_SHADER_H
#define SOFT_SHADER_H

#include "common.h"

u32 newVertexShader(const char *source);
u32 newFragmentShader(const char *source);

u32 newShaderFromSource(const char *vertex, const char *fragment);
u32 newShaderFromFile(const char *vertex, const char *fragment);

void shaderSetBool(u32 shader, const char *name, bool value);
void shaderSetInt(u32 shader, const char *name, int value);
void shaderSetFloat(u32 shader, const char *name, f32 value);

#endif //SOFT_SHADER_H

//
// Created by Skyler on 11/11/23.
//

#include <stdio.h>

#include <glad/glad.h>

#include "common.h"
#include "util.h"

u32 newVertexShader(const char *source) {
    if (source == nullptr) {
        fprintf(stderr, "newVertexShader passed nullptr\n");
        return 0;
    }

    u32 vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &source, nullptr);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        fprintf(stderr, "Vertex shader failed to compile!\n%s\n", infoLog);
        return 0;
    }

    return vertexShader;
}

u32 newFragmentShader(const char *source) {
    if (source == nullptr) {
        fprintf(stderr, "newFragmentShader passed nullptr\n");
        return 0;
    }

    u32 fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &source, nullptr);
    glCompileShader(fragmentShader);
    int success;
    char infoLog[512];
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        fprintf(stderr, "Fragment shader failed to compile!\n%s\n", infoLog);
        return 0;
    }

    return fragmentShader;
}

u32 newShaderFromSource(const char *vertex, const char *fragment) {
    u32 vertexShader = newVertexShader(vertex);
    u32 fragmentShader = newFragmentShader(fragment);
    if (vertexShader == 0 || fragmentShader == 0) {
        return 0;
    }

    u32 shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        fprintf(stderr, "Failed to link shader program!\n%s\n", infoLog);
        return 0;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

u32 newShaderFromFile(const char *vertex, const char *fragment) {
    if (vertex == nullptr) {
        fprintf(stderr, "vertex passed to newShaderFromFile as nullptr\n");
        return 0;
    }

    if (fragment == nullptr) {
        fprintf(stderr, "fragment passed to newShaderFromFile as nullptr\n");
    }

    const char *vertexSource = readFileToStr(vertex);
    const char *fragmentSource = readFileToStr(fragment);
    if (vertexSource == nullptr || fragmentSource == nullptr) {
        return 0;
    }

    return newShaderFromSource(vertexSource, fragmentSource);
}

void shaderSetBool(u32 shader, const char *name, bool value) {
    glUniform1i(glGetUniformLocation(shader, name), value);
}

void shaderSetInt(u32 shader, const char *name, int value) {
    glUniform1i(glGetUniformLocation(shader, name), value);
}

void shaderSetFloat(u32 shader, const char *name, f32 value) {
    glUniform1f(glGetUniformLocation(shader, name), value);
}

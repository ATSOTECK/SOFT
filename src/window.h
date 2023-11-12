//
// Created by Skyler on 11/11/23.
//

#ifndef SOFT_WINDOW_H
#define SOFT_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "common.h"

static const int WINDOW_WIDTH_DEFAULT = 1200;
static const int WINDOW_HEIGHT_DEFAULT = 720;

GLFWwindow *newWindow(int w, int h, char *title);

#endif //SOFT_WINDOW_H

//
// Created by Skyler on 11/11/23.
//

#include "window.h"

#include <stdio.h>

#include "input.h"

void windowResizeCallback(GLFWwindow *window, int w, int h) {
    glViewport(0, 0, w, h);
}

GLFWwindow *newWindow(int w, int h, char *title) {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW!\n");
        return nullptr;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (w == 0) {
        w = WINDOW_WIDTH_DEFAULT;
    }

    if (h == 0) {
        h = WINDOW_HEIGHT_DEFAULT;
    }

    GLFWwindow* window = glfwCreateWindow(w, h, title, nullptr, nullptr);
    if (window == nullptr) {
        fprintf(stderr, "Failed to create GLFW window!\n");
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        fprintf(stderr, "Failed to initialize GLAD!\n");
        return nullptr;
    }

    glViewport(0, 0, w, h);
    glfwSetFramebufferSizeCallback(window, windowResizeCallback);

    inputInit(window);

    return window;
}

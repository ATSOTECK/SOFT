//
// Created by Skyler on 11/11/23.
//

#include "window.h"

#include <stdio.h>

void windowResizeCallback(GLFWwindow *window, int w, int h) {
    glViewport(0, 0, w, h);
}

GLFWwindow *newWindow(int w, int h, char *title) {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW!\n");
        return NULL;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (w == 0) {
        w = WINDOW_WIDTH_DEFAULT;
    }

    if (h == 0) {
        h = WINDOW_HEIGHT_DEFAULT;
    }

    GLFWwindow* window = glfwCreateWindow(w, h, title, NULL, NULL);
    if (window == NULL) {
        fprintf(stderr, "Failed to create GLFW window!\n");
        glfwTerminate();
        return NULL;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        fprintf(stderr, "Failed to initialize GLAD!\n");
        return NULL;
    }

    glViewport(0, 0, w, h);
    glfwSetFramebufferSizeCallback(window, windowResizeCallback);

    return window;
}

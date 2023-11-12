//
// Created by Skyler on 11/11/23.
//

#include "input.h"

#include <string.h>
#include <stdlib.h>

static bool *currentKeyState;
static bool *previousKeyState;
static bool *currentButtonState;
static bool *previousButtonState;

static GLFWwindow *inputWindow;

void inputInit(GLFWwindow *window) {
    inputWindow = window;
    currentKeyState     = (bool*)calloc(vk_keyCount    - 1, sizeof(bool));
    previousKeyState    = (bool*)calloc(vk_keyCount    - 1, sizeof(bool));
    currentButtonState  = (bool*)calloc(mb_buttonCount - 1, sizeof(bool));
    previousButtonState = (bool*)calloc(mb_buttonCount - 1, sizeof(bool));
}

void inputUpdate() {
    memcpy(previousKeyState,    currentKeyState,    (vk_keyCount    - 1) * sizeof(bool));
    memcpy(previousButtonState, currentButtonState, (mb_buttonCount - 1) * sizeof(bool));

    for (int i = 1; i < vk_keyCount; ++i) {
        currentKeyState[i - 1] = glfwGetKey(inputWindow, keyToGLFWKey(i));
    }

    for (int i = 1; i < mb_buttonCount; ++i) {
        currentButtonState[i - 1] = glfwGetMouseButton(inputWindow, buttonToGLFWButton(i + 200));
    }
}

int keyToGLFWKey(int key) {
    switch (key) {
        default:
        case vk_unknown:      return GLFW_KEY_UNKNOWN;
        case vk_a:            return GLFW_KEY_A;
        case vk_b:            return GLFW_KEY_B;
        case vk_c:            return GLFW_KEY_C;
        case vk_d:            return GLFW_KEY_D;
        case vk_e:            return GLFW_KEY_E;
        case vk_f:            return GLFW_KEY_F;
        case vk_g:            return GLFW_KEY_G;
        case vk_h:            return GLFW_KEY_H;
        case vk_i:            return GLFW_KEY_I;
        case vk_j:            return GLFW_KEY_J;
        case vk_k:            return GLFW_KEY_K;
        case vk_l:            return GLFW_KEY_L;
        case vk_m:            return GLFW_KEY_M;
        case vk_n:            return GLFW_KEY_N;
        case vk_o:            return GLFW_KEY_O;
        case vk_p:            return GLFW_KEY_P;
        case vk_q:            return GLFW_KEY_Q;
        case vk_r:            return GLFW_KEY_R;
        case vk_s:            return GLFW_KEY_S;
        case vk_t:            return GLFW_KEY_T;
        case vk_u:            return GLFW_KEY_U;
        case vk_v:            return GLFW_KEY_V;
        case vk_w:            return GLFW_KEY_W;
        case vk_x:            return GLFW_KEY_X;
        case vk_y:            return GLFW_KEY_Y;
        case vk_z:            return GLFW_KEY_Z;
        case vk_num0:         return GLFW_KEY_0;
        case vk_num1:         return GLFW_KEY_1;
        case vk_num2:         return GLFW_KEY_2;
        case vk_num3:         return GLFW_KEY_3;
        case vk_num4:         return GLFW_KEY_4;
        case vk_num5:         return GLFW_KEY_5;
        case vk_num6:         return GLFW_KEY_6;
        case vk_num7:         return GLFW_KEY_7;
        case vk_num8:         return GLFW_KEY_8;
        case vk_num9:         return GLFW_KEY_9;
        case vk_escape:       return GLFW_KEY_ESCAPE;
        case vk_lControl:     return GLFW_KEY_LEFT_CONTROL;
        case vk_lShift:       return GLFW_KEY_LEFT_SHIFT;
        case vk_lAlt:         return GLFW_KEY_LEFT_ALT;
        case vk_lSystem:      return GLFW_KEY_LEFT_SUPER;
        case vk_rControl:     return GLFW_KEY_RIGHT_CONTROL;
        case vk_rShift:       return GLFW_KEY_RIGHT_SHIFT;
        case vk_rAlt:         return GLFW_KEY_RIGHT_ALT;
        case vk_rSystem:      return GLFW_KEY_RIGHT_SUPER;
        case vk_menu:         return GLFW_KEY_MENU;
        case vk_lBracket:     return GLFW_KEY_LEFT_BRACKET;
        case vk_rBracket:     return GLFW_KEY_RIGHT_BRACKET;
        case vk_semicolon:    return GLFW_KEY_SEMICOLON;
        case vk_comma:        return GLFW_KEY_COMMA;
        case vk_period:       return GLFW_KEY_PERIOD;
        case vk_quote:        return GLFW_KEY_APOSTROPHE;
        case vk_slash:        return GLFW_KEY_SLASH;
        case vk_backslash:    return GLFW_KEY_BACKSLASH;
        case vk_tilde:        return GLFW_KEY_GRAVE_ACCENT;
        case vk_equal:        return GLFW_KEY_EQUAL;
        case vk_dash:         return GLFW_KEY_MINUS;
        case vk_space:        return GLFW_KEY_SPACE;
        case vk_return:       return GLFW_KEY_ENTER;
        case vk_backspace:    return GLFW_KEY_BACKSPACE;
        case vk_tab:          return GLFW_KEY_TAB;
        case vk_pageUp:       return GLFW_KEY_PAGE_UP;
        case vk_pageDown:     return GLFW_KEY_PAGE_DOWN;
        case vk_end:          return GLFW_KEY_END;
        case vk_home:         return GLFW_KEY_HOME;
        case vk_insert:       return GLFW_KEY_INSERT;
        case vk_delete:       return GLFW_KEY_DELETE;
        case vk_add:          return GLFW_KEY_KP_ADD;
        case vk_subtract:     return GLFW_KEY_KP_SUBTRACT;
        case vk_multiply:     return GLFW_KEY_KP_MULTIPLY;
        case vk_divide:       return GLFW_KEY_KP_DIVIDE;
        case vk_left:         return GLFW_KEY_LEFT;
        case vk_right:        return GLFW_KEY_RIGHT;
        case vk_up:           return GLFW_KEY_UP;
        case vk_down:         return GLFW_KEY_DOWN;
        case vk_numpad0:      return GLFW_KEY_KP_0;
        case vk_numpad1:      return GLFW_KEY_KP_1;
        case vk_numpad2:      return GLFW_KEY_KP_2;
        case vk_numpad3:      return GLFW_KEY_KP_3;
        case vk_numpad4:      return GLFW_KEY_KP_4;
        case vk_numpad5:      return GLFW_KEY_KP_5;
        case vk_numpad6:      return GLFW_KEY_KP_6;
        case vk_numpad7:      return GLFW_KEY_KP_7;
        case vk_numpad8:      return GLFW_KEY_KP_8;
        case vk_numpad9:      return GLFW_KEY_KP_9;
        case vk_f1:           return GLFW_KEY_F1;
        case vk_f2:           return GLFW_KEY_F2;
        case vk_f3:           return GLFW_KEY_F3;
        case vk_f4:           return GLFW_KEY_F4;
        case vk_f5:           return GLFW_KEY_F5;
        case vk_f6:           return GLFW_KEY_F6;
        case vk_f7:           return GLFW_KEY_F7;
        case vk_f8:           return GLFW_KEY_F8;
        case vk_f9:           return GLFW_KEY_F9;
        case vk_f10:          return GLFW_KEY_F10;
        case vk_f11:          return GLFW_KEY_F11;
        case vk_f12:          return GLFW_KEY_F12;
        case vk_f13:          return GLFW_KEY_F13;
        case vk_f14:          return GLFW_KEY_F14;
        case vk_f15:          return GLFW_KEY_F15;
        case vk_pause:        return GLFW_KEY_PAUSE;
        case vk_numpad_enter: return GLFW_KEY_KP_ENTER;
        case vk_numpad_equal: return GLFW_KEY_KP_EQUAL;
    }
}

int GLFWKeyToKey(int key) {
    switch (key) {
        default:
        case GLFW_KEY_UNKNOWN:       return vk_unknown;
        case GLFW_KEY_A:             return vk_a;
        case GLFW_KEY_B:             return vk_b;
        case GLFW_KEY_C:             return vk_c;
        case GLFW_KEY_D:             return vk_d;
        case GLFW_KEY_E:             return vk_e;
        case GLFW_KEY_F:             return vk_f;
        case GLFW_KEY_G:             return vk_g;
        case GLFW_KEY_H:             return vk_h;
        case GLFW_KEY_I:             return vk_i;
        case GLFW_KEY_J:             return vk_j;
        case GLFW_KEY_K:             return vk_k;
        case GLFW_KEY_L:             return vk_l;
        case GLFW_KEY_M:             return vk_m;
        case GLFW_KEY_N:             return vk_n;
        case GLFW_KEY_O:             return vk_o;
        case GLFW_KEY_P:             return vk_p;
        case GLFW_KEY_Q:             return vk_q;
        case GLFW_KEY_R:             return vk_r;
        case GLFW_KEY_S:             return vk_s;
        case GLFW_KEY_T:             return vk_t;
        case GLFW_KEY_U:             return vk_u;
        case GLFW_KEY_V:             return vk_v;
        case GLFW_KEY_W:             return vk_w;
        case GLFW_KEY_X:             return vk_x;
        case GLFW_KEY_Y:             return vk_y;
        case GLFW_KEY_Z:             return vk_z;
        case GLFW_KEY_0:             return vk_num0;
        case GLFW_KEY_1:             return vk_num1;
        case GLFW_KEY_2:             return vk_num2;
        case GLFW_KEY_3:             return vk_num3;
        case GLFW_KEY_4:             return vk_num4;
        case GLFW_KEY_5:             return vk_num5;
        case GLFW_KEY_6:             return vk_num6;
        case GLFW_KEY_7:             return vk_num7;
        case GLFW_KEY_8:             return vk_num8;
        case GLFW_KEY_9:             return vk_num9;
        case GLFW_KEY_ESCAPE:        return vk_escape;
        case GLFW_KEY_LEFT_CONTROL:  return vk_lControl;
        case GLFW_KEY_LEFT_SHIFT:    return vk_lShift;
        case GLFW_KEY_LEFT_ALT:      return vk_lAlt;
        case GLFW_KEY_LEFT_SUPER:    return vk_lSystem;
        case GLFW_KEY_RIGHT_CONTROL: return vk_rControl;
        case GLFW_KEY_RIGHT_SHIFT:   return vk_rShift;
        case GLFW_KEY_RIGHT_ALT:     return vk_rAlt;
        case GLFW_KEY_RIGHT_SUPER:   return vk_rSystem;
        case GLFW_KEY_MENU:          return vk_menu;
        case GLFW_KEY_LEFT_BRACKET:  return vk_lBracket;
        case GLFW_KEY_RIGHT_BRACKET: return vk_rBracket;
        case GLFW_KEY_SEMICOLON:     return vk_semicolon;
        case GLFW_KEY_COMMA:         return vk_comma;
        case GLFW_KEY_PERIOD:        return vk_period;
        case GLFW_KEY_SLASH:         return vk_slash;
        case GLFW_KEY_BACKSLASH:     return vk_backslash;
        case GLFW_KEY_GRAVE_ACCENT:  return vk_tilde;
        case GLFW_KEY_EQUAL:         return vk_equal;
        case GLFW_KEY_MINUS:         return vk_dash;
        case GLFW_KEY_SPACE:         return vk_space;
        case GLFW_KEY_ENTER:         return vk_return;
        case GLFW_KEY_BACKSPACE:     return vk_backspace;
        case GLFW_KEY_TAB:           return vk_tab;
        case GLFW_KEY_PAGE_UP:       return vk_pageUp;
        case GLFW_KEY_PAGE_DOWN:     return vk_pageDown;
        case GLFW_KEY_END:           return vk_end;
        case GLFW_KEY_HOME:          return vk_home;
        case GLFW_KEY_INSERT:        return vk_insert;
        case GLFW_KEY_DELETE:        return vk_delete;
        case GLFW_KEY_KP_ADD:        return vk_add;
        case GLFW_KEY_KP_SUBTRACT:   return vk_subtract;
        case GLFW_KEY_KP_MULTIPLY:   return vk_multiply;
        case GLFW_KEY_KP_DIVIDE:     return vk_divide;
        case GLFW_KEY_LEFT:          return vk_left;
        case GLFW_KEY_RIGHT:         return vk_right;
        case GLFW_KEY_UP:            return vk_up;
        case GLFW_KEY_DOWN:          return vk_down;
        case GLFW_KEY_KP_0:          return vk_numpad0;
        case GLFW_KEY_KP_1:          return vk_numpad1;
        case GLFW_KEY_KP_2:          return vk_numpad2;
        case GLFW_KEY_KP_3:          return vk_numpad3;
        case GLFW_KEY_KP_4:          return vk_numpad4;
        case GLFW_KEY_KP_5:          return vk_numpad5;
        case GLFW_KEY_KP_6:          return vk_numpad6;
        case GLFW_KEY_KP_7:          return vk_numpad7;
        case GLFW_KEY_KP_8:          return vk_numpad8;
        case GLFW_KEY_KP_9:          return vk_numpad9;
        case GLFW_KEY_F1:            return vk_f1;
        case GLFW_KEY_F2:            return vk_f2;
        case GLFW_KEY_F3:            return vk_f3;
        case GLFW_KEY_F4:            return vk_f4;
        case GLFW_KEY_F5:            return vk_f5;
        case GLFW_KEY_F6:            return vk_f6;
        case GLFW_KEY_F7:            return vk_f7;
        case GLFW_KEY_F8:            return vk_f8;
        case GLFW_KEY_F9:            return vk_f9;
        case GLFW_KEY_F10:           return vk_f10;
        case GLFW_KEY_F11:           return vk_f11;
        case GLFW_KEY_F12:           return vk_f12;
        case GLFW_KEY_F13:           return vk_f13;
        case GLFW_KEY_F14:           return vk_f14;
        case GLFW_KEY_F15:           return vk_f15;
        case GLFW_KEY_PAUSE:         return vk_pause;
        case GLFW_KEY_KP_ENTER:      return vk_numpad_enter;
        case GLFW_KEY_KP_EQUAL:      return vk_numpad_equal;
    }
}

int buttonToGLFWButton(int btn) {
    switch (btn) {
        default:
        case mb_none:   return -1;
        case mb_left:   return GLFW_MOUSE_BUTTON_1;
        case mb_right:  return GLFW_MOUSE_BUTTON_2;
        case mb_middle: return GLFW_MOUSE_BUTTON_3;
        case mb_x1:     return GLFW_MOUSE_BUTTON_4;
        case mb_x2:     return GLFW_MOUSE_BUTTON_5;
    }
}

bool isKeyDown(int key) {
    if (key == vk_none || !glfwGetWindowAttrib(inputWindow, GLFW_FOCUSED)) {
        return false;
    }

    if (key == vk_any) {
        for (int i = 0; i < vk_keyCount; ++i) {
            if (currentKeyState[i]) {
                return true;
            }
        }

        return false;
    }

    if (key == vk_control) {
        return currentKeyState[vk_lControl - 1] || currentKeyState[vk_rControl - 1];
    } else if (key == vk_shift) {
        return currentKeyState[vk_lShift - 1] || currentKeyState[vk_rShift - 1];
    } else if (key == vk_alt) {
        return currentKeyState[vk_lAlt - 1] || currentKeyState[vk_rAlt - 1];
    }

    if (key >= vk_keyCount || key < 0) {
        return false;
    }

    return currentKeyState[key - 1];
}

bool isKeyDown2(int key, int key1) {
    return isKeyDown(key) || isKeyDown(key1);
}

bool isKeyPressed(int key) {
    if (key == vk_none || !glfwGetWindowAttrib(inputWindow, GLFW_FOCUSED)) {
        return false;
    }

    if (key == vk_control) {
        return (!previousKeyState[vk_lControl - 1] && currentKeyState[vk_lControl - 1]) || (!previousKeyState[vk_rControl - 1] && currentKeyState[vk_rControl - 1]);
    } else if (key == vk_shift) {
        return (!previousKeyState[vk_lShift - 1] && currentKeyState[vk_lShift - 1]) || (!previousKeyState[vk_rShift - 1] && currentKeyState[vk_rShift - 1]);
    } else if (key == vk_alt) {
        return (!previousKeyState[vk_lAlt - 1] && currentKeyState[vk_lAlt - 1]) || (!previousKeyState[vk_rAlt - 1] && currentKeyState[vk_rAlt - 1]);
    }

    if (key >= vk_keyCount || key < 0) {
        return false;
    }

    return (!previousKeyState[key - 1] && currentKeyState[key - 1]);
}


bool isKeyPressed2(int key, int key1) {
    return isKeyPressed(key) || isKeyPressed(key1);
}

bool isKeyReleased(int key) {
    if (key == vk_none || !glfwGetWindowAttrib(inputWindow, GLFW_FOCUSED)) {
        return false;
    }

    if (key == vk_control) {
        return (previousKeyState[vk_lControl - 1] && !currentKeyState[vk_lControl - 1]) || (previousKeyState[vk_rControl - 1] && !currentKeyState[vk_rControl - 1]);
    } else if (key == vk_shift) {
        return (previousKeyState[vk_lShift - 1] && !currentKeyState[vk_lShift - 1]) || (previousKeyState[vk_rShift - 1] && !currentKeyState[vk_rShift - 1]);
    } else if (key == vk_alt) {
        return (previousKeyState[vk_lAlt - 1] && !currentKeyState[vk_lAlt - 1]) || (previousKeyState[vk_rAlt - 1] && !currentKeyState[vk_rAlt - 1]);
    }

    if (key >= vk_keyCount || key < 0) {
        return false;
    }

    return (previousKeyState[key - 1] && !currentKeyState[key - 1]);
}

bool isKeyReleased2(int key, int key1) {
    return isKeyReleased(key) || isKeyReleased(key1);
}

bool isButtonDown(int btn) {
    if (btn < mb_none || btn > mb_x2) {
        return false;
    }

    return currentButtonState[btn - 201];
}

bool isButtonDown2(int btn, int btn1) {
    return isButtonDown(btn) || isButtonDown(btn1);
}

bool isButtonPressed(int btn) {
    if (btn < mb_none || btn > mb_x2) {
        return false;
    }

    return (!previousButtonState[btn - 201] && currentButtonState[btn - 201]);
}

bool isButtonPressed2(int btn, int btn1) {
    return isButtonPressed(btn) || isButtonPressed(btn1);
}

bool isButtonReleased(int btn) {
    if (btn < mb_none || btn > mb_x2) {
        return false;
    }

    return (previousButtonState[btn - 201] && !currentButtonState[btn - 201]);
}

bool isButtonReleased2(int btn, int btn1) {
    return isButtonReleased(btn) || isButtonReleased(btn1);
}
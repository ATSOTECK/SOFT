//
// Created by Skyler on 11/11/23.
//

#ifndef SOFT_INPUT_H
#define SOFT_INPUT_H

#include <GLFW/glfw3.h>

#include "common.h"

static const int vk_none           = 0;
static const int vk_unknown        = 0;
static const int vk_a              = 1;
static const int vk_b              = 2;
static const int vk_c              = 3;
static const int vk_d              = 4;
static const int vk_e              = 5;
static const int vk_f              = 6;
static const int vk_g              = 7;
static const int vk_h              = 8;
static const int vk_i              = 9;
static const int vk_j              = 10;
static const int vk_k              = 11;
static const int vk_l              = 12;
static const int vk_m              = 13;
static const int vk_n              = 14;
static const int vk_o              = 15;
static const int vk_p              = 16;
static const int vk_q              = 17;
static const int vk_r              = 18;
static const int vk_s              = 19;
static const int vk_t              = 20;
static const int vk_u              = 21;
static const int vk_v              = 22;
static const int vk_w              = 23;
static const int vk_x              = 24;
static const int vk_y              = 25;
static const int vk_z              = 26;
static const int vk_num0           = 27;
static const int vk_num1           = 28;
static const int vk_num2           = 29;
static const int vk_num3           = 30;
static const int vk_num4           = 31;
static const int vk_num5           = 32;
static const int vk_num6           = 33;
static const int vk_num7           = 34;
static const int vk_num8           = 35;
static const int vk_num9           = 36;
static const int vk_escape         = 37;
static const int vk_lControl       = 38;
static const int vk_lShift         = 39;
static const int vk_lAlt           = 40;
static const int vk_lSystem        = 41; ///< The left os specific key, eg the windows key;
static const int vk_rControl       = 42;
static const int vk_rShift         = 43;
static const int vk_rAlt           = 44;
static const int vk_rSystem        = 45;
static const int vk_menu           = 46;
static const int vk_lBracket       = 47;
static const int vk_rBracket       = 48;
static const int vk_semicolon      = 49;
static const int vk_comma          = 50;
static const int vk_period         = 51;
static const int vk_quote          = 52;
static const int vk_slash          = 53;
static const int vk_backslash      = 54;
static const int vk_tilde          = 55;
static const int vk_equal          = 56;
static const int vk_dash           = 57;
static const int vk_space          = 58;
static const int vk_return         = 59; ///< Enter;
static const int vk_backspace      = 60;
static const int vk_tab            = 61;
static const int vk_pageUp         = 62;
static const int vk_pageDown       = 63;
static const int vk_end            = 64;
static const int vk_home           = 65;
static const int vk_insert         = 66;
static const int vk_delete         = 67;
static const int vk_add            = 68;
static const int vk_subtract       = 69;
static const int vk_multiply       = 70;
static const int vk_divide         = 71;
static const int vk_left           = 72;
static const int vk_right          = 73;
static const int vk_up             = 74;
static const int vk_down           = 75;
static const int vk_numpad0        = 76;
static const int vk_numpad1        = 77;
static const int vk_numpad2        = 78;
static const int vk_numpad3        = 79;
static const int vk_numpad4        = 80;
static const int vk_numpad5        = 81;
static const int vk_numpad6        = 82;
static const int vk_numpad7        = 83;
static const int vk_numpad8        = 84;
static const int vk_numpad9        = 85;
static const int vk_f1             = 86;
static const int vk_f2             = 87;
static const int vk_f3             = 88;
static const int vk_f4             = 89;
static const int vk_f5             = 90;
static const int vk_f6             = 91;
static const int vk_f7             = 92;
static const int vk_f8             = 93;
static const int vk_f9             = 94;
static const int vk_f10            = 95;
static const int vk_f11            = 96;
static const int vk_f12            = 97;
static const int vk_f13            = 98;
static const int vk_f14            = 99;
static const int vk_f15            = 100;
static const int vk_pause          = 101;
static const int vk_numpad_enter   = 102;
static const int vk_numpad_equal   = 103;
static const int vk_keyCount       = 104;

static const int vk_control        = 1000;
static const int vk_shift          = 1001;
static const int vk_alt            = 1002;

static const int vk_any            = 2000; ///< Only works with isKeyDown for now.

static const int mb_none           = 200;
static const int mb_left           = 201;
static const int mb_right          = 202;
static const int mb_middle         = 203;
static const int mb_x1             = 204;
static const int mb_x2             = 205;
static const int mb_buttonCount    = 6;

void inputInit(GLFWwindow *window);
void inputUpdate();

int keyToGLFWKey(int key);
int GLFWKeyToKey(int key);
int buttonToGLFWButton(int btn);

bool isKeyDown(int key);
bool isKeyDown2(int key, int key1);

bool isKeyPressed(int key);
bool isKeyPressed2(int key, int key1);

bool isKeyReleased(int key);
bool isKeyReleased2(int key, int key1);

bool isButtonDown(int btn);
bool isButtonDown2(int btn, int btn1);

bool isButtonPressed(int btn);
bool isButtonPressed2(int btn, int btn1);

bool isButtonReleased(int btn);
bool isButtonReleased2(int btn, int btn1);

#endif //SOFT_INPUT_H

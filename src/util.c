//
// Created by Skyler on 11/11/23.
//

#include <stdio.h>
#include <stdlib.h>

#include "common.h"

char *readFileToStr(const char *filename) {
    if (filename == nullptr) {
        fprintf(stderr, "readFileToStr passed nullptr\n");
        return nullptr;
    }

    FILE *file = fopen(filename, "r");
    if (file == nullptr) {
        fprintf(stderr, "Could not open '%s'!\n", filename);
        return nullptr;
    }

    if (fseek(file, 0, SEEK_END) != 0) {
        fprintf(stderr, "Could not seek in '%s'!\n", filename);
        return nullptr;
    }

    long length = ftell(file);
    if (length == -1) {
        fprintf(stderr, "Could not get the length of '%s'!\n", filename);
        return nullptr;
    }

    if (fseek(file, 0, SEEK_SET) != 0) {
        fprintf(stderr, "Could not seek in '%s'!\n", filename);
        return nullptr;
    }

    char *str = (char*)malloc(sizeof(char) * length);
    if (str == nullptr) {
        fprintf(stderr, "Out of memory while opening '%s'!\n", filename);
        return nullptr;
    }

    size_t read = fread(str, 1, length, file);
    if (read == 0 || ferror(file)) {
        fprintf(stderr, "Could not read from '%s'!\n", filename);
        return nullptr;
    }

    if (fclose(file) != 0) {
        fprintf(stderr, "Could not close '%s'!\n", filename);
    }

    return str;
}

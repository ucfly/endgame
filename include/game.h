#pragma once

// includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// funcs
char *mx_strcpy(char *dst, const char *src);

int mx_strlen(const char *s);

void mx_err_check(void *target);
void mx_printerr(const char *s);

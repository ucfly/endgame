#pragma once

// includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <sdl2_gfx/SDL2_gfxPrimitives.h>
#include <sdl2_gfx/SDL2_rotozoom.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// structs

typedef struct s_car {
    int x;
    int y;
    char *name;
}              t_car;

// funcs
char *mx_strcpy(char *dst, const char *src);

int mx_strlen(const char *s);
int mx_process_events(SDL_Window *window, t_car *plane, t_car *astr);

void mx_err_check(void *target);
void mx_printerr(const char *s);
void mx_do_render(SDL_Renderer *rend, t_car *plane, t_car *astr, SDL_Rect *tor);
void mx_scale_tor(SDL_Rect *tor);

#pragma once

// includes
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

#include <sdl2_gfx/SDL2_gfxPrimitives.h>
#include <sdl2_gfx/SDL2_rotozoom.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// structs

typedef struct world {
    int x;
    int y;
    int w;
    int h;
}              t_world;

typedef struct s_state {
    t_world plane;
    t_world world;
}              t_state;

// funcs
char *mx_strcpy(char *dst, const char *src);

int mx_strlen(const char *s);
int mx_process_events(SDL_Window *window, t_world *plane);

void mx_err_check(void *target);
void mx_printerr(const char *s);
void mx_do_render(SDL_Renderer *rend, t_world *plane, t_world *world);
void mx_scale_gate(t_world *gate);

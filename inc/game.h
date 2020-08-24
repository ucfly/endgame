#pragma once

// includes
#include <SDL2_image/SDL_image.h>
#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>


// #include <sdl2_gfx/SDL2_gfxPrimitives.h>
// #include <sdl2_gfx/SDL2_rotozoom.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// structs

typedef struct s_world {
    float x;
    float y;
    float w;
    float h;
    float cnt;
    float dy;
}              t_world;

typedef struct s_state {
    // objects
    t_world plane;
    t_world gate;
    t_world space;

    // imgs
    SDL_Texture *bg;
    SDL_Texture *car;
    SDL_Texture *gate_img[2];

    SDL_Renderer *renderer;
    

}              t_state;

// funcs
char *mx_strcpy(char *dst, const char *src);

int mx_strlen(const char *s);
int mx_process_events(SDL_Window *window, t_state *game);

void mx_err_check(void *target);
void mx_printerr(const char *s);
void mx_do_render(SDL_Renderer *rend, t_state *game);
void mx_scale_gate(t_state *game);
void mx_scale_car(t_state *game, int direction);
void mx_load_game(t_state *game);
void process(t_state *game);

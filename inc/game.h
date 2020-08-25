#pragma once

// === defines ===
#define MX_WIND_W 1600
#define MX_WIND_H 1000

#define MX_GRAVITY 0.02f

#define MX_RING_L 5
#define MX_RING_W 120
#define MX_RING_H 40

#define MX_RANDOM_X ((rand() % (MX_WIND_W + 1 - 0)) +0)
#define MX_RANDOM_Y ((rand() % (MX_WIND_H + 1 - 0)) +0)

#define MX_PLANE_W 300
#define MX_PLANE_H 100
#define MX_PLANE_ST_X (MX_WIND_W / 2 - MX_PLANE_W / 2)
#define MX_PLANE_ST_Y (MX_WIND_H / 2 - MX_PLANE_H / 2)

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
#include <time.h>

// structs
// TODO razobratsia s tipami na rayone
typedef struct s_world {
    float x;
    float y;
    float w;
    float h;
    int cnt;
    float dy;
    int dw;
}              t_world;



typedef struct s_state {
    // objects
    t_world plane;
    t_world gate;
    t_world space;

    // imgs
    SDL_Texture *bg;
    SDL_Texture *car;
    SDL_Texture *gate_img;

    SDL_Renderer *renderer;
    Mix_Music *bg_music;
    int play;
    int exit;
    

}              t_state;

// funcs
char *mx_strcpy(char *dst, const char *src);

int mx_strlen(const char *s);
int mx_process_events(SDL_Window *window, t_state *game);

void mx_err_check(void *target);
void mx_printerr(const char *s);
void mx_do_render(SDL_Renderer *rend, t_state *game);
void mx_play_game(t_state *game);
void mx_load_game(t_state *game);

int show_menu(SDL_Renderer *renderer);

void draw_text( SDL_Color color, int x, int y, char *text, 
                SDL_Renderer *renderer, TTF_Font *font);

// void process(t_state *game);

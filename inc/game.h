#pragma once

// === defines ===
#define MX_WIND_W 1600
#define MX_WIND_H 1000

#define MX_GRAVITY 0.02f

#define MX_RING_L 5
#define MX_RING_W 40
#define MX_RING_H 40 +120

#define MX_RANDOM_X ((rand() % (MX_WIND_W + 1 - 0)) +0)
#define MX_RANDOM_Y ((rand() % (MX_WIND_H + 1 - 0)) +0)

#define MX_PLANE_W 300/2
#define MX_PLANE_H 240/2
#define MX_PLANE_ST_X (MX_WIND_W / 2 - MX_PLANE_W / 2)
#define MX_PLANE_ST_Y (MX_WIND_H / 2 - MX_PLANE_H / 2)

#define MX_BTN_W 300
#define MX_BTN_H 60
#define MX_BTN_X ((MX_WIND_W - MX_BTN_W) / 2)
#define MX_BTN_Y (MX_WIND_H / 2 - MX_BTN_H)
#define GAME_LIFE 3

#define MX_R_MENU 0
#define MX_R_GAME 1
#define MX_R_OVER 2
#define MX_R_BOARD 3
#define MX_R_EXIT -1

#define CIRCLE  "resource/img/circles/circle_orange.png"
#define CIRCLE2  "resource/img/circles/circle_green.png"

#define PLANE  "resource/img/car_blue.png"
#define PLANE2  "resource/img/car_green.png"

#define BACKGROUND_IMG "resource/img/space_bg.jpg"

#define FONT_MAIN "resource/font/Sansation-Bold.ttf"
#define MUSIC_MENU "resource/audio/space_oddity.mp3"

// colors
#define TEAL {0, 0, 0, 0}
#define ORANGE {255, 255, 255, 0}
#define GREEN {144, 178, 71, 0}

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

typedef enum e_scenestatus {
    MENU_STATE,
    GAME_STATE,
    GAMEOVER_STATE,
    MULTIPLAYER_STATE,
    LEADERBOARD_STATE,
    EXIT_STATE
}    e_scenes;

// structs

typedef struct s_calculation {
    int temp;
    int dec;
    int rem;
    int size;
    int i;
}              t_calculation;

typedef struct s_world {
    float x;
    float y;
    float w;
    float h;
    int cnt;
    float dy;
    int dw;
    int life;

}              t_world;


typedef struct s_state {
    // objects
    t_world plane;
    t_world gate;
    t_world plane2;
    t_world gate2;
    t_world space;

    // imgs
    SDL_Texture *bg;
    SDL_Texture *car;
    SDL_Texture *car2;
    SDL_Texture *gate_img;
    SDL_Texture *gate2_img;

    SDL_Renderer *renderer;
    Mix_Music *bg_music;
    TTF_Font *font;
    
    int play;
    int exit;

    e_scenes status;

}              t_state;

// funcs
char *mx_strcpy(char *dst, const char *src);

void mx_do_render(SDL_Renderer *rend, t_state *game);
void mx_do_render_mult(SDL_Renderer *rend, t_state *game);

void mx_play_game(t_state *game);
void mx_play_game_mult(t_state *game);

void mx_load_game(t_state *game);

int mx_strlen(const char *s);
int mx_check_pass(t_world *gate, t_world *plane);

void mx_printerr(const char *s);
void mx_is_over(t_world *plane);
void mx_scale_car(t_world *plane);
void mx_scale_gate(t_world *gate);
void mx_gravitation (t_world *plane);

char *mx_int_to_str(int n);
void mx_initial_state(t_world *gate, t_world *plane);


e_scenes mx_menu(SDL_Renderer *renderer);
e_scenes mx_leaderboard(SDL_Renderer *renderer);
e_scenes mx_game(SDL_Window *window, t_state *game);
e_scenes mx_multiplayer(SDL_Window *window, t_state *game);
e_scenes mx_gameover(SDL_Renderer *renderer);



void mx_draw_text( SDL_Color color, int x, int y, char *text, 
                SDL_Renderer *renderer, TTF_Font *font);


#pragma once

//наши фреймворки
#include "../frameworks/SDL2.framework/Headers/SDL.h"
#include "../frameworks/SDL2_image.framework/Headers/SDL_image.h"

//системные библиотеки
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define ScreenWidth 1024
#define ScreenHight 768

typedef struct s_man{
  int x, y;
  // short life;
  // char *name;
  int color[3];
  int size[2];
  int speed;
}              t_man;
typedef struct s_star {
  int x, y;
}              t_star;

typedef struct s_world {
    t_man man;
    t_star stars[100];
    SDL_Texture *star;
    SDL_Renderer *renderer;
    SDL_Texture *background;
    int mouse[2];
} t_world;

//декларация функций
void loadgame(t_world *world);
void doRender(t_world *world);
int processEvents(SDL_Window *window, t_world *world);

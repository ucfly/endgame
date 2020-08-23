#include "game.h"

void mx_load_game(t_state *game) {
    SDL_Surface *bg_surf = NULL;
    SDL_Surface *gate_surf = NULL;
    SDL_Surface *car_surf = NULL;

    bg_surf = IMG_Load("img/space_bg.jpg");
    gate_surf = IMG_Load("img/circle.png");
    car_surf = IMG_Load("img/new_red_car.png");

    if (bg_surf == NULL || car_surf == NULL) {
        mx_printerr(SDL_GetError());
        SDL_Quit();
        exit(1);
    }
    game->bg = SDL_CreateTextureFromSurface(game->renderer, bg_surf);
    SDL_FreeSurface(bg_surf);

    game->car = SDL_CreateTextureFromSurface(game->renderer, car_surf);
    SDL_FreeSurface(car_surf);

    game->gate_img = SDL_CreateTextureFromSurface(game->renderer, gate_surf);
    SDL_FreeSurface(gate_surf);

    game->plane.x = 160;
    game->plane.y = 220;
    game->plane.w = 210;
    game->plane.h = 130;
    // game->plane.cnt = 0;

    game->gate.x = 50;
    game->gate.y = 50;
    game->gate.w = 100;
    game->gate.h = 50;
    // game->gate.cnt = 1;

    game->space.x = 0;
    game->space.y = 0;
    game->space.w = 800;
    game->space.h = 800;
}

#include "game.h"

void mx_load_game(t_state *game) {
    // SDL_Surface *bg_surf = NULL;
    // SDL_Surface *gate_surf = NULL;
    // SDL_Surface *car_surf = NULL;

    SDL_Surface *surf = NULL;

    // space bg:
    surf = IMG_Load("img/space_bg.jpg");
    if (surf == NULL) {
        mx_printerr("can't find space bg");
        SDL_Quit();
        exit(1);
    }

    game->bg = SDL_CreateTextureFromSurface(game->renderer, surf);

    // orange circle
    surf = IMG_Load("img/circle.png");
    if (surf == NULL) {
        mx_printerr("Can't load orange gate");
        SDL_Quit();
        exit(1);
    }

    game->gate_img[0] = SDL_CreateTextureFromSurface(game->renderer, surf);

    // green circle
    surf = IMG_Load("img/circle_green .png");
    if (surf == NULL) {
        mx_printerr("  Can't load green gate");
        SDL_Quit();
        exit(1);
    }

    game->gate_img[1] = SDL_CreateTextureFromSurface(game->renderer, surf);

    // car

    surf = IMG_Load("img/new_red_car.png");
    if (surf == NULL) {
        mx_printerr("Can't load car");
        SDL_Quit();
        exit(1);
    }

    game->car = SDL_CreateTextureFromSurface(game->renderer,surf);

    SDL_FreeSurface(surf);

    game->plane.x = 160;
    game->plane.y = 220;
    game->plane.w = 210;
    game->plane.h = 130;
    // game->plane.cnt = 0;

// TODO randomazi first x, y for ring
    // game->gate.x = 50;
    // game->gate.y = 50;
    game->gate.w = 100;
    game->gate.h = 50;
    // game->gate.cnt = 1;

    game->space.x = 0;
    game->space.y = 0;
    game->space.w = 800;
    game->space.h = 800;
}

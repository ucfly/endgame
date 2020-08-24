#include "game.h"

void mx_load_game(t_state *game) {
    SDL_Surface *surf = NULL;


    //load BG musix

    Mix_Music *namemusic = Mix_LoadMUS("resource/audio/space_oddity.mp3");
    if(!namemusic) {    
        printf("Mix_LoadMUS(\"namemusic.mp3\"): %s\n", Mix_GetError());
    // this might be a critical error...
    }
    game->bg_music = namemusic;

    // space bg:
    surf = IMG_Load("resource/img/space_bg.jpg");
    if (surf == NULL) {
        mx_printerr("can't find space bg");
        SDL_Quit();
        exit(1);
    }

    game->bg = SDL_CreateTextureFromSurface(game->renderer, surf);

    // orange circle
    surf = IMG_Load("resource/img/circle.png");
    if (surf == NULL) {
        mx_printerr("Can't load orange gate");
        SDL_Quit();
        exit(1);
    }

    game->gate_img[0] = SDL_CreateTextureFromSurface(game->renderer, surf);

    // green circle
    surf = IMG_Load("resource/img/circle_green .png");
    if (surf == NULL) {
        mx_printerr("  Can't load green gate");
        SDL_Quit();
        exit(1);
    }

    game->gate_img[1] = SDL_CreateTextureFromSurface(game->renderer, surf);

    // car

    surf = IMG_Load("resource/img/space_car.png");
    if (surf == NULL) {
        mx_printerr("Can't load car");
        SDL_Quit();
        exit(1);
    }

    game->car = SDL_CreateTextureFromSurface(game->renderer, surf);

    SDL_FreeSurface(surf);

    game->plane.x = MX_PLANE_ST_X;
    game->plane.y = 220;
    game->plane.w = MX_PLANE_W;
    game->plane.h = MX_PLANE_H;
    game->plane.dy = 0;
    // game->plane.cnt = 0;

    game->gate.x = MX_RANDOM_X;
    game->gate.y = MX_RANDOM_Y;
    game->gate.w = 50;
    game->gate.h = 50;
    // game->gate.cnt = 1;

    game->space.x = 0;
    game->space.y = 0;
    game->space.w = MX_WIND_W;
    game->space.h = MX_WIND_H;
}

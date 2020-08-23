#include "header.h"

void loadgame(t_world *world) {
    SDL_Surface *starSurface = NULL;
    SDL_Surface *backGround = NULL;


    t_man man = {200, 140, {50, 50, 50}, {50, 50}, 1};
    t_star mario = {100, 100};
    world->man = man;
    world->stars[0] = mario;
    backGround = IMG_Load("./images/main_page.png");
    if (backGround == NULL) {
        printf("Cannot fint picture!!!\n");
        SDL_Quit();
        exit(1);
    }
    world->background = SDL_CreateTextureFromSurface(world->renderer, backGround);

    starSurface = IMG_Load("./images/mario.png");
    if (starSurface == NULL) {
        printf("Cannot fint picture!!!\n");
        SDL_Quit();
        exit(1);
    }
    for(int i = 0; i < 100; i++) {
        world->stars[i].y = random()%ScreenHight;
        world->stars[i].x = random()%ScreenWidth;
    }
    world->star = SDL_CreateTextureFromSurface(world->renderer, starSurface);

    SDL_FreeSurface(starSurface);
  
}

#include "game.h"

int main(void) {
    t_state game_state;
    SDL_Renderer *rend = NULL;
    SDL_Window *wind = NULL;
    SDL_Surface *bg_surf = NULL;
    SDL_Surface *car_surf = NULL;

    int quit;

    if (SDL_Init(SDL_INIT_VIDEO)) {
        mx_printerr("ne paluchilos");
        exit(1);
    }

    game_state.plane.x = 160;
    game_state.plane.y = 220;
    game_state.plane.w = 126;
    game_state.plane.h = 98;
    // game_state.plane.cnt = 0;

    game_state.gate.x = 50;
    game_state.gate.y = 50;
    game_state.gate.w = 100;
    // game_state.gate.cnt = 1;

    wind = SDL_CreateWindow("Kuku", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, 800, 800, 0);

    rend = SDL_CreateRenderer(
        wind, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


    bg_surf = IMG_Load("img/starfield_1922x1037.jpg");
    car_surf = IMG_Load("img/cropped_car.png");

    if(bg_surf == NULL || car_surf == NULL ){
        mx_printerr(SDL_GetError());
        SDL_Quit();
        return 1;
    }
    game_state.bg = SDL_CreateTextureFromSurface(rend, bg_surf);
    SDL_FreeSurface(bg_surf);    
    
    game_state.car = SDL_CreateTextureFromSurface(rend, car_surf);
    SDL_FreeSurface(car_surf);

    // SDL_RenderClear(rend);
    // SDL_RenderCopy(rend, txtr, NULL, NULL);
    // SDL_RenderPresent(rend);

    quit = 0;
    while (!quit) {
        quit = mx_process_events(wind, &game_state);

        mx_scale_gate(&game_state);

        mx_do_render(rend, &game_state);
    }

    SDL_DestroyTexture(game_state.bg);
    SDL_DestroyWindow(wind);
    SDL_DestroyRenderer(rend);
    SDL_Quit();

    return 0;
}

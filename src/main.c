#include "game.h"

int main(void) {
    t_state game_state;
    SDL_Renderer *rend = NULL;
    SDL_Window *wind = NULL;
    // t_world plane = {160, 220, 200, 50};
    // t_world world = {50, 50, 100, 50};

    int quit;

    if (SDL_Init(SDL_INIT_VIDEO)) {
        mx_printerr("ne paluchilos");
        exit(1);
    }

    game_state.plane.x = 160;
    game_state.plane.y = 220;
    game_state.plane.w = 200;
    game_state.plane.h = 50;

    game_state.gate.x = 50;
    game_state.gate.y = 50;
    game_state.gate.w = 100;
    game_state.gate.h = 50;

    wind = SDL_CreateWindow("Kuku", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, 800, 800, 0);

    rend = SDL_CreateRenderer(
        wind, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    quit = 0;

    // SDL_Surface *img = IMG_Load("img/space_bg.jpg");
    // SDL_Texture *txtr = SDL_CreateTextureFromSurface(rend, img);
    // SDL_FreeSurface(img);
    // SDL_RenderClear(rend);
    // SDL_RenderCopy(rend, txtr, NULL, NULL);
    // SDL_RenderPresent(rend);

    while (!quit) {
        quit = mx_process_events(wind, &game_state);

        mx_scale_gate(&game_state);

        mx_do_render(rend, &game_state);
    }

    SDL_DestroyWindow(wind);
    SDL_DestroyRenderer(rend);
    SDL_Quit();

    return 0;
}

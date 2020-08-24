#include "game.h"

int main(void) {
    t_state game;
    SDL_Window *wind = NULL;
    SDL_Renderer *rend = NULL;
    int quit;
    
    if (SDL_Init(SDL_INIT_VIDEO)) {
        mx_printerr("ne paluchilos");
        exit(1);
    }
 
    wind = SDL_CreateWindow("Kuku", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, 1600, 1000, 0);

    rend = SDL_CreateRenderer(
        wind, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    game.renderer = rend;


    mx_load_game(&game);

    quit = 0;
    while (!quit) {
        quit = mx_process_events(wind, &game);

        mx_scale_gate(&game);
        // mx_collision_detect(rend, &game);

        process(&game);

        mx_do_render(game.renderer, &game);
    }

    SDL_DestroyTexture(game.bg);
    SDL_DestroyTexture(game.car);
    SDL_DestroyWindow(wind);
    SDL_DestroyRenderer(game.renderer);
    SDL_Quit();

    return 0;
}

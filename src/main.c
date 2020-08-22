#include "game.h"

int main(void) {
    SDL_Event e;
    SDL_Renderer *rend;
    SDL_Window *wind;
    int quit = 0;

    if (SDL_Init(SDL_INIT_VIDEO)) {
        mx_printerr("ne paluchilos");
        exit(1);
    }

    wind = SDL_CreateWindow("Kuku",
                            SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED,
                            640,
                            480,
                            0);

    rend = SDL_CreateRenderer(wind, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(rend, 179, 240, 100, 255);
    SDL_RenderClear(rend);

    SDL_SetRenderDrawColor(rend, 255, 150, 0, 255);
    SDL_Rect rect = {120, 140, 400, 200};
    SDL_RenderFillRect(rend, &rect);

    SDL_SetRenderDrawColor(rend, 25, 150, 200, 255);
    SDL_Rect plane = {160, 215, 320, 50};
    SDL_RenderFillRect(rend, &plane);

    SDL_RenderPresent(rend);

    while (!quit) {
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }
    }

    SDL_DestroyWindow(wind);
    SDL_DestroyRenderer(rend);
    SDL_Quit();

    return 0;
}

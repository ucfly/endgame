#include "game.h"

int main(void) {
    SDL_Renderer *rend;
    SDL_Window *wind;
    t_car astr = {240, 180};
    t_car plane = {160, 220};
    t_world world = {50, 50, 100, 50};

    int quit;

    if (SDL_Init(SDL_INIT_VIDEO)) {
        mx_printerr("ne paluchilos");
        exit(1);
    }
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
        quit = mx_process_events(wind, &plane, &astr);

        mx_scale_gate(&world);

        mx_do_render(rend, &plane, &astr, &world);

        SDL_Delay(100);
    }

    SDL_DestroyWindow(wind);
    SDL_DestroyRenderer(rend);
    SDL_Quit();

    return 0;
}

#include "game.h"

int main(void) {
    SDL_Renderer *rend;
    SDL_Window *wind;
    SDL_Rect tor;
    t_car astr;
    t_car plane;
    int quit;

    if (SDL_Init(SDL_INIT_VIDEO)) {
        mx_printerr("ne paluchilos");
        exit(1);
    }

    wind = SDL_CreateWindow("Kuku", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

    rend = SDL_CreateRenderer(wind, -1, SDL_RENDERER_ACCELERATED);

     astr.x = 300;
     astr.y = 180;

     plane.x = 160;
     plane.y = 220;

     tor.w = 100;
     tor.h = 50;

     quit = 0;

    while (!quit) {
       quit = mx_process_events(wind, &plane, &astr);
       mx_do_render(rend, &plane, &astr, &tor);

       SDL_Delay(100);
    }

    SDL_DestroyWindow(wind);
    SDL_DestroyRenderer(rend);
    SDL_Quit();

    return 0;
}

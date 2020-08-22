#include "game.h"

void mx_scale_tor(SDL_Rect *tor) {
    // SDL_Rect init_tor = *tor;

    for (int i = 0; i < 10; i++) {
        SDL_Delay(1000);
        tor->w += 10;
        tor->h += 10;
    }
//     tor->w = init_tor.w;
//     tor->h = init_tor.h;
}

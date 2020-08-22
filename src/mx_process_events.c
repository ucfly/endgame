#include "game.h"

int mx_process_events(SDL_Window *window, t_car *plane, t_car *astr) {
    SDL_Event e;
    int quit = 0;

    if (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_WINDOWEVENT_CLOSE:
                if (window) {
                    SDL_DestroyWindow(window);
                    window = NULL;
                    quit = 1;
                }
                break;
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        quit = 1;
                        break;
                    case SDLK_RIGHT:
                        plane->x += 10;
                        astr->x += 10;
                        break;
                    case SDLK_LEFT:
                        plane->x -= 10;
                        astr->x -= 10;
                        break;
                    case SDLK_UP:
                        plane->y -= 10;
                        astr->y -= 10;
                        break;
                    case SDLK_DOWN:
                        plane->y += 10;
                        astr->y += 10;
                        break;
                    default:
                        break;
                }
                break;
            case SDL_QUIT:
                quit = 1;
                break;
            default:
                break;
        }
    }
    return quit;
}

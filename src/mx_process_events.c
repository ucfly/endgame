#include "game.h"

int mx_process_events(SDL_Window *window, t_state *game) {
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
                    case SDLK_UP:
                    game->plane.dy = -2;
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

    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_LEFT]) {
        game->plane.x -= 5;
    }
    if (state[SDL_SCANCODE_RIGHT]) {
        game->plane.x += 5;
    }
    if(state[SDL_SCANCODE_UP]){
        game->plane.y -= 5;
    }
    if(state[SDL_SCANCODE_DOWN]){
        game->plane.y += 5;
    }
    return quit;
}

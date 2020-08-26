#include "game.h"

e_scenes mx_multiplayer(SDL_Window *window, t_state *game) {
    SDL_Event e;
    e_scenes status = MENU_STATE;
    int running = 1;
    game->plane.life = 3;
    game->plane.cnt = 0;
    game->plane2.life = 3;
    game->plane2.cnt = 0;

    while (running) {
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_WINDOWEVENT_CLOSE:
                    if (window) {
                        SDL_DestroyWindow(window);
                        window = NULL;
                        status = EXIT_STATE;
                    }
                    break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym) {
                        case SDLK_q:
                            return GAMEOVER_STATE;
                            // game.exit = 0;
                            break;
                        case SDLK_UP:
                        game->plane.dy = -2;
                        break;

                        default:
                            break;
                    }
                    break;
                case SDL_QUIT:
                    status = EXIT_STATE;
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
        if (state[SDL_SCANCODE_A]) {
            game->plane2.x -= 5;
        }
        if (state[SDL_SCANCODE_D]) {
            game->plane2.x += 5;
        }
        if(state[SDL_SCANCODE_W]){
            game->plane2.y -= 5;
        }
        if(state[SDL_SCANCODE_S]){
            game->plane2.y += 5;
        }
        mx_play_game(game);
        mx_do_render(game->renderer, game);

        
        if (game->plane.life <= 0 || game->plane2.life <= 0)
            return GAMEOVER_STATE;
    }

    return status;
}

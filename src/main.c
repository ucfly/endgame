#include "game.h"

int main(void) {
    t_state game;
    SDL_Window *wind = NULL;
    SDL_Renderer *rend = NULL;
    int quit;

    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    TTF_Init();

    if (SDL_Init(SDL_INIT_VIDEO)) {
        mx_printerr("ne paluchilos");
        exit(1);
    }

    wind = SDL_CreateWindow("Kuku", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, MX_WIND_W, MX_WIND_H, 0);

    rend = SDL_CreateRenderer(
        wind, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    game.renderer = rend;

    mx_load_game(&game);

    quit = 0;
    srand(time(0));

    Mix_PlayMusic(game.bg_music, -1);

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

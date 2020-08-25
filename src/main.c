#include "game.h"

int main(void) {
    t_state game;
    SDL_Window *wind = NULL;
    // SDL_Renderer *rend = NULL;
    // int quit;

    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    TTF_Init();

    wind = SDL_CreateWindow("Kuku", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, MX_WIND_W, MX_WIND_H, 0);

    game.renderer = SDL_CreateRenderer(
        wind, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    mx_load_game(&game);

    game.exit = 0;
    game.play = 0;
    srand(time(0));

    Mix_PlayMusic(game.bg_music, -1);

    while (!game.exit) {
        game.exit = show_menu(game.renderer);
        while (!game.play)
        {
            game.exit = 0;
            game.play = mx_process_events(wind, &game);
            mx_play_game(&game);
            mx_do_render(game.renderer, &game);
        }
        // mx_process_events(wind, &game);
        
        // quit = mx_process_events(wind, &game);


        // mx_play_game(&game);
        // mx_do_render(game.renderer, &game);
    }


    SDL_DestroyTexture(game.bg);
    SDL_DestroyTexture(game.car);
    SDL_DestroyTexture(game.gate_img);
    SDL_DestroyWindow(wind);
    SDL_DestroyRenderer(game.renderer);
    // SDL_FreeChunk(game.bg_music);

    IMG_Quit();
    TTF_Quit();
    Mix_CloseAudio();
    SDL_Quit();

    system("leaks -q game");
    return 0;
}

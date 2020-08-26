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
    Mix_PlayMusic(game.bg_music, -1);

    game.status = MENU_STATE;
    game.exit = 0;
    srand(time(0));

    game.play = MX_R_MENU;

    while (!game.exit) {

        switch (game.status) {
            case MENU_STATE:
                game.status = mx_menu(game.renderer); 
                break;
            case GAME_STATE:
                game.status = mx_game(wind, &game);
                break;
            case GAMEOVER_STATE:
                game.status = mx_gameover(game.renderer);
                printf("GAME OWER!!!");
                break;
            case LEADERBOARD_STATE:
                game.status = mx_leaderboard(game.renderer);
                printf("LEADERBOARD!!!");
                break;
            case EXIT_STATE:
                game.exit = 1;
                printf("EXIT");
                break;
        }
        printf("\n kuku: %d", game.exit);
    }

    SDL_DestroyTexture(game.bg);
    SDL_DestroyTexture(game.car);
    SDL_DestroyTexture(game.gate_img);
    SDL_DestroyWindow(wind);
    SDL_DestroyRenderer(game.renderer);

    IMG_Quit();
    TTF_Quit();
    Mix_CloseAudio();
    TTF_CloseFont(game.font);
    SDL_Quit();

    system("leaks -q game");
    return 0;
}

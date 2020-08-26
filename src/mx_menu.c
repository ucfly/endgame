<<<<<<< HEAD
#include "game.h"

e_scenes mx_menu(SDL_Renderer *renderer) {
    int running = 1;
    SDL_Event event;
    e_scenes result = MENU_STATE;
    int index_menu = 1;


    if (TTF_Init() == -1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(1);
    }

    TTF_Font *font = TTF_OpenFont("resource/font/Russo_One.ttf", 35);
    SDL_Color color = TEAL;
    SDL_Color color_selected = ORANGE;

    SDL_Texture *menu_bg =
        IMG_LoadTexture(renderer, "resource/img/empty_back.png");
    SDL_Texture *btn_img = IMG_LoadTexture(renderer, "resource/img/empty.png");

    SDL_Rect backgroundRect = {0, 0, MX_WIND_W, MX_WIND_H};



    SDL_Rect play_btn = {MX_BTN_X, MX_BTN_Y - 70, MX_BTN_W, MX_BTN_H};
    SDL_Rect mult_btn = {MX_BTN_X, MX_BTN_Y -5 , MX_BTN_W,
                          MX_BTN_H};
    SDL_Rect board_btn = {MX_BTN_X, MX_BTN_Y + 60 , MX_BTN_W,
                          MX_BTN_H};
    SDL_Rect exit_btn = {MX_BTN_X, MX_BTN_Y + MX_BTN_H + 65 , MX_BTN_W, MX_BTN_H};


    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYUP) {

                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    return EXIT_STATE;
                }
                if (event.key.keysym.sym == SDLK_UP) {
                    index_menu = (index_menu > 1) ? (index_menu - 1) : 4;
                    
                }
                if (event.key.keysym.sym == SDLK_DOWN) {
                    
                    index_menu = (index_menu < 4) ? (index_menu + 1) : 1;

                }
                if (event.key.keysym.sym == SDLK_RETURN) {
                   
                        SDL_DestroyTexture(btn_img);
                        SDL_DestroyTexture(menu_bg);
                        TTF_CloseFont(font);
                    switch (index_menu)
                    {
                    case 1:
                        return GAME_STATE;
                        break;
                    case 2:
                        return MULTIPLAYER_STATE;
                        break;
                    case 3:
                        return LEADERBOARD_STATE;
                        break;
                    case 4:
                        return EXIT_STATE;
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        SDL_RenderCopy(renderer, menu_bg, NULL, &backgroundRect);
       
        SDL_RenderCopy(renderer, btn_img, NULL, &play_btn);
        SDL_RenderCopy(renderer, btn_img, NULL, &mult_btn);
        SDL_RenderCopy(renderer, btn_img, NULL, &board_btn);
        SDL_RenderCopy(renderer, btn_img, NULL, &exit_btn);
        
        switch (index_menu) {
            case 1:
                mx_draw_text(color_selected, play_btn.x + 100, play_btn.y + 5,
                          "PLAY", renderer, font);
                mx_draw_text(color, mult_btn.x + 20, mult_btn.y + 5,
                          "MULTIPLAYER", renderer, font);
                mx_draw_text(color, board_btn.x + 15, board_btn.y + 5,
                          "LEADERBOARD", renderer, font);
                mx_draw_text(color, exit_btn.x + 100, exit_btn.y + 5, "QUIT",
                          renderer, font);
                break;

            case 2:
                mx_draw_text(color, play_btn.x + 100, play_btn.y + 5, "PLAY",
                          renderer, font);
                mx_draw_text(color_selected, mult_btn.x + 20, mult_btn.y + 5,
                          "MULTIPLAYER", renderer, font);
                mx_draw_text(color, board_btn.x + 15, board_btn.y + 5,
                          "LEADERBOARD", renderer, font);
                mx_draw_text(color, exit_btn.x + 100, exit_btn.y + 5, "QUIT",
                          renderer, font);
                break;

            case 3:
                mx_draw_text(color, play_btn.x + 100, play_btn.y + 5, "PLAY",
                          renderer, font);
                mx_draw_text(color, mult_btn.x + 20, mult_btn.y + 5,
                          "MULTIPLAYER", renderer, font);
                mx_draw_text(color_selected, board_btn.x + 15, board_btn.y + 5,
                          "LEADERBOARD", renderer, font);
                mx_draw_text(color, exit_btn.x + 100, exit_btn.y + 5,
                          "QUIT", renderer, font);
                break;
            case 4:
                mx_draw_text(color, play_btn.x + 100, play_btn.y + 5, "PLAY",
                          renderer, font);
                mx_draw_text(color, mult_btn.x + 20, mult_btn.y + 5,
                          "MULTIPLAYER", renderer, font);
                mx_draw_text(color, board_btn.x + 15, board_btn.y + 5,
                          "LEADERBOARD", renderer, font);
                mx_draw_text(color_selected, exit_btn.x + 100, exit_btn.y + 5,
                          "QUIT", renderer, font);
                break;
            default:
                break;
        }
        
        usleep(100);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(btn_img);
    SDL_DestroyTexture(menu_bg);
    TTF_CloseFont(font);


    return result;
}
=======
>>>>>>> d0bf89dc821091afc04e7212f310b1142674f4a6

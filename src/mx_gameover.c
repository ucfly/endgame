#include "game.h"
// #include <stdbool.h>

e_scenes mx_gameover(SDL_Renderer *renderer) {
    int running = 1;
    SDL_Event event;
    e_scenes result = MENU_STATE;
    int index_menu = 1;
    TTF_Init();
    if (TTF_Init() == -1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        exit(1);
    }

    TTF_Font *font = TTF_OpenFont("resource/font/Russo_One.ttf", 35);
    SDL_Color color = TEAL;
    SDL_Color color_selected = ORANGE;

    SDL_Texture *menu_bg = IMG_LoadTexture(renderer, "resource/img/GameOver.png");
    SDL_Texture *btn_img = IMG_LoadTexture(renderer, "resource/img/empty.PNG");


    SDL_Rect backgroundRect = {0, 0, MX_WIND_W, MX_WIND_H};
    
    // SDL_Rect replay_btn = {MX_BTN_Y, MX_BTN_X + MX_BTN_H, MX_BTN_W , MX_BTN_H};
    // SDL_Rect menu_btn = {MX_BTN_Y + MX_BTN_W + 40, MX_BTN_X + MX_BTN_H, MX_BTN_W, MX_BTN_H};

    SDL_Rect replay_btn = {MX_BTN_X - MX_BTN_W - 20,
                           MX_BTN_X + MX_BTN_H, 
                           MX_BTN_W,
                           MX_BTN_H};
    SDL_Rect menu_btn = {MX_BTN_X + MX_BTN_W + 20,
                         MX_BTN_X + MX_BTN_H,
                         MX_BTN_W,
                         MX_BTN_H};
   
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYUP) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    return EXIT_STATE;
                }
                if (event.key.keysym.sym == SDLK_LEFT) {
                    index_menu = 1;
                    
                }
                if (event.key.keysym.sym == SDLK_RIGHT) {
                    
                    index_menu = 2;

                }
                if (event.key.keysym.sym == SDLK_RETURN) {
                   
                        SDL_DestroyTexture(btn_img);
                        SDL_DestroyTexture(menu_bg);
                        TTF_CloseFont(font);

                    if (index_menu == 1) 
                        return GAME_STATE;
                    else 
                        return MENU_STATE;
                }
            }
        }
        SDL_RenderCopy(renderer, menu_bg, NULL, &backgroundRect);
       
        SDL_RenderCopy(renderer, btn_img, NULL, &replay_btn);
        SDL_RenderCopy(renderer, btn_img, NULL, &menu_btn);

        
        if (index_menu == 1) {
            mx_draw_text(color_selected, replay_btn.x + 80, replay_btn.y+5, "REPLAY", renderer, font);
            mx_draw_text(color, menu_btn.x + 100 , menu_btn.y+5, "MENU", renderer, font);
           
        } else if (index_menu == 2) {
            mx_draw_text(color, replay_btn.x + 80, replay_btn.y+5, "REPLAY", renderer, font);
            mx_draw_text(color_selected, menu_btn.x + 100 , menu_btn.y+5, "MENU", renderer, font);

        }
        
        usleep(100);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(btn_img);
    SDL_DestroyTexture(menu_bg);
    TTF_CloseFont(font);

    return result;
}

#include "game.h"
// #include <stdbool.h>

e_scenes mx_leaderboard(SDL_Renderer *renderer) {
    SDL_Event event;
    int running = 1;
    e_scenes result = MENU_STATE;
    int index = 1;
    TTF_Font *font = TTF_OpenFont("resource/font/ARIAL.TTF", 25);
    SDL_Color color = {0, 0, 255, 0};
    SDL_Color color_selected = {100, 100, 100, 0};

 
    SDL_Rect play_btn = {MX_BTN_X, MX_BTN_Y, MX_BTN_W , MX_BTN_H};
    SDL_Texture *play_btn_img =
            IMG_LoadTexture(renderer, "resource/img/empty.PNG");
    SDL_Rect board_btn = {MX_BTN_X, MX_BTN_Y + MX_BTN_H / 2, MX_BTN_W, MX_BTN_H};
    SDL_Texture *board_btn_img =
            IMG_LoadTexture(renderer, "resource/img/empty.PNG");

    SDL_Rect exit_btn = {MX_BTN_X, MX_BTN_Y + MX_BTN_H, MX_BTN_W, MX_BTN_H};
    SDL_Texture *exit_btn_img =
            IMG_LoadTexture(renderer, "resource/img/empty.PNG");
    
    SDL_Rect backgroundRect = {0, 0, MX_WIND_W, MX_WIND_H};
    SDL_Texture *imgBackground =
            IMG_LoadTexture(renderer, "resource/img/empty_back.png");

    while (running) {
        color.r = 0;
        color.g = 255;
        color.b = 255;
        color.a = 0;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYUP) {
                if (event.key.keysym.sym == SDLK_UP) {
                    index = (index > 1) ? (index - 1) : 3;
                    
                }
                if (event.key.keysym.sym == SDLK_DOWN) {
                    
                    index = (index < 3) ? (index + 1) : 1;

                }
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                   
                    SDL_DestroyTexture(play_btn_img);
                    SDL_DestroyTexture(board_btn_img);
                    SDL_DestroyTexture(exit_btn_img);
                    
                    SDL_DestroyTexture(imgBackground);
                    TTF_CloseFont(font);
                    return MENU_STATE;
                }
            }
        }
        SDL_RenderCopy(renderer, imgBackground, NULL, &backgroundRect);
       
        SDL_RenderCopy(renderer, play_btn_img, NULL, &play_btn);
        SDL_RenderCopy(renderer, board_btn_img, NULL, &board_btn);
        SDL_RenderCopy(renderer, exit_btn_img, NULL, &exit_btn);
        
        if (index == 1) {
            color.r = 0;
            mx_draw_text(color_selected, play_btn.x + 40, play_btn.y+50, "FIRST", renderer, font);
            color.r = 255;
            mx_draw_text(color, board_btn.x + 40 , board_btn.y+50, "SECOND", renderer, font);
            color.r = 255;
            mx_draw_text(color, exit_btn.x + 40 , exit_btn.y+50, "THIRD", renderer, font);

           
        } else if (index == 2) {
            color.r = 255;
            mx_draw_text(color, play_btn.x + 40, play_btn.y+50, "FIRST", renderer, font);
            color.r = 0;
            mx_draw_text(color_selected,board_btn.x + 40 , board_btn.y+50, "SECOND", renderer, font);
            color.r = 255;
            mx_draw_text(color, exit_btn.x + 40, exit_btn.y+50, "THIRD", renderer, font);

        
        } else if (index == 3) {
            color.r = 255;
            mx_draw_text(color, play_btn.x + 40, play_btn.y+50, "FIRST", renderer, font);
            color.r = 255;
            mx_draw_text(color, board_btn.x + 40, board_btn.y+50, "SECOND", renderer, font);
            color.r = 0;
            mx_draw_text(color_selected, exit_btn.x + 40, exit_btn.y+50, "THIRD", renderer, font);

        } 
        
        usleep(100);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyTexture(imgBackground);

    return result;
}

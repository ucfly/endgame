#include "game.h"

void mx_do_render_mult(SDL_Renderer *rend, t_state *game) {
    SDL_SetRenderDrawColor(rend, 4, 21, 66, 1);
    SDL_RenderClear(rend);

    SDL_Rect bg_rect = {game->space.x,
                        game->space.y,
                        game->space.w,
                        game->space.h};
    SDL_RenderCopy(rend, game->bg, NULL, &bg_rect);

    SDL_SetRenderDrawColor(rend, 25, 50, 200, 255);
    SDL_Rect tor_p = {game->gate.x,
                      game->gate.y,
                      game->gate.w,
                      game->gate.h};
     SDL_RenderFillRect(rend, &tor_p);
    SDL_RenderCopy(rend, game->gate_img, NULL, &tor_p);

    SDL_SetRenderDrawColor(rend, 25, 50, 200, 255);
    SDL_Rect tor_p2 = {game->gate2.x,
                      game->gate2.y,
                      game->gate2.w,
                      game->gate2.h};
    SDL_RenderFillRect(rend, &tor_p2);
    SDL_RenderCopy(rend, game->gate_img, NULL, &tor_p2);

    SDL_SetRenderDrawColor(rend, 250, 50, 20, 0);
    SDL_Rect plane_p = {game->plane.x,
                        game->plane.y,
                        game->plane.w,
                        game->plane.h};
    SDL_RenderFillRect(rend, &plane_p);
    SDL_RenderCopy(rend, game->car, NULL, &plane_p);

    SDL_SetRenderDrawColor(rend, 250, 50, 20, 0);
    SDL_Rect plane_p2 = {game->plane2.x,
                        game->plane2.y,
                        game->plane2.w,
                        game->plane2.h};
    SDL_RenderFillRect(rend, &plane_p2);
    SDL_RenderCopy(rend, game->car, NULL, &plane_p2);

    // TTF_CloseFont(game->font); 
    
    SDL_Color score_color_or = ORANGE;

    char *score_1 =  mx_int_to_str(game->plane.cnt);
    mx_draw_text(score_color_or,
                 20,
                 20,
                 "SCORE: ",
                 game->renderer,
                 game->font);
    mx_draw_text(score_color_or, 
                120, 
                20, 
                score_1, 
                game->renderer,
                game->font);
    free(score_1);
    score_1 = NULL;


    SDL_Color score_color_te = GREEN;

    char *score_2 = mx_int_to_str(game->plane2.cnt);
    mx_draw_text(score_color_te,
                 MX_WIND_W - 220,
                 20,
                 "SCORE: ",
                 game->renderer,
                 game->font);
    mx_draw_text(score_color_te,
                 120,
                 MX_WIND_H - 120,
                 score_2,
                 game->renderer,
                 game->font);
    free(score_2);
    score_2 = NULL;

    SDL_RenderPresent(rend);
}

#include "game.h"

void mx_do_render(SDL_Renderer *rend, t_state *game) {
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
    //  SDL_RenderFillRect(rend, &tor_p);
    SDL_RenderCopy(rend, game->gate_img, NULL, &tor_p);

    SDL_SetRenderDrawColor(rend, 250, 50, 20, 0);
    SDL_Rect plane_p = {game->plane.x,
                        game->plane.y,
                        game->plane.w,
                        game->plane.h};
    // SDL_RenderFillRect(rend, &plane_p);
    SDL_RenderCopy(rend, game->car, NULL, &plane_p);

    for (int i = GAME_LIFE; i > 0; i--) {
        int heart_x = HEART_SIZE + HEART_SIZE * i;
        game->life_img = (i <= game->plane.life) 
                            ? game->heart_img 
                            : game->heart_empty_img;

        SDL_Rect heart_p = {heart_x, HEART_SIZE * 2, HEART_SIZE, HEART_SIZE};
        SDL_RenderCopy(rend, game->life_img, NULL, &heart_p);
    }

    SDL_Color score_color = ORANGE;

    char *score = mx_int_to_str(game->plane.cnt);
    mx_draw_text(score_color, 20, 20, "SCORE: ", game->renderer, game->font);
    mx_draw_text(score_color, 120, 20, score, game->renderer, game->font);
    free(score);
    score = NULL;

    SDL_RenderPresent(rend);
}


#include "game.h"

void mx_do_render(SDL_Renderer *rend, t_state *game) {

    SDL_SetRenderDrawColor(rend, 4, 21, 66, 1);
    SDL_RenderClear(rend);

    SDL_Rect bg_rect = {game->space.x,
                        game->space.y,
                        game->space.w,
                        game->space.h};
    SDL_RenderCopy(rend, game->bg, NULL, &bg_rect);

    // SDL_SetRenderDrawColor(rend, 25, 50, 200, 255);
    // SDL_Rect tor_pb = {game->gate.x + MX_RING_L , 
    //                   game->gate.y + 10,
    //                   game->gate.w - MX_RING_L*2,
    //                   game->gate.h -20};
    // SDL_RenderFillRect(rend, &tor_pb);

    SDL_SetRenderDrawColor(rend, 25, 50, 200, 255);
    SDL_Rect tor_p = {game->gate.x, 
                      game->gate.y,
                      game->gate.w,
                      game->gate.h};
    SDL_RenderCopy(rend, game->gate_img[0], NULL, &tor_p);

    SDL_SetRenderDrawColor(rend, 250, 50, 20, 0);
    SDL_Rect plane_p = {game->plane.x,
                        game->plane.y,
                        game->plane.w,
                        game->plane.h};
    // SDL_RenderFillRect(rend, &plane_p);
    SDL_RenderCopy(rend, game->car, NULL, &plane_p);
    SDL_RenderPresent(rend);
}

#include "game.h"

void mx_do_render(SDL_Renderer *rend, t_state *game) {
        // int pl_x = game->plane.x;
        // int pl_y = game->plane.y;
        // int pl_w = game->plane.w;
        // int pl_h = game->plane.h;

        SDL_SetRenderDrawColor(rend, 4, 21, 66, 1);
        SDL_RenderClear(rend);

        SDL_Rect bg_rect = {0, 0, 800, 800};
        SDL_RenderCopy(rend, game->bg, NULL, &bg_rect);


        SDL_SetRenderDrawColor(rend, 25, 50, 200, 255);
        SDL_Rect tor_p = {game->gate.x, game->gate.y, game->gate.w, game->gate.h};
        SDL_RenderCopy(rend, game->bg, NULL, &tor_p);
        // SDL_RenderFillRect(rend, &tor_p); 
        
        // SDL_SetRenderDrawColor(rend, 250, 250, 250, 250);
        // SDL_Rect astr_p = { (pl_x + pl_w / 4), (pl_y - game->plane.h), (pl_w/4), pl_h};
        // SDL_RenderFillRect(rend, &astr_p);

        SDL_SetRenderDrawColor(rend, 250, 50, 20, 255);
        SDL_Rect plane_p = {game->plane.x, game->plane.y, game->plane.w, game->plane.h};
        // SDL_RenderFillRect(rend, &plane_p);
        SDL_RenderCopy(rend, game->car, NULL, &plane_p);

        SDL_RenderPresent(rend);
}

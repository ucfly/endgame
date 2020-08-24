#include "game.h"

void mx_do_render(SDL_Renderer *rend, t_car *plane, t_car *astr, t_world *world) {

        SDL_SetRenderDrawColor(rend, 4, 21, 66, 1);
        SDL_RenderClear(rend);

        SDL_SetRenderDrawColor(rend, 25, 50, 200, 255);
        SDL_Rect tor_p = {world->x, world->y, world->w, world->h};
        SDL_RenderFillRect(rend, &tor_p);
        
        SDL_SetRenderDrawColor(rend, 250, 250, 250, 250);
        SDL_Rect astr_p = { astr->x, astr->y, 40, 40};
        SDL_RenderFillRect(rend, &astr_p);

        SDL_SetRenderDrawColor(rend, 250, 50, 20, 255);
        SDL_Rect plane_p = {plane->x, plane->y, 200, 50};
        SDL_RenderFillRect(rend, &plane_p);

        SDL_RenderPresent(rend);
}

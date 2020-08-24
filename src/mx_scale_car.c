#include "game.h"

void mx_scale_car(t_state *game, int direction) {
    int init_w = 300;
    int init_h = 100;

    if (direction == 0) {
        game->plane.w = init_w;
        game->plane.h = init_h;
    } 
    else {
        game->plane.w += 5 * direction;
        game->plane.h += 5 * direction;
    }
}

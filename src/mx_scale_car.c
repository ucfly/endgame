#include "game.h"

void mx_scale_car(t_state *game, int direction) {

    if (direction == 0) {
        game->plane.w = MX_PLANE_W;
        game->plane.h = MX_PLANE_H;
    } 
    else {
        game->plane.w += 7 * direction;
        game->plane.h += 5 * direction;
    }
}

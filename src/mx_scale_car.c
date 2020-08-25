#include "game.h"

void mx_scale_car(t_state *game) {
    switch (game->plane.dw) {
        case -1:
            game->plane.w -= 7 * game->plane.dw;
            game->plane.h -= 5 * game->plane.dw;
            break;
        case 1:
            game->plane.w -= 5 * game->plane.dw;
            game->plane.h -= 5 * game->plane.dw;
            break;
        default:
            game->plane.w = MX_PLANE_W;
            game->plane.h = MX_PLANE_H;
            break;
    }
}

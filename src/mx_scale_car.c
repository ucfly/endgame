#include "game.h"

void mx_scale_car(t_world *plane) {
    switch (plane->dw) {
        case -1:
            plane->w -= 5 * plane->dw;
            plane->h -= 5 * plane->dw;
            break;
        case 1:
            plane->w -= 5 * plane->dw;
            plane->h -= 5 * plane->dw;
            break;
        default:
            plane->w = MX_PLANE_W;
            plane->h = MX_PLANE_H;
            break;
    }
}

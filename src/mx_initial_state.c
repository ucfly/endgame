#include "game.h"

void mx_initial_state(t_world *gate, t_world *plane) {
    gate->x = MX_RANDOM_X;
    gate->y = MX_RANDOM_Y;
    gate->w = MX_RING_W;
    gate->h = MX_RING_H ;

    plane->x = MX_PLANE_ST_X;
    plane->dw = 0;
}

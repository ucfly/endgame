#include "game.h"

int mx_check_pass(t_world *gate, t_world *plane) {
    float pl_max_x = plane->x + plane->w;
    float pl_max_y = plane->y + plane->h;

    float gt_in_max_x = gate->x - MX_RING_L + gate->w - MX_RING_L;
    float gt_in_max_y = gate->y - MX_RING_L + gate->h - MX_RING_L;

    if (plane->x > gate->x && pl_max_x < gt_in_max_x) {
        if (plane->y > gate->y && pl_max_y < gt_in_max_y) {
            return 1;
        }
    }
        return -1;
}

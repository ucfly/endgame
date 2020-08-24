#include "game.h"
int mx_check_pass(t_state *game) {
    if (game->plane.x > (game->gate.x - MX_RING_L) &&
        game->plane.x < (game->gate.x + game->gate.w - MX_RING_L)) {
            return -1;
        }
        return 1;
    }

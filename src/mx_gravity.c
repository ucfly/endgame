#include "game.h"

void process(t_state *game) {
    t_world *plane = &game->plane;
    plane->y += plane->dy;

    plane->dy += MX_GRAVITY;
}

#include "game.h"

void process(t_state *game) {
    // t_world *plane = &game->plane;
    // plane->y += plane->dy;
    game->plane.y += game->plane.dy;
    // plane->dy += MX_GRAVITY;
    game->plane.dy += MX_GRAVITY;
}

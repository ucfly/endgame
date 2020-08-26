#include "game.h"


void mx_gravitation (t_world *plane) {
    plane->y += plane->dy;
    plane->dy += MX_GRAVITY;
}

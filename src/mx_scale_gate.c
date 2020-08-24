#include "game.h"

void mx_scale_gate(t_state *game) {

    int random_x = (rand() % (750));
    int random_y = (rand() % (750));
    int init_w = 300;
    int init_h = 100;


    if (game->gate.w < 480) {
        game->gate.w += 2;
        game->gate.h += 1;

        if (game->gate.x > (game->gate.w - 200)) {
            game->gate.x -= 2;
        } else {
            game->gate.x++;
        }

        if (game->gate.y > (game->gate.w - 200)) {
            game->gate.y -= 2;
        } else {
            game->gate.y++;
        }
    }

    // car(plane) scale
    if (game->gate.w > 420 && game->gate.w < 480) {
        game->plane.w -= 3;
        game->plane.h -= 3;
    }

    if (game->gate.w >= 480) {
        game->gate.x = random_x;
        game->gate.y = random_y;
        game->gate.w = 100;
        game->gate.h = 50;

        game->plane.w = init_w;
        game->plane.h = init_h;
    }
}

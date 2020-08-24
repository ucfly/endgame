#include "game.h"

void mx_scale_gate(t_state *game) {
    int random_x = (rand() % (1500));
    int random_y = (rand() % (900));

    if (game->gate.w < 480) {
        game->gate.w += 2;
        game->gate.h += 1;

        if (game->gate.x > (game->gate.w - 200)) {
            game->gate.x -= 2;
        }
        else {
            game->gate.x++;
        }

        if (game->gate.y > (game->gate.w - 200)) {
            game->gate.y -= 2;
        }
        else {
            game->gate.y++;
        }
    }

    if (game->gate.w > 440 && game->gate.w < 480) {
        mx_scale_car(game, -1);
    }

    if (game->gate.w >= 480) {
        game->gate.x = random_x;
        game->gate.y = random_y;
        game->gate.w = 100;
        game->gate.h = 50;

        mx_scale_car(game, 0);
    }
}

#include "game.h"

void mx_scale_gate(t_state *game) {

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

    if (game->gate.w > 420 && game->gate.w < 480) {
        game->plane.dy = mx_check_pass(game);

        mx_scale_car(game, game->plane.dy);

        // if(is_crush > 0) {
        //     mx_printerr("     UMIR \n");
        // }
    }

    if (game->gate.w >= 480) {
        game->gate.x = MX_RANDOM_X;
        game->gate.y = MX_RANDOM_Y;
        game->gate.w = 100;
        game->gate.h = 50;

        mx_scale_car(game, 0);
    }
}

#include "game.h"

void mx_scale_gate(t_state *game) {

    if (game->gate.w < MX_PLANE_W + 80) {
        game->gate.w++;
        game->gate.h++;

        if (game->gate.x > (game->gate.w - 200)) {
            game->gate.x -= 1;
        }
        else {
            game->gate.x += 0.5;
        }

        if (game->gate.y > (game->gate.w - 200)) {
            game->gate.y -= 2;
        }
        else {
            game->gate.y++;
        }
    }

    if (game->gate.w > MX_PLANE_W+40 && game->gate.w < MX_PLANE_W + 80) {
        game->plane.dy = mx_check_pass(game);

        mx_scale_car(game, game->plane.dy);

        // if(is_crush > 0) {
        //     mx_printerr("     UMIR \n");
        // }
    }

    if (game->gate.w >= MX_PLANE_W + 80) {
        game->gate.x = MX_RANDOM_X;
        game->gate.y = MX_RANDOM_Y;
        game->gate.w = 100;
        game->gate.h = 50;

        game->plane.x = MX_PLANE_ST_X;
        // game->plane.x = MX_PLANE_ST_X;
        

        mx_scale_car(game, 0);

    }
}

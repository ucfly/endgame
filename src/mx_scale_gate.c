#include "game.h"

static void mx_f1(t_state *game) {
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

void mx_scale_gate(t_state *game) {
    if (game->gate.w < MX_PLANE_W + 80) {
        mx_f1(game);
    }

    if (game->gate.w == MX_PLANE_W + 40) {
        int is_passed = mx_check_pass(game);

        game->plane.dw = is_passed;

        if (is_passed == 1) {
            printf("score: %d\n----\n",game->plane.cnt );
            game->plane.cnt++;
            write(1, "pass\n", 5);
            printf("score: %d\n----\n", game->plane.cnt );
        }
        else if (is_passed == -1) {
            write(1, "\numir\n", 6);
        }
    }

    if (game->gate.w > MX_PLANE_W + 40 && game->gate.w < MX_PLANE_W + 80) {
        mx_scale_car(game);
    }

    if (game->gate.w >= MX_PLANE_W + 80) {
        game->gate.x = MX_RANDOM_X;
        game->gate.y = MX_RANDOM_Y;
        game->gate.w = 100;
        game->gate.h = 50;

        game->plane.x = MX_PLANE_ST_X;
        game->plane.dw = 0;
        mx_scale_car(game);
    }
}



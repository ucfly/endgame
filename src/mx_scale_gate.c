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

static void mx_f2 (t_state *game) {
        game->gate.x = MX_RANDOM_X;
        game->gate.y = MX_RANDOM_Y;
        game->gate.w = 100;
        game->gate.h = 50;

        game->plane.x = MX_PLANE_ST_X;
        game->plane.dw = 0;
}

// static int mx_check_pass(t_state *game) {
//     float pl_max_x = game->plane.x + game->plane.w;
//     float pl_max_y = game->plane.y + game->plane.h;

//     float gt_in_max_x = game->gate.x - MX_RING_L + game->gate.w - MX_RING_L;
//     float gt_in_max_y = game->gate.y - MX_RING_L + game->gate.h - MX_RING_L;

//     if (game->plane.x > game->gate.x && pl_max_x < gt_in_max_x) {
//         if (game->plane.y > game->gate.y && pl_max_y < gt_in_max_y) {
//             return 1;
//         }
//     }
//         return -1;
// }

// static void mx_scale_car(t_state *game) {
//     switch (game->plane.dw) {
//         case -1:
//             game->plane.w -= 7 * game->plane.dw;
//             game->plane.h -= 5 * game->plane.dw;
//             break;
//         case 1:
//             game->plane.w -= 5 * game->plane.dw;
//             game->plane.h -= 5 * game->plane.dw;
//             break;
//         default:
//             game->plane.w = MX_PLANE_W;
//             game->plane.h = MX_PLANE_H;
//             break;
//     }
// }


void mx_scale_gate(t_state *game) {
    if (game->gate.w < MX_PLANE_W + 80) {
        mx_f1(game);
    }

    if (game->gate.w == MX_PLANE_W + 40) {
        int is_passed = mx_check_pass(game);
        game->plane.dw = is_passed;

        switch (is_passed) {
            case 1: 
                game->plane.cnt++;
                break;
            case -1:
                write(1, "\numir\n", 6);
                break;
            default:
                break;
        }
    }

    if (game->gate.w > MX_PLANE_W + 40 && game->gate.w < MX_PLANE_W + 80) {
        mx_scale_car(game);
    }

    if (game->gate.w >= MX_PLANE_W + 80) {
        mx_f2(game);
        mx_scale_car(game);
    }
}



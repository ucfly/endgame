#include "game.h"

void mx_play_game_mult(t_state *game) {
    mx_gravitation (&game->plane);
    mx_gravitation (&game->plane2);

    // mx_score_to_str(game);

    if (game->gate.w < MX_PLANE_W * 2) {
        mx_scale_gate(&game->gate);
    }
    if (game->gate2.w < MX_PLANE_W * 2) {
        mx_scale_gate(&game->gate2);
    }

    if (game->gate.w == MX_PLANE_W * 1.7) {
        game->plane.dw = mx_check_pass(&game->gate, &game->plane);
        mx_is_over(&game->plane);
    }

    if (game->gate2.w == MX_PLANE_W * 1.7) {
        game->plane2.dw = mx_check_pass(&game->gate2, &game->plane2);
        mx_is_over(&game->plane2);
    }

    if (game->gate.w > MX_PLANE_W * 1.7 && game->gate.w < MX_PLANE_W * 2) {
        mx_scale_car(&game->plane);
    }
    if (game->gate2.w > MX_PLANE_W * 1.7 && game->gate2.w < MX_PLANE_W * 2) {
        mx_scale_car(&game->plane2);
    }

    if (game->gate.w >= MX_PLANE_W * 2) {
        mx_initial_state(&game->gate, &game->plane);
        mx_scale_car(&game->plane);
    }
    if (game->gate2.w >= MX_PLANE_W * 2) {
        mx_initial_state(&game->gate2, &game->plane2);
        mx_scale_car(&game->plane2);
    }
}

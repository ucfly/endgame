#include "game.h"

static void scale_gate(t_world *gate) {
    gate->w++;
    gate->h++;

    if (gate->x > (gate->w - 200)) {
        gate->x -= 1;
    }
    else {
        gate->x += 0.5;
    }

    if (gate->y > (gate->w - 200)) {
        gate->y -= 2;
    }
    else {
        gate->y++;
    }
   
}

static void initial_state(t_world *gate, t_world *plane) {
    gate->x = MX_RANDOM_X;
    gate->y = MX_RANDOM_Y;
    gate->w = MX_RING_W;
    gate->h = MX_RING_H ;

    plane->x = MX_PLANE_ST_X;
    // gate.plane.
    plane->dw = 0;
}

static int check_pass(t_state *game) {
    float pl_max_x = game->plane.x + game->plane.w;
    float pl_max_y = game->plane.y + game->plane.h;

    float gt_in_max_x = game->gate.x - MX_RING_L + game->gate.w - MX_RING_L;
    float gt_in_max_y = game->gate.y - MX_RING_L + game->gate.h - MX_RING_L;

    if (game->plane.x > game->gate.x && pl_max_x < gt_in_max_x) {
        if (game->plane.y > game->gate.y && pl_max_y < gt_in_max_y) {
            return 1;
        }
    }
        return -1;
}

static void gravitation (t_state *game) {
    game->plane.y += game->plane.dy;
    game->plane.dy += MX_GRAVITY;
}

static void scale_car(t_world *plane) {
    switch (plane->dw) {
        case -1:
            plane->w -= 5 * plane->dw;
            plane->h -= 5 * plane->dw;
            break;
        case 1:
            plane->w -= 5 * plane->dw;
            plane->h -= 5 * plane->dw;
            break;
        default:
            plane->w = MX_PLANE_W;
            plane->h = MX_PLANE_H;
            break;
    }
}

// static void render_score(t_state *game) {

//     TTF_Font *font = TTF_OpenFont("resource/font/Sansation-Bold.ttf", 25);
//     SDL_Color score_color = ORANGE;
//     draw_text (score_color, 20, 20, "SCORE: ", game->renderer, font);
//     draw_text (score_color, 120, 20,  game->plane.hello, game->renderer, font);
//     // SDL_RenderPresent(game->renderer);
// }

static void is_over(t_world *plane) {
    
    switch (plane->dw) {
    case 1: 
        plane->cnt++;
        plane->hello = "kukusiki \n";
        break;
    case -1:
        plane->life--;
        break;
    default:
        break;
    }
}

// void mx_score_to_str(t_state *game){
//     char *result = NULL;
//     int leng;
//     int cnt = game->plane.cnt;
//     int dig;
//     int rest;

//     for (leng = 1; cnt > 0; leng++) {
//         cnt /= 10;
//     }

//    result = (char*)malloc(leng+1);
//     if (result == NULL) {
//         exit(1);
//     }

//     cnt = game->plane.cnt;

//     for (int i = leng; i < 0; i--) {
//         dig = cnt % 10;
//         cnt /= 10;

//         result[i] = '\0';
//         if (i != leng)
//             result[i] = dig;
//     }

//     game->plane.hello = result;
//     free(result);
// }


void mx_play_game(t_state *game) {
    gravitation (game);
    
    // mx_score_to_str(game);

    if (game->gate.w < MX_PLANE_W * 2) {
        scale_gate(&game->gate);
        scale_gate(&game->gate2);
    }

    if (game->gate.w == MX_PLANE_W * 1.7) {
        game->plane.dw = check_pass(game);
        is_over(&game->plane);
        is_over(&game->plane2);
    }

    if (game->gate.w > MX_PLANE_W * 1.7 && game->gate.w < MX_PLANE_W * 2) {
        scale_car(&game->plane);
        scale_car(&game->plane2);
    }

    if (game->gate.w >= MX_PLANE_W * 2) {
        initial_state(&game->gate, &game->plane);
        initial_state(&game->gate2, &game->plane2);
        scale_car(&game->plane);
        scale_car(&game->plane2);
    }
}



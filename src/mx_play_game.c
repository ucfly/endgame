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

static void is_over(t_state *game) {
    
    switch (plane->dw) {
    case 1: 
        plane->cnt++;
        break;
    case -1:
        plane->life--;
        break;
    default:
        break;
    }
}

static char int_to_char(int n) {
    char result;
    int temp = n;

    if(temp > 9)
        mx_int_to_str(n / 10);

    result = temp % 10 + 48;
    return result;
}


char *mx_int_to_str(int n) {
    int temp = n;
    int i;
    char *result = NULL;
    int count = 0;
    if (n >= 0) {
    for(count = 0; temp > 0; count++)
        temp /= 10;

    result = malloc(count + 1);
    for(i = 0; i <= count; i++)
        result[i] = '\0';
    
    temp = n; 
 
    for(i = count; i >= 0; i--) {
        if (i == count)
            result[i] = '\0';
        else
            result[i] = int_to_char(temp);    
        }
    }
    return result;
}

void mx_play_game(t_state *game) {
    gravitation (game);

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



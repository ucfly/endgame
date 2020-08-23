#include "game.h"

void mx_scale_gate(t_state *game) {
    int random_x = (rand() % (400 + 1 - 10) + 10);
    // int init_w = 126;
    // int init_h = 98;

    if (game->gate.w < 480) {
        game->gate.y += 1;
        game->gate.w += 2;
        game->gate.h += 1;

        // game->plane.h +=1;
        // game->plane.w +=1;
    }


    // // car(plane) scale 
    //     if (game->gate.w > 420 && game->gate.w < 480) {
    //     game->plane.w -= 5;
    //     game->plane.h -= 5;
    // } 


    if (game->gate.w >= 480) {
        game->gate.x = random_x;
        game->gate.y = 10;
        game->gate.w = 120;
        game->gate.h = 50;

        // game->plane.w = init_w;
        // game->plane.h = init_h;
    }
}

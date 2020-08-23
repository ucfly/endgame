#include "game.h"

void mx_scale_gate(t_state *game) {

    int random_x = (rand() % (400 + 1 - 10) + 10);

    if (game->gate.w < 480) {
        // gate->x = ( gate->x >= 280 && ) ? gate->x - gate->w : gate->x ;
        game->gate.y+= 1;
        game->gate.w += 2;
        game->gate.h += 1;
    }

    if (game->gate.w >= 480) { 
        game->gate.x = random_x;
        game->gate.y = 10;
        game->gate.w = 120;
        game->gate.h = 50;
    }
}

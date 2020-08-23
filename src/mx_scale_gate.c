#include "game.h"

void mx_scale_gate(t_world *gate) {

    int random_x = (rand() % (400 + 1 - 10) + 10);

    if (gate->w < 480) {
        gate->x = ( gate->x >= 280) ? gate->x - gate->w : gate->x ;
        gate->y+= 5;
        gate->w += 10;
        gate->h += 2;
    }

    if (gate->w >= 480) { 
        gate->x = random_x;
        gate->y = 10;
        gate->w = 120;
        gate->h = 50;
    }
}

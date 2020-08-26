#include "game.h"

void mx_scale_gate(t_world *gate) {
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

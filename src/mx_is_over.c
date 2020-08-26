#include "game.h"

void mx_is_over(t_world *plane) {
    
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

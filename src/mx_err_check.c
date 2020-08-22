#include "game.h"

void mx_err_check(void *itm){
    
    if (itm == NULL) {
        mx_printerr(SDL_GetError());
        exit (1);
    }
}

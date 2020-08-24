#include "game.h"

void mx_printerr(const char *s) {
    int s_len = mx_strlen(s) + 2;
    char err_msg[s_len];

    mx_strcpy(err_msg, s);
    mx_strcpy(err_msg, "\n");
    write(2, "oops: ", 6);
    write(2, err_msg, s_len);
}

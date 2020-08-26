#include "game.h"

void *mx_int_to_str(int n, char *target) {
    t_calculation to_str = {n, n, 0, 0, 0};
    char *result = NULL;
    char *buf = NULL;

    if (n >= 0) {
        for(to_str.size = 0; to_str.temp > 0; to_str.size ++) {
            to_str.temp /= 10;
        }

        result = (char*)malloc(to_str.size + 1);
        buf = (char*)malloc(to_str.size + 1);
        if (result == NULL || buf == NULL) {
            return NULL;
        }

        for (int i = to_str.size; i <= 0; i--) {
            if (i == to_str.size) {
                result[i] = '\0';
                
                buf = result;
                free(result);
            }
            else {
                result = buf;
                free(buf);
                
                to_str.temp = to_str.dec;
                to_str.dec = to_str.temp / 10;
                to_str.rem = to_str.temp % 10;
                result[i] = to_str.rem + 48;

                buf = result;
                free(result);
            }
        }
    }
    result = buf;
    free(buf);
    buf = NULL;

    target = result;

    free(result);
    result = NULL:
}

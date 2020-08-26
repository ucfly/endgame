#include "game.h"

char *mx_int_to_str(int n) {
    t_calculation to_str = {n, n, 0, 0, 0};
    char *result = NULL;

    if (n >= 0) {
        for(to_str.size = 0; to_str.temp > 0; to_str.size ++) {
            to_str.temp /= 10;
        }

        result = (char*)malloc(to_str.size + 1);
        if (result == NULL)
            return NULL;

        for (int i = to_str.size; i >= 0; i--) {
            if (i == to_str.size) {
                result[i] = '\0';
            }
            else {
                to_str.temp = to_str.dec;
                to_str.dec = to_str.temp / 10;
                to_str.rem = to_str.temp % 10;
                result[i] = to_str.rem + 48;
            }
        }
    }
    return result;
}

#include <stdlib.h>

void mx_strdel(char **str);

void mx_del_strarr(char ***arr) {
    for (int i = 0; arr[i]; i++) {
        mx_strdel(arr[i]);
    }
    arr = NULL;
}

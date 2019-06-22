#include <stdlib.h>

int *mx_copy_int_arr(const int *src, int size) {
    if (src == NULL)
        return NULL;
    int *copy = (int *) malloc(size);
    for (int i = 0; i < size; i++) {
        copy[i] = src[i];
    }
    return copy;
}

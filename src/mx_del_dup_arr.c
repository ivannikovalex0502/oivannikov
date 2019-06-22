#include <stdlib.h>

int *mx_copy_int_arr(const int *src, int size);

int *mx_del_dup_arr(int *src, int src_size, int *dst_size) {
    int index = 0;
    int i = 0;
    int flag = 0;
    int *dst = (int *) malloc(sizeof(int) * *dst_size);

    while (index < src_size) {
        for (int j = 0; j < i; j++) {
            if (src[index] == dst[j])
                flag = 1;
        }

        if (!flag) {
            dst[i] = src[index];
            i++;
        }
        else
            flag = 0;

        index++;
    }
    return dst; 
}

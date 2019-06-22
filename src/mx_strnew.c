#include <stdlib.h>

int mx_strlen(char *s);

char *mx_strnew(const int size) {
    if (size < 1)
        return NULL;
    char *str = (char*) malloc(size + 1);
    for (int i = 0; i < size + 1; i++) {
        str[i] = '\0';
    }
    return str;
}

#include <stdio.h>

char *mx_strchr(const char *s, int c) {
    char ch = c;

    while (s) {
        if (*s == ch) {
            return (char *) s;
        }
        if (*s == '\0') {
            return NULL;
        }
        s++;
    }
    return NULL;
}

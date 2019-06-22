#include <stdlib.h>

char *mx_strnew(const int size);
int mx_strlen(const char *s);
void mx_strcpy(char *s1, const char *s2);

char *mx_strdup(const char *str) {
    char *simulacrum = mx_strnew(mx_strlen(str));
    mx_strcpy(simulacrum, str);
    return simulacrum;
}

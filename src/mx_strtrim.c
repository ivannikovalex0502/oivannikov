#include <stdlib.h>

void mx_strdel(char **str);
char *mx_strnew(const int size);
int mx_isspace(char c);
char *mx_strncpy(char *dst, const char *src, int i);
int mx_strlen(const char *s);

char *mx_strtrim(const char *str) {
    int len = mx_strlen(str);
    char *result = NULL;
    int first = 0;
    int last = 0;

    if (!str) return NULL;
    for (int i = 0; mx_isspace(str[i]); i++) {
        first++;
    }
    for (int i = len - 1; mx_isspace(str[i]); i--) {
        last++;
    }
    result = mx_strnew(len - first -last);
    result = mx_strncpy(result, str + first, len - first - last); 
    return result;
}

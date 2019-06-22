#include <stdio.h>

int mx_isspace(int c);
void mx_strdel(char **str);
char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strncpy(char *dst, const char *src, int i);
char *mx_strtrim(const char *str);

char *mx_del_extra_whitespaces(const char *str) {
    char *tmp = mx_strnew(mx_strlen(str) - 1);
    int flag = 0;
    int j = 0;

    for (int i = 0; i < mx_strlen(str - 1); i++) {
        if (!mx_isspace(str[i])) {
            tmp[j] = str[i];
            j++;
            flag = 0;
        }
        else if (flag == 0) {
            tmp[j] = ' ';
            j++;
            flag = 1;
        }
    }
    char *result = mx_strnew(mx_strlen(tmp) - 2);
    result = mx_strtrim(tmp);
    mx_strdel(&tmp);
    return result;
}

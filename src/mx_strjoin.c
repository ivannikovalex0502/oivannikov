#include <stdlib.h>

char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strdup(const char *str);
void mx_strcpy(char *s1, const char *s2);
char *mx_strcat(char *s1, const char *s2);

char *mx_strjoin(char const *s1, char const *s2) {
    int len1 = 0, len2 = 0;

    if (s1 == NULL && s2 == NULL)
        return NULL;

    if (s1 != NULL)
        len1 = mx_strlen(s1);
    if (s2 != NULL)
        len2 = mx_strlen(s2);

    char *newStr = mx_strnew(len1 + len2);

    if (s1 == NULL)
        newStr = mx_strcat(newStr, s2);
    else if (s2 == NULL)
        newStr = mx_strcat(newStr, s1);
    else if (s1 != NULL && s2 != NULL){
        newStr = mx_strcat(newStr, s1);
        newStr = mx_strcat(newStr, s2);
    }
    return newStr;
}

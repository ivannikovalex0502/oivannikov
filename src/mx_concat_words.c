#include <stdlib.h>

char *mx_strcat(char *s1, const char *s2);
void mx_strdel(char **str);
char *mx_strdup(const char *str);
char *mx_strnew(const int size);
int mx_strlen(const char *s);
void mx_strcpy(char *s1, const char *s2);
char *mx_strjoin(char const *s1, char const *s2);

char *mx_concat_words(char **words) {
    int j = 0;
    int len = 0;
    while (words[j]) {
        j++;
    }
    for (int i = 0; i < j; i++) {
        len += mx_strlen(words[i]);
    }
    char *str = mx_strnew(len);
    for (int i = 0; i < j; i++) {
        str = mx_strjoin(str, words[i]);
        if (i != j - 1)
            str = mx_strjoin(str, " ");
    } 
    free(str);
    return str;
}

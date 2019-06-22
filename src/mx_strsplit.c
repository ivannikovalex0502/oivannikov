#include <stdio.h>
#include <stdlib.h>

int mx_count_word(const char *str, char delim);
char *mx_strnew(const int size);
char *mx_strncpy(char *dst, const char *src, int len);
void mx_strdel(char **str);

char **mx_strsplit(char const *s, char c) {
     char **words = (char **) malloc(sizeof(char*) * mx_count_word(s, c));
     int index = 0;
     int symbols = 0;
     int words_index = 0;
     int flag = 0;

     while (s[index]) {
         while (s[index] != c && s[index]) {
             symbols++;
             index++;
             flag = 1;
         }
         if (flag) {
             words[words_index] = mx_strnew(symbols);
             mx_strncpy(words[words_index], (s + index - symbols), symbols);
             symbols = 0;
             words_index++;
             flag = 0;
         }
         index++;
     }
     words[words_index] = NULL;
     return words;
}

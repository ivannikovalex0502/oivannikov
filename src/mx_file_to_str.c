#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char *mx_strjoin(char const *s1, char const *s2);
char *mx_strcat(char *s1, const char *s2);
void mx_strcpy(char *s1, const char *s2);
char *mx_strdup(const char *str);
int mx_strlen(const char *s);
char *mx_strnew(const int size);

char *mx_file_to_str(const char *filename) {
    char buf[1];
    int len = 0;
    int fd = open(filename, O_RDONLY);
    if(fd < 0)
        return NULL;
    while (read(fd, buf, 1)) {
        len++;
    }
    int fd_close = close(fd);
    if (fd_close < 0)
        return NULL;
    char *result = mx_strnew(len);

    int fd2 = open(filename, O_RDONLY);
    read(fd2, result, len);
    close(fd2);
    return result;
}

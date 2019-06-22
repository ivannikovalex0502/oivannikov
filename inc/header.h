#ifndef HEADER_H
#define HEADER_H

#include<stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

char *mx_file_to_str(const char *filename);
void mx_printerr(const char *s);
void mx_printchar(char c);
int mx_strlen(const char *s);
void mx_printstr(const char *s);
char *mx_strcpy(char *dst, const char *src);
bool mx_isdigit(int c);
bool mx_isspace(char c);
void mx_printint(int n);
int mx_atoi(const char *str);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strnew(const int size);

#endif

#include <stdbool.h>

bool mx_isspace(int c);
bool mx_isdigit(int c);

int mx_atoi(const char *str) {
    int i = 0;
    int sign = 1;
    int res = 0;

    while (mx_isspace(str[i])) {
        i++;
    }
    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    while (str[i] && !mx_isspace(str[i]) && mx_isdigit(str[i])) {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return res * sign;
}

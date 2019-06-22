#include <stdbool.h>
#include <unistd.h>

bool mx_islower(int c);
bool mx_isupper(int c);
int mx_tolower(int c);
int mx_toupper(int c);

void mx_reverse_case(char *s) {
    int length = 0;
    while (s[length]) {
        if (mx_isupper(s[length])) {
            s[length] = mx_tolower(s[length]);
        }
        else {
            s[length] = mx_toupper(s[length]);
        }
        length++;
    }
}

#include <unistd.h>

void mx_printchar(char c);

void mx_printint(int n) {
    int length = 0;
    int tmp = n;
    int isNeg = 0;    

    if (n == 0) {
        mx_printchar('0');
    }

    if(n < 0) {
        n *= -1;
        isNeg = 1;
    }

    while (tmp != 0) {
        length++;
        tmp /= 10;
    }

    int value[length];

    while (tmp != length) {
        value[tmp] = n % 10;
        n /= 10;
        tmp++; 
    }
    
    length--;
    
    if(isNeg) {
        mx_printchar('-');
    }

    while (length != -1) {
        mx_printchar(value[length] + 48);
        length--;
    }
}

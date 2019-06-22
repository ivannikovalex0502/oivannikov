char *mx_strncpy(char *dst, const char *src, int len) {
    int i = 0;

    if(dst == '\0') {
        return "\0";
    }

    while (i < len) {
        dst[i] = src[i];
        i++;
    }

    while (dst[len]) {
        dst[len] = '\0';
        len++;
    }

    return (dst);
}

int mx_count_word(const char *str, char delim) {
    int i = 0;
    int count = 0;
    int flag = 0;

    while (str[i] != '\0') {
        if(flag == 0 && str[i] != delim) {
            count++;
            flag = 1;
        }
        
        if (str[i + 1] == delim)
            flag = 0;
        i++;
    }
    
    return count;
}

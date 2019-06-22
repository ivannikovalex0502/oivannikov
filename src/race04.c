#include "header.h"
#include<fcntl.h>
 
int row_len (char *str);
int row_count(char *str);
int is_exist(char *str);
int coma_count(char *str);
char *delete_coma(char *str, int row, int len);
int is_map(char *str, int row);
int is_range (char **argv, int row, int len);

int main (int argc, char **argv) {
    if (argc != 6) {
        mx_printstr("usage: ./race04 [file_name] [x1] [y1] [x2] [y2]");
        exit(1);
    }

    if (!is_exist(argv[1]))
        exit(1);
    char *temp = mx_file_to_str(argv[1]); 
    int row = row_count(temp);
    int coma = coma_count(temp);
    int len = 1 + row_len(temp) - coma;
    int error_flag = 0;

    char *str_maze = delete_coma(temp, row, len);

    char arr[row][len]; //Валидный масив
    int k = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < len; j++) {
            if (str_maze[k] != '#' && str_maze[k] != '.' && str_maze[k] != '\n') {
                error_flag = 1;
            }
            else {
                arr[i][j] = str_maze[k];
                if (j == len - 1) { 
                    arr[i][j] = '\0';
                } 
                k++;
            }
        }
    }

    if (error_flag || is_map(temp, row)) {
        mx_printstr("map error");   
        exit(1);
    }

    len--;
    if (is_range(argv, row, len)) {
        mx_printstr("points are out of map range");
        exit(1);
    }

    if (arr[mx_atoi(argv[3])][mx_atoi(argv[2])] == '#') {
        mx_printstr("entry point cannot be an obstacle");
        exit(1);
    }
    if (arr[mx_atoi(argv[5])][mx_atoi(argv[4])] == '#') {
        mx_printstr("entry point cannot be an obstacle");
        exit(1);
    }

    //Цикл выводит валидный масив строк
//    for (int i = 0; i < row; i++) { 
  //      printf("%s", arr[i]);       
  //      if (i != row)
  //          printf("\n");
   
//}
//----------------------------------------------//
    //mx_printstr("4 ");
    k = 69;
    int start_i = mx_atoi(argv[3]);
    int start_j = mx_atoi(argv[2]);
    arr[start_i][start_j] = k;
     for(int count = 0; count < len * 4; count++) {
     for(int i = 0; i <  row + 1 ; i++) {
         for(int j = 0; j < len -1 ; j++) {
             if (arr[i][j] == k) {
                if(arr[i + 1] [j] != 35 && arr[i + 1] [j] == 46){ //vniz
              arr[i+1][j] = k +1;
                 }
                 if(arr[i - 1] [j] != 35 && arr[i - 1] [j] == 46){ //vverx
                arr[i - 1][j] = k +1;
                   }
 		 if(arr[i] [j + 1] != 35 && arr[i] [j + 1] == 46){  //vpravo
                  arr[i][j + 1] = k +1;
                   }
		if(arr[i] [j - 1] != 35 && arr[i] [j - 1] == 46){  //vlevo
                    arr[i][j - 1] = k +1;
                     }

         }
         }
}
k++;
}
int count_max = 0;


 char max = 0;
        for(int i = 0; i < row + 1; i++) { // D
            for(int j = 0; j < len - 1; j++) {
               if(arr[i][j] > max) {
                max = arr[i][j];
               }
            }
        }
           for(int i = 0; i < row + 1; i++) { // D > 1
               for(int j = 0; j < len -1; j++) {
                   if(arr[i][j] == max) {
                   arr[i][j] = 'D';
                   }
               }
           }
 for(int i = 0; i < max - 69; i++){
       count_max++;
       }

       int finish_i = mx_atoi(argv[5]);
       int finish_j = mx_atoi(argv[4]);
      int count = 0;
      for(int g = 0; g < len *5; g++) {   //dlina massiva x2
      for(int i = 0; i < row + 1; i++) {
            for(int j = 0; j < len - 1; j++) {
                if(arr[finish_i][finish_j] -1 == arr[finish_i -1][finish_j] ) { //vverx
                    arr[finish_i][finish_j] = '*';
                    finish_i -=1;
                    count++;
                }
           if(arr[finish_i][finish_j] -1 == arr[finish_i + 1][finish_j]) { //vniz               
                     arr[finish_i][finish_j] = '*';
                      finish_i +=1;
                      count++;
                  }
          if(arr[finish_i][finish_j] -1 == arr[finish_i][finish_j + 1]) { //vpravo

                     arr[finish_i][finish_j] = '*';
                        finish_j += 1;
                        count++;
                    }
           if(arr[finish_i][finish_j] -1 == arr[finish_i][finish_j - 1]) { //nalevo
                     arr[finish_i][finish_j] = '*';
                          finish_j -= 1;
                          count++;
                      }
            }
      }
      }
       finish_i = mx_atoi(argv[4]);
        finish_j = mx_atoi(argv[5]);
for(int i = 0; i < len - 1; i++) {
           for(int j = 0; j < row + 1;  j++) {
            if(arr[i][j] == arr[finish_i][finish_j] && arr[i][j] == 68 ) {
            arr[i][j] = 88;
            }

           if (arr[i][j] > 48 && arr[i][j] != 68 ) {
           arr[i][j] = '.';
           }
           }
       }
 arr[start_i][start_j] = 42; //tochka vxoda

mx_printstr("dist =");
mx_printint(count_max);
mx_printchar('\n');
mx_printstr("exit =");
mx_printint(count);
}

 //////// написать вывод в файл            перебор массива  for(int i = 0; i <  len - 1 ; i++) {
 //                                         (int j = 0; j < row + 1; j++)
//---------------------------Optional Func-----------------------------//

int is_range (char **argv, int row, int len) {
    if (mx_atoi(argv[2]) > len - 1 || mx_atoi(argv[4]) > len - 1)
        return 1;
    if (mx_atoi(argv[3]) > row - 1 || mx_atoi(argv[5]) > row - 1)
        return 1;
    return 0;
}

int is_map(char *str, int row) {
    int check_len = row_len(str);
    for (int i = 0; i < row * check_len;) {
        int tmp_len = 0;
        while(str[i] != '\n') {
            tmp_len++;
            i++;
        }
        if (tmp_len != check_len) {
            return 1;
        }
        i++;
    }
    return 0;
}

char *delete_coma(char *str, int row, int len) {
    char *result = mx_strnew(row * len);
    int index = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ',') {
            result[index] = str[i];
            index++;
        }
    }
    return result;
}

int coma_count(char *str) {
    int coma = 0;
    for (int i = 0; str[i] && str[i] != '\n'; i++) {
        if (str[i] == ',')
            coma++;
    }
    return coma;
}

int is_exist(char *str) {
    int fd = open(str, O_RDONLY);
    int len = -1;
    char buf[1];
    if(fd < 0) {
        mx_printstr("map does not exist");
        return 0;
    }
    while (read(fd, buf, 1)) {
        len++;
    }
    if (len <= 0) {
        mx_printstr("map does not exist");
        return 0;
    }
    close(fd);
    return 1;
}
//mx_printstr("11 ");
int row_len (char *str) {
    int len = 0;
    int i = 0;
    while (str[i] != '\n') {
        len++;
        i++;
    }
    return len;
}

int row_count(char *str) {
    int row = 0;
    int i = 0;
    while (str[i]) {
        if (str[i] == '\n')
            row++;
        i++;
    }
    return row;
}

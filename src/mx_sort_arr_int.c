void mx_sort_arr_int(int *arr, int size) {
    int tmp;
    int i = 0;
    int flag = 0;

    while (i < size) {
        if (i + 1 != size && arr[i] > arr[i + 1]) {
            tmp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = tmp;
            flag = 1;
        }
        i++;
        if (i == size && flag == 1) {
            flag = 0;
            i = 0;
        }
    }
}

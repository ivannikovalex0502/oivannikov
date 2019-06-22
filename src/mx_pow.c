double mx_pow(double n, unsigned int pow) {
    if(pow == 0){
        return 1;
    }

    double product = n;

    while(pow > 1) {
        product = product * n;
        pow--;
    }
    return product;
}

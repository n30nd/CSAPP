#include "stdio.h"

int devide1(int x, unsigned k) {
    return (x<0 ? x+(1<<k)-1 : x) >> k;
}


int devide2(int x, unsigned k) {
    int bias = (x>>31) & 0x3;
    return (x+bias)>>k;
}

int devide3(int x, unsigned k) {
    int sign_flag = (x>>31)&&0x1;
    return sign_flag ? (x>>31)&(~((~x+1)>>k)+1) : x >> k;
    // return ((x>>31)&(~((~x+1)>>k)+1)) | (x >> k);
    // // return (x>>31)&((~((~x+1)>>k)+1));
}

int main() {
    int x = -9;
    int y = 9;
    printf("x/4\n");
    printf("%d\n", x/4);
    printf("%d\n", devide1(x, 2));
    printf("%d\n", devide2(x, 2));
    printf("%d\n", devide3(x, 2));


    printf("y/4\n");
    printf("%d\n", y/4);
    printf("%d\n", devide1(y, 2));
    printf("%d\n", devide2(y, 2));
    printf("%d\n", devide3(y, 2));


    return 0;
}
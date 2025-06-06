#include <stdio.h>

// Intution: b = a^b^a, a = a^b^a
void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int a[], int cnt) {
    int first, last;
    for (first=0, last=cnt-1; first < last; first++, last--)
        inplace_swap(&a[first], &a[last]);
}

void print_array(int a[], int cnt) {
    for(int i=0;i<cnt;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main() {
    // int x = 1;
    // int y=2;
    // printf("x: %d, y: %d\n", x, y);
    // inplace_swap(&x, &y);
    // printf("x: %d, y: %d\n", x, y);

    int a[] = {1,2,3,4,5};
    reverse_array(a, 5);

    print_array(a, 5);
    return 0;
}
#include <stdio.h>

int sqroot(int x) {
    if (x == 0 || x == 1) {
        return x;                               // return 0 or 1 if x is equal to 0 or 1
    }

    if (x < 0) {
        return -1;                              // terminate the func if x is a negative num
    }

    int sqrt_x = 0;

    while (sqrt_x * sqrt_x < x) {               // multiply sqrt_x until it is bigger than x
        sqrt_x++;                               // plus 1 to sqrt_x after multiplied value is smaller than x
    }

    return sqrt_x;
}

int main() {
    int x = 36;                                 // using 36, as a perfect sqrtroot

    int squareRoot = sqroot(x);

    printf("Square root of %d is %d\n", x, squareRoot);

    return 0;
}

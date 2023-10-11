#include <stdio.h>

void main() {
    for (int i=1; i<=100; i++) {            // using the for loop so it stops at 100 
        if (i%3==0 && i%5==0) {             // using modulus to get the perfect divisible number
            printf("FizzBuzz");
        } else if (i%3==0) {
            printf("Fizz");
        } else if (i%5==0) {
            printf("Buzz");
        } else {
            printf("%d", i);
        }

        if (i!=100) {
            printf(", ");       // print comma when it's not 100
        } else {
            printf("\n");       // go to the next line when it reaches 100
        }
    }
}

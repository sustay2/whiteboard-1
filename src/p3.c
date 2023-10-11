#include <stdio.h>

void fibbonacci(int num) {
    int term1 = 0, term2 = 1;
    int nextTerm = term1 + term2;

    printf("%d, %d, ", term1, term2);      // print the first 2 terms

    for (int i=2; i<num; i++) {         // start at 3rd and stop at nth terms
        printf("%d", nextTerm);
        term1 = term2;
        term2 = nextTerm;
        nextTerm = term1 + term2;

        if (i!=num-1) {
            printf(", ");               // print comma when it's not the last term
        } else {
            printf("\n");               // go to the next line when it's the last term
        }
    }
}

void main() {
    int num = 0;

    // prompt user to enter num of fibbonacci seqeunce elements
    printf("Enter the number of Fibbonacci sequence elements to generate: ");
    scanf("%d", &num);

    // handle stack overflow exception (exclude negative num)
    if (num < 0) {
        printf("Error: Please enter a positive number!\n");
    } else {
        fibbonacci(num);
    }
}

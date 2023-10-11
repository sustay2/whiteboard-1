// it is coded in C as it is the simplest language to perform basic tasks
#include <stdio.h>

void main() {
    int array[11] = {21, 400, 8, -3, 77, 99, -16, 55, 111, -36, 28}; // create an array of numbers
    int temp = 0; // a temp var to store temp value while sorting

    for (int i=0; i<11; i++) {
        for (int j=i+1; j<11; j++) {
            if (array[i] > array[j]) {      // do the sorting only if the array[i] is bigger than array[j]
                temp = array[i];
                array[i] = array[j];         
                array[j] = temp;
            }
        }
    }

    // print expected output
    for (int i=0; i<11; i++) {
        if (i == 10) {
            printf("%d\n", array[i]);       // to exclude the comma and go to the next line at the last num
            break;       
        }
        printf("%d, ", array[i]);
    }
}

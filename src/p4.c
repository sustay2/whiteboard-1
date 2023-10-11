#include <stdio.h>

void main() {
    int list1[6] = {4, 5, 2, 3, 1, 6};
    int list2[6] = {8, 7, 6, 9, 4, 5};
    int comma = 0;

    // intersection
    for (int i=0; i<6; i++) {
        for (int j=0; j<6; j++) {
            if (list1[i] == list2[j]) {     // print the num from list1 when it is the same as list2
                if (comma > 0) {
                    printf(", ");           // purpose: to stop printing comma at the last num
                }

                printf("%d", list1[i]);
                comma = 1;
                break;                      // stop the inner loop
            }
        }
    }

    printf("\n");
}

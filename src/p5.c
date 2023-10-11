#include <stdio.h>
#include <stdbool.h>

void sortList(int arrayList[]) {
    int temp = 0;

    for (int i=0; i<6; i++) {
        for (int j=i+1; j<6; j++) {
            if (arrayList[i] > arrayList[j]) {      // do the sorting only if the arrayList[i] is bigger than arrayList[j]
                temp = arrayList[i];
                arrayList[i] = arrayList[j];         
                arrayList[j] = temp;
            }
        }
    }
}

void main() {
    int list1[6] = {4, 5, 2, 3, 1, 6};
    int list2[6] = {8, 7, 6, 9, 4, 5};
    int comma = 0;
    bool symDiff;

    // pass the lists to sort
    sortList(list1);
    sortList(list2);

    // symmetric difference for list1
    for (int i=0; i<6; i++) {
        symDiff = true;                     // used to indicate whether the value in list1 exists in list2

        for (int j=0; j<6; j++) {
            if (list1[i] == list2[j]) {
                symDiff = false;
                break;
            }
        }

        if (symDiff) {
            if (comma > 0) {
                printf(", ");           // purpose: to stop printing comma at the last num
            }

            printf("%d", list1[i]);
            comma = 1;
        }
    }

    // symmetric difference in list2
    for (int i=0; i<6; i++) {
        symDiff = true;                     // used to indicate whether the value in list2 exists in list1

        for (int j=0; j<6; j++) {
            if (list2[i] == list1[j]) {
                symDiff = false;
                break;
            } 
        }

        if (symDiff) {
            if (comma > 0) {
                printf(", ");           // purpose: to stop printing comma at the last num
            }

            printf("%d", list2[i]);
            comma = 1;
        }
    }

    printf("\n");
}

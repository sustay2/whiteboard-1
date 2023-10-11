#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void main() {
    char strInput1[50];
    char strInput2[50];
    int ascII_one[256] = {0};
    int ascII_two[256] = {0};
    bool anagram = true;

    printf("Enter first string : ");
    fgets(strInput1, sizeof(strInput1), stdin);                 // prompt for the first string

    printf("Enter second string: ");
    fgets(strInput2, sizeof(strInput2), stdin);                 // prompt for the second string

    // check whether they have the same length or not
    if (strlen(strInput1) == strlen(strInput2)) {
        // count the chars in the strings
        for (int i=0; i<strlen(strInput1); i++) {
            char currentChar1 = strInput1[i];
            char currentChar2 = strInput2[i];

            if (isalpha(currentChar1)) {                        // check if the char from first string is an alphabet or not
                currentChar1 = tolower(currentChar1);

                ascII_one[currentChar1]++;
            }

            if (isalpha(currentChar2)) {                        // check if the char from second string is an alphabet or not
                currentChar2 = tolower(currentChar2);

                ascII_two[currentChar2]++;
            }
        }

        // check whether the chars from two strings have the same num or not
        for (int i=0; i<256; i++) {
            if (ascII_one[i] != ascII_two[i]) {
                anagram = false;
                break;
            }
        }
    } else {
        anagram = false;
    }

    if (anagram) {
        printf("True\n");
    } else {
        printf("False\n");
    }
}

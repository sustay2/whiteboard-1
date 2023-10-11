#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char character;
    int maxCount;
} charCount;

void main() {
    charCount charCounter = {'\0', 0};      // initialize with null values
    char strInput[50];                      // user input
    int ascII[256] = {0};                   // using ascII for the supported characters

    printf("Enter a string: ");
    fgets(strInput, sizeof(strInput), stdin);

    for (int i=0; i<strlen(strInput); i++) {
        char currentChar = strInput[i];

        if (isalpha(currentChar)) {                             // check if the current char is an alphabet or not
            ascII[currentChar]++;                               // exp: 'A' is 65, so it adds up on ascII[65] if the current char is 'A'

            if (ascII[currentChar] > charCounter.maxCount) {    // check if the count of current char is larger than previous one
                charCounter.character = currentChar;
                charCounter.maxCount = ascII[currentChar];
            }
        }
    }

    printf("Character: \'%c\', Occurence: %d\n", charCounter.character, charCounter.maxCount);
}

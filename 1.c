#include <stdint.h>

#include <stdio.h>

#include <limits.h>

#include <stdlib.h>

#pragma warning(disable: 4996)

#define TRUE 1
#define FALSE 0
#define ERROR - 1

int main() {
    char buffer;
    int value = 0;
    int count = 0;
    int sign = FALSE;
    while (((buffer = getchar()) != EOF) && buffer != '\n' && buffer != '\0') {
        if ((buffer == '-') && (sign == FALSE)) {
            sign = TRUE;
        }
        else {

            if ((buffer == '1') || (buffer == '0')) {
                value <<= 1;
                value += buffer - '0';
                count++;
            }
            else {
                printf("Error .\n");
                exit(ERROR);
            }
        }
    }
    if (count > sizeof(int) * CHAR_BIT) {
        printf("Error oversize.\n");
        exit(ERROR);
    }

    if (sign == TRUE)
        value = value * (-1);
    printf("%i", value);
    return 0;
}
#include <stdio.h>
#include <string.h>

void cs392_reversestr(char* str) {
    char* ptr = str;
    while (*ptr != '\0') {
        ptr++;
    }
    --ptr;  // move the pointer back to the last character of the string

    while (str != ptr) {
        *str = *ptr ^ *str;
        *ptr = *ptr ^ *str;
        *str = *ptr ^ *str;
        str++;
        ptr--;
    }
}

int main(int argc, char** argv) {
    int index;
    char src[128];
    char dst[128];

    printf("CS_392 midterm task 1: \n");

    index = 1;

    while (index <= 5) {
        printf("	Test case %d:\n", index);

        memset(src, 0, 128);
        memset(dst, 0, 128);

        strcpy(src, argv[index]);
        strcpy(dst, argv[index + 5]);

        cs392_reversestr(src);

        printf("	Original string: \"%s\"; Reversed string: \"%s\"; \n", argv[index], src);

        if (strcmp(src, dst) == 0)
            printf("	=== Result: PASSED === \n\n");
        else
            printf("	=== Result: FAILED === \n\n");

        index += 1;
    }

    return 0;
}

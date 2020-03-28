#include <stdio.h>
#include <string.h>

int cs392_substr_count(char* str, char* substr) {
    int str_size = sizeof(substr), sub_size = sizeof(substr), i, j;
}

int main(int argc, char** argv) {
    int index;
    int cnt;

    printf("CS_392 midterm task 2: \n");

    printf("	Test case 1 string \"%s\" and substring \"%s\"\n", "aaaa", "a");

    cnt = cs392_substr_count("aaaa", "a");

    printf("	Correct result 4 and your result %d\n", cnt);

    if (cnt == 4)
        printf("	=== Result: PASSED === \n\n");
    else
        printf("	=== Result: FAILED === \n\n");

    printf("	Test case 2 string \"%s\" and substring \"%s\"\n", "aaaa", "");

    cnt = cs392_substr_count("aaaa", "");

    printf("	Correct result 0 and your result %d\n", cnt);

    if (cnt == 0)
        printf("	=== Result: PASSED === \n\n");
    else
        printf("	=== Result: FAILED === \n\n");

    printf("	Test case 3 string \"%s\" and substring \"%s\"\n", "abc@def@ab@c@abc", "abc");

    cnt = cs392_substr_count("abc@def@ab@c@abc", "abc");

    printf("	Correct result 2 and your result %d\n", cnt);

    if (cnt == 2)
        printf("	=== Result: PASSED === \n\n");
    else
        printf("	=== Result: FAILED === \n\n");

    return 0;
}

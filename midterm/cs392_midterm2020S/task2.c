#include <stdio.h>
#include <string.h>

int stringcomp(const char *str1, const char *str2) {
    for (int i = 0;; i++) {
        if (str1[i] != str2[i]) {  // different character found
            return str1[i] < str2[i] ? -1 : 1;
        }

        if (str1[i] == '\0') {  // both strings are of equal length
            return 0;
        }
    }
}

void swap(char **arr, int i, int j) {
    char *temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void percolate_down(char **arr, int i, int end) {
    int parent = i,
        left = (2 * parent) + 1,
        right = (2 * parent) + 2;

    while (right <= end) {
        int maxChild = left;
        if (right < end && stringcomp(arr[right], arr[left]) > 0) {
            maxChild = right;
        }

        if (stringcomp(arr[parent], arr[maxChild]) > 0) {
            break;
        }

        swap(arr, parent, maxChild);
        parent = maxChild;
        left = (2 * parent) + 1;
        right = (2 * parent) + 2;
    }
}

void cs392_str_sort(char **strlist, int number) {
    // create a max max heap O(n)
    for (int i = (number / 2) - 1; i >= 0; i--) {
        percolate_down(strlist, i, number);
    }

    // sort by removing elements from the 'top' of the heap O(n log n)
    for (int end = number - 1; end > 0; end--) {
        swap(strlist, 0, end);
        percolate_down(strlist, 0, end);
    }
}

int main(int argc, char **argv) {
    printf("CS_392 midterm task 2: \n");

    printf("        Test case 1:\n");

    char *strlist[5] = {"String1", "STring1", "String1extended", "String", "StRING1"};

    cs392_str_sort(strlist, 5);

    printf("	Correct results are: STring1, StRING1, String, String1, String1extended\n");
    printf("	Your results are: %s, %s, %s, %s, %s\n", strlist[0], strlist[1], strlist[2], strlist[3], strlist[4]);

    if (strcmp(strlist[0], "STring1") == 0 && strcmp(strlist[1], "StRING1") == 0 && strcmp(strlist[2], "String") == 0 && strcmp(strlist[3], "String1") == 0 && strcmp(strlist[4], "String1extended") == 0)
        printf("	=== Result: PASSED === \n\n");
    else
        printf("	=== Result: FAILED === \n\n");

    char *strlist1[5] = {"string2", "s@ing2", "stringA", "sTRING2", "@tring2"};

    cs392_str_sort(strlist1, 5);

    printf("	Correct results are: @tring2, s@ing2, sTRING2, string2, stringA\n");
    printf("	Your results are: %s, %s, %s, %s, %s\n", strlist1[0], strlist1[1], strlist1[2], strlist1[3], strlist1[4]);

    if (strcmp(strlist1[0], "@tring2") == 0 && strcmp(strlist1[1], "s@ing2") == 0 && strcmp(strlist1[2], "sTRING2") == 0 && strcmp(strlist1[3], "string2") == 0 && strcmp(strlist1[4], "stringA") == 0)
        printf("	=== Result: PASSED === \n\n");
    else
        printf("	=== Result: FAILED === \n\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy_string(char **dest, const char *src) {
    *dest = (char *)malloc((strlen(src) + 1) * sizeof(char));
    if (*dest == NULL) {
        return;
    }
    strcpy(*dest, src);
}

int main() {
    char *str1 = NULL;
    char *str2 = NULL;

    copy_string(&str1, "Hello, World!");
    copy_string(&str2, "Goodbye, World!");

    if (strlen(str1) > 5) {
        free(str2);
        str2 = (char *)malloc(10 * sizeof(char));
        if (str2 == NULL) {
            free(str1);
            str1 = NULL;
            return 1; // Potential leak of str1
        }
        strncpy(str2, "New Data", 9);
        str2[9] = '\0';
    }

    if (str2 != NULL && strlen(str2) < 5) {
        free(str2);
        str2 = NULL;
    }

    free(str1);
    str1 = NULL;
    free(str2);
    str2 = NULL;

    return 0; // Potential leak of str1 or str2
}

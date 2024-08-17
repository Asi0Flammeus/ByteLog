#include <stdio.h>
#include <stdlib.h>

void process_data(int count) {
    for (int i = 0; i < count; i++) {
        char *buffer = (char *)malloc(256 * sizeof(char));

        // Simulate some processing
        for (int j = 0; j < 256; j++) {
            buffer[j] = 'A' + (j % 26);
        }

        printf("Processing iteration %d complete.\n", i + 1);
        free(buffer);
        buffer = NULL;
    }
}

int main() {
    process_data(5);
    return 0;
}

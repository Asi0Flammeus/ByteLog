#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numbers = (int *)malloc(10 * sizeof(int));
    
    for (int i = 0; i < 10; i++) {
        numbers[i] = i * i;
    }
    
    // Some other operations here...

    free(numbers);
    numbers = NULL;
    
    return 0; // Memory leak occurs here
}

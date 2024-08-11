#include <stdio.h>

// something is wrong here :(
void swap( int *a, int *b) {
    int temp = *a;
    *a = *b;
    printf("%d %d\n", temp, *a);
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    printf("%d %d\n", x, y);
    swap(&x, &y);
    printf("%d %d\n", x, y);
    return 0;
}

#include "./algorithms.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *arr = (int *)malloc(5 * sizeof(int));
  arr[0] = 10;
  arr[1] = 5;
  arr[2] = 7;
  arr[3] = 7;
  arr[4] = 8;

  int size = 5;
  printf("%d\n", size);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  int mid = get_pivot(arr, 0, 4);

  printf("\n%d\n", arr[mid]);

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}

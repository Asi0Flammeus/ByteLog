#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int get_pivot(int *arr, int low, int high) {
  /**
   * Get the pivot of an array
   * based on the median of three method
   */

  int mid = (low + high) / 2;

  if (arr[low] < arr[mid]) {
    swap(&arr[low], &arr[mid]);
  }
  if (arr[low] < arr[high]) {
    swap(&arr[low], &arr[high]);
  }
  if (arr[mid] < arr[high]) {
    swap(&arr[mid], &arr[high]);
  }
  return mid;
}

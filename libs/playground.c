#include <stdio.h>
#include "./algorithms.c"

int main(){
  int c = 10; 
  int d = 20;
  int *a = &c;
  int *b = &d;
  swap(a, b);
  printf("%d\n", *a);
  printf("%d\n", *b);

  return 0;
}

#include <stdio.h>

#define MAX_TEMPERATURE 10
int main(int argc, char **argv) {

  int temperatures[MAX_TEMPERATURE];
  temperatures[3] = 2;

  printf("%d\n", temperatures[3]);

  return 0;

}

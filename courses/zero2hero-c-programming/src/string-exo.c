#include <stdio.h>

int main(int argc, char **argv) {

    char *str = "hehe";
    char otherstr[] = {'h', 'e', 'h', 'e', 0};
    if (!strcmp(str, otherstr)) {
        printf("Yay!\n");
  } else {
        
        printf("Nay!\n");
  }
  return 0;
}

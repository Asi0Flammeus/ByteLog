#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_EMPLOYEES = 1000 

struct employee_t {
    int id;
    int income;
    bool staff;
};

void initialize_employee(struct employee_t *e) {
    e->id = 0;
    e->income = 1000;
    e->staff = false;

    return;
}
int main() {
   
  int x = 3;
  int *pX = &x; 
  // pX is a pointer to the address of x

  // print the value behind the address of x
  printf("%d\n", *pX);
  // print the value of the address of x
  printf("%p\n", pX);

  struct employee_t Ralph; 

  initialize_employee(&Ralph);

  printf("%d\n", Ralph.income);

  int n = 4; 

  struct employee_t *employees = malloc(sizeof(struct employee_t)*n);
  // use this to verify proper memory allocation 
  if (employees == NULL) {
      printf("The allocator failed \n");
      return -1;
  }
  initialize_employee(&employees[0]);

  printf("%d\n", employees[0].income);
  
  // FREE THE POINTERS 
  free(employees);
  employees = NULL;

}


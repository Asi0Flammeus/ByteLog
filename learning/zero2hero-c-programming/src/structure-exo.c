#include <stdio.h>

// create a structure named 'struct Employee'
// it should have a name, and an age

struct employee_t {
    char name[64];
    int age;
};

int main(int argc, char **argv) {

    // Initialize an employee, name him "Steve"
    // Steve is 42
    struct employee_t employee = {"Steve", 42};

    // print his name and age
    printf("%s, aged %d years\n", employee.name, employee.age);

    return 0;

}



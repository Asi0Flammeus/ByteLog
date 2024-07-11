#include <stdio.h>

#define MAX_PERSONS = 1024

// #define DEBUG

// Global scope variable 
int g_NumPersons = 0;
void some_other_function()
{
    int personID = 1;
}
int main()
{
    // syntax: type name = initial value
    int personID = 0;
    int person2ID = personID + 1;
    char personName[] = "asi0";
    float pi = 3.14159265359;
    
    #ifdef DEBUG
    printf("WE ARE IN DEBUG MODE: %s:%d", __FILE__, __LINE__);
    #endif

    
    
    // local scope variable = within function
    personID += 1;

    return 0;
}

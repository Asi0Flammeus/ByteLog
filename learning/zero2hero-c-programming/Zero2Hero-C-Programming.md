# Zero2Hero C Programming

## Introduction

- recommands 1 or 2 sections / week
- objective:
  - learn the basis of C
  - practice C via a project
    - project is a basic employee database
- installed `gcc` C compiler

## Why learn C?

- initially thought as a [[high level language]], though now it is perceived as [[low level language]]
- its name comes from the fact that is was the 3rd language created at T&T Bell inc
- with C one can do what the fuck they want, but one will have the responsibility to secure their code to avoid heap overflow, correct memory allocation and other delightful traits that has to be cared because in C land there's nothing that will prevent from doing a mistake.
- characterisation of a language
  - compiled language or interpreted language
    - C is compiled
  - Strong or weakly typed
    - C is weakly typed
  - Pocess a garbage collector or not (the fuck is a garbage collector?)
    - C does not have a GC
  - is memory safe?
    - C is ABSOLUTELY NOT memory safe

## C Fundamentals

### Variables

- cf. `variables.c`
  - notice that in first line there's `#include <stdio.>`
    - used to import a header file that is Standard Input Output
    - contains definition of basic functions
  - notice that all declaration line ends with `;`
  - notice that we have `int main()`
    - it's a standard in C to use the output type int for main() function
      - and return 0
    - `void` type for function is used when nothing is returned
- variable = memory allocation
  - syntax: type name = initial value

### Variable Scope Rules

- define who has access to variable
- local scope = withing a specific scope
  - local scopes are delimited by `{}`
  - local scopes can be nested in a function
  - different scopes can share variable with same name
    - update is always done inside the current local scope
    - variables declared in higher level are accessibles to lower scopes
- global scope = can be accessed anywhere
  - notice the used of prefix `g_` to the name of the variable to tag its global scope
  - can be difficult to monitor value if used in multiple functions and can lead to logic error

### C Preprocessors

- preprocessors is things that starts with `#`
- preprocessor -> compilation -> assembling -> linking = compilation process
- `#include` copy paste some header file to access functions
- `#define` to set a static constant that would be accessed in compile time

  - act as compile variable
  - compile time is phase often used for static allocation, syntax error checking, optimization, code generation
  - run time is phase for dynamic allocation, code execution, error handling, interaction with environment
  - eg. is `#define DEBUG` and then use `#ifdef DEBUG` to execute code only if the debug is initially defined
    - see example in `variables.c`
    - can define DEBUG directly in compiler command
      - `gcc -o variables variables.c -DDEBUG`

## Arrays & Strings

- an array is a block of memory allocated to a set of variables that share the same type like `int`
- it's a good practice to "pound" a max of the number of elements for an array via the `#define` compiler variable
  - eg. `#define MAX_IDS 32`
- no need to declare the value of the element when declaring the array.
- a string is simply an array
- using `""` let the compiler to add a "0-delimiter", whereas with `''` will not be null-terminated
  - eg. `char otherstr[] = {'h', 'e', 'h', 'e', 0};`
  - not null-terminated arrays is a risk of leaking data of the code that wasn't supposed to be shared.

## Control Flow Structure

### Conditional statements

- conditional helps to apply some logic to script
  - there are at the core of proggramming
- the syntax of if is simply `if (condition) {do thing} else if (condition 2) {other thing to do} else {3rd thing}`
- for `for` loops, the best practice is to initialise the iterator twice (cf. `conditional-loops.c`)
- there are 3 loops
  - for: apply logic for a given iterator
  - while: check condition and apply logic, over again while condition true
  - do while: do one logic and then check conditional and do it again while condition true

### Function syntax

- `return_type name(list of arguments){}`
  - the return_type is the type of the returned variable
  - in general, the `main` function has an int as a return and most of the time we `return 0;`
- most of the time, functions are used to avoid repeting ourself, and for better code it's preferable that a function achieves a single thing

## Structs & Unions

### Structures

- A structure is a way to create an object of a new type with multiple data type
- must be define in compile time (see `structure.c`)
- it's a good practice to append a suffix `_t` to the name of the struc to note that it is a new type
  - why? bc like this the variable would not have the same variable name as the type itself
- the struct modifier `packed` is used to make sure the memory allocation for that struct is the same through different OS environment
  - sometime it can reduce the use of memory
- simple structures can be directly initialize with `struct mystruct_t something = {var1, var2, ...}`

### Union

- union is like a structure but it will create just enough room in memory for the largest element
- useful in memory constraint environment

## Pointers & Memory Allocation

### Pointers

- when declaring a variable it define an address where the value is saved
- a pointer is simply a reference to that address
  - by convention we add the prefix `p` to any variable that is a pointer
- we use the term 'deference' to mean that we take the value behind the address
  - `pX` is the address behind X
  - `*pX`is the value behind the address of `pX`, so the value `X`
- to set the address of `X` to a pointer simply use `&`
  - `int \*pX = &X
- the reason why it is handy to use pointers rather the variable (or struct) itself is
  - to use variable that live in outside local scope
    - for eg. like we define a struct and then initialize it with a function
  -

## Introduction to glibc

## File Input & Output

## Data Types

## Advanced C Programming

## Course Project

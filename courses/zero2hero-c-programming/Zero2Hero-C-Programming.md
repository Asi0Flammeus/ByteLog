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

## Structs & Unions

## Pointer& Memory Allocatio

## Introduction to glibc

## File Input & Output

## Data Types

## Advanced C Programming

## Course Project

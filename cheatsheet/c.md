# standard header librairies

tips: if you forget what lib is associated to a function, use in the terminal `man funcion_name`

## Basics functions

```c
#include <stdio.h>
```

## bool variable

```c
#include <stdbool.h>
```

## dynamic memory allocation

```c
#include <stdbool.h>
```

# Data types

## short

- `size_t` is an allias for unsigned interger
- is a subset of `int` type
- `signed` by default
  - range from -32768 to 32728
- unsigned ranged from 0 65535
  - size of a short is 2 bytes (2^16 = 65536)
- useful in situation with high memory constraints

# printf data representation

- `%f`, float
- `%d`, int in decimal
- `%hx`, short int in hexadecimal
- `%hhx`, unsigned char in hexadecimal

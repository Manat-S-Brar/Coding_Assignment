
# BigInt

BigInt library provides basic mathematical operations for arbitrarily large numbers.

## Description

In `C`,

- Range of `int(4 bytes)` is `-2,147,483,648` to `2,147,483, 647` 
- Range of `long(8 bytes)` is `-9,223,372,036,854,775,808` to `9,223,372,036,854,775,807`

But what if we want to store even a bigger integer? 

To solve this problem, I have tried to implement the **BigInt** library which can be used to do basic mathematical operations(addition, subtraction, multiplication, division etc.) on arbitrarily large numbers. This library can also handle negative integers.

Some of the applications of **BigInt** :

- To check whether a 50 digit number is prime or not?
- Used in cryptography techniques.
- To Calculate the factorial of 50 or 100.

## Specifications

- BigInt.h has declarations of `struct big_int ` and all other mathematical operations.
- BigInt.c has definitions of all the functions

## BigInt Structure

`big_int` structure has

- `int num_of_digits`: To store the count of digits in the given number
- `int is_nagative`: To check whether the given number is negative or positive
- `int size`: Actual Size of char array
- `char *num`: To store the number 

```c
    typedef struct big_int
    {
        char *num; // Array for storing the number(stored in reverse order)
        unsigned int size; // Size of num array;
        unsigned int num_of_digits; // Number of digits in the number
        unsigned int is_negative; // 1 if the number is negative and 0 if the number is positive

    } big_int;

```

## Setup

1. Create a new C file in desired directory.
```shell
    touch test.c
```
2. Import `BigInt.h` into your C file.

```c

    #include "BigInt.h" 

```
3. Compile the program with GCC
```shell
    gcc BigInt.c test.c
```
4. Run the executible
```shell
    ./a.out
```
## Usage

1. Declaration

```c

    big_int *big_number = big_int_constructor(char *value);

```

2. Using any function

```c
    
    //Adds the value of big_number1 to big_number and places it in big_number
    big_int_add(big_int *big_number, const big_int *big_number1);    

```

## Functions

### Contructor and Assignment functions

|  Function Name                       | Description |
| :-----:                              | :--: |
| `big_int* big_int_constructor(char *value)`      | Returns a pointer to a new big_int initialized with specified value|
| `void big_int_free(big_int *big_num)` | Frees the dynamically allocated memory|
| `void big_int_assign(big_int *big_num1, const big_int *big_num2)` | Assigns big_num2(big_int) to big_num1(big_int) |

### Basic mathematical functions

|  Function Name                       | Description |
| :-----:                              | :--: |
| `int big_int_abs_compare(const big_int *big_num1, const big_int *big_num2)`| Returns **0** if abs(big_num1) == abs(big_num2), **1** if abs(big_num1) > abs(big_num2), **-1** if abs(big_num1) < abs(big_num2)  |
| `int big_int_compare(const big_int *big_num1, const big_int *big_num2)`| Returns **0** if big_num1 == big_num2, **1** if big_num1 > big_num2, **-1** if big_num1 < big_num2  |
| `void big_int_abs_add(big_int *big_num1, const big_int *big_num2)` | Adds the absolute value of **big_num2** to **big_num1** and places it in **big_num1** |
| `void big_int_add(big_int *big_num1, const big_int *big_num2)` | Adds the value of **big_num2** to **big_num1** and places it in **big_num1** |
| `void big_int_add_int(big_int *big_num1, const int int_value)` | Adds the value of **int_value** to **big_num1** and places it in **big_num1** |
| `void big_int_abs_subtract(big_int *big_num1, const big_int *big_num2)` | Subtracts the absolute value of **larger number** from **smaller number** and places it in **big_num1** |
| `void big_int_subtract(big_int *big_num1, const big_int *big_num2)` | Subtracts the value of **big_num2** from **big_num1** and places it in **big_num1** |
| `void big_int_subtract_int(big_int *big_num1, const int int_value)` | Subtracts the value of **int_value** from **big_num1** and places it in **big_num1** |
| `void big_int_multiply(big_int *big_num1, const big_int *big_num2)` | Multiplies the value of **big_num1** with **big_num2** and places it in **big_num1** |
| `void big_int_multiply_int(big_int *big_num1, const int int_value)` | Multiplies the value of **big_num1** by **int_value** and places it in **big_num1** |
| `void big_int_divide(big_int *big_num1, const big_int *big_num2)` | Divides the  **big_num1** by **big_num2** and places it in **big_num1** |
| `void big_int_divide_int(big_int *big_num1, const int int_value)` | Divides the  **big_num1** by **int_value** and places it in **big_num1** |
| `void big_int_modulo(big_int *big_num1, const big_int *big_num2)` | Places the remainder in **big_num1** when **big_num1** is divided by **big_num2**|
| `void big_int_modulo_int(big_int *big_num1, const int int_value)` | Places the remainder in **big_num1** when **big_num1** is divided by **int_value**|

### Miscellaneous functions

|  Function Name                       | Description |
| :-----:                              | :--: |
| `void big_int_print(const big_int* big_num)` | Prints **big_num**|
| `void big_int_allocate_digits(big_int *big_num, unsigned int required_digits)` | If big_num->size < required digits, this function increases big_num->size by dynamically allocating memory|


# BigInt

BigInt library provides basic mathematical operations for arbitrarily large numbers.

## Description

In `C`,

- Range of `int(4 bytes)` is `-2,147,483,648` to `2,147,483, 647` 
- Range of `long(8 bytes)` is `-9,223,372,036,854,775,808` to `9,223,372,036,854,775,807`

But what if we want to store even a bigger integer? 

To solve this problem, I have tried to implement the **BigInt** library which can be used to do basic mathematical operations(addition, subtraction, multiplication, division etc.) on arbitrarily large numbers (theoratically no limit). This library can also handle negative integers.

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
- `char *num`: To store the number 

```c
    typedef struct big_int 
    {
         int num_of_digits; // Number of digits in the number
         int is_negative; // 1 if the number is negative and 0 if number is positive
         char* num; // Array for storing the number
    } big_int;

```

## Usage

1. Import `BigInt.h` into your C file.

```c

    #include "BigInt.h" 

```
2. Declaration

```c

    big_int *big_number = big_int_constructor(char *value);

```

3. Using any function

```c
    
    //Adds the value of big_number1 to big_number and places it in big_number
    big_int_add(big_int *big_number, const big_int *big_number1);    

```

## Functions

### Basic mathematical operations

|  Function Name                       | Description |
| :-----:                              | :--: |
| `int big_int_compare(const big_int* a, const big_int* b)`      | Returns  **-1** if a < b,  **0** if a == b, **1** if a > b  |
| `void big_int_add(big_int *big_number, const big_int *big_number1)` | Adds the value of **big_number1** to **big_number** and places it in **big_number** |
| `void big_int_add_int(big_int *big_number, const int big_number1)` | Adds the value of **big_number1** to **big_number** and places it in **big_number** |
| `void big_int_subtract(big_int *big_number, const big_int *big_number1)` | Subtracts the value of **big_number1** from **big_number** and places it in **big_number** |
| `void big_int_subtract_int(big_int *big_number, const int big_number1)` | Subtracts the value of **big_number1** from **big_number** and places it in **big_number** |
| `void big_int_multiply(big_int *big_number, const big_int *big_number1)` | Multiplies the value of **big_number** by **big_number1** and places it in **big_number** |
| `void big_int_multiply_int(big_int *big_number, const int big_number1)` | Multiplies the value of **big_number** by **big_number1** and places it in **big_number** |
| `void big_int_divide(big_int *big_number, const big_int *big_number1)` | Divides the  **big_number** by **big_number1** and places it in **big_number** |
| `void big_int_divide_int(big_int *big_number, const int big_number1)` | Divides the  **big_number** by **big_number1** and places it in **big_number** |
| `big_int* big_int_modulo(big_int *big_number, const big_int *big_number1)` | Returns the  **big_number** % **big_number1**|
| `big_int* big_int_modulo_int(big_int *big_number, const int big_number1)` | Returns the  **big_number** % **big_number1**|
| `void big_int_print(const big_int* big_number)` | Prints the contents of **big_number** to stdout|


### Contructor and Assignment operations

|  Function Name                       | Description |
| :-----:                              | :--: |
| `big_int* big_int_constructor(char *value)`      | Returns a pointer to a new big_int initialized with specified value|
| `void big_int_free(big_int *big_number)` | Frees the dynamically allocated memory|
| `void big_int_assign(big_int *big_number, const big_int *big_number1)` | Sets the value of **big_number** to the value of **big_number1**|

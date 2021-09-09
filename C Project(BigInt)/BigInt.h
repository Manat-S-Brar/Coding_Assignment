#ifndef BIG_INT_H
#define BIG_INT_H

// Structure of big_int
typedef struct big_int
{
    char *num; // Array for storing the number(stored in reverse order)
    unsigned int size; // Size of num array;
    unsigned int num_of_digits; // Number of digits in the number
    unsigned int is_negative; // 1 if the number is negative and 0 if the number is positive

} big_int;

//----------------------------------------------------------------


// Construction and Assignment functions


// Returns a pointer to a big_int initialized with 'value'
big_int* big_int_constructor(char *value);

// Frees the memory of big_int
void big_int_free(big_int *big_num);

// Assigns big_num2(big_int) to big_num1(big_int) 
void big_int_assign(big_int *big_num1, const big_int *big_num2);

// Assigns int_value(int) to big_num1(big_int)
void big_int_assign_int(big_int *big_num1, const int int_value);

//----------------------------------------------------------------


// Mathematical functions


// Compares the absolute value of two big_int numbers
// Returns 0 if |big_num1| == |big_num2|,
// 1 if |big_num1| > |big_num2|,
// -1 if |big_num1| < |big_num2| 
int big_int_abs_compare(const big_int *big_num1, const big_int *big_num2);

// Compares the value of two big_int numbers
// Returns 0 if big_num1 == big_num2,
// 1 if big_num1 > big_num2,
// -1 if big_num1 < big_num2 
int big_int_compare(const big_int *big_num1, const big_int *big_num2);

// Adds the absolute value of big_num2 to big_num1 and places it in big_num1
void big_int_abs_add(big_int *big_num1, const big_int *big_num2);

// Adds the value of big_num2 to big_num1 and places it in big_num1
void big_int_add(big_int *big_num1, const big_int *big_num2);
void big_int_add_int(big_int *big_num1, const int int_value);

// Subtracts the absolute value of larger number from smaller number and places it in big_num1
void big_int_abs_subtract(big_int *big_num1, const big_int *big_num2);

// Subtracts the value of big_num2 from big_num1 and places it in big_num1
void big_int_subtract(big_int *big_num1, const big_int *big_num2);
void big_int_subtract_int(big_int *big_num1, const int int_value);

// Multiplies big_num1 with big_num2 and places the result in big_num1
void big_int_multiply(big_int *big_num1, const big_int *big_num2);
void big_int_multiply_int(big_int *big_num1, const int int_value);

// Divides big_num1 by big_num2 and places the result in big_num1
void big_int_divide(big_int *big_num1, const big_int *big_num2);
void big_int_divide_int(big_int *big_num1, const int int_value);

// Places the remainder in big_num1 when big_num1 is divided by big_num2
void big_int_modulo(big_int *big_num1, const big_int *big_num2);
void big_int_modulo_int(big_int *big_num1, const int int_value);

//----------------------------------------------------------------


// Miscellaneous functions


// Prints big_num
void big_int_print(const big_int *big_num);

// If big_num->size < required digits, this function increases big_num->size by dynamically allocating memory
void big_int_allocate_digits(big_int *big_num, unsigned int required_digits);


#endif

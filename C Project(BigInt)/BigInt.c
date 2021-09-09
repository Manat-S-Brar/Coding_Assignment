/*
 * BigInt library which can perform basic mathematical operations on arbitrary large numbers 
 *
 * @author: Manat Singh Brar, @Roll-number: 1910990761
 */

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BigInt.h"
#define MAX(x,y) (((x) > (y) ? (x) : (y)))

big_int* big_int_constructor(char *value)
{   
    if(strlen(value) == 0)
    {
        printf("Error: NULL argument while calling big_int_constructor");
        exit(1);
    }

    big_int *new_bi = (big_int*)malloc(sizeof(big_int));
    
    new_bi->size = strlen(value);
    new_bi->num = (char*)malloc(sizeof(char) * new_bi->size);

    if(value[0] == '-')
    {
        new_bi->is_negative = 1;
	new_bi->num_of_digits = strlen(value) - 1;
    }
    else
    {
        new_bi->is_negative = 0;
	new_bi->num_of_digits = strlen(value);
    }

    int i = strlen(value) - 1;
    int j = 0;
    
    // Storing the number in reverse order    
    while(i >= 0 && value[i] != '-')
    {
        new_bi->num[j++] = value[i--]; 
    }
   
    j = j - 1;

    // For removing leading zeroes
    // E.g if the input is "00000000011"
    // the number should be stored as "11"
    while(j > 0 && new_bi->num[j] == '0')
    {
	j--;
    }
    
    j = j + 1;

    new_bi->num_of_digits = j;

    return new_bi;
}

void big_int_free(big_int *big_num)
{
    free(big_num->num);
    free(big_num);
}

void big_int_assign(big_int *big_num1, const big_int *big_num2)
{
    // If size of big_num1 < big_num2
    // Increase size of big_num1 
    big_int_allocate_digits(big_num1,big_num2->num_of_digits);

    unsigned int i = 0;

    for( ; i < big_num2->num_of_digits ; i++)
    {
	big_num1->num[i] = big_num2->num[i];
    }    

    big_num1->num_of_digits = big_num2->num_of_digits;
    big_num1->is_negative = big_num2->is_negative;
}

void big_int_assign_int(big_int *big_num1, const int int_value)
{
    int temp = int_value;
    
    if(int_value >= 0)
    {
        big_num1->is_negative = 0;
    }
    else
    {
        big_num1->is_negative = 1;
	temp *= -1;
    }

    int count = 0;

    // Finding number of digits
    while(temp > 0)
    {
        count++;
	temp /= 10;
    }

    if(count == 0)
    {
	big_num1->num_of_digits = 1;
    }
    else
    {
	big_num1->num_of_digits = count;
    }

    big_int_allocate_digits(big_num1, big_num1->num_of_digits + 1);

    temp = int_value >= 0 ? int_value : (int_value * -1) ;

    unsigned i = 0;

    // Storing number in reverse
    for( ; i < big_num1->num_of_digits ; i++)
    {
	// Adding '0' to convert int to char
	big_num1->num[i] = (temp % 10) + '0';
	temp /= 10;
    }

}

void big_int_print(const big_int *big_num)
{
    if(big_num->is_negative)
    {
        printf("-");
    }

    int i = big_num->num_of_digits - 1;

    while(i >= 0)
    {
        printf("%c",big_num->num[i--]);
    }
}

void big_int_allocate_digits(big_int *big_num, unsigned int required_digits)
{
    if(big_num->size < required_digits)
    {
        char *temp = big_num->num;
	
	// Allocating new space
	big_num->num = (char*)malloc(sizeof(char) * required_digits);
	// Copying the digits to newly allcated space
	memcpy(big_num->num,temp,big_num->num_of_digits);
        
	big_num->size = required_digits;

	free(temp);
    }
}

void big_int_abs_add(big_int *big_num1, const big_int *big_num2)
{
    // While adding two numbers, the result can have maximum of max(num1, num2) + 1 digits
    unsigned required_digits = MAX(big_num1->num_of_digits,big_num2->num_of_digits) + 1;
    
    big_int_allocate_digits(big_num1,required_digits);

    int carry = 0;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;

    while(i < big_num1->num_of_digits && j < big_num2->num_of_digits)
    {
	// Subtracting '0' to convert char to int
        int temp_sum = (big_num1->num[i++] - '0') + (big_num2->num[j++] - '0') + carry ;

	if(temp_sum > 9)
	{
	    carry = temp_sum / 10;
	    temp_sum %= 10;
	}
	else
	{
	    carry = 0;
	}

	// Again converting int to char by adding '0'
	big_num1->num[k++] = temp_sum + '0'; 
    }

    while(i < big_num1->num_of_digits)
    {
        int temp_sum = (big_num1->num[i++] - '0') + carry ;

	if(temp_sum > 9)
	{
	    carry = temp_sum / 10;
	    temp_sum %= 10;
	}
	else
	{
	    carry = 0;
	}
	big_num1->num[k++] = temp_sum + '0'; 
    }
    
    while(j < big_num2->num_of_digits)
    {
        int temp_sum = (big_num2->num[j++] - '0') + carry ;

	if(temp_sum > 9)
	{
	    carry = temp_sum / 10;
	    temp_sum %= 10;
	}
	else
	{
	    carry = 0;
	}
	big_num1->num[k++] = temp_sum + '0'; 
    }

    if(carry != 0)
    {
	big_num1->num[k++] = carry + '0'; 
    }

    big_num1->num_of_digits = k;

    // Since we are adding absolute values, the result will always be positive
    big_num1->is_negative = 0;
}

void big_int_add(big_int *big_num1, const big_int *big_num2)
{
    // If sign of both the numbers is same
    // We will always add the two numbers
    // Result's sign will be same as that of the numbers
    if(big_num1->is_negative == big_num2->is_negative)
    {
	big_int_abs_add(big_num1, big_num2);
	big_num1->is_negative = big_num2->is_negative;
    }
    // If sign of both the numbers is not same
    // We will always subtract the two numbers
    else
    {
        // For storing the result's sign
	int result_sign = 0;
	
	// If both the numbers are equal, result will be '0'
	if(big_int_abs_compare(big_num1, big_num2) == 0)
	{ 
	    big_num1->num_of_digits = 1;
	    big_num1->is_negative = 0;
	    big_num1->num[0] = '0';
	    big_num1->num[1] = '\0';
	    return;
	}
        // Result will have the same sign as that of larger number(absolute value)	
	else if(big_int_abs_compare(big_num1, big_num2) > 0)
	{
	    result_sign = big_num1->is_negative;
	}
	else
	{
	    result_sign = big_num2->is_negative;
	}

	big_int_abs_subtract(big_num1, big_num2);

	big_num1->is_negative = result_sign;
    }
}

void big_int_add_int(big_int *big_num1, const int int_value)
{
    // Converting int to big_int
    big_int *big_int_value = big_int_constructor("0");
    big_int_assign_int(big_int_value, int_value);

    big_int_add(big_num1, big_int_value);

    big_int_free(big_int_value);
}

int big_int_abs_compare(const big_int *big_num1, const big_int *big_num2)
{
    if(big_num1->num_of_digits > big_num2->num_of_digits)
    {
        return 1;
    }
    else if(big_num1->num_of_digits < big_num2->num_of_digits)
    {
	return -1;
    }

    int i = big_num1->num_of_digits - 1;
    
    while(i >= 0)
    {
        if(big_num1->num[i] > big_num2->num[i])
	{
	    return 1;
	}
	else if(big_num1->num[i] < big_num2->num[i])
	{
	    return -1;
	}
	i--;
    }
    return 0; 
}

int big_int_compare(const big_int *big_num1, const big_int *big_num2)
{
    if(big_num1->is_negative == big_num2->is_negative)
    {
	// If both the numbers are negative
	if(big_num1->is_negative)
	{
	    return big_int_abs_compare(big_num2,big_num1);
	}
	
	// If both the numbers are positive
	return big_int_abs_compare(big_num1,big_num2);
    }

    // If both numbers do not have same sign
    // If first number is negative, that means the second number must be positive
    if(big_num1->is_negative)
    {
	return -1;
    }

    return 1;
}

void big_int_abs_subtract(big_int *big_num1, const big_int *big_num2)
{
    big_int *greater_num = big_int_constructor("0");// For storing the greater number
    big_int *smaller_num = big_int_constructor("0");// For storing the smaller number
    
    if(big_int_abs_compare(big_num1,big_num2) == 0)
    {
	big_num1->num_of_digits = 1;
	big_num1->is_negative = 0;
	big_num1->num[0] = '0';
	big_num1->num[1] = '\0';
	return;
    } 
    
    if(big_int_abs_compare(big_num1,big_num2) > 0)
    {
        big_int_assign(greater_num, big_num1);
	big_int_assign(smaller_num, big_num2);
    }
    else 
    {
        big_int_assign(greater_num, big_num2);
	big_int_assign(smaller_num, big_num1);
    }

    int carry = 0;

    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;

    // Used the 'Subraction with best friend(vedic maths)' technique
    while(i < greater_num->num_of_digits && j < smaller_num->num_of_digits)
    {
	smaller_num->num[j] = ((smaller_num->num[j] - '0') + carry) + '0';

	if(greater_num->num[i] >= smaller_num->num[j])
	{
	    big_num1->num[k] = (greater_num->num[i] - smaller_num->num[j]) + '0';
	    carry = 0;
	}
	else
	{
	    big_num1->num[k] = (10 - (smaller_num->num[j] - '0') + (greater_num->num[i] - '0')) + '0';
	    carry = 1;
	}
	i++;
	j++;
	k++;
    }

    while(i < greater_num->num_of_digits)
    {
	if((greater_num->num[i] - '0') >= carry)
	{
            big_num1->num[k] = ((greater_num->num[i] - '0') - carry) + '0';
	    carry = 0; 
	}
	else
	{
	    big_num1->num[k] = 9 + '0';
	    carry = 1;
	}
	i++;
	k++;
    }

    k = k - 1;

    // For removing the leading zeroes
    while(big_num1->num[k] == '0')
    {
	k--;
    }

    k = k + 1;

    big_num1->num_of_digits = k;
    big_num1->is_negative = 0;

    big_int_free(greater_num);
    big_int_free(smaller_num);
}

void big_int_subtract(big_int *big_num1, const big_int *big_num2)
{
    int result_sign = 0;

    // If both the numbers have different sign
    // We will always add the numbers
    if(big_num1->is_negative != big_num2->is_negative)
    {
	// First number will decide the sign
	result_sign = big_num1->is_negative;
	big_int_abs_add(big_num1, big_num2);
	big_num1->is_negative = result_sign;
    }
    else
    {
	// If the first number is greater than the second number
	// then sign will be positive otherwise it will be negative
	result_sign = big_int_compare(big_num1, big_num2) >= 0 ? 0 : 1;
	big_int_abs_subtract(big_num1, big_num2);
	big_num1->is_negative = result_sign;
    }
}

void big_int_subtract_int(big_int *big_num1, const int int_value)
{
    // Converting int to big_int
    big_int *big_int_value = big_int_constructor("0");
    big_int_assign_int(big_int_value, int_value);

    big_int_subtract(big_num1, big_int_value);

    big_int_free(big_int_value);
}

void big_int_multiply(big_int *big_num1, const big_int *big_num2)
{
    // If either of the number is '0'
    // Result will always be zero
    if((big_num1->num_of_digits == 1 && big_num1->num[0] == '0') || (big_num2->num_of_digits == 1 && big_num2->num[0] == '0'))
    {
	big_num1->num_of_digits = 1;
	big_num1->num[0] = '0';
	big_num1->is_negative = 0;
	return;	
    }	

    // For storing the result
    big_int *result = big_int_constructor("0");

    // For storing the partial product
    big_int *partial_product = big_int_constructor("0");

    // When multiplying two numbers (m,n)
    // The maximum number of digits in result is 'm + n'
    // where m = number of digits in first number
    // n = number of digits in second number
    unsigned int required_digits = big_num1->num_of_digits + big_num2->num_of_digits + 1;

    big_int_allocate_digits(partial_product, required_digits);

    unsigned int i, j, k;
    int carry = 0;

    // Used the 'long multiplication' technique
    for(i = 0 ; i < big_num2->num_of_digits ; i++)
    {
        if(i > 0)
	{
	    partial_product->num[i - 1] = '0';
	}

	k = i;

	for(j = 0 ; j < big_num1->num_of_digits ; j++)
	{
	    int temp_mul = (big_num2->num[i] - '0') * (big_num1->num[j] - '0') + carry;

	    if(temp_mul > 9)
	    {
		carry = temp_mul / 10;
		temp_mul %= 10;
	    }
	    else
	    {
		carry = 0;
	    }

	    partial_product->num[k++] = temp_mul + '0';
	}

	if(carry != 0)
	{
	    partial_product->num[k++] = carry + '0';
	    carry = 0;
	}

	partial_product->num_of_digits = k;

	big_int_add(result, partial_product);
    }

    if(big_num1->is_negative == big_num2->is_negative)
    {
	result->is_negative = 0;
    }
    else
    {
	result->is_negative = 1;
    }

    big_int_assign(big_num1, result);
    
    big_int_free(result);
    big_int_free(partial_product);
}

void big_int_multiply_int(big_int *big_num1, const int int_value)
{
    // Converting int to big_int
    big_int *big_int_value = big_int_constructor("0");
    big_int_assign_int(big_int_value, int_value);

    big_int_multiply(big_num1, big_int_value);

    big_int_free(big_int_value);
}

void big_int_divide(big_int *big_num1, const big_int *big_num2)
{
    if(big_num2->num_of_digits == 1 && big_num2->num[0] == '0')
    {
	printf("Error: Divide by zero");
	exit(1);
    }

    int result_sign = 0;

    if(big_num1->is_negative != big_num2->is_negative)
    {
	result_sign = 1;
    }

    if(big_int_abs_compare(big_num1, big_num2)  == 0)
    {
	big_num1->num_of_digits = 1;
	big_num1->num[0] = '1';
	big_num1->is_negative = result_sign;
    }
    // If second number > first number, the result is always '0'
    // If the first number is '0', the result is always '0'
    else if((big_int_abs_compare(big_num1, big_num2)  < 0 ) || ( big_num1->num_of_digits == 1 && big_num1->num[0] == '0'))
    {	
	big_num1->num_of_digits = 1;
	big_num1->num[0] = '0';
	big_num1->is_negative = 0;
    }
    else
    {
	unsigned int count = 0;
        // Subtracting big_num2 from big_num1 until big_num1 >= big_num2
       	while(big_int_abs_compare(big_num1, big_num2) >= 0)
	{
	    count++;
	    big_int_abs_subtract(big_num1, big_num2);
	}
	big_int_assign_int(big_num1, count);
    }
    big_num1->is_negative = result_sign;
}

void big_int_divide_int(big_int *big_num1, const int int_value)
{
    // Converting int to big_int
    big_int *big_int_value = big_int_constructor("0");
    big_int_assign_int(big_int_value, int_value);

    big_int_divide(big_num1, big_int_value);

    big_int_free(big_int_value);
}

void big_int_modulo(big_int *big_num1, const big_int *big_num2)
{
    if(big_num2->num_of_digits == 1 && big_num2->num[0] == '0')
    {
	printf("Error: Modulo by zero");
	exit(1);
    }
    
    // First number decides the modulo's sign
    // As modulo is defines as
    // a = ((a / b) * b) + (a % b)
    int result_sign = big_num1->is_negative;

    big_int *temp_num1 = big_int_constructor("0");
    big_int_assign(temp_num1, big_num1);

    big_int *temp_num2 = big_int_constructor("0");
    big_int_assign(temp_num2, big_num2);
    
    temp_num1->is_negative = 0;
    temp_num2->is_negative = 0;

    // We know divisor * quotient + remainder = dividend
    // Therefore remainder = dividend - (divisor * quotient) 
    big_int_divide(temp_num1, temp_num2);// temp_num1 stores quotient
    big_int_multiply(temp_num1, temp_num2);// quotient * divisor

    big_int_abs_subtract(big_num1, temp_num1);
    big_num1->is_negative = result_sign;

    big_int_free(temp_num1);
    big_int_free(temp_num2);    
}

void big_int_modulo_int(big_int *big_num1, const int int_value)
{
    // Converting int to big_int
    big_int *big_int_value = big_int_constructor("0");
    big_int_assign_int(big_int_value, int_value);

    big_int_modulo(big_num1, big_int_value);

    big_int_free(big_int_value);
}

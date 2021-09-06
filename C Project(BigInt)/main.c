#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct big_int
{
    unsigned int num_of_digits; // Number of digits in the number
    unsigned int is_negative; // 1 if the number is negative and 0 if the number is positive
    unsigned int size; // Size of num array;
    char *num; // Array for storing the number

} big_int;

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
    
    while(i >= 0 && value[i] != '-')
    {
        new_bi->num[j++] = value[i--]; 
    }
    
    new_bi->num[j] = '\0';

    return new_bi;
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

	big_num->num = (char*)malloc(sizeof(char) * required_digits);
	
	memcpy(big_num->num,temp,big_num->num_of_digits);
        
	big_num->size = required_digits;
	free(temp);
    }
}

void big_int_abs_add(big_int *big_num1, const big_int *big_num2)
{
    unsigned required_digits = MAX(big_num1->num_of_digits,big_num2->num_of_digits) + 1;
    
    big_int_allocate_digits(big_num1,required_digits);

    int carry = 0;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;

    while(i < big_num1->num_of_digits && j < big_num2->num_of_digits)
    {
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
	if(big_num1->is_negative)
	{
	    return big_int_abs_compare(big_num2,big_num1);
	}

	return big_int_abs_compare(big_num1,big_num2);
    }

    if(big_num1->is_negative)
    {
	return -1;
    }

    return 1;
}

int main()
{
    char a[4];
    char b[4];
    scanf("%s",a);
    scanf("%s",b);

    big_int *b1 = big_int_constructor(a);
    big_int_print(b1);
    printf("\n");
    big_int *b2 = big_int_constructor(b);
    big_int_print(b2);
    printf("\n");

    printf("%d",big_int_compare(b1,b2));
    return 0;
}

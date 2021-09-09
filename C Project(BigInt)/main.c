#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x,y) (((x) > (y) ? (x) : (y)))

typedef struct big_int
{
    unsigned int num_of_digits; // Number of digits in the number
    unsigned int is_negative; // 1 if the number is negative and 0 if the number is positive
    unsigned int size; // Size of num array;
    char *num; // Array for storing the number

} big_int;

big_int* big_int_constructor(char *value);
void big_int_free(big_int *big_num);
void big_int_assign(big_int *big_num1, const big_int *big_num2);
void big_int_assign_int(big_int *big_num1, const int int_value);
void big_int_print(const big_int *big_num);
void big_int_allocate_digits(big_int *big_num, unsigned int required_digits);
void big_int_abs_add(big_int *big_num1, const big_int *big_num2);
void big_int_add(big_int *big_num1, const big_int *big_num2);
void big_int_add_int(big_int *big_num1, const int int_value);
int big_int_abs_compare(const big_int *big_num1, const big_int *big_num2);
int big_int_compare(const big_int *big_num1, const big_int *big_num2);
void big_int_abs_subtract(big_int *big_num1, const big_int *big_num2);
void big_int_subtract(big_int *big_num1, const big_int *big_num2);
void big_int_subtract_int(big_int *big_num1, const int int_value);
void big_int_multiply(big_int *big_num1, const big_int *big_num2);
void big_int_multiply_int(big_int *big_num1, const int int_value);
void big_int_divide(big_int *big_num1, const big_int *big_num2);

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
   
    j = j - 1;

    while(j > 0 && new_bi->num[j] == '0')
    {
	j--;
    }
    
    j = j + 1;

    new_bi->num_of_digits = j;
    new_bi->num[j] = '\0';

    return new_bi;
}

void big_int_free(big_int *big_num)
{
    free(big_num->num);
    free(big_num);
}

void big_int_assign(big_int *big_num1, const big_int *big_num2)
{
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

    for( ; i < big_num1->num_of_digits ; i++)
    {
	big_num1->num[i] = (temp % 10) + '0';
	temp /= 10;
    }

    big_num1->num[i] = '\0';
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
    big_num1->is_negative = 0;
    big_num1->num[k] = '\0';
}

void big_int_add(big_int *big_num1, const big_int *big_num2)
{
    if(big_num1->is_negative == big_num2->is_negative)
    {
	big_int_abs_add(big_num1, big_num2);
	big_num1->is_negative = big_num2->is_negative;
    }
    else
    {
	int result_sign = 0;
	
	if(big_int_abs_compare(big_num1, big_num2) == 0)
	{ 
	    big_num1->num_of_digits = 1;
	    big_num1->is_negative = 0;
	    big_num1->num[0] = '0';
	    big_num1->num[1] = '\0';
	    return;
	}
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

void big_int_abs_subtract(big_int *big_num1, const big_int *big_num2)
{
    big_int *greater_num = big_int_constructor("0");
    big_int *smaller_num = big_int_constructor("0");
    
    /*char *greater_num;
    unsigned int greater_num_of_digits;

    char *smaller_num;
    unsigned int smaller_num_of_digits;
    */

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
	/*greater_num = big_num1->num;
	greater_num_of_digits = big_num1->num_of_digits;

	smaller_num = big_num2->num;
	smaller_num_of_digits = big_num2->num_of_digits;*/

        big_int_assign(greater_num, big_num1);
	big_int_assign(smaller_num, big_num2);
    }
    else 
    {
	/*greater_num = big_num2->num;
	greater_num_of_digits = big_num2->num_of_digits;

	smaller_num = big_num1->num;
	smaller_num_of_digits = big_num1->num_of_digits;*/

        big_int_assign(greater_num, big_num2);
	big_int_assign(smaller_num, big_num1);
    }

    int carry = 0;

    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int k = 0;

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

    while(big_num1->num[k] == '0')
    {
	k--;
    }

    k = k + 1;

    big_num1->num_of_digits = k;
    big_num1->is_negative = 0;
    big_num1->num[k] = '\0';

    big_int_free(greater_num);
    big_int_free(smaller_num);
}

void big_int_subtract(big_int *big_num1, const big_int *big_num2)
{
    int result_sign = 0;

    if(big_num1->is_negative != big_num2->is_negative)
    {
	result_sign = big_num1->is_negative;
	big_int_abs_add(big_num1, big_num2);
	big_num1->is_negative = result_sign;
    }
    else
    {
	result_sign = big_int_compare(big_num1, big_num2) >= 0 ? 0 : 1;
	big_int_abs_subtract(big_num1, big_num2);
	big_num1->is_negative = result_sign;
    }
}

void big_int_subtract_int(big_int *big_num1, const int int_value)
{
    big_int *big_int_value = big_int_constructor("0");
    big_int_assign_int(big_int_value, int_value);

    big_int_subtract(big_num1, big_int_value);

    big_int_free(big_int_value);
}

void big_int_multiply(big_int *big_num1, const big_int *big_num2)
{
    if((big_num1->num_of_digits == 1 && big_num1->num[0] == '0') || (big_num2->num_of_digits == 1 && big_num2->num[0] == '0'))
    {
	big_num1->num_of_digits = 1;
	big_num1->num[0] = '0';
	big_num1->is_negative = 0;
	return;	
    }	

    big_int *result = big_int_constructor("0");

    big_int *partial_product = big_int_constructor("0");

    unsigned int required_digits = big_num1->num_of_digits + big_num2->num_of_digits + 1;

    big_int_allocate_digits(partial_product, required_digits);

    unsigned int i, j, k;
    int carry = 0;

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
    else if((big_int_abs_compare(big_num1, big_num2)  < 0 ) || ( big_num1->num_of_digits == 1 && big_num1->num[0] == '0'))
    {	
	big_num1->num_of_digits = 1;
	big_num1->num[0] = '0';
	big_num1->is_negative = 0;
    }
    else
    {
	unsigned int count = 0;
        
       	while(big_int_abs_compare(big_num1, big_num2) >= 0)
	{
	    count++;
	    big_int_abs_subtract(big_num1, big_num2);
	}
	big_int_assign_int(big_num1, count);
    }
    big_num1->is_negative = result_sign;
}

int main()
{
    int t;

    scanf("%d",&t);

    while(t--)
    {
        char a[5000],b[5000];
        scanf("%s",a);
        scanf("%s",b);

        big_int *b1 = big_int_constructor(a);
        big_int_print(b1);
        printf("\n");
        big_int *b2 = big_int_constructor(b);
        big_int_print(b2);
        printf("\n");
    
        //int x;
        //scanf("%d",&x);
        //printf("%d\n",x);

        //big_int_subtract_int(b1,x); 
        big_int_divide(b1,b2);
	big_int_print(b1);

        big_int_free(b1);
        big_int_free(b2);
    }

    /*int x;
    scanf("%d",&x);

    while(x--)
    {
        int t;
        scanf("%d",&t);

        int p;
        scanf("%d",&p);
        
	big_int *f = big_int_constructor("1");
        big_int_assign_int(f,t);

	big_int *r = big_int_constructor("0");
	big_int_assign(r,f);

        while(p > 1)
        {
            big_int_multiply(r,f);
	    p--;
        }

        big_int_print(r);

        big_int_free(f);
        big_int_free(r);
    }*/

    return 0;
}

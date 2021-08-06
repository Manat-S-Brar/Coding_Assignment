/* Swap two numbers without using third variable
 * Assignment: C Foundations
 * Date: 29/07/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>

void swap(int *num1, int *num2)
{
    *num1 += *num2;
    *num2 = *num1 - *num2;
    *num1 -= *num2;
}

int main()
{
    int num1,num2;
    scanf("%d %d",&num1,&num2);

    printf("Before swapping\nFirst number:%d Second number:%d\n",num1,num2);
    
    swap(&num1,&num2);

    printf("After swapping\nFirst number:%d Second number:%d",num1,num2);

    return 0;
}

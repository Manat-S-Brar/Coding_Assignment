/* Program to find the greatest common divisor(gcd) 
 * Assignment: 5
 * Date: 03/08/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>

int gcd(int num1, int num2)
{
    if(num2 % num1 == 0)
    {
	return num1;
    }
    gcd(num2 % num1, num1);
}

int main()
{
    int num1,num2;

    printf("Enter first number\n");
    scanf("%d",&num1);

    printf("Enter second number\n");
    scanf("%d",&num2);
    
    printf("GCD:%d\n",gcd(num1,num2));
    return 0;
}

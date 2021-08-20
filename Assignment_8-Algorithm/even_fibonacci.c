/* Program to print first n even numbers of the fibonacci series 
 *
 * Compilation: even_fibonaci.c
 * Execution: ./a.out
 *
 * Assignment: 8
 * Date: 20/08/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;

    scanf("%d",&n);

    /*In fibonacci series we have observed that every 3rd number is even
     *Eg- 1 1 2 3 5 8 13 21 34
      Here 3rd term = 2, 6th term = 8, 9th term = 34 and so on.

      To calculate every third term in fibonacci series we have
      f(n) = 4*f(n - 3) + f(n - 6);
      where f(0) = 0 , f(3) = 2;
     */
    
    long f0 = 0;
    long f3 = 2;

    for(int i = 0 ; i < n ; i++)
    {
	if(i == 0)
	{
	    printf("%ld ",f3);
	}
	else
	{
	    long temp = 4 * f3 + f0;
	    printf("%ld ",temp);

	    f0 = f3;
	    f3 = temp;
	}
    }

    return 0;
}

/* Program to print a pyramid
 * Assignment: C_Foundation
 * Date: 29/07/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>

int main()
{
    int num;
    scanf("%d",&num);
    
    for(int i = 1 ; i <= num ; i++)
    {
        for(int j = 1 ; j <= num ; j++)
	{
            if(j >= num + 1 - i)
	    {
	        printf("# ");
	    }
	    else
	    {
	        printf(" ");
	    }
	}
	printf("\n");
    }
    return 0;
}

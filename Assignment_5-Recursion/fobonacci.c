/* Print every third element of fibonacci series 
 * Assignment: 5
 * Date: 03/08/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>

void fib(int n)
{
    int size = (3 * n) + 1;
    int arr[size];

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;

    for(int i = 3 ; i < size ; i++)
    {
	arr[i] = arr[i - 1] + arr[i - 2];
	if(i % 3 == 0)
	{
	    printf("%d ",arr[i]);
	}
    }

}

int main()
{
    int n;

    printf("Enter number of terms \n");
    scanf("%d",&n);
    
    fib(n);

    return 0;
}

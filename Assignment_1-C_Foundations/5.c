/* Program to multiply 2 matrices
 * Assignment: C_Foundation
 * Date: 29/07/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>

int main()
{
    int size;
    scanf("%d",&size);

    int arr1[size][size];
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size ; j++)
	{
	    scanf("%d",&arr1[i][j]);
	}
    }

    int arr2[size][size];
    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size ; j++)
	{
	    scanf("%d",&arr2[i][j]);
	}
    }

    int result_arr[size][size];
    int sum = 0;
    for(int i = 0 ; i < size ; i++) //loop to access the rows of 1st arr
    {
        for(int j = 0 ; j < size ; j++)//loop to access the columns of 2nd arr
	{
            for(int k = 0 ; k < size ; k++)//loop to access the elements of ith row(jth column)
	    {
	        sum += arr1[i][k] * arr2[k][j]; 
	    }
	    result_arr[i][j] = sum;
	    sum = 0;
	}
    }

    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size ; j++)
	{
	    printf("%d ",result_arr[i][j]);
	}
	printf("\n");
    }
    return 0;
}

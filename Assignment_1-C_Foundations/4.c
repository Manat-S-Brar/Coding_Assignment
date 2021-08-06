/* Program to reverse an array
 * Assignment: C_Foundation
 * Date: 29/07/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>

void reverse_array(int *arr , int size)
{
    int start = 0;
    int end = size - 1;
    while(start < end)
    {
	int temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;

	start++;
	end--;
    }
}
int main()
{
    int size;
    scanf("%d",&size);

    int arr[size];
    for(int i = 0 ; i < size ; i++)
    {
	scanf("%d",&arr[i]);
    }
    reverse_array(arr,size);
    for(int i = 0 ; i < size ; i++)
    {
	printf("%d ",arr[i]);
    }
    return 0;
}

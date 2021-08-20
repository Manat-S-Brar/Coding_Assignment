/* Program to find mth smallest number in an array
 *
 * Compilation: mth_smallest_number.c
 * Execution: ./a.out
 *
 * Assignment: 8
 * Date: 20/08/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>
#include<stdlib.h>

void swap(int *num1,int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition(int *arr, int L, int R)
{
    int pivot = arr[L];
    int i = L;
    int j = R;

    while(i < j)
    {
	while(arr[i] <= pivot)
	{
	    i++;
	}

	while(arr[j] > pivot)
	{
	    j--;
	}

	if(i < j)
	{
	    swap(&arr[i],&arr[j]);
	}

    }

    swap(&arr[L],&arr[j]);
    
    return j;
}

void quick_sort(int *arr, int L, int R)
{
    if(L >= R)
    {
        return;
    }

    int pivot = partition(arr,L,R);
    quick_sort(arr,L,pivot - 1);
    quick_sort(arr,pivot + 1,R);
}

int main()
{
    int n;
    printf("Enter size of array\n");

    scanf("%d",&n);
    int *arr = (int*)malloc(n * sizeof(n));

    printf("Enter array elements\n");
    for(int i = 0 ; i < n ; i++)
    {
	scanf("%d",&arr[i]);
    }

    int m;
    printf("Enter m\n");
    scanf("%d",&m);

    quick_sort(arr,0,n-1);

    printf("%d\n",arr[m-1]);   

    return 0;
}

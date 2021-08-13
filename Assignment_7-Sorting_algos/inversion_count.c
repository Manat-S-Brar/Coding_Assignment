/* Program to find the count of inversions
 * Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
 *
 * Compilation: gcc inversion_count.c
 * Execution: ./a.out
 *
 * Assignment: 7
 * Date: 13/08/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>
#include<stdlib.h>

/*This problem cam be solved with merge_sort with a slight modification
 * While merging in merge_sort, we will check 
 * if arr[i] (i in this case is the poniter to our left array) > arr[j] that means all the elements ahead of i will also be greater than arr[j]
 * as both the arrays are sorted, so we will increment the count by (mid - i + 1) 
 */

int merge(int *arr, int l, int m, int r, int inversion)
{
    int size = r - l + 1;

    int *temp = (int*)malloc(size * sizeof(int));

    int i = l;
    int j = m + 1;
    int k = 0;

    while(i <= m && j <= r)
    {
	if(arr[i] <= arr[j])
	{
            temp[k++] = arr[i++];
	}
	else if(arr[j] < arr[i])
	{
	    inversion += (m - i + 1);
	    temp[k++] = arr[j++];
	}
    }

    while(i <= m)
    {
	temp[k++] = arr[i++];
    }

    while(j <= r)
    {
	temp[k++] = arr[j++];
    }

    i = l;
    k = 0;

    while(i <= r)
    {
	arr[i++] = temp[k++];
    }

    free(temp);

    return inversion;
}

int inversion_count(int *arr, int l, int r, int inversion)
{
    if(l >= r)
    {
	return inversion;
    }

    int mid = (l + r) / 2;

    inversion = inversion_count(arr,l,mid,inversion);
    inversion = inversion_count(arr,mid + 1,r,inversion);

    return merge(arr,l,mid,r,inversion);
}

int main()
{
    int size;
    printf("Enter the size of array\n");

    scanf("%d",&size);

    int *arr = (int*)malloc(size * sizeof(int));

    printf("Enter the array elements\n");

    for(int i = 0 ; i < size ; i++)
    {
	scanf("%d",&arr[i]);	    
    }

    int inversion = inversion_count(arr,0,size - 1,0);
    
    printf("%d",inversion);

    free(arr);
    
    return 0;
}

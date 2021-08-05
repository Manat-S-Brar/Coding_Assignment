/* Selection sort using recursion
 * Assignment: 5
 * Date: 03/08/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>

void selection_sort(int *arr, int size, int index)
{
    if(index == size - 1)
    {
        return;
    }
    int min_index = index;

    for(int i = index ; i < size ; i++)//loop for finding minimum element
    {
	if(arr[i] < arr[min_index])
	{
	    min_index = i;
	}
    }

    if(arr[index] != arr[min_index])//swap elements if arr[index] != arr[min_index]
    {
        int temp = arr[index];
        arr[index] = arr[min_index];
        arr[min_index] = temp;
    }
    
    selection_sort(arr,size,index+1);
}

int main()
{
    int arr[] = {2,5,1,0,3,4,0,0,0,0,0,345};
    int size = sizeof(arr) / sizeof(arr[0]);
    int start_index = 0;
    selection_sort(arr,size,start_index);
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

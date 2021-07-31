/* Program to sort an array using selection sort
 * Assignment: 2 
 * Date: 31/07/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/*
 * Function to swap two numbers
 *
 * Parameters:
 * num1 = First number
 * num2 = Second number
 */
void swap(int *num1 , int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

/*
 * Function to fill array with random numbers
 *
 * Parameters:
 * arr = Array which needs to be filled
 * size = Size of array
 */
void fill_array(int *arr , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        arr[i] = rand();
    }
}

/*
 * Function to sort array with selection sort
 *
 * Parameters:
 * arr = Array which needs to be sorted
 * size = Size of array
 */
void selection_sort(int *arr , int size)
{
    //we find the minimum element and swap it with ith element

    for(int i = 0 ; i < size - 1 ; i++)
    {
        int min_index = i;

        for(int j = i+1 ; j < size ; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        if(arr[i] != arr[min_index])
        {
            swap(&arr[i],&arr[min_index]);
        }
    }
}

void get_result(int input_size, int increment)
{

    struct timeval t;

    for(int i = 0 ; i < 8 ; i++)
    {
        int size_of_array = input_size + increment * i;
	int arr[size_of_array];

        fill_array(arr , size_of_array);
        
	gettimeofday(&t , NULL);
        long long start_time = t.tv_sec * 1000LL + t.tv_usec / 1000;
	
        selection_sort(arr , size_of_array);

	gettimeofday(&t , NULL);
        long long end_time = t.tv_sec * 1000LL + t.tv_usec / 1000;
        printf("%lld\n" , end_time - start_time);

    }
}
int main()
{
    int input_size = 8000;
    int increment = 4000;
    get_result(input_size,increment);
    return 0;    
}

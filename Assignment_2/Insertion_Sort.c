/* Program to sort an array using insertion sort
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
 * Function to sort array with insertion sort
 *
 * Parameters:
 * arr = Array which needs to be sorted
 * size = Size of array
 */
void insertion_sort(int *arr , int size)
{
    //Consider 0th element sorted

    for(int i = 1 ; i < size ; i++)
    {
        int curr_index = i;
        int curr_element = arr[curr_index];

        while( (curr_index > 0) && (arr[curr_index - 1] > curr_element) )
        {
            arr[curr_index] = arr[curr_index - 1]; //if element at current_index is less than current_index - 1 then shift element
            curr_index--;
        }
        if(arr[curr_index] != curr_element)
        {
            arr[curr_index] = curr_element;
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
	
        insertion_sort(arr , size_of_array);

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

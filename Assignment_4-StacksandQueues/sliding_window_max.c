/* Sliding Window Maximum
 *
 * Compilation: gcc sliding_window_max.c
 * Execution: ./a.out
 *
 * Assignment: 4
 * Date: 11/08/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    
    *returnSize = numsSize - k + 1;
    int *maxArray = (int*)malloc((*returnSize) * sizeof(int));
    
    int *queue = (int*)malloc(numsSize * sizeof(int));
    int head = -1;
    int tail = -1;
    int size = 0;
    
    int i = 0;
    int j = 0;
    int l = 0;
    
    while(j < numsSize)
    {
        /*We maintain a queue in descending order*/
        if(size == 0)
        {
            queue[++tail] = nums[j];
            head++;
            size++;
        }
        else
        {
            /*Remove all the previous elements from queue which are smaller than the current value*/
            while(size > 0 && nums[j] > queue[tail])
            {
                tail--;
                size--;
            }
            queue[++tail] = nums[j];
            size++;
        }
        
        /*If size of window is less than k we just increase the j pointer*/
        if((j - i + 1) < k)
        {
            j++;
        }
        else if((j - i + 1) == k)
        {
            /*Whenever we hit the window size our answer will at the head of queue
              Then we move the window forward i.e increase i and j pointer by 1
            */
            maxArray[l++] = queue[head];
            
            /*If the removed element i.e ith element is at the head of queue then we remove the element also from queue*/
            if(queue[head] == nums[i])
            {
                size--;
                if(size ==  0)
                {
                    head = tail;
                }
                else
                {
                    head++;
                }
            }
            
            i++;
            j++;
        }
    }
    
    return maxArray;
}

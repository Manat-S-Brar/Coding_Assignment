/* Largest Rectangle in Histogram
 *
 * Compilation: gcc largest_rectangle_histogram.c
 * Execution: ./a.out
 *
 * Assignment: 4
 * Date: 11/08/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */


int largestRectangleArea(int* heights, int heightsSize){
    
    if(heightsSize == 1)
    {
        return heights[0];
    }
    
    int *stack = (int*)malloc(heightsSize * sizeof(int));
    int top = -1;
    
    int *left_limits_index = (int*)malloc(heightsSize * sizeof(int));
    int *right_limits_index = (int*)malloc(heightsSize * sizeof(int));;
    
    /*For finding the left limit of each bar */
    for(int i = 0 ; i < heightsSize ; i++)
    {
        if(top == -1)
        {
            stack[++top] = i;
            left_limits_index[i] = 0;
        }
        else
        {
            while(top != -1 && heights[i] <= heights[stack[top]])
            {
                top--;
            }
            if(top == -1)
            {
                left_limits_index[i] = 0;
            }
            else
            {
                left_limits_index[i] = stack[top] + 1;
            }
            stack[++top] = i; 
        }
            
    }
    
    /*Resetting the stack*/
    top = -1;
    
    /*For finding the right limit of each bar */
    for(int i = heightsSize - 1 ; i >= 0 ; i--)
    {
        if(top == -1)
        {
            right_limits_index[i] = heightsSize - 1;
            stack[++top] = i;
        }
        else
        {
            while(top != -1 && heights[i] <= heights[stack[top]])
            {
                top--;
            }
            
            if(top == -1)
            {
                right_limits_index[i] = heightsSize - 1;
            }
            else
            {
                right_limits_index[i] = stack[top] - 1;
            }
            stack[++top] = i; 
        }
    }
    
    int max_area = INT_MIN;
    
    for(int i = 0 ; i < heightsSize ; i++)
    {
        /*Area of bar will be (right_limit - left_limit + 1) * height of that bar  */
        int area = (right_limits_index[i] - left_limits_index[i] + 1) * heights[i];
        
        if(area > max_area)
        {
            max_area = area;
        }
    }

    free(stack);
    free(left_limits_index);
    free(right_limits_index);
    
    return max_area;
}

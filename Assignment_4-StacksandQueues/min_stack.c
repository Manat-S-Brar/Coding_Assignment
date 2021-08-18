/* Minimum element Stack in constant time O(1)
 *
 * Compilation: gcc min_stack.c
 * Execution: ./a.out
 *
 * Assignment: 4
 * Date: 11/08/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */




typedef struct {
    
    int *stk;
    int initial_capacity;
    int top;
    
    int *min_value_stack;
    int initial_capacity1;
    int min_top;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    
    MinStack *stack = (MinStack*)malloc(sizeof(MinStack));
    
    stack->initial_capacity = 10;
    stack->stk = (int*)malloc(stack->initial_capacity * sizeof(int));
    stack->top = -1;
    
    /*min_value_stack is storing decreasing order 
      While pushing the values in stack we check if the current value is less than the value which is at the top min_value_stack if so then we push this value in min_value_stack
    */
    stack->initial_capacity1 = 10;
    stack->min_value_stack = (int*)malloc(stack->initial_capacity1 * sizeof(int));
    stack->min_top = -1;
    
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    
    /*Increasing the size of stack if it reaches at its full capacity*/
    if(obj->top == obj->initial_capacity - 1)
    {
        obj->initial_capacity += 10;
        obj->stk = (int*)realloc(obj->stk, obj->initial_capacity * sizeof(int));
        
    }
    
    obj->top++;
    obj->stk[obj->top] = val;
    
    if(obj->min_top == -1)
    {
        obj->min_top++;
        obj->min_value_stack[obj->min_top] = val;
    }
    else if(val <= obj->min_value_stack[obj->min_top])
    {
        if(obj->min_top == obj->initial_capacity1 - 1)
        {
            obj->initial_capacity1 += 10;
            obj->min_value_stack = (int*)realloc(obj->min_value_stack, obj->initial_capacity1 * sizeof(int));
        
        }
                                     
        obj->min_top++;
        obj->min_value_stack[obj->min_top] = val;
    }
}

void minStackPop(MinStack* obj) {
    
    if(obj->stk[obj->top] == obj->min_value_stack[obj->min_top])
    {
        obj->top--;
        obj->min_top--;
    }
    else
    {
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    
    return obj->stk[obj->top];
  
}

int minStackGetMin(MinStack* obj) {
    
    return obj->min_value_stack[obj->min_top];
  
}

void minStackFree(MinStack* obj) {
    
    free(obj->stk);
    free(obj->min_value_stack);
    free(obj);
    
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

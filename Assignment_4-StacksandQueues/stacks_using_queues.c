/* Implement Stack using Queues
 *
 * Compilation: gcc stacks_using_queues.c
 * Execution: ./a.out
 *
 * Assignment: 4
 * Date: 11/08/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */




typedef struct {
    
    int head1;
    int tail1;
    int *q1;
    
    int head2;
    int tail2;
    int *q2;
    
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    
    MyStack *stack = (MyStack*)malloc(sizeof(MyStack));
    
    stack->head1 = -1;
    stack->tail1 = -1;
    stack->q1 = (int*)malloc(100 * sizeof(int));
    
    stack->head2 = -1;
    stack->tail2 = -1;
    stack->q2 = (int*)malloc(100 * sizeof(int));
    
    return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    
    if(obj->head1 == -1)
    {
        obj->head1 = 0;
        obj->tail1 = 0;
        obj->q1[obj->tail1] = x;
    }
    else
    {
        /* Removing elements from queue1 and inserting into queue2*/
        obj->head2 = 0;
        while(obj->head1 <= obj->tail1)
        {
            obj->tail2++;
            obj->q2[obj->tail2] = obj->q1[obj->head1];
            obj->head1++;
        }
        
        /*Inserting x in queue1*/
        obj->head1 = 0;
        obj->tail1 = 0;
        obj->q1[obj->tail1] = x;
        
        /*Finally removing elements from queue2 and inserting into queue1*/
        while(obj->head2 <= obj->tail2)
        {
            obj->tail1++;
            obj->q1[obj->tail1] = obj->q2[obj->head2];
            obj->head2++;
        }
        
        obj->head2 = -1;
        obj->tail2 = -1;
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    
    int poped_ele = obj->q1[obj->head1];
    obj->head1++;
    
    return poped_ele;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->q1[obj->head1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if(obj->head1 == -1 || obj->head1 > obj->tail1)
    {
        return 1;
    }
    return 0;
}

void myStackFree(MyStack* obj) {
    
    free(obj->q1);
    free(obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
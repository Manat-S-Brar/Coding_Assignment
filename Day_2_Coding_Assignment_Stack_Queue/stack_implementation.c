/* Stack implementation 
 * Assignment: Day_2_Coding_Assignment
 * Date: 29/07/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>
#include<stdlib.h>

int top = -1;
int initial_size = 10;
int *stack = NULL; //global pointer to point  stack

void push(int value)
{
    if(top == initial_size - 1)//if stack is full increase stack size by double
    {
        initial_size *= 2;
        stack = (int*)realloc(stack,initial_size * sizeof(int));
        top += 1;
        stack[top] = value;	
    }
    else
    {
	top += 1;
	stack[top] = value;
    }
}

int pop()
{
    if(top == -1)
    {
	printf("Stack is empty, can not remove any element\n");
	return NULL;
    }
    int poped_ele = stack[top];
    top -= 1;
    return poped_ele;
}

int peek()
{
    return stack[top];
}

int is_empty()
{
    if(top == -1)
    {
	return 1;
    }
    else
    {
	return 0;
    }
}

void print()
{
    printf("Stack : ");
    for(int i = 0 ; i <= top ; i++)
    {
	printf("%d ",stack[i]);
    }
    printf("\n");
}

int main()
{
    stack = (int*)calloc(initial_size , sizeof(int));

    printf("is stack empty : %d\n",is_empty());
    push(1);
    push(3);
    push(4);
    print();
    printf("is stack empty : %d\n",is_empty());
    printf("Element at top = %d\n",peek());
    printf("Popped element = %d\n",pop());
    printf("Popped element = %d\n",pop());

    for(int i = 0 ; i < 10 ; i++)
    {
        push(i);
    }

    print();

    for(int i = 0 ; i < 4 ; i++)
    {
        printf("Popped element = %d\n",pop());
    }

    for(int i = 0 ; i < 10 ; i++)
    {
        push(i - 30);
    }

    print();

    free(stack);
    return 0;
}

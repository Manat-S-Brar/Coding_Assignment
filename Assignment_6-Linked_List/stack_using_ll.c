/* Stack implementation using linked list 
 *
 * Compilation: stack_using_ll.c
 * Execution: ./a.out
 *
 * Assignment: 6
 * Date: 29/08/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

//Top represents the top of stack
struct Node *top = NULL;

void push(int value)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

    // Adding the temp node in the beginning of the linked list
    temp->value = value;
    temp->next = top;

    top = temp;
}

int pop()
{
    //While poping we remove the node from beginning
    if(top == NULL)
    {
	printf("There is no element in stack\n");
	exit(0);
    }

    struct Node *temp;
    temp = top;

    top = temp->next;
    temp->next = NULL;
    
    int poped_ele = temp->value;

    free(temp);

    return poped_ele;
}

int is_empty()
{
    return (top == NULL);
}

int peek()
{
    if(!is_empty())
    {
	return top->value;
    }
}

void print()
{
    struct Node *temp = top;

    while(temp != NULL)
    {
	printf("%d ",temp->value);
	temp = temp->next;
    }
    printf("\n");
}

int main()
{
    push(1);
    push(2);
    
    printf("Peek Value:%d\n",peek());
    
    push(3);
    
    print();
    
    pop();
    
    push(15);
    
    pop();
    pop();
    
    push(30);
    
    print();

    return 0;
}

/* Queue implementation using linked list 
 *
 * Compilation: queue_using_ll.c
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

//Head represents the front of the queue
struct Node *head = NULL;

//Tail represents the back of the queue
struct Node *tail = NULL;

void enqueue(int value)
{
    //While adding the elements in queue, we are adding new node at the end of linked list 
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

    temp->value = value;
    temp->next = NULL;

    //If queue is empty, make head and tail to point to the first node 
    if(head == NULL)
    {
        head = temp; 
	tail = temp;
    }
    else
    {
        tail->next = temp;
	tail = temp;
    }
}

void dequeue()
{
    //While removing elements from the queue, we are removing the node from the beginning of linked list
    if(head == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp = head;
	head = temp->next;
	temp->next = NULL;

	free(temp);
    }
}

int is_empty()
{
    return (head == NULL);
}

int peek()
{
    if(!is_empty())
    {
	return head->value;
    }
}

void print()
{
    if(head == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        struct Node *temp = head;

        while(temp != NULL)
        {
	    printf("%d ",temp->value);
	    temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    print();

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    print();

    dequeue();
    dequeue();

    print();

    printf("Peek Value:%d\n",peek());
    printf("isEmpty : %d\n",is_empty());

    dequeue();
    dequeue();
    dequeue();

    printf("isEmpty : %d\n",is_empty());
    dequeue();

    return 0;
}

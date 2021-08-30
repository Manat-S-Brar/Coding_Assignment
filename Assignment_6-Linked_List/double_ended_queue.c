/* Double Ended Queue implementation using linked list 
 *
 * Compilation: double_ended_queue.c
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
    struct Node *prev;
};

//Head represents the front of the queue
struct Node *head = NULL;

//Tail represents the back of the queue
struct Node *tail = NULL;

void enqueue_front(int value)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->value = value;
    temp->prev = NULL;

    if(head == NULL && tail == NULL)
    {
	temp->next = NULL;
	head = tail = temp;	
    }
    else
    {
	temp->next = head;
	head->prev = temp;
	head = temp;
    }
}

void enqueue_back(int value)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->value = value;
    temp->next = NULL;

    if(head == NULL && tail == NULL)
    {
	temp->prev = NULL;
	head = tail = temp;	
    }
    else
    {
	temp->prev = tail;
	tail->next = temp;
	tail = temp;
    }
}

void dequeue_front()
{
    if(head == NULL && tail == NULL)
    {
	printf("Queue is empty, can not remove any element\n");
    }
    else
    {
	struct Node *temp = head;
	head = head->next;

	temp->next = NULL;
        if(head == NULL)
        {
	    tail = NULL;
        }
	else
	{
	    head->prev = NULL;
	}

	free(temp);

    }

}

void dequeue_back()
{
    if(head == NULL && tail == NULL)
    {
	printf("Queue is empty,can not remove any element\n");
    }
    else
    {
	struct Node *temp = tail;
	tail = tail->prev;

	temp->prev = NULL;
    
	if(tail == NULL)
        {
	    head = NULL;
        }
	else
	{
	    tail->next = NULL;
	}
	free(temp);

    }

}

int is_empty()
{
    return (head == NULL && tail == NULL);
}

int peek_front()
{
    if(!is_empty())
    {
	return head->value;
    }
}

int peek_back()
{
    if(!is_empty())
    {
	return tail->value;
    }
}

int is_present(int ele)
{
    struct Node *temp = head;

    while(temp != NULL)
    {
	if(temp->value == ele)
	{
	    return 1;
	}
	temp = temp->next;
    }

    return 0;
}

void print()
{
    if(head == NULL && tail == NULL)
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

    enqueue_front(1);
    enqueue_front(2);
    enqueue_front(3);

    print();

    enqueue_back(1);
    enqueue_back(2);
    enqueue_back(3);

    print();

    dequeue_front();
    dequeue_front();

    print();

    dequeue_back();
    dequeue_back();

    print();

    printf("Peek_Front Value:%d\n",peek_front());
    printf("Peek_Back Value:%d\n",peek_back());
    printf("isEmpty : %d\n",is_empty());

    dequeue_back();
    dequeue_front();
    dequeue_back();

    printf("isEmpty : %d\n",is_empty());

    enqueue_front(1);
    enqueue_back(2);
    enqueue_front(3);

    print();

    printf("Is 2 present in queue : %d\n",is_present(2));
    printf("Is 8 present in queue : %d\n",is_present(8));

    return 0;
}

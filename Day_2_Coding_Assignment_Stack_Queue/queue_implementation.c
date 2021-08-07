/* Queue implementation 
 * Assignment: Day_2_Coding_Assignment
 * Date: 06/08/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>
#include<stdlib.h>

int head = -1;
int tail = -1;
int initial_capacity = 10;
int size = 0;
int *queue = NULL; //global pointer to point the queue

void enqueue(int value)
{
    if(head == -1)
    {
	head = 0;
    }

    if(size < initial_capacity)
    {
	/*For implementing circular queue
	 * Eg. Let's assume head = 1, tail = 9 and capacity = 10
	 * We have to fill new element at '0' index
	 * tail++ => 9 + 1 = 10
	 * tail % capacity => 10 % 10 = 0*/

        tail++;
        tail %= initial_capacity;
        queue[tail] = value;
        size++;
    }
    else
    {
        /*For increasing the size of queue when it is full*/

	initial_capacity *= 2;
	int *new_queue = (int*)calloc(initial_capacity, sizeof(int));

	int j = head;
	int i = 0;
	
	for(i ; i < size ; i++)
	{
            new_queue[i] = queue[j];
	    j++;
	    j = j % (initial_capacity / 2);
	}
	
	new_queue[i] = value;
	
	head = 0;
	tail = i;
	
	size++;

	/*Deallocating the memory of old queue*/
	free(queue);
	queue = new_queue;
    }
}

int dequeue()
{
    if(size == 0)
    {
	printf("Queue is empty, can not perform dequeue\n");
	return NULL;
    }

    int removed_ele = queue[head];
    head++;
    size--;
    
    return removed_ele;
}

int peek()
{
    return queue[head];
}

int is_empty()
{
    if(size == 0)
    {
	return 1;
    }
    return 0;
}

void print()
{
    printf("Queue: ");
    int j = head;
    for(int i = 0 ; i < size ; i++)
    {
        printf("%d ",queue[j]);
	j++;
	j = j % initial_capacity;
    }
    printf("\n");
}

int main()
{
    queue = (int*)calloc(initial_capacity , sizeof(int));

    for(int i = 0 ; i < initial_capacity ; i++)
    {
	printf("Enqueued Element:%d\n",i);
	enqueue(i);
    
    }

    printf("Head:%d Tail:%d Size:%d\n",head,tail,size);
    print();

    dequeue();
    dequeue();
    enqueue(10);
    enqueue(11);

    printf("After dequeueing two times and enqueueing 10 and 11\n");
    printf("Head:%d Tail:%d Size:%d\n",head,tail,size);
    print();


    printf("Enqueued Element:%d\n",10);
    enqueue(10);

    printf("Head:%d Tail:%d Size:%d\n",head,tail,size);
    print();

    for(int j = 0 ; j < 3 ; j++)
    {
	printf("Dequeued Element:%d\n",dequeue());
    }

    for(int i = 10 ; i < 13 ; i++)
    {
	printf("Enqueued Element:%d\n",i);
	enqueue(i);
    }

    printf("Head:%d Tail:%d Size:%d\n",head,tail,size);
    print();

    free(queue);

    return 0;
}

/* Program that checks whether the sequence of brackets the given string is balanced or not
 *
 * Compilation: gcc balanced_paranthesis.c
 * Execution: ./a.out
 *
 * Assignment: 4
 * Date: 08/08/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>
#include<stdlib.h>

/*--------------------------------- Stack Implementation ---------------------------------*/

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

/*----------------------------------------------------------------------------------------*/

int balanced_paranthesis(char *s)
{
    int i = 0;

    while(s[i] != '\n')
    {
        switch(s[i])
	{
	    case '(':
	    case '{':
	    case '[': push(s[i]);
		      break;

	    case ')': if(is_empty())
		      {
		          return 0;
		      }
		      if(pop() != '(')
		      {
		          return 0;
		      }
		      break;

	    case '}': if(is_empty())
		      {
		          return 0;
		      }
		      if(pop() != '{')
		      {
		          return 0;
		      }
		      break;

	    case ']': if(is_empty())
		      {
		          return 0;
		      }
		      if(pop() != '[')
		      {
		          return 0;
		      }
		      break;
	}
	i++;
    }
    /* If stack is not empty that means there are open brackets left */
    if(is_empty())
    {
        return 1;
    }
    return 0;
}

int main()
{
    char string[1000];
    fgets(string,sizeof(string),stdin);

    stack = (int*)calloc(initial_size , sizeof(int));

    if(balanced_paranthesis(string))
    {
        printf("True\n");
    }
    else
    {
	printf("False\n");
    }

    free(stack);
    return 0;
}

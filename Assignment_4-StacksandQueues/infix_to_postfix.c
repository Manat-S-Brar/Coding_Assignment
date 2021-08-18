/* Program to convert infix expression to postfix expression
 *
 * Compilation: gcc infix_to_postfix.c
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
    return 0;
}

int peek()
{
    return stack[top];
}

/*----------------------------------------------------------------------------------------*/

//Returns the precedence of operators 
int precedence(char operator)
{
    if(operator == '*' || operator == '/')
    {
	return 2;
    }

    if(operator == '+' || operator == '-')
    {
	return 1;
    }
    return 0;
}

void infix_to_postfix(char *s, char *postfix)
{
    int i = 0;
    int j = 0;

    while(s[i] != '\n')
    {
	if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' )
	{
	    //Lower precedence operator can not be placed above Higher precedence operator
	    //Higher precedence operator is poped from stack and put in the final postfix expression
	    while(!is_empty() && precedence(s[i]) <= precedence(peek()))
	    {
		postfix[j] = pop();
		j++;
	    }

	    push(s[i]);
	}
	else if(s[i] == '(')
	{
	    push(s[i]);
	} 
	else if(s[i] == ')')
	{
	    while(peek() != '(')
	    {
		postfix[j] = pop();
	        j++;
	    }
	    pop();
	}
	else
	{
	    postfix[j] = s[i];
	    j++;
	}
	
	i++;
    }

    while(!is_empty())
    {
        postfix[j] = pop();
	j++;
    }

    postfix[j] = '\0';

}

int main()
{
    char string[1000];
    fgets(string,sizeof(string),stdin);

    stack = (int*)calloc(initial_size , sizeof(int));

    char postfix[1000];

    infix_to_postfix(string,postfix);

    printf("%s",postfix);

    free(stack);
    return 0;
}

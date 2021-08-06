/* Program to evaluate Reverse Polish expression 
 * Assignment: C_Foundations
 * Date: 06/08/21
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

int evaluate_reverse_polish(char *str)
{
    int i = 0;
    int word_size = 0;

    while(str[i] != '\n')
    {
        
	if(str[i] != ' ' && str[i] != '+' && str[i] != '-' &&  str[i] != '*' && str[i] != '/' )//to calculate word size
	{
	    word_size++;
	}

	// As we are taking input from char array it is difficult to distinguish negative numbers from '-' operator
	// If the number is negative, '-' sign is followed by a number whereas if it is '-' operator, it is followed by a space character or '\n'
	// So this condition (str[i] == '-' && (str[i + 1] == ' ' || str[i + 1] == '\n') ) is used to find '-' operator
	if(str[i] == '*' || str[i] == '/' || (str[i] == '-' && (str[i + 1] == ' ' || str[i + 1] == '\n')) || str[i] == '+')
	{
	    int prev_element1 = pop();
	    int prev_element2 = pop();
	    int result = 0;

	    switch(str[i])
	    {
	        case '*': result = prev_element2 * prev_element1;
			  break;
	        case '/': result = prev_element2 / prev_element1;
			  break;
	        case '+': result = prev_element2 + prev_element1;
			  break;
		case '-': result = prev_element2 - prev_element1;
			  break;
	    }
	    push(result);
	}
	else if(str[i + 1] == ' ' || str[i + 1] == '\n')
	{
	    int base = 1;
	    int num = 0;
	    int j = 0;

	    for(j ; j < word_size ; j++)
	    {
	        num += (str[i - j] - 48) * base; // 48 is subtracted to convert char to int
	        base *= 10;	
	    }

	    if((i - j) >= 0 && str[i - j] == '-')//condition to check if a number is nagative
	    {
	        num -= 2 * num;//to make number negative 
	    }

	    push(num);
	    word_size = 0;
	}
	i++;
    }
    return peek();
}

int main()
{
    char reverse_polish_expr[1000];
    printf("Enter reverse polish expression\n");
    fgets(reverse_polish_expr,sizeof(reverse_polish_expr),stdin);

    stack = (int*)calloc(initial_size , sizeof(int));
    int result = evaluate_reverse_polish(reverse_polish_expr);
    printf("Value: %d\n",result);
    free(stack);

    return 0;
}

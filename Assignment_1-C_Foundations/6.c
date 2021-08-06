/* Program to check if given string is palindrome or not 
 * Assignment: C_Foundation
 * Date: 29/07/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>

int check_palindrome(char *str)
{
    int i = 0;
    int size = 0;

    while(str[i] != '\0')
    {
        size++;
	if(str[i] >= 'a' && str[i] <= 'z')
	{
	    str[i] -= 32; // converting str[i] to uppercase
	}
	i++;
    }

    size -= 1; // subtract 1 as '\n' was also included in size

    i = 0;
    int j = size - 1;
    int ans = 1;

    while(i < j)
    {
    	if(str[i] == ' ')
	{
	    i++;
	}
	if(str[j] == ' ')
	{
	    j--;
	}
	if(str[i] != str[j])
	{
	    ans = 0;
	    break;
	}	
	i++;
	j--;
    }
    return ans;

}

int main()
{
    char str[100];
    fgets(str,sizeof(str),stdin);
    
    int ans = check_palindrome(str);

    if(!ans)
    {
        printf("False");
    }
    else
    {
        printf("True");
    }

    return 0;
}

/* Program to reverse the given string 
 * Assignment: C_Foundation
 * Date: 29/07/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>

void reverse(char *str)
{
    int size = 0;
    int i = 0;

    while(str[i] != '\0')
    {
        size++;
	i++;
    }
    size -= 1; // subtract 1 as '\n' is also included in size
    i = 0;
    int j = size - 1;

    while(i < j)
    {
        char temp = str[i];
	str[i] = str[j];
	str[j] = temp;
	i++;
	j--;
    }

}

int main()
{
    char str[100];
    fgets(str,sizeof(str),stdin);

    reverse(str);
    
    printf("%s",str);

    return 0;
}

/* This function strncat(char *s1, char *s2, n) concatenates n characters from s2 string to s1 string 
 * Assignment: C_Foundation
 * Date: 29/07/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>

void strncat(char *s1, char *s2, int n)
{
    int i = 0;
    int size = 0;

    while(s1[i] != '\0')
    {
        size++;
	i++;
    }

    for(i = size ; i < size + n ; i++)
    {
        s1[i] = s2[i - size];
    }
    s1[i] = '\0';
}

int main()
{
    char str1[] = "Qwerty";
    char str2[] = "Hello World";
    int n = 2;

    strncat(str1,str2,n);

    printf("%s",str1);

    return 0;
}

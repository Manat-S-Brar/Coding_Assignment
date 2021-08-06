/* This function strncpy(char *s1, char *s2, n) copies n characters from s2 string to s1 string 
 * Assignment: C_Foundation
 * Date: 29/07/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>

void strncpy(char *s1, char *s2, int n)
{

    for(int i = 0 ; i < n ; i++)
    {
        s1[i] = s2[i];
    }

}

int main()
{
    char str1[100];
    char str2[] = "Hello World";
    int n = 10;

    strncpy(str1,str2,n);

    printf("%s",str1);

    return 0;
}

/* This function strncmp(char *s1, char *s2, n) compares n characters of string s1 and string s2 returns 0 if n characters from both the strings are same , value '< 0' if s1 has ascii value lower than s2 and value '> 0' if ascii value of s1 is greater than s2
 * Assignment: C_Foundation
 * Date: 29/07/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>

int strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    while(s1[i] != '\0' && s2[i] != '\0' && i < n)
    {
        if(s1[i] < s2[i] || s1[i] > s2[i])
	{
	    return s1[i] - s2[i];
	}
	i++;
    }
    return 0;
}

int main()
{
    char str1[] = "Qwerty";
    char str2[] = "Qwfrty World";
    int n = 6;

    int cmp = strncmp(str1,str2,n);

    printf("%d",cmp);

    return 0;
}

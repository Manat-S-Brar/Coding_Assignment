/* This function returns 1 if the string t occurs at the end of the string s and zero otherwise 
 * Assignment: C_Foundation
 * Date: 29/07/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>
#include<string.h>

int strend(char *s1, char *s2)
{
    int size1 = strlen(s1) - 1;
    int size2 = strlen(s2) -1; 
    int j = 0;

    for(int i = size1 - 1 ; i >= (size1 - size2) ; i--)//we start from back and check upto size1 - size2
    {
        if(s1[i] != s2[size2 - 1 - j])
        {
	    return 0;
        }
	j++;	
    }
    return 1;
}

int main()
{
    char str1[100],str2[100];
    fgets(str1,sizeof(str1),stdin);
    fgets(str2,sizeof(str2),stdin);
    int index = strend(str1,str2);
    
    printf("%d",index);

    return 0;
}

/* Alternate version of squeeze 
 * Assignment: C_Foundation
 * Date: 29/07/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>
#include<string.h>

void squeeze(char *s1, char *s2)
{
    char ascii[128];//chars are stored as ascii values.

    for(int i = 0 ; i < 128 ; i++)
    {
        ascii[i] = '0';
    }

    for(int i = 0 ; i < strlen(s2) - 1 ; i++)
    {
        ascii[s2[i]] = '1';
    }

    for(int i = 0 ; i < strlen(s1) - 1 ; i++)
    {
        if(ascii[s1[i]] == '1')
	{
	    s1[i] = 127;// 127 in ascii is for 'del'
	}
    }
}

int main()
{
    char str1[100],str2[100];
    fgets(str1,sizeof(str1),stdin);
    fgets(str2,sizeof(str2),stdin);
    squeeze(str1,str2);
    
    printf("%s",str1);

    return 0;
}

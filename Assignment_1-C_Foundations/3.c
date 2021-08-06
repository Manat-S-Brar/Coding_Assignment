/* Program to find the count of number of vowels and consonents
 * Assignment: C_Foundation
 * Date: 29/07/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>

int main()
{
    char str[100];
    fgets(str,sizeof(str),stdin);
    int vowels = 0;
    int total_characters = 0;

    int i = 0;

    while(str[i] != '\0')
    {
        total_characters++;
	if(str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' || str[i] == 'u' || str[i] == 'U')
	{
	    vowels++;
	}
	i++;	
    }
    printf("Vowels:%d\nConsonents:%d\n",vowels,total_characters - vowels - 1);

    return 0;
}

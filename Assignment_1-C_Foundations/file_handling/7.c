/* Program to print all input lines that are longer than 80 characters 
 * Assignment: C Foundations
 * Date: 06/08/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("file1.txt","r");

    char ch = fgetc(fp);
    char line[200];

    while(ch != EOF)
    {
        int i = 0;

	while(ch != '\n')
	{
	    line[i] = ch;
	    i++;
	    ch = fgetc(fp);  
	}

	line[i] = '\0';

	if(i > 80)
	{
	    printf("%s\n",line);
	}
	ch = fgetc(fp);
    }

    return 0;
}

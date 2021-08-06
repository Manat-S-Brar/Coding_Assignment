/* This function returns the position of rightmost occurence of t in s or -1 if there is none 
 * Assignment: C_Foundation
 * Date: 29/07/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>
#include<string.h>

int strindex(char *s1, char *s2)
{
    int size1 = strlen(s1) - 1;
    int size2 = strlen(s2) -1;
    int is_present = 1; 

    for(int i = size1 - 1 ; i >= size2 - 1 ; i--)//we start from back(rightmost) of char array as we have to find the rightmost occurance
    {
        is_present = 1;
        for(int j = 0 ; j < size2 ; j++)
	{
	    if(s1[i-j] != s2[size2 - 1 - j])
	    {
	        is_present = 0;
		break;
	    } 
	}
	if(is_present == 1)
	{
            return i - (size2 - 1);//(size2 - 1) is subtracted as we are checking from back. In this case i = rightmost_index + (size2 - 1) 
	}	
    }
    return -1;
}

int main()
{
    char str1[100],str2[100];
    fgets(str1,sizeof(str1),stdin);
    fgets(str2,sizeof(str2),stdin);
    int index = strindex(str1,str2);
    
    printf("%d",index);

    return 0;
}

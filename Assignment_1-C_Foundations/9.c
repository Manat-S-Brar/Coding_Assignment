/* Program to convert hexadecimal to decimal number 
 * Assignment: C_Foundation
 * Date: 29/07/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>

int hexa_to_decimal(char *hxd)
{
    int size = 0;
    int i = 0;

    while(hxd[i] != '\0')
    {
        size++;
	i++;
    }
    size -= 1; //subtract 1 as '\n' is also included in size
    i = size - 1;
    int base = 1;
    int decimal = 0;

    while(i >= 0 && hxd[i] != 'X' && hxd[i] != 'x')
    {
        if(hxd[i] >= '0' && hxd[i] <= '9')
	{
            decimal += base * (hxd[i] - '0');// to convert char to decimal subtract '0' or 48 
	    base *= 16; // as in case of hexadecimal base is 16
	}
	else if(hxd[i] >= 'A' && hxd[i] <= 'F')
	{
	    decimal += base * (hxd[i] - 55);//eg ASCII value of 'A' is 65. (65 - 55) = 10 which is the decimal value of 'A'
	    base *= 16;
	}
	else if(hxd[i] >= 'a' && hxd[i] <= 'f')
	{
	    decimal += base * (hxd[i] - 87);//eg ASCII value of 'a' is 97. (97 - 87) = 10 which is the decimal vvalue of 'a'
	    base *= 16;
	}
	i--;
    } 
    return decimal;
}

int main()
{
    char str[100];
    fgets(str,sizeof(str),stdin);

    int number = hexa_to_decimal(str);
    
    printf("%d",number);

    return 0;
}

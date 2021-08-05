/* Tower of Hanoi 
 * Assignment: 5
 * Date: 03/08/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>
#include<math.h>

int tower_of_hanoi(int num, char from, char to, char aux,int movements)
{
    if(num == 1)//if there is 1 plate move that plate from 'A' to 'C'
    {
	printf("%c to %c\n",from,to);
	return movements + 1;
    }

    movements = tower_of_hanoi(num - 1,from,aux,to,movements);//move n-1 plates from 'A' to 'B' 

    printf("%c to %c\n",from,to);
    movements++;

    movements = tower_of_hanoi(num - 1,aux,to,from,movements);//move n-1 plates from 'B' to 'C'
    
    return movements;
}

int main()
{
    int num;

    printf("Enter number of plates\n");
    scanf("%d",&num);

    int movements = tower_of_hanoi(num,'A','C','B',0);
    printf("Total movements required = %d",movements);
    return 0;
}

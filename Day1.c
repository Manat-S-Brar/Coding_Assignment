/* Program to find the square root a number upto precision p using binary search
 * Assignment: 1
 * Date: 18/07/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>

long double squareRoot(int number, int precision)
{
    //To find the integer part
    int start = 0;
    int end = number;
    long double sqrt = 0;
    while(start <= end)
    {
        int mid = (start + end) / 2;
	if(mid * mid == number)
	{
	    sqrt = mid;
	    break;
	}
	else if(mid * mid < number)
	{
	    sqrt = mid;
	    start = ++mid;
	}
        else
	{
	    end = --mid;
        }
    }
    

    //To find the decimal part 
    long double  denominator = 0.1;
    for(int i = 0 ; i < precision ; i++)
    {
	long double temp = sqrt + denominator;
        for(int j = 0 ; j < 9 ; j++)
	{
	    if(temp * temp > number)
	    {
	        break;
	    }
	    sqrt = temp;
	    temp += denominator;
	}
        denominator /= 10;	
    } 
    return sqrt;
}    

int main()
{
    int number;
    int precision;
    scanf("%d %d",&number,&precision);
    long double ans = squareRoot(number,precision);    
    printf("%.16Lg",ans);
    return 0;
}

/* Bitwise operations 
 *
 * Compilation: gcc bitwise_operations.c
 * Execution: ./a.out
 *
 * Assignment: 3
 * Date: 17/08/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include<stdio.h>
#include<stdlib.h>

int bitAnd(int x, int y)
{
    return ~(~x | ~y);
}

int bitXor(int x, int y)
{
    return ~(~(x & ~y) & ~(~x & y));
}

int sign(int x)
{
    return ((x >> 31) | (!!x));
}

int getByte(int x, int n)
{
    return ((x >> (n << 3)) & 0xff);
}

int logicalShift(int x, int n)
{
    return ((x >> n) & (~(((1 << 31) >> n) << 1)));
}

int conditional(int x, int y, int z)
{
    return (z ^ ((y ^ z) & ((!x) + 1)));
}

int bang(int x)
{
    return (((x | (~x + 1) ) >> 31) + 1);
}

int invert (int x, int p, int n) 
{
    return (x ^ ((1 << n) - 1) << p);
}


int main()
{
    printf("bitAnd:%d\n",bitAnd(6,5));
    printf("bitXor:%d\n",bitXor(4,5));
    printf("sign:%d\n",sign(-23));
    printf("getByte:%d\n",getByte(70,1));
    printf("logicalShift:%d\n",logicalShift(-1,30));
    printf("conditional:%d\n",conditional(2,4,5));
    printf("bang:%d\n",bang(3));
    printf("bang:%d\n",bang(0));
    printf("invert:%d\n",invert(94,5,5));

    return 0;
}










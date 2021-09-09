#include <stdio.h>
#include "BigInt.h"

int main()
{
    int t;

    scanf("%d",&t);

    while(t--)
    {
        char a[5000],b[5000];
        scanf("%s",a);
        scanf("%s",b);

        big_int *b1 = big_int_constructor(a);
        big_int_print(b1);
        printf("\n");
        big_int *b2 = big_int_constructor(b);
        big_int_print(b2);
        printf("\n");
    
        //int x;
        //scanf("%d",&x);
        //printf("%d\n",x);

        //big_int_subtract_int(b1,x); 
        big_int_multiply(b1,b2);
	big_int_print(b1);

        big_int_free(b1);
        big_int_free(b2);
    }

    // Calculates power of a number
    /*int x;
    scanf("%d",&x);

    while(x--)
    {
        int t;
        scanf("%d",&t);

        int p;
        scanf("%d",&p);
        
	big_int *f = big_int_constructor("1");
        big_int_assign_int(f,t);

	big_int *r = big_int_constructor("0");
	big_int_assign(r,f);

        while(p > 1)
        {
            big_int_multiply(r,f);
	    p--;
        }

        big_int_print(r);

        big_int_free(f);
        big_int_free(r);
    }*/

    return 0;
}

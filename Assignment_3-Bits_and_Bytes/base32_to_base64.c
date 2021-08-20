/* Converting base32 encoded string to base64 encoded string
 *
 * Compilation: gcc base32_to_base64.c
 * Execution: ./a.out
 *
 * Assignment: 3
 * Date: 17/08/21
 * Name: Manat Singh Brar
 * Id: 1910990761
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    /*base32_binary stores binary representation of base32 characters
      Size of base32_binary is 33 (32 for storing base32 characters' binary representation and 33rd for padding )
   */
    int base32_binary[33][5];
    
    for(int i = 0 ; i < 31 ; i++)
    {
        int num = i;
        int pos = 4;
        while(num > 0)
        {
            base32_binary[i][pos] = (num % 2);
            num /= 2;
            pos--;
        }
        while(pos >= 0)
        {
            base32_binary[i][pos] = 0;
            pos--;
        }
        
    }
    for(int i = 0 ; i < 5 ; i++)
    {
        base32_binary[32][i] = -1;
    }
    
    /*base64 maps (0-25 indices) with (A-Z) , (26-51) with (a-z) , 
    (52-61) with (0-9) , 62 with '+' , 63 with '/' and 64 with '='*/
    char base64[65];
    
    base64[62] = '+';
    base64[63] = '/';
    base64[64] = '=';
    for(int i = 0 ; i < 63 ; i++)
    {
        if(i < 26)
        {
            base64[i] = i + 65;
        }
        else if(i < 52)
        {
            base64[i] = i + 71;
        }
        else if(i < 62)
        {
            base64[i] = i - 4;
        }
    }
    
    int n;
    scanf("%d",&n);
    
    while(n--)
    {
        char str[200];
        scanf("%s",str);
        
        /*combined_binary stores the base32 encoded string converted into binary
          E.g if base32 string is 'NBQ'
          combined_binary stores '011010000110000' (N => 16 =>'01101' , B => 1 => '00001' , Q => 16 => '10000')
        */
        int combined_binary[1000];
        int j = 0;
        
        for(int i = 0 ; str[i] != '\0' ; i++ )
        {
            int temp = 0;
            if(str[i] >= 'A' && str[i] <= 'Z')
            {
                temp = str[i] - 65;
            }
            else if(str[i] >= '2' && str[i] <= '7')
            {
                temp = str[i] - 24;  
            }
            else if(str[i] == '=')
            {
                temp = 32;
            }
                
            for(int k = 0 ; k < 5 ; k++)
            {
                combined_binary[j] = base32_binary[temp][k];
                j++;
            }
        }
        
        /*Checking the LSB ,if it is -1 that means, this particular byte is not part of original string (decoded) 
          and is used as padding
          so that is why j = z - 7 ,to remove that byte(or 8 bits) 
          from j (which stores the total number of bits the    decoded string has)
          
          We are not actually decoding the string but just finding the size of decoded string
        */
        for(int z = 7 ; z < j ; z = z + 8)
        {
            if(combined_binary[z] == -1)
            {
                j = z - 7;
            }
        }
        
        /*At this point j stores the number of bits(j / 8 = number of characters) that our decoded string has
        
          Converting to base64:
          In base64, we pad the string to make it multiple of 24
          We use -1 for padding
        */
        while(j % 24 != 0)
        {
            combined_binary[j] = -1;
            j++;
        }
        
        char final_base64[j];
        int q = 0;
        
        for(int z = 0 ; z < j ; z = z + 6)
        {
            int t = 0;
            int base = 32;
            
            if(combined_binary[z] == -1)
            {
                t = 64;
            }
            else
            {
                for(int k = z ; k < (z + 6) ; k++)
                {
                    if(combined_binary[k] != -1)
                    {
                        t += (base * combined_binary[k]);
                    }
                    base /= 2;
                }
            }
            final_base64[q++] = base64[t];
        }
        
        final_base64[q] = '\0';
        
        printf("%s\n",final_base64);
    }
    return 0;
}

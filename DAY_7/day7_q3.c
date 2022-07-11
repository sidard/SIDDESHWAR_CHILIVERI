
/* Author: Siddeshwar Chiliveri
Programming Language: C
IDE used: Eclipse
Compiler Used : GCC C Compiler
3. Write program to clear(0) bits CIS, CM2, CM1, CM0 in register "CMCON"
      if bits CHS3, CHS2, CHS1, CHS0 bits are set to 0x07 in register "ADCON0"


Algorithm:
1. Initialize some value in ADCON register with any value
2. Initialize some value in CMCON register with any value
3. Get the input value in ADCON register and compare with 0x07
4. If ADCON register is having 0x07 then clear the bits CHS3, CHS2, CHS1, CHS0 bits in CMCON register
  */

#include <stdio.h>8
int main()
{
    char ADCON0bits_t, CMCONbits_t,i;

    ADCON0bits_t = 0x3C; //Initialize with 0x3C
    CMCONbits_t = 0x02;//Initialize with 0x02
     printf("ADCON Register bits from bit 7 to bit 0:\n");


   for(i=7;i>=0;i--)
        printf("%d ", (ADCON0bits_t>>i)&1);
    
   printf("\nGive input value above 0x1C in ADCON0 Reg to clear bits CIS, CM2, CM1, CM0 in register CMCON\n");
   scanf("%hhx",&ADCON0bits_t);

   if(((ADCON0bits_t>>2)&(0x0F)) == 0x07)
                CMCONbits_t = 0xF0;
   printf("\n");
   printf("ADCON Register bits from bit 7 to bit 0:\n");
   for(i=7;i>=0;i--)
        printf("%d ", (ADCON0bits_t>>i)&1);
    printf("\n");
   printf("CMCON Register bits from bit 7 to bit 0:\n");
   for(i=7;i>=0;i--)
        printf("%d ", (CMCONbits_t>>i)&1);

    return 0;
}


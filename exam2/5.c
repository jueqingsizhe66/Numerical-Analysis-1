#include <stdlib.h>
#include <math.h>

int main()
{	
   int i, j;
   double romberg[4][4];
   romberg[0][0] = 62.805490362276984; 
   romberg[1][0] = 62.730178635116282;
   romberg[2][0] = 62.711424441887445; 
   romberg[3][0] = 62.706740475223107;

   for (j = 1; j < 4; j++)
       for (i = 1; i < 4; i++)
       {
          romberg[i][j] = (pow(4.0, j) * romberg[i][j-1] - 
                           romberg[i-1][j-1]) / (pow(4.0, j) - 1.0);
       }
   
   for (i = 0; i < 4; i++)
       for (j = 0; j <= 1; j++)
           printf("%d \t %d \t %3.12f \n", i, j, romberg[i][j]);
   
   return 0;
}

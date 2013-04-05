// Daniel Purcell
// MATH 4670
// Section 2.3, Problem 16.
// Use the Secant method to find x and y, such that
//             x + y = 20
//                    and
//            (x + sqrt(x)) * (y + sqrt(y)) = 155.55

#include <stdlib.h>
#include <math.h>

double f(double x);
void secant_method(double a, double b);

int main()
{
   secant_method(0, 20);
   return 0;
}

double f(double x)
{
   return (x + sqrt(x)) * (20 - x + sqrt(20 - x)) - 155.55;
}

void secant_method(double a, double b)
{
   double x[100];
   unsigned int k = 1;
   x[0] = a;
   x[1] = b;
   
   printf("%d \t %5.20f \t %5.20f \n", 0, x[0], 20 - x[0] );
   printf("%d \t %5.20f \t %5.20f \n", 1, x[1], 20 - x[1] );

   while( f(x[k+1]) < 155.55  )
   {
        while (x[k] >= 20)
             x[k] -= 19.9;
	if (x[k] <= 0)
             x[k] = .1;
        x[k+1] = x[k] - ( f(x[k]) * (x[k] - x[k-1]) ) / ( f(x[k]) - f(x[k-1]) );
        printf("%d \t %5.20f \t %5.20f \n", k+1, x[k+1], 20 - x[k+1] );
        k++;
   }
   printf("\n");
}

// Daniel Purcell
// MATH 4670
// Section 2.3, Problem 4.a.
// Use the Secant method to solve  the equation
//          2x cos 2x - (x - 2)^2 = 0     on [2, 3] and on [3, 4].

#include <stdlib.h>
#include <math.h>

double f(double x);
void secant_method(double a, double b);

int main()
{
   secant_method(2.00, 3.00);
   secant_method(3.00, 4.00);
   return 0;
}

double f(double x)
{
   return 2 * x * cos(2*x) - pow(x - 2, 2);
}

void secant_method(double a, double b)
{
   double x[100];
   unsigned int k = 1;
   x[0] = a;
   x[1] = b;
   
   printf("%d \t %5.20f \t %5.20f \n", 0, x[0], f(x[0]) );
   printf("%d \t %5.20f \t %5.20f \n", 1, x[1], f(x[1]) );

   while( f(x[k]) != f(x[k-1]) )
   {
        x[k+1] = x[k] - ( f(x[k]) * (x[k] - x[k-1]) ) / ( f(x[k]) - f(x[k-1]) );
        printf("%d \t %5.20f \t %5.20f \n", k+1, x[k+1], f(x[k+1]) );
        k++;
   }
   printf("\n");
}

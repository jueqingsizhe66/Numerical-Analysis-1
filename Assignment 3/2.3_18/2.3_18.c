// Daniel Purcell
// MATH 4670
// Section 2.3, Problem 18.
// Use the Secant method to find w in the equation
//             x(t) = g/(2w^2) * ( (e^(wt) - e^(-wt)) / 2 - sin (wt) )
//             when x(t) = 1.7, g = -32.17, and t = 1.

#include <stdlib.h>
#include <math.h>

#define E 2.71828182846

double f(double x);
void secant_method(double a, double b);

int main()
{
   secant_method(-0.999999, .999999);
   return 0;
}

double f(double x)
{
   return -1.7 + -32.17/(2*x*x) * ( (pow(E, x) - pow(E, -x))/2 - sin(x) );
}

void secant_method(double a, double b)
{
   double x[100];
   unsigned int k = 1;
   x[0] = a;
   x[1] = b;
   
   printf("%d \t %5.20f \t %5.20f \n", 0, x[0], f(x[0]) + 1.7);
   printf("%d \t %5.20f \t %5.20f \n", 1, x[1], f(x[1]) + 1.7);

   while( f(x[k]) != f(x[k-1]) )
   {
        x[k+1] = x[k] - ( f(x[k]) * (x[k] - x[k-1]) ) / ( f(x[k]) - f(x[k-1]) );
        printf("%d \t %5.20f \t %5.20f \n", k+1, x[k+1], f(x[k+1]) + 1.7 );
        k++;
   }
   printf("\n");
}

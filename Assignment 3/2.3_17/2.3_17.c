// Daniel Purcell
// MATH 4670
// Section 2.3, Problem 17.
// Use the Secant method to find h in the equation
//             V = L [0.5 * pi * r^2 - r^2 arcsin(h/r) - h(r^2 - h^2)^(1/2)]
//             when L = 10 ft, r = 1 ft, and V = 12.4 ft^3.

#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

double f(double x);
void secant_method(double a, double b);

int main()
{
   secant_method(-0.999999, .999999);
   return 0;
}

double f(double x)
{
   return -12.4 + 10 * ( 0.5 * PI - asin(x) - x * sqrt(1 - x * x));
}

void secant_method(double a, double b)
{
   double x[100];
   unsigned int k = 1;
   x[0] = a;
   x[1] = b;
   
   printf("%d \t %5.20f \t %5.20f \n", 0, x[0], f(x[0]) + 12.4);
   printf("%d \t %5.20f \t %5.20f \n", 1, x[1], f(x[1]) + 12.4);

   while( f(x[k]) != f(x[k-1]) )
   {
        x[k+1] = x[k] - ( f(x[k]) * (x[k] - x[k-1]) ) / ( f(x[k]) - f(x[k-1]) );
        printf("%d \t %5.20f \t %5.20f \n", k+1, x[k+1], f(x[k+1]) + 12.4 );
        k++;
   }
   printf("\n");
}

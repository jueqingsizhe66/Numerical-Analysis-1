// Daniel Purcell
// MATH 4670
// Section 2.3, Problem 4.d.
// Use the Secant method to solve  the equation
//          sin x - e^(-x) = 0     on [0, 1], on [3, 4], and on [6, 7].

#include <stdlib.h>
#include <math.h>

#define E 2.71828182846
double f(double x);
void secant_method(double a, double b);

int main()
{
   secant_method(0, 1);
   secant_method(3, 4);
   secant_method(6, 7);
   return 0;
}

double f(double x)
{
   return sin(x) - pow(E, -x);
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

// Daniel Purcell
// MATH 4670
// Section 2.4, Problem 7.c.
// Use Newton's Method to solve  the equation
//          x^3 - 3x^2 * (2^-x) + 3x(4^-x) + 8^-x = 0           on [0, 1].

#include <stdlib.h>
#include <math.h>

#define E 2.71828182846

double f(double x);
double fprime(double x);
void newton_method(double a, double b);

int main()
{
   newton_method(0.2, 0.8);
   return 0;
}

double f(double x)
{
   return pow(x, 3) - 3 * x*x * pow(2, -x) + 3 * x * pow(4, -x) + pow(8, -x);
}

double fprime(double x)
{
   return 3 * x*x - ((3 * x*x * -log(2) + 6 * x) * pow(2, -x) )
        + ((3*x * -log(4) + 3) * pow(4, -x)) + (-log(8) * pow(8, -x) );
}

void newton_method(double a, double b)
{
   double x[3];
   unsigned int k;
   x[0] = a;
   x[1] = b;

   printf("%d \t %5.20f \t %5.20f \n", 0, x[0], f(x[0]) );
   printf("%d \t %5.20f \t %5.20f \n", 1, x[1], f(x[1]) );

   for(k = 1; k < 50 && f(x[1]) >= fprime(x[1]); k++ )
   {
        x[2] =  x[1] - f(x[1])/fprime(x[1]);
        x[0] = x[1];
        x[1] = x[2];
        printf("%d \t %5.20f \t %5.20f \n", k+1, x[2], f(x[2]) );
   }

   printf("\n");
}


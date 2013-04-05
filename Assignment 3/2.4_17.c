// Daniel Purcell
// MATH 4670
// Section 2.4, Problem 17.
// Use Newton's Method to find the minimal interest rate, i,
//          so that A = 750000

#include <stdlib.h>
#include <math.h>

#define E 2.71828182846

double f(double x);
double fprime(double x);
void newton_method(double a, double b);

int main()
{
   newton_method(0.001, .1);
   return 0;
}

double f(double x)
{
   return -750000 + 1500/x * ( pow(1 + x, 240) - 1);
}

double fprime(double x)
{
   return -1500/(x*x) * (pow(1+x, 240) - 1) + 1500/x * 240 * pow(1+x, 239);
}

void newton_method(double a, double b)
{
   double x[3];
   unsigned int k;
   x[0] = a;
   x[1] = b;
   
   printf("%d \t %5.20f \t %5.20f \n", 0, x[0], f(x[0]) + 750000);
   printf("%d \t %5.20f \t %5.20f \n", 1, x[1], f(x[1]) + 750000);

   for (k = 1; k < 30 && f(x[1]) != f(x[0]); k++ )
   {
        x[2] = x[1] - f(x[1])/fprime(x[1]);
	x[0] = x[1];
	x[1] = x[2];
        printf("%d \t %5.20f \t %5.20f \n", k+1, x[2], f(x[2]) + 750000);
   }
   printf("\n");
}

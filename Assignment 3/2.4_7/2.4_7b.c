// Daniel Purcell
// MATH 4670
// Section 2.4, Problem 7.b.
// Use Newton's Method to solve  the equation
//          cos(x + sqrt(2)) + x(x/2 + sqrt(2)) = 0		on [-2, -1].

#include <stdlib.h>
#include <math.h>

#define E 2.71828182846

double f(double x);
double fprime(double x);
void newton_method(double a, double b);

int main()
{
   newton_method(-2, -1);
   return 0;
}

double f(double x)
{
   return cos(x + sqrt(2)) + x * (x/2 + sqrt(2));
}

double fprime(double x)
{
   return -1 * sin(x + sqrt(2)) + x + sqrt(2);
}

void newton_method(double a, double b)
{
   double x[3];
   unsigned int k;
   x[0] = a;
   x[1] = b;
   
   printf("%d \t %5.20f \t %5.20f \n", 0, x[0], f(x[0]) );
   printf("%d \t %5.20f \t %5.20f \n", 1, x[1], f(x[1]) );

   for(k = 1; k < 30 && f(x[1]) > 0; k++ )
   {
        x[2] = x[1] - f(x[1])/fprime(x[1]);
	x[0] = x[1];
	x[1] = x[2];
        printf("%d \t %5.20f \t %5.20f \n", k+1, x[2], f(x[2]) );
   }
   printf("\n");
}

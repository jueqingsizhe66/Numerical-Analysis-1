#include <stdlib.h>
#include <math.h>

double gauss(int n);
double f(double x);

int main()
{  
   int n;
   for (n = 2; n <= 5; n++)
      printf("%d \t %3.11f \n", n, gauss(n));
   return 0;
}

double gauss(int n)
{
   if (n == 2)
   {
     return f(0.5773502692) + f(-0.5773502692);
   }
   else if (n == 3)
   {
     return 0.5555555556 * f(0.7745966692) + 0.8888888889 * f(0.0000000000) + 
	    0.5555555556 * f(-0.7745966692);
   }
   else if (n == 4)
   {
     return 0.3478548451 * f(0.8611363116) + 0.6521451549 * f(0.3399810436) + 
	    0.6521451549 * f(-0.3399810436) + 0.3478548451 * f(-0.8611363116);
   }
   else if (n == 5)
   {
     return 0.2369268850 * f(0.9061798459) + 0.4786286705 * f(0.5384693101) +
	    0.5688888889 * f(0.0000000000) + 0.4786286705 * f(-0.5384693101) +
	    0.2369268850 * f(-0.9061798459);
   }
   else
     return 0.0;
}

double f(double x)
{
   return 1.0 / ( sqrt(pow(x - 5.0, 2) + pow(x - 7.0, 2) + pow(3.0, 2) ) );
}

#include <stdio.h>
#include <math.h>

#define PI 3.14159265

double f(double x);

int main()
{
   int n = 20, i;
   double w = 8, a = 10, b = 0, t, h;
   h = (b - a) / (double) n;
   for (i = n; i >= 0; i--)
   {
      t = a + i * h;
      w = w + h * f(t);
      printf("%d \t %1.8f \t %3.8f \n", i, t, w);
   }
   
   return 0;
}

double f(double x)
{
   return -0.6 * PI * (0.1 * 0.1) * sqrt(-64.34) * sqrt(x)/(PI*x*x);
} 

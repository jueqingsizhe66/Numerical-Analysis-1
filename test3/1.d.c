#include <stdio.h>
#include <math.h>


double f(double t, double w);

int main()
{
   int n = 20, i;
   double w = 1, a = 0, b = 1, t, h;
   h = (b - a) / (double) n;
   for (i = 0; i <= n; i++)
   {
      t = a + i * h;
      w = w + h * f(t, w);
      printf("%d \t %1.8f \t %3.8f \t \n", i, t, w);
   }
   
   return 0;
}

double f(double t, double w)
{
   return cos(2*t) + sin(3*t);
} 

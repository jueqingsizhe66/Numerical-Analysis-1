#include <stdio.h>
#include <math.h>


double f(double t, double w);
double exact(double t);

int main()
{
   int n = 20, i;
   double w = 1, a = 2, b = 3, t, h;
   h = (b - a) / (double) n;
   for (i = 0; i <= n; i++)
   {
      t = a + i * h;
      w = w + h * f(t + .5 * h, w + h * .5 * f(t, w));
      printf("%d \t %1.8f \t %3.8f \t %3.8f \t %3.8f \n", i, t, w, exact(t), 
                                                                  exact(t) - w);
   }
   
   return 0;
}

double f(double t, double w)
{
   return 1.0 + (t - w)*(t - w);
} 

double exact(double t)
{
  return t + 1.0/(1.0 - t);
}

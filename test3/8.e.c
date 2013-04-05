#include <stdio.h>
#include <math.h>


double f(double t, double w);
double y2(double t, double y);
double y3(double t, double y);
double exact(double t);
double taylor(double t, double y, double h);

int main()
{
   int n = 25, i;
   double w = 0, a = 1, b = 2, t, h;
   h = (b - a) / (double) n;
   for (i = 0; i <= n; i++)
   {
      t = a + i * h;
      w = w + h * taylor(t, w, h);
      printf("%d \t %1.8f \t %3.8f \t %3.8f \t %3.8f \n", i, t, w, exact(t), 
		      				               exact(t) - w);
   }
   
   return 0;
}

double f(double t, double w)
{
   return 2/t * w + t*t * exp(t);
}

double y2(double t, double y)
{
   return (-2/(t * t)) * y + 2 * t * exp(t) + t * t * exp(t) + 2 * t * f(t, y);
}

double y3(double t, double y)
{
  return (-4/(t*t*t) * y + 2*exp(t) + t*t*exp(t)) + (-2/(t*t) * f(t, y))
	  + f(t, y) * 2 + 2 * t * y2(t, y);
}

double exact(double t)
{
   return t * t * (exp(t) - exp(1));
}

double taylor(double t, double y, double h)
{
   return f(t, y) + h/2 * y2(t, y) + (h*h*h)/6 * y3(t, y);
}

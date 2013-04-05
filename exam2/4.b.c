#include <stdlib.h>
#include <math.h>

double f(double x, double y);
double trapezoid2d(int n, int m, double a, double b, double c, double d);


int main()
{
   int n, m;
   double a, b, c, d;
   a = 1;
   b = 4;
   c = 0;
   d = 3;
   for (m = n = 6; n <= 48; m = n = n * 2)	   
      printf("%d \t %d \t %3.15f \n", n, m, trapezoid2d(n, m, a, b, c, d));
   return 0;
}

double f(double x, double y)
{
   return cos(x) + 2 * x * y;
}

double trapezoid2d(int n, int m, double a, double b, double c, double d)
{
   double h, k, sum[3], i, j, xi, yj;
   h = (b - a) / n;
   k = (d - c) / m;
   sum[0] = sum[1] = sum[2] = 0.0;
   
   for (i = 1; i < n; i++)
   {
      xi = a + (double) i * h;
      sum[0] = sum[0] + f(xi, c) + f(xi, d);
   }
   
   for (j = 1; j < n; j++)
   {
      yj = c + (double) j * k;
      sum[1] = sum[1] + f(a, yj) + f(b, yj);
   }

   for (i = 1; i < n; i++)
   {
      for (j = 1; j < n; j++)
      {
         xi = a + (double) i * h;
	 yj = c + (double) j * k;
	 sum[2] = sum[2] + f(xi, yj);
      }
   }

   return (.25) * h * k * (2 * sum[0] + 2 * sum[1] + 4 * sum[2] + f(a, c)
          + f(a, d) + f(b, c) + f(b, d) );
}

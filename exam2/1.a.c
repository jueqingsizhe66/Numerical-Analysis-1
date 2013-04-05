#include<stdlib.h>
#include<math.h>

double f(double x);
void trapezoid(double a, double b);
void output(int n, double val, double exact);

int main()
{
   double a, b;
   a = -1;
   b = 3;
   trapezoid(a, b); 
   return 0;
}

double f(double x)
{
   return exp(x) * pow(sin(x), 2);
}

void trapezoid(double a, double b)
{
   int n = 10000;
   double sum, h, exact;
   sum = 0.0;
   int i;
   exact = 8.97050567528;
   while (exact - sum > 0.00000000009) 
   {
      h = (b - a) / (n);
      sum = 0.0;
      for (i = 1; i < n - 1; i++)
	 sum += f(a + i * h);
      sum = (h/2) * ( f(a) + f(b) + 2 * sum );
      output(n, sum, exact);
      n += 10000;
      
   }
}

void output(int n, double val, double exact)
{
   printf("%d \t %3.11f \t %3.11f \n", n, val, exact - val);
}

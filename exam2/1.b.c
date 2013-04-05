#include<stdlib.h>
#include<math.h>

double f(double x);
void simpson(double a, double b);
void output(int n, double val, double exact);
double max(double x, double y);
double min(double x, double y);

int main()
{
   double a, b;
   a = -1;
   b = 3;
   simpson(a, b); 
   return 0;
}

double f(double x)
{
   return exp(x) * pow(sin(x), 2);
}

double max(double x, double y)
{
   return (x >= y) ? x : y;
}

double min(double x, double y)
{
   return (x <= y) ? x : y;
}

void simpson(double a, double b)
{
   int n = 10;
   double sum, sum_one, sum_two, h, exact;
   sum = 0.0;
   int i;
   exact = 8.97050567528;
   while (!(max(exact, sum) - min(exact, sum) < 0.00000000009 
		      && max(exact, sum) - min(exact, sum) >= 0)) 
   {
      h = (b - a) / n;
      sum = sum_one = sum_two = 0.0;
      for (i = 1; i <= ( (n/2) - 1) ; i++)
	 sum_one += f(a + (2 * i) * h);
      sum_one *= 2;
      for (i = 1; i <= (n/2); i++)
	 sum_two += f(a + (2 * i - 1) * h);
      sum_two *= 4; 
      sum = (h/3) * (f(a) + sum_one + sum_two + f(b));
      output(n, sum, exact);
      n += 10;
   }
}

void output(int n, double val, double exact)
{
   printf("%d \t %3.11f \t %3.11f \n", n, val, exact - val);
}

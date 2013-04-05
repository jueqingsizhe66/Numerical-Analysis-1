#include<stdlib.h>
#include<math.h>

double f(double x);
void simpson(double a, double b);
void output(int n, double val);

int main()
{
   double a, b;
   a = (1.0/4.0);
   b = 7;
   simpson(a, b); 
   return 0;
}

double f(double x)
{
   return sqrt(1 + pow(-pow(x, 2), 2));
}

void simpson(double a, double b)
{
   int n = 10;
   double sum, sum_one, sum_two, h, previous;
   sum = 0.0;
   previous = -1.0;
   int i;
   while (sum != previous) 
   {
      previous = sum;   
      h = (b - a) / n;
      sum = sum_one = sum_two = 0.0;
      for (i = 1; i <= ( (n/2) - 1) ; i++)
	 sum_one += f(a + (2 * i) * h);
      sum_one *= 2;
      for (i = 1; i <= (n/2); i++)
	 sum_two += f(a + (2 * i - 1) * h);
      sum_two *= 4; 
      sum = (h/3) * (f(a) + sum_one + sum_two + f(b));
      output(n, sum);
      n += 10;
   }
}

void output(int n, double val)
{
   printf("%d \t %3.11f \n", n, val);
}

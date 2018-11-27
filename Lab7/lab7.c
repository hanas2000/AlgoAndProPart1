#include <stdarg.h>
#include <stdio.h>
double mult(int n,...)
{
    va_list ptr;
	va_start(ptr, n);
	double mult = va_arg(ptr,double);
	for (int i = 1; i < n;i++ ) {
		double a = va_arg(ptr,double);
		mult *= a;
	}
	va_end(ptr);
	return mult;
}
int main()
{
printf("Mult1 %lf\nMult2 %lf\nMult3 %lf\n", mult(3,1.0,2.0,3.0), mult(7,1.2,2.2,4.2,6.2,79.2,4.2,3.2), mult(11,1.3,2.4,3.3,4.4,5.3,6.3,7.5,8.2,9.7,10.5,11.6));
return 0;
}


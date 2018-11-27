#include <stdio.h>
#include <math.h>

int main()
{
    double a,b,k;
    float d,c,l;
    
    printf("Enter  double a:");
    scanf("%lf",&a);
    printf("Enter double b:");
    scanf("%lf",&b);
    printf("Enter float d:");
    scanf("%f",&d);
    printf("Enter float c:");
    scanf("%f",&c);
    
    k=(pow((a-b),2)-(pow(a,2)-2*a*b))/(pow(b,2));
    l=(pow((d-c),2)-(pow(d,2)-2*d*c))/(pow(c,2));
    
    printf("Result DOUBLE: %lf\n",k);
    printf("Result FLOAT: %f\n",l); 
    
    return 0;
}


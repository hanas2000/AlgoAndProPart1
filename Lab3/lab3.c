#include <stdio.h>
#include <math.h>
int main(){

    double b=3.14,f=(9*b/5-b/5)/10,x=b/5,result1=0;

    for(;x<9*b/5;x+=f)
    {
        result1=-log(fabs(2*sin(x/2)));
    
        double result2=0,result3=0;
    
        for(int n=1;n<41;n++)
        {
            double el;
            el=cos(n*x)/n;
            result2+=el;
        }
    
        int n=1;
        double el;
    
        do
        {
            el=cos(n*x)/n;
            result3+=el;
            n++;
        }while(fabs(el)>0.0001);
    
        printf("Result1: %lf\n",result1);
        printf("Result2: %lf\n",result2);
        printf("Result3: %lf\n",result3);
    }

}

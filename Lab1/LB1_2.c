#include <stdio.h>
#include <math.h>


int main()
{
    int m,n,k;
    
    printf("Enter m:");
    scanf("%d",&m);
    printf("Enter n:");
    scanf("%d",&n);
    
    k=++n*++m;
    
    printf("Result: %d\n",k);
    
    k=m++<n;
    
    printf("Result: %d\n",k);
    
    k=n++>m;
    
    printf("Result: %d\n",k);
    
    return 0;
}

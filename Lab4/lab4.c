#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 10
int main()
{
    int a, i, k;
    int b[ARR_SIZE];
    int d[ARR_SIZE];
    int l=0;
    do
    {
    
        printf("Put the number for array:");
        scanf("%d",&a);
    } while(a<0||a>ARR_SIZE);
    
    
    for(i=0;i<a;i++)
    {
            b[i]=rand()%2;
            printf("%d ",b[i]);
    }
    printf("\n");
    
    for(k=0;k<a;k++)
    {
        if(!l && b[k]==0)
        {
            l++;
            continue;
        }
          
        d[k-l] = b[k];
        printf("%d ",d[k-l]);
    }
    printf("\n");
    
    int f=0;
    for(int y=0;y<a-l;y++)
        {
            int c = y + f;
            if(y && y%2==0 && c < ARR_SIZE - 1)
            {
                b[c] = d[y];
                printf("%d ",b[c]);
                f++;
                b[c + 1] = d[y-1]+2;
                printf("%d ",b[y+f]);
                
            }else if(c < ARR_SIZE)
            {
                b[c] = d[y];
                printf("%d ",b[c]);
            }
        }
    printf("\n");
    return 0;
}

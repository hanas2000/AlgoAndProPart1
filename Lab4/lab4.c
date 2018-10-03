#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    int a;
    do
    {
        printf("Put the number for array:");
        scanf("%d",&a);
    }while(a<0||a>100);
    int b[a];
    for(int i=0;i<a;i++)
        {
            b[i]=rand()%2;
            printf("%d ",b[i]);
        }
    printf("\n");
    int d[a-1];
    int l=0;
    for(int k=0;k<a;k++)
        {
            if(b[k]==0&&l==0)
            {
            l++;
            }
            else 
            {
            d[k-l]=b[k];
            printf("%d ",d[k-l]);
            }
        }
    printf("\n");
    int h[200];
    int f=0;
    for(int y=0;y<a-1;y++)
        {
            if(y!=0&&y%2==0)
            {
                h[y+f]=d[y];
                printf("%d ",h[y+f]);
                f++;
                h[y+f]=d[y-1]+2;
                printf("%d ",h[y+f]);
            }else
            {
                h[y+f]=d[y];
                printf("%d ",h[y+f]);
            }
        }
    printf("\n");
    return 0;
}

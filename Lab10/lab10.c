#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int *fill(int n)
{
    int *mas;
    mas=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        *(mas + i*sizeof(int))=rand()%10;
    }
    return mas;
}
void *print(int *mas,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d",*(mas + i*sizeof(int)));
    }
    printf("\n");
    return 0;
}
void *delete(int *mas,int id,int n)
{
    int temp[n-1];
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(i==id-1)
        {
            c++;
        }
        temp[i]=*(mas + (i+c)*sizeof(int));
    }
    if((mas = realloc(mas,(n - c)*sizeof(int))) == NULL)
    {
        return NULL;
    }
    for(int i=0;i<n-1;i++)
    {
        *(mas + i*sizeof(int))=temp[i];
    }
    return mas;
}
void *add(int *mas,int id,int n)
{
    int temp[n];
    int c=0;
    for(int i=0;i<n-1;i++)
    {
        if(i==id-1)
        {
            temp[i]=rand()%10;
            c++;
        }
        temp[i+c]=*(mas+(i)*sizeof(int));
    }
    if((mas=realloc(mas,n*sizeof(int)))==NULL)
    {
        return NULL;
    }
    for(int i=0;i<n;i++)
    {
        *(mas+i*sizeof(int))=temp[i];
    }
    return mas;
}
int main()
{
    int n,id,ad;
    printf("Put the number of elements in array: ");
    scanf("%d",&n);
    int *arr=fill(n);
    print(arr,n);
    printf("Put the number of element you want to delete: ");
    scanf("%d",&id);
    delete(arr,id,n);
    print(arr,n-1);
    printf("Put the number of element you want to add: ");
    scanf("%d",&ad);
    add(arr,ad,n);
    print(arr,n);
    free(arr);
    return 0;
}


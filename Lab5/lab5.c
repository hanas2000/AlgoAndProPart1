int swap(int a[5][5],int arr[5][5],int n,int m)
{
    arr[n][m]=a[n+1][m];
    a[n+1][m]=a[n][m];
    a[n][m]=arr[n][m];
    return 0;
}

int main()
{

int a[5][5];

int i,j;
    int arr[5][5];
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            a[i][j]=rand()%5;
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
        {
            if(a[j][2]>a[j+1][2])
            {
                for(int u=0;u<5;u++)
                {
                    swap(a,arr,j,u);
                    
                }
            }
        }
        
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
return 0;
}


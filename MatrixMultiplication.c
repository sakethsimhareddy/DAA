#include<stdio.h>
#include<time.h>
#include<windows.h>
#define N 5
int c[N][N];
void MatrixMultiplication(int a[N][N],int b[N][N])
{
    int i,j,k;
    for(i=0;i<N;i++)
    {
        for ( j = 0; j < N; j++)
        {
            for ( k = 0; k < N; k++)
            {
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
            
        }
        
    }
}
int main()
{
    int i,j,a[N][N],b[N][N];
    clock_t start,end;
    for(i=0;i<N;i++)
    {
        for ( j = 0; j < N; j++)
        {
            a[i][j]=rand()%999;
            b[i][j]=rand()%999;
            c[i][j]=0;

        }
        
    }
    start=clock();
    MatrixMultiplication(a,b);
    Sleep(1000);
    end=clock();
        for(i=0;i<N;i++)
    {
        for ( j = 0; j < N; j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
        
    }
    printf("Time taken is %f",((double)(end-start))/CLOCKS_PER_SEC -1);
}
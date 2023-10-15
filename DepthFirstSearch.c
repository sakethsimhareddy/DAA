#include<stdio.h>
#define N 5
int c[N][N],v[N]={0};
void dfs(int i)
{
    int j;
    v[i]=1;
    printf("%d",i);
    for(j=0;j<N;j++)
    {
        if (!v[j] && c[i][j])
        {
            dfs(j);
        }
        
    }
}
int main()
{
    int i,j,s;
    printf("\n enter the adjacncy matrix for %d nodes",N);
    for (i = 0; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
            scanf("%d",&c[i][j]);
        } 
    }
    printf("enter the strat vertex:");
    scanf("%d",&s);
    dfs(s);
    return 0;
}
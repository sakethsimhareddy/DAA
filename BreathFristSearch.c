#include<stdio.h>
#define N 4
int v[N]={0},c[N][N];
void bfs(int i)
{
    int j,q[N],f,r;
    f=r=0;
    v[i]=1;
    printf("%d",i);
    for ( j = 0; j < N; j++)
    {
        if (!v[j] && c[i][j])
        {
            q[r++]=j;
        }
    }
    while (f<r)
    {
         bfs(q[f++]);
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
    bfs(s);
    return 0;
}
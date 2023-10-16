#include <stdio.h>
int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void floyds(int c[10][10], int n)
{
    int i, k, j;
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (i == j)
                {
                    c[i][j] = 0;
                }
                else
                {
                    c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
                }
            }
        }
    }
}
int main()
{
    int c[10][10], n, i, j;
    printf("Enter the number of vertices:");
    scanf("%d", &n);
    printf("\nEnter adjacency matrix:\n");
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            scanf("%d", &c[i][j]);
        }
    }
    floyds(c, n);
    printf("\nThe minimum spanning tree is :\n");
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            printf("%5d ", c[i][j]);
        }
        printf("\n");
    }
     for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            printf("<%d,%d>=%d ",i,j, c[i][j]);
        }
    }
    return 0;
}
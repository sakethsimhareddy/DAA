#include <stdio.h>
#define infinity 999
#define N 10

void prim(int n, int cost[N][N]) {
    int i, u, count = 1, min,j,v,mincost=0;
    int flag[N]={0}; 
    flag[1]=1;
    while (count < n) { 
        min = infinity;
        for (i = 1; i <= n; i++) {
            for ( j = 1; j <= n; j++)
            {
            
            if (cost[i][j] < min && flag[i]!=0) { 
                min = cost[i][j];
                u = i;
                v=j;
            }
            }
        }

        if (flag[u]==0 || flag[v]==0)
        {
             printf("%d -> %d, cost = %d \n",u, v,cost[u][v]);
             flag[u]=flag[v]=1;
             mincost=mincost+cost[u][v];
             cost[u][v]=cost[v][u]=infinity;
        }
        count++;
        
    }
    printf("min cost = %d",mincost);
}

int main() {
    int n, i, j, cost[N][N];
    printf("Enter the number of vertices:");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = infinity;
            }
        }
    }
    prim(n,cost);
    return 0;
}

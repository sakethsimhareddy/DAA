#include <stdio.h>
#define infinity 999
#define N 10

void dij(int n, int v, int cost[N][N], int dis[]) {
    int i, u, count = 1, min;
    int flag[N]; 

    for (i = 1; i <= n; i++) {
        dis[i] = cost[v][i];
        flag[i] = 0;
    }

    flag[v] = 1;

    while (count < n) { 
        min = infinity;
        for (i = 1; i <= n; i++) {
            if (dis[i] < min && !flag[i]) { 
                min = dis[i];
                u = i;
            }
        }

        flag[u] = 1;
        count++;

        for (i = 1; i <= n; i++) {
            if (dis[u] + cost[u][i] < dis[i] && !flag[i]) {
                dis[i] = dis[u] + cost[u][i];
            }
        }
    }
}

int main() {
    int n, v, i, j, cost[N][N], dis[N];
    printf("Enter the number of vertices:");
    scanf("%d", &n);
    printf("\nEnter the source vertex:");
    scanf("%d", &v);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = infinity;
            }
        }
    }
    dij(n, v, cost, dis);
    printf("\nThe shortest path from %d to all other nodes is:\n", v);
    for (i = 1; i <= n; i++) {
        if (i != v) {
            printf("%d -> %d, cost = %d\n", v, i, dis[i]);
        }
    }
    return 0;
}

#include <stdio.h>
#define infinity 999
#define N 10

struct Edge {
    int u, v, cost;
};

void kruskals(int n, int cost[N][N]) {
    int i, j, mincost = 0;
    struct Edge edges[N * N]; 
    int parent[N];

    int edgeCount = 0;
    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (cost[i][j] != infinity) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].cost = cost[i][j];
                edgeCount++;
            }
        }
    }

    for (i = 0; i < edgeCount - 1; i++) {
        for (j = i + 1; j < edgeCount; j++) {
            if (edges[i].cost > edges[j].cost) {
                struct Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
    for (i = 1; i <= n; i++) {
        parent[i] = i;
    }

    printf("Edges in the minimum spanning tree:\n");
    for (i = 0; i < edgeCount; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int uParent = parent[u];
        int vParent = parent[v];
        if (uParent != vParent) {
            printf("%d -> %d, cost = %d\n", u, v, edges[i].cost);
            mincost += edges[i].cost;
            for (j = 1; j <= n; j++) {
                if (parent[j] == vParent) {
                    parent[j] = uParent;
                }
            }
        }
    }

    printf("Minimum cost = %d\n", mincost);
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
    kruskals(n, cost);
    return 0;
}

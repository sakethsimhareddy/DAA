#include <stdio.h>
#define N 100

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

void knapSack(int MaxWeight, int weights[], int profits[], int n) {
    int x[n + 1], cost[n + 1][MaxWeight + 1], w, i;

    for (i = 0; i <= n; i++) {  
        for (w = 0; w <= MaxWeight; w++) {
            if (i == 0 || w == 0) {
                cost[i][w] = 0;
            } else if (weights[i - 1] <= w) {  
                cost[i][w] = max(cost[i - 1][w], profits[i - 1] + cost[i - 1][w - weights[i - 1]]);
            } else {
                cost[i][w] = cost[i - 1][w];
            }
        }
    }

    printf("The optimal profit is %d\n", cost[n][MaxWeight]);
    w = MaxWeight;
    for (i = n; i > 0; i--) {  
        if (cost[i][w] > cost[i - 1][w]) {
            x[i] = 1;
            w = w - weights[i - 1];  
        } else {
            x[i] = 0;
        }
    }

    printf("\nItems included in the bag are : \n");
    printf("sno Profit Weight\n");
    for (i = 1; i <= n; i++) {  
        if (x[i] == 1) {
            printf("%d   %d       %d\n", i, profits[i - 1], weights[i - 1]);
        }
    }
}

int main() {
    int i, profits[N], weights[N], maxWeight, n;
    printf("\nEnter the number of items: ");
    scanf("%d", &n);
    printf("\nEnter maximum weight capacity of the sack: ");
    scanf("%d", &maxWeight);
    printf("\nEnter weights and profits:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &profits[i]);
    }
    knapSack(maxWeight, weights, profits, n);
    return 0;
}

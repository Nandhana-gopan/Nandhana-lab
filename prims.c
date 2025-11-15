#include <stdio.h>
#include <limits.h>

#define MAX 10

int main() {
    int n;
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int i, j, edges = 0, u, v, min, total = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    visited[0] = 1;  // Start from vertex 0

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        min = INT_MAX;
        u = v = -1;

        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        visited[v] = 1;
        total += min;

        printf("%d -> %d   cost = %d\n", u, v, min);

        edges++;
    }

    printf("\nTotal cost of the Minimum Spanning Tree = %d\n", total);

    return 0;
}

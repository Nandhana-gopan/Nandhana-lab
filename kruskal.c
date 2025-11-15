#include <stdio.h>
#include <limits.h>
#define MAX 10

struct Edge 
{
    int u, v, cost;
};

int parent[MAX];

int find(int x)
 {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);   
}

void unionSet(int a, int b) {
    a = find(a);
    b = find(b);
    parent[b] = a;  
}

int main() {
    int n;
    int cost[MAX][MAX];
    struct Edge edgesList[MAX * MAX];
    int i, j, k = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (i = 0; i < n; i++)
        parent[i] = i;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {     
            if (cost[i][j] != 0) {
                edgesList[k].u = i;
                edgesList[k].v = j;
                edgesList[k].cost = cost[i][j];
                k++;
            }
        }
    }

    for (i = 0; i < k - 1; i++) {
        for (j = 0; j < k - 1 - i; j++) {
            if (edgesList[j].cost > edgesList[j + 1].cost) {
                struct Edge temp = edgesList[j];
                edgesList[j] = edgesList[j + 1];
                edgesList[j + 1] = temp;
            }
        }
    }

    int total = 0;
    int edgesChosen = 0;

    printf("\nEdges in Minimum Spanning Tree (Kruskal):\n");

    for (i = 0; i < k && edgesChosen < n - 1; i++) {
        int u = edgesList[i].u;
        int v = edgesList[i].v;

        if (find(u) != find(v)) {
            unionSet(u, v);
            total += edgesList[i].cost;

            printf("%d -> %d   cost = %d\n", u, v, edgesList[i].cost);

            edgesChosen++;
        }
    }

    printf("\nTotal cost of the Minimum Spanning Tree = %d\n", total);

    return 0;
}

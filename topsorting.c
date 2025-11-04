#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];  // adjacency matrix
int visited[MAX];
int stack[MAX];
int top = -1;
int n; // number of vertices

void push(int v) {
    stack[++top] = v;
}

int pop() {
    return stack[top--];
}

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i])
            dfs(i);
    }
    push(v); // push to stack after exploring all neighbors
}

void topologicalSort() {
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);

    printf("Topological Order: ");
    while (top != -1)
        printf("%d ", pop());
    printf("\n");
}

int main() {
    int edges, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &src, &dest);
        adj[src][dest] = 1;
    }

    topologicalSort();

    return 0;
}

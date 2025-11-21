#include <stdio.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void push(int v) 
{ 
    stack[++top] = v; 
}
int pop()
 {
    return stack[top--]; 
}
int isEmpty()
{
    
    return top == -1;
}

int main() {
    int n, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    for (int i = 0; i < n; i++) 
    visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");

    push(start);

    while (!isEmpty()) 
    {
        int v = pop();

        if (!visited[v])
        {
            visited[v] = 1;
            printf("%d ", v);

            // Push neighbors in reverse order (optional)
            for (int i = n - 1; i >= 0; i--) {
                if (adj[v][i] == 1 && !visited[i])
                 {
                    push(i);
                }
            }
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int adj[MAX][MAX], visited[MAX];

void bfs(int start) {
    int queue[MAX], front = -1, rear = -1, node;
    visited[start] = 1;
    queue[++rear] = start;
    while (front != rear) {
        node = queue[++front];
        printf("%d ", node);
        for (int i = 0; i < MAX; i++) {
            if (adj[node][i] && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int start) {
    printf("%d ", start);
    visited[start] = 1;
    for (int i = 0; i < MAX; i++) {
        if (adj[start][i] && !visited[i]) dfs(i);
    }
}

int main() {
    int edges, src, dest, choice, start;
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        adj[src][dest] = adj[dest][src] = 1;
    }
    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("\n1. BFS\n2. DFS\nChoice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        bfs(start);
    } else if (choice == 2) {
        dfs(start);
    } else {
        printf("Invalid choice\n");
    }
    getch();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[10];
int visited[10];

void addEdge(int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = adj[src];
    adj[src] = newNode;
}

void bfs(int start) {
    int queue[10], front = -1, rear = -1, vertex;
    visited[start] = 1;
    queue[++rear] = start;
    while (front != rear) {
        vertex = queue[++front];
        printf("%d ", vertex);
        struct Node* temp = adj[vertex];
        while (temp) {
            if (!visited[temp->vertex]) {
                queue[++rear] = temp->vertex;
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

void dfs(int vertex) {
    struct Node* adjList = adj[vertex];
    struct Node* temp = adjList;
    visited[vertex] = 1;
    printf("%d ", vertex);
    while (temp) {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex]) dfs(connectedVertex);
        temp = temp->next;
    }
}

int main() {
    int edges, src, dest, choice, start;
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
        addEdge(dest, src);  // For undirected graph
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
    return 0;
}
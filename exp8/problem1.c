#include <stdio.h>
#include <stdlib.h>

// Define the structure for an adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Define the structure for an adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Define the structure for a graph with V vertices
struct Graph {
    int V;
    struct AdjList* array;
};

// Create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists. Size of array will be V
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head NULL
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest. A new node is added to the adjacency list of src.
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Remove an edge from an undirected graph
void removeEdge(struct Graph* graph, int src, int dest) {
    struct AdjListNode* temp = graph->array[src].head;
    struct AdjListNode* prev = NULL;

    // If the head node itself holds the destination to be deleted
    if (temp != NULL && temp->dest == dest) {
        graph->array[src].head = temp->next; // Change head
        free(temp);                          // Free old head
        return;
    }

    // Search for the destination to be deleted, keep track of the previous node
    while (temp != NULL && temp->dest != dest) {
        prev = temp;
        temp = temp->next;
    }

    // If destination was not present in adjacency list
    if (temp == NULL)
        return;

    // Unlink the node from the linked list
    prev->next = temp->next;

    free(temp); // Free memory
}

// Print the adjacency list representation of the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Driver program to test above functions
int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("Graph before removing any edge:");
    printGraph(graph);

    // Remove an edge between 1 and 4
    removeEdge(graph, 1, 4);

    printf("\nGraph after removing edge between 1 and 4:");
    printGraph(graph);

    return 0;
}

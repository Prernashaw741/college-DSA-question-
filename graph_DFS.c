#include <stdio.h>
#include <stdlib.h>

// Structure for an adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Structure for an adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Structure for a graph
struct Graph {
    int vertices;
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with 'V' vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    graph->vertices = vertices;

    // Allocate memory for an array of adjacency lists
    graph->array = (struct AdjList*)malloc(vertices * sizeof(struct AdjList));
    if (graph->array == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // For an undirected graph, add an edge from dest to src as well
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Recursive function to perform DFS traversal
void DFSUtil(struct Graph* graph, int currentVertex, int* visited) {
    visited[currentVertex] = 1; // Mark the current vertex as visited
    printf("%d ", currentVertex);

    struct AdjListNode* temp = graph->array[currentVertex].head;
    while (temp != NULL) {
        int adjVertex = temp->dest;
        if (!visited[adjVertex]) {
            DFSUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Function to perform DFS traversal of the graph
void DFS(struct Graph* graph, int startVertex) {
    int* visited = (int*)malloc(graph->vertices * sizeof(int));
    if (visited == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    printf("Depth-First Search starting from vertex %d: ", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");

    free(visited);
}

// Function to free memory allocated for the graph
void freeGraph(struct Graph* graph) {
    if (graph != NULL) {
        if (graph->array != NULL) {
            for (int i = 0; i < graph->vertices; ++i) {
                struct AdjListNode* temp = graph->array[i].head;
                while (temp) {
                    struct AdjListNode* prev = temp;
                    temp = temp->next;
                    free(prev);
                }
            }
            free(graph->array);
        }
        free(graph);
    }
}

int main() {
    int vertices, edges, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    struct Graph* graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (src dest):\n");
    for (int i = 0; i < edges; ++i) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &src);

    DFS(graph, src);

    // Free allocated memory for the graph
    freeGraph(graph);

    return 0;
}

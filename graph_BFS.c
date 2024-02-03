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

// Structure for a queue used in BFS
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
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

// Function to create a queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;  // This is important for the 'isFull' condition
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    if (queue->array == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to enqueue an element to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        fprintf(stderr, "Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        fprintf(stderr, "Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to perform BFS traversal of the graph
void BFS(struct Graph* graph, int startVertex) {
    // Create a boolean array to keep track of visited vertices
    int* visited = (int*)malloc(graph->vertices * sizeof(int));
    if (visited == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < graph->vertices; ++i) {
        visited[i] = 0; // Mark all vertices as not visited
    }

    // Create a queue for BFS traversal
    struct Queue* queue = createQueue(graph->vertices);
    enqueue(queue, startVertex);
    visited[startVertex] = 1; // Mark the starting vertex as visited

    printf("Breadth-First Search starting from vertex %d: ", startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        // Traverse the adjacent vertices of currentVertex
        struct AdjListNode* temp = graph->array[currentVertex].head;
        while (temp != NULL) {
            int adjVertex = temp->dest;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");

    free(queue->array);
    free(queue);
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

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &src);

    BFS(graph, src);

    // Free allocated memory for the graph
    freeGraph(graph);

    return 0;
}

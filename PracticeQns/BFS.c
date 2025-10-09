#include <stdio.h>

#define MAX 10  // maximum number of vertices

int queue[MAX];
int front = -1, rear = -1;
int visited[MAX];

// Function to enqueue an element
void enqueue(int v) {
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = v;
    }
}

// Function to dequeue an element
int dequeue() {
    int v;
    if (front == -1 || front > rear)
        return -1;
    else {
        v = queue[front++];
        return v;
    }
}

// BFS traversal
void bfs(int adj[MAX][MAX], int n, int start) {
    int i, vertex;
    for (i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        vertex = dequeue();
        printf("%d ", vertex);

        for (i = 0; i < n; i++) {
            if (adj[vertex][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, i, j, start;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    bfs(adj, n, start);

    return 0;
}

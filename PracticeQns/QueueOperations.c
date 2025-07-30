#include <stdio.h>
#define MAX 100
int main() {
    int queue[MAX];
    int front = -1, rear = -1;
    int value;
    int n, m;
    // ENQUEUE
    printf("Enter the number of elements to insert into the queue: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        if (rear == MAX - 1) {
            printf("Queue is full\n");
            break;
        } else {
            if (front == -1)
                front = 0;
            printf("Enter value to insert: ");
            scanf("%d", &value);
            rear++;
            queue[rear] = value;
            printf("Inserted %d\n", value);
        }
    }
    // DEQUEUE
    printf("\nEnter the number of elements to delete from the queue: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        if (front == -1 || front > rear) {
            printf("Queue is empty\n");
            break;
        } else {
            printf("Deleted element: %d\n", queue[front]);
            front++;
        }
    }
    // DISPLAY remaining elements
    if (front == -1 || front > rear) {
        printf("\nQueue is now empty\n");
    } else {
        printf("\nRemaining elements in the queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
    return 0;
}

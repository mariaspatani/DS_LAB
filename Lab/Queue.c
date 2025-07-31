#include <stdio.h>
#define MAX 5

void displayQueue(int queue[], int front, int rear) {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Current queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int queue[MAX];
    int front = -1, rear = -1;
    int value;

    // ENQUEUE
    printf("Enter the 5 elements to insert into the queue: \n");
    for (int i = 0; i < MAX; i++) {
        if (rear == MAX - 1) {
            printf("Queue is full\n");
            break;
        } else {
            if (front == -1)
                front = 0; // First element inserted
            printf("Enter value to insert: ");
            scanf("%d", &value);
            rear++;
            queue[rear] = value;
            printf("Inserted %d\n", value);
            // Display current state of the queue
            displayQueue(queue, front, rear);
        }
    }

    // DEQUEUE
    int n;  // Number of elements to delete from the queue
    printf("\nEnter the number of elements to delete from the queue: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        if (front == -1 || front > rear) {
            printf("Queue is empty\n");
            break;
        } else {
            printf("Deleted element: %d\n", queue[front]);
            front++;
            displayQueue(queue, front, rear);
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

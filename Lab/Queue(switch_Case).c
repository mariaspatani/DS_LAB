#include <stdio.h>
#define size 5
int queue[size];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == size - 1) {
        printf("Queue is full (Overflow).\n");
    } else {
        if (front == -1) front = 0; 
        rear++;
        queue[rear] = value;
        printf("%d enqueued to the queue.\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty (Underflow).\n");
    } else {
        printf("%d dequeued from the queue.\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    do {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while(choice != 4);

    return 0;
}

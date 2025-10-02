#include <stdio.h>
#include <stdlib.h>

// Node = memory block
struct Node {
    int size;                 
    int free;                 
    struct Node *prev, *next; 
};

struct Node *head = NULL;

// Create memory pool
void createMemory(int totalSize) {
    head = (struct Node*)malloc(sizeof(struct Node));
    head->size = totalSize;
    head->free = 1;   // initially free
    head->prev = head->next = NULL;
}

// Allocate memory (splitting free block)
void allocate(int size) {
    struct Node *curr = head;
    while (curr != NULL) {
        if (curr->free == 1 && curr->size >= size) {
            if (curr->size > size) {
                // split block
                struct Node *newBlock = (struct Node*)malloc(sizeof(struct Node));
                newBlock->size = curr->size - size;
                newBlock->free = 1;
                newBlock->next = curr->next;
                newBlock->prev = curr;

                if (curr->next != NULL)
                    curr->next->prev = newBlock;
                curr->next = newBlock;

                curr->size = size;
            }
            curr->free = 0;
            printf("\n✅ Allocated %d units\n", size);
            return;
        }
        curr = curr->next;
    }
    printf("\n❌ No sufficient memory available!\n");
}

// Free memory (frees first allocated block)
void freeBlock() {
    struct Node *curr = head;
    while (curr != NULL) {
        if (curr->free == 0) {
            curr->free = 1;
            printf("\n♻️  Block freed\n");
            return;
        }
        curr = curr->next;
    }
    printf("\n⚠️  No allocated block to free!\n");
}

// Display blocks
void display() {
    struct Node *curr = head;
    int block = 1;
    printf("\n📌 Memory Status:\n");
    while (curr != NULL) {
        printf("Block %d: Size=%d, %s\n",
               block, curr->size,
               curr->free ? "Free" : "Allocated");
        curr = curr->next;
        block++;
    }
}

int main() {
    int choice, size, total;

    // take memory size from user
    printf("Enter total memory size: ");
    scanf("%d", &total);

    createMemory(total);  

    while (1) {
        printf("\nMenu:\n1. Allocate\n2. Free\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter size to allocate: ");
                scanf("%d", &size);
                allocate(size);
                display();   // always show after allocation
                break;

            case 2:
                freeBlock();
                display();   // always show after freeing
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

// Node = memory block
struct Node {
    int size;                 
    int free;                 // whether the block is free (1) or allocated (0)
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

// First Fit Allocation
void allocateFirstFit(int size) {
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
            printf("\nAllocated %d units using First Fit\n", size);
            return;
        }
        curr = curr->next;
    }
    printf("\nNo sufficient memory available for First Fit!\n");
}

// Best Fit Allocation
void allocateBestFit(int size) {
    struct Node *curr = head;
    struct Node *bestFit = NULL;
    int minDiff = __INT_MAX__;  // initially set to a very large number

    while (curr != NULL) {
        if (curr->free == 1 && curr->size >= size) {
            int diff = curr->size - size;
            if (diff < minDiff) {
                minDiff = diff;
                bestFit = curr;
            }
        }
        curr = curr->next;
    }

    if (bestFit != NULL) {
        // Split block
        if (bestFit->size > size) {
            struct Node *newBlock = (struct Node*)malloc(sizeof(struct Node));
            newBlock->size = bestFit->size - size;
            newBlock->free = 1;
            newBlock->next = bestFit->next;
            newBlock->prev = bestFit;

            if (bestFit->next != NULL)
                bestFit->next->prev = newBlock;
            bestFit->next = newBlock;

            bestFit->size = size;
        }
        bestFit->free = 0;
        printf("\nAllocated %d units using Best Fit\n", size);
    } else {
        printf("\nNo sufficient memory available for Best Fit!\n");
    }
}

// Worst Fit Allocation
void allocateWorstFit(int size) {
    struct Node *curr = head;
    struct Node *worstFit = NULL;
    int maxDiff = -1;  // initially set to a very small number

    while (curr != NULL) {
        if (curr->free == 1 && curr->size >= size) {
            int diff = curr->size - size;
            if (diff > maxDiff) {
                maxDiff = diff;
                worstFit = curr;
            }
        }
        curr = curr->next;
    }

    if (worstFit != NULL) {
        // Split block
        if (worstFit->size > size) {
            struct Node *newBlock = (struct Node*)malloc(sizeof(struct Node));
            newBlock->size = worstFit->size - size;
            newBlock->free = 1;
            newBlock->next = worstFit->next;
            newBlock->prev = worstFit;

            if (worstFit->next != NULL)
                worstFit->next->prev = newBlock;
            worstFit->next = newBlock;

            worstFit->size = size;
        }
        worstFit->free = 0;
        printf("\nAllocated %d units using Worst Fit\n", size);
    } else {
        printf("\nNo sufficient memory available for Worst Fit!\n");
    }
}

// Free memory (frees first allocated block)
void freeBlock() {
    struct Node *curr = head;
    while (curr != NULL) {
        if (curr->free == 0) {
            curr->free = 1;
            printf("\nBlock freed\n");
            return;
        }
        curr = curr->next;
    }
    printf("\nNo allocated block to free!\n");
}

// Display blocks
void display() {
    struct Node *curr = head;
    int block = 1;
    printf("\nMemory Status:\n");
    while (curr != NULL) {
        printf("Block %d: Size=%d, %s\n",
               block, curr->size,
               curr->free ? "Free" : "Allocated");
        curr = curr->next;
        block++;
    }
}

int main() {
    int choice, size, total, strategy;

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
                printf("Choose allocation strategy:\n");
                printf("1. First Fit\n2. Best Fit\n3. Worst Fit\n");
                scanf("%d", &strategy);

                switch (strategy) {
                    case 1:
                        allocateFirstFit(size);
                        break;
                    case 2:
                        allocateBestFit(size);
                        break;
                    case 3:
                        allocateWorstFit(size);
                        break;
                    default:
                        printf("Invalid strategy choice!\n");
                        continue;
                }

                display();   
                break;

            case 2:
                freeBlock();
                display();   
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}

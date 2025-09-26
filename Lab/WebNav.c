#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    char url[50];
    struct Node *prev;
    struct Node *next;
};
struct Node *current = NULL;
struct Node* createNode(char url[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->prev = newNode->next = NULL;
    return newNode;
}
void visitPage(char url[]) {
    struct Node *newNode = createNode(url);

    if (current != NULL) {
        // Clear forward history
        struct Node *temp = current->next;
        while (temp) {
            struct Node *del = temp;
            temp = temp->next;
            free(del);
        }
        current->next = NULL;=
        // Link new node
        newNode->prev = current;
        current->next = newNode;
    }
    current = newNode;
    printf("Visited: %s\n", current->url);
}
void goBack() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Moved Back -> Current Page: %s\n", current->url);
    } else {
        printf("No previous page.\n");
    }
}
void goForward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Moved Forward -> Current Page: %s\n", current->url);
    } else {
        printf("No forward page.\n");
    }
}

void displayCurrentPage() {
    if (current != NULL)
        printf("Current Page: %s\n", current->url);
    else
        printf("No page visited yet.\n");
}
int main() {
    int choice;
    char url[50];
    while (1) {
        printf("\n--- Web Browser Navigation ---\n");
        printf("1. Visit New Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Display Current Page\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter URL: ");
                scanf("%s", url);
                visitPage(url);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                displayCurrentPage();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

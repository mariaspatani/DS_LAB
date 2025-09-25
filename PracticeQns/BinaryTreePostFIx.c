#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node *left, *right;
};

// Stack for tree nodes
struct Node* stack[50];
int top = -1;

// Stack functions
void push(struct Node* node) {
    stack[++top] = node;
}

struct Node* pop() {
    return stack[top--];
}

// Create a new tree node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Convert infix to postfix (for simplicity: assumes single-letter operands)
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    char opStack[50];
    int topOp = -1, i, k = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {  // operand
            postfix[k++] = c;
        }
        else if (c == '(') {
            opStack[++topOp] = c;
        }
        else if (c == ')') {
            while (topOp >= 0 && opStack[topOp] != '(')
                postfix[k++] = opStack[topOp--];
            topOp--; // remove '('
        }
        else {  // operator
            while (topOp >= 0 && precedence(opStack[topOp]) >= precedence(c))
                postfix[k++] = opStack[topOp--];
            opStack[++topOp] = c;
        }
    }
    while (topOp >= 0)
        postfix[k++] = opStack[topOp--];
    postfix[k] = '\0';
}

// Build expression tree from postfix
struct Node* buildTree(char postfix[]) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isalnum(c)) {  // operand
            push(createNode(c));
        } else {  // operator
            struct Node *right = pop();
            struct Node *left = pop();
            struct Node *opNode = createNode(c);
            opNode->left = left;
            opNode->right = right;
            push(opNode);
        }
    }
    return pop();  // root node
}

// Preorder traversal (Prefix)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal (Postfix)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

int main() {
    char infix[50], postfix[50];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    struct Node* root = buildTree(postfix);

    printf("Prefix Expression: ");
    preorder(root);
    printf("\n");

    printf("Postfix Expression: ");
    postorder(root);
    printf("\n");

    return 0;
}

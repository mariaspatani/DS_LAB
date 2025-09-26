#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char value;
    struct Node *left, *right;
} Node;

// Stack for operands (tree nodes)
Node* operandStack[100];
int topOperand = -1;

// Stack for operators (tree nodes)
Node* operatorStack[100];
int topOperator = -1;

// Stack operations for operand stack
void pushOperand(Node* n) {
    operandStack[++topOperand] = n;  // Increment topOperand and store node
}

Node* popOperand() {
    return operandStack[topOperand--];  // Return the top node and decrement topOperand
}

Node* peekOperand() {
    return operandStack[topOperand];  // Return the node at the top of the stack
}

// Stack operations for operator stack
void pushOperator(Node* n) {
    operatorStack[++topOperator] = n;  // Increment topOperator and store operator
}

Node* popOperator() {
    return operatorStack[topOperator--];  // Return the top operator and decrement topOperator
}

Node* peekOperator() {
    return operatorStack[topOperator];  // Return the operator at the top of the stack
}

// Function to create a new node
Node* createNode(char val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Build expression tree from infix expression
void buildTree(char expr[]) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (isspace(ch)) continue;  // Skip spaces

        // If the character is an operand (variable or number)
        if (isalnum(ch)) {
            pushOperand(createNode(ch));  // Create a node for the operand and push to operand stack
        } 
        // If it's a left parenthesis '('
        else if (ch == '(') {
            pushOperator(createNode(ch));  // Push '(' onto the operator stack
        } 
        // If it's a right parenthesis ')'
        else if (ch == ')') {
            while (topOperator >= 0 && peekOperator()->value != '(') {
                Node* op = popOperator();  // Pop operator
                op->right = popOperand();  // Pop two operands and form the subtree
                op->left = popOperand();
                pushOperand(op);  // Push the resulting subtree back onto the operand stack
            }
            if (topOperator >= 0) popOperator();  // Pop '(' from the operator stack
        } 
        // If it's an operator (like +, -, *, /)
        else {
            while (topOperator >= 0 && precedence(peekOperator()->value) >= precedence(ch)) {
                Node* op = popOperator();  // Pop operator with higher or equal precedence
                op->right = popOperand();  // Pop operands and build subtree
                op->left = popOperand();
                pushOperand(op);  // Push the subtree back onto the operand stack
            }
            pushOperator(createNode(ch));  // Push the current operator onto the operator stack
        }
    }

    // Pop any remaining operators and build the tree
    while (topOperator >= 0) {
        Node* op = popOperator();
        op->right = popOperand();
        op->left = popOperand();
        pushOperand(op);  // Push the final tree root to the operand stack
    }
}

// Prefix (pre-order) traversal
void printPrefix(Node* root) {
    if (root == NULL) return;
    printf("%c ", root->value);  // Print the current node's value
    printPrefix(root->left);     // Traverse the left subtree
    printPrefix(root->right);    // Traverse the right subtree
}

// Postfix (post-order) traversal
void printPostfix(Node* root) {
    if (root == NULL) return;
    printPostfix(root->left);    // Traverse the left subtree
    printPostfix(root->right);   // Traverse the right subtree
    printf("%c ", root->value);  // Print the current node's value
}

// Main program
int main() {
    char expr[100];
    int choice;

    printf("Enter infix expression (single-letter operands): ");
    scanf("%s", expr);  // Read the infix expression

    buildTree(expr);  // Build the expression tree from the infix expression

    while (1) {
        printf("\nMenu:\n");
        printf("1. Prefix\n");
        printf("2. Postfix\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);  // Get user's choice

        switch (choice) {
            case 1:
                printf("Prefix: ");
                printPrefix(peekOperand());  // Print the prefix (pre-order) traversal
                printf("\n");
                break;
            case 2:
                printf("Postfix: ");
                printPostfix(peekOperand());  // Print the postfix (post-order) traversal
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                return 0;  // Exit the program
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

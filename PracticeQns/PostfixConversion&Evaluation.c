#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For exit()
#include <ctype.h>  // For isdigit() and isalnum()

#define MAX_SIZE 100

// ===================================
// STACK FOR INFIX TO POSTFIX CONVERSION (CHARACTERS)
// ===================================
char charStack[MAX_SIZE];
int charTop = -1;

void charPush(char value) {
    if (charTop >= MAX_SIZE - 1) {
        printf("Character stack overflow\n");
        exit(1);
    }
    charStack[++charTop] = value;
}

char charPop() {
    if (charTop < 0) {
        printf("Character stack underflow\n");
        exit(1);
    }
    return charStack[charTop--];
}

char charPeek() {
    if (charTop < 0) {
        return '\0';
    }
    return charStack[charTop];
}

int isCharStackEmpty() {
    return charTop == -1;
}

// ===================================
// STACK FOR POSTFIX EVALUATION (INTEGERS)
// ===================================
int intStack[MAX_SIZE];
int intTop = -1;

void intPush(int value) {
    if (intTop >= MAX_SIZE - 1) {
        printf("Integer stack overflow\n");
        exit(1);
    }
    intStack[++intTop] = value;
}

int intPop() {
    if (intTop < 0) {
        printf("Integer stack underflow\n");
        exit(1);
    }
    return intStack[intTop--];
}

// ===================================
// HELPER FUNCTIONS
// ===================================

int precedence(char symbol) {
    switch (symbol) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Custom integer power function
int intPower(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

// ===================================
// MAIN LOGIC
// ===================================

void infixToPostfix(char *infix, char *postfix) {
    int i, j = 0;
    for (i = 0; i < strlen(infix); i++) {
        char symbol = infix[i];
        
        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        } else if (symbol == '(') {
            charPush('(');
        } else if (symbol == ')') {
            while (!isCharStackEmpty() && charPeek() != '(') {
                postfix[j++] = charPop();
            }
            if (!isCharStackEmpty()) {
                charPop(); // Pop the '('
            }
        } else { // Operator
            while (!isCharStackEmpty() && precedence(charPeek()) >= precedence(symbol)) {
                // Correct logic for right-to-left associativity of '^'
                if (precedence(charPeek()) == precedence(symbol) && symbol == '^') {
                    break;
                }
                postfix[j++] = charPop();
            }
            charPush(symbol);
        }
    }

    while (!isCharStackEmpty()) {
        postfix[j++] = charPop();
    }
    postfix[j] = '\0';
}

int postEval(char *postfix) {
    int i;
    for (i = 0; i < strlen(postfix); i++) {
        char symbol = postfix[i];

        if (isdigit(symbol)) {
            intPush(symbol - '0');
        } else {
            int a = intPop();
            int b = intPop();
            
            switch (symbol) {
                case '^': intPush(intPower(b, a)); break;
                case '*': intPush(b * a); break;
                case '/':
                    if (a == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    intPush(b / a); 
                    break;
                case '+': intPush(b + a); break;
                case '-': intPush(b - a); break;
            }
        }
    }
    return intPop();
}

void displayPost(char *postfix) {
    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    
    printf("Enter the infix expression (single-digit operands): ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    displayPost(postfix);
    
    int result = postEval(postfix);
    printf("Evaluated Postfix: %d\n", result);
    
    return 0;
}

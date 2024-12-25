#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define SIZE 100

struct stack {
    int top;
    char data[SIZE];
} st;

void initStack() {
    st.top = -1;
}

int isFull() {
    return st.top == SIZE - 1;
}

int isEmpty() {
    return st.top == -1;
}

void push(char value) {
    if (isFull()) {
        printf("Stack is full\n");
        return;
    }
    st.data[++st.top] = value;
}

char pop() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return '\0';
    }
    return st.data[st.top--];
}

char peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return '\0';
    }
    return st.data[st.top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void infixToPostfix(char infix[], char postfix[]) {
    initStack();
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        } else if (isOperator(ch)) {
            while (!isEmpty() && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]) {
    initStack();
    int i = 0, a, b;
    char ch;

    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            b = pop();
            a = pop();
            switch (ch) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
                case '^': push(pow(a, b)); break;
            }
        }
    }

    return pop();
}

int main() {
    char infix[] = "((a+b)^((c/d)*e))";
    char postfix[SIZE];
    
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    
    for (int i = 0; postfix[i] != '\0'; i++) {
        switch (postfix[i]) {
            case 'a': postfix[i] = '2'; break;
            case 'b': postfix[i] = '6'; break;
            case 'c': postfix[i] = '3'; break;
            case 'd': postfix[i] = '2'; break;
            case 'e': postfix[i] = '-'; break;
        }
    }

    printf("Postfix expression with values: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}

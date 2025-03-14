#include <stdio.h>
#include <stdlib.h>


struct StackNode {
    int data;
    struct StackNode* next;
};



struct StackNode* newNode(int data) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}


int isEmpty(struct StackNode* root) {
    return !root;
}


void push(struct StackNode** root, int data) {
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}



void printStack(struct StackNode* root) {
    while (root != NULL) {
        printf("%d -> ", root->data);
        root = root->next;
    }
    printf("NULL\n");
}

int main() {
    struct StackNode* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);

    printStack(root);

    return 0;
}
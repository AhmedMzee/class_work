#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void front_insertion() {
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    printf("Enter the element to be inserted at the beginning:\n");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    return;
}

void back_insertion() {
    struct node *newNode, *temp;

    newNode = malloc(sizeof(struct node));
    printf("Enter the element to be inserted at the end:\n");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return;
}

void print_list() {
    struct node *temp;
    temp = head;

    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("The elements in the list are:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return;
}

int main() {
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                front_insertion();
                break;
            case 2:
                back_insertion();
                break;
            case 3:
                print_list();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

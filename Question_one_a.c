#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
    int priority;
    char device[10];
    struct node* next;
};

struct node* head = NULL;

struct node* createNode(int priority, char* device) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->priority = priority;
    strcpy(newNode->device, device);
    newNode->next = NULL;
    return newNode;
}


void front_insertion(int priority, char* device) {
    struct node* newNode = createNode(priority, device);
    if (head == NULL || head->priority > priority) {
        newNode->next = head;
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    return;
}


void back_insertion(int priority, char* device) {
    struct node* newNode = createNode(priority, device);
    struct node* temp = head;

    if (head == NULL) {
        head = newNode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return;
}


void middle_insertion(int priority, char* device) {
    struct node* newNode = createNode(priority, device);
    struct node* temp = head;

    if (head == NULL || head->priority > priority) {
        front_insertion(priority, device);
    } else {
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return;
}


void delete_node() {
    if (head == NULL) {
        printf("The queue is empty.\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
}


void display() {
    if (head == NULL) {
        printf("The queue is empty.\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("Device: %s, Priority: %d\n", temp->device, temp->priority);
        temp = temp->next;
    }
    return;
}

int main() {
 
    front_insertion(1, "Keyboard");
    back_insertion(4, "Printer");
    middle_insertion(2, "Mouse");
    middle_insertion(3, "Scanner");


    printf("Priority Queue:\n");
    display();

    
    printf("\nHandling requests:\n");
    while (head != NULL) {
        printf("Handling device: %s\n", head->device);
        delete_node();
    }

    return 0;
}

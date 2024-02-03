#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

void insertNode(struct LinkedList* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(struct LinkedList* list) {
    struct Node* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteNode(struct LinkedList* list, int nodeOffset) {
    struct Node* temp1 = list->head;
    struct Node* temp2 = NULL;
    int listLen = 0;
    if (list->head == NULL) {
        printf("List empty.\n");
        return;
    }

    while (temp1 != NULL) {
        temp1 = temp1->next;
        listLen++;
    }

    if (listLen < nodeOffset) {
        printf("Index out of range\n");
        return;
    }

    temp1 = list->head;

    if (nodeOffset == 1) {
        list->head = list->head->next;
        free(temp1);
        return;
    }
//incomplete
}
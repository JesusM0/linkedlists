#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

struct Node{
    int data;
    Node * next;
};

void insertHead(Node ** head, int data){
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;

    *head = newNode;
}

void insertTail(Node **head, int data){
    if(*head == NULL){
        Node * newNode = (Node *) malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        (*head) = newNode;
        return;
    }
    insertTail(&((*head)->next), data);
}

void printList(Node * head){
    if(head == NULL){
        printf("NULL\n");
        return;
    }

    printf("%d -> ", head->data);
    printList(head->next);
}

int main(){
    Node * head = NULL;
    
    insertHead(&head, 5);
    insertHead(&head, 4);
    insertHead(&head, 3);
    insertHead(&head, 2);
    insertHead(&head, 1);
    insertHead(&head, 0);
    insertTail(&head, -1);
    insertTail(&head, -2);
    insertTail(&head, -3);
    insertTail(&head, -4);
    insertTail(&head, -5);

    printList(head);
}
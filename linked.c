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

int main(){
    Node * head = NULL;
    
    insertHead(&head, 5);
    insertHead(&head, 4);
    insertHead(&head, 3);
    insertHead(&head, 2);
    insertHead(&head, 1);
    insertHead(&head, 0);

    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL");
    printf("\n");
}
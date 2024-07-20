#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    int option = 0;
    while(true){
        printf("Linked List Menu: \n");
        printf("1. Insert New Node: \n");
        printf("2. Delete Node \n");
        printf("3. Print List \n");
        printf("4. Exit \n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Insert To 1.Head or 2.Tail?\n");
            int inChoice = 0;
            scanf("%d", &inChoice);
            if(inChoice == 1){
                printf("Enter the Data for the New Node: \n");
                int data;
                scanf("%d", &data);
                insertHead(&head, data);
            }
            else if(inChoice == 2){
                printf("Enter the Data for the New Node: \n");
                int data;
                scanf("%d", &data);
                insertHead(&head, data);
            }
            else{
                printf("Incorrect Option, Try Again\n");
            }
            break;
        case 2:
            break;
        case 3:
            printList(head);
            break;
        case 4:
            printf("BYEBYE\n");
            exit(0);
            break;
        default:
            break;
        }

    }

    printList(head);
}
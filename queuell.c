#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY -1

typedef struct Node Node;
typedef struct Queue Queue;

struct Node{
    int data;
    Node * next;
};

struct Queue{
    Node * front;
    Node * back;
};

void initQueue(Queue *qPtr){
    qPtr->front = qPtr->back = NULL;
}

Node* makeNode(int val) {
    Node* tmp = (Node *) malloc(sizeof(Node));
    tmp->data = val;
    tmp->next = NULL;
    return tmp;
}

int enqueue(Queue * qPtr, int data){
    
}

int dequeue(Queue * qptr){
  
}

void addFront(Queue * qPtr, int data){
    
}

int front(Queue * qPtr){
   
}

void printQueue(Node *front) {
    //if the list is empty or reached the end, return
    if(front == NULL){
        return;
    }
    
    //print currently queue items front to back
    printf("<- %d ", front->data);
    //recurse to next item
    printQueue(front->next);
}

int main(){
    Queue * qPtr = (Queue *) malloc(sizeof(Queue));
    initQueue(qPtr);

    int option = 0;
    while(true){
        printf("Queue Menu: \n");
        printf("1. Enqueue \n");
        printf("2. Dequeue \n");
        printf("3. Check Front \n");
        printf("4. Print List \n");
        printf("5. Exit \n");
        scanf("%d", &option);
        printf("\n");
        switch (option)
        {
        case 1:
            printf("/////////////////////////////////////////////////\n");
            printf("Insert 1.Normally(from back) or 2.Front or 3.Random ?\n");
            int inChoice = 0;
            scanf("%d", &inChoice);
            if(inChoice == 1){
                printf("Enter the Data for the New Node: \n");
                int data;
                scanf("%d", &data);
                printf("Enqueueing %d....\n", data);
                enqueue(qPtr, data);
            }
            else if(inChoice == 2){
                printf("Enter the Data for the New Node: \n");
                int data;
                scanf("%d", &data);
                addFront(qPtr, data);
            }
            else{
                printf("Incorrect Option, Try Again\n");
            }
            printf("/////////////////////////////////////////////////\n");
            printf("\n");
            break;
        case 2:
            printf("/////////////////////////////////////////////////\n");
            dequeue(qPtr);
            printf("/////////////////////////////////////////////////\n");
            printf("\n");
            break;
        case 3:
            front(qPtr);
            printf("\n");
            break;
        case 4:
            printf("Front ");;
            printQueue(qPtr->front);
            printf("<- Back\n");
            printf("\n");
            break;
        case 5:
            printf("BYE BYE\n");
            exit(0);
            break;
        default:
            break;
        }

    }
    return 0;
}



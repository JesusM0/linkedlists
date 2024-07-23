#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    //create a temporary Node pointer to access node structs fields
    Node * temp = (Node *) malloc(sizeof(Node));

    //if temp was successfully allocated
    if(temp){ 
        temp->data = data;
        temp->next = NULL;

        if(qPtr->back != NULL){
            qPtr->back->next = temp;
        } 
        qPtr->back = temp;

        if(qPtr->front == NULL){
            qPtr->front = temp;
        }
        return 1;
    }
    else{
        return 0;
    }
}

int dequeue(Queue * qptr){
    Node * tmp;
    int ret;

    ret = qptr->front->data;
    tmp = qptr->front;

    qptr->front = qptr->front->next;

    if(!qptr->front){
        qptr->back = NULL;
    }

    free(tmp);

    return ret;
}

void addFront(Queue * qPtr, int data){
    Node * newNode = makeNode(data);

    if(!qPtr->front){
        qPtr->front = qPtr->back = newNode;
        return;
    }

    newNode->next = qPtr->front;
    qPtr->front = newNode;
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

    enqueue(qPtr, 15);
    enqueue(qPtr, 16);
    enqueue(qPtr, 17);

    printf("Front ");
    printQueue(qPtr->front);
    printf("<- Back\n");
    printf("Currently Dequeueing %d\n", dequeue(qPtr));
    addFront(qPtr, 14);
    addFront(qPtr, 15);
    printf("Front ");
    printQueue(qPtr->front);
    printf("<- Back\n");
}



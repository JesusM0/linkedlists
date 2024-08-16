#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node Node;
typedef struct Stack Stack;

struct Node{
    int data;
    Node * next;
};


Node* NodeCreate() {
    Node * obj = (Node *) malloc(sizeof(Node));
    obj = NULL;
}

void NodePush(Node* obj, int x) {
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = obj;
    obj = newNode;
}

int NodePop(Node* obj) {
    int res = obj->data;
    Node * tmp = obj;
    obj = obj->next;
    free(tmp);
    return res;
}

int NodeTop(Node* obj) {
    return obj->data;
}

bool NodeEmpty(Node* obj) {
    if(!obj){
        return false;
    }
    else{
        return true;
    }
}

void NodeFree(Node* obj) {
    if(!obj){
        return;
    }
    while(obj != NULL){
        Node * temp;
        temp = obj;
        obj = obj->next;
        free(temp);
    }
    free(obj);
}

int main(){
    Node* obj = NodeCreate();
    NodePush(obj, 1);
    NodePush(obj, 2);
    
    int param_2 = NodePop(obj);
    printf("%d\n", param_2);
    
    int param_3 = NodeTop(obj);
    printf("%d\n", param_3);
    
    bool param_4 = NodeEmpty(obj);
    NodeFree(obj);
}
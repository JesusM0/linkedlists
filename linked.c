#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node Node;

struct Node{
    int data;
    Node * next;
};

void printList(Node *head);
Node * insertHead(Node *head, int data);
Node * insertTail(Node *head, int data);
Node * deleteHead(Node * head);
Node * deleteTail(Node * head);
Node * deleteByValue(Node *head, int data);
Node * moveHeadNearTail(Node * head);

Node * insertHead(Node *head, int data){
    Node * newNode = (Node *) malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = head;
    
    return newNode;
}

Node * insertTail(Node *head, int data){
    if(head == NULL){
        Node * newNode = (Node*) malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        head = newNode;
        return newNode;
    }

    head->next = insertTail(head->next, data);
    return head;
}

Node * deleteHead(Node * head){
    Node * tmp = head;
    printf("Deleting Original Head with Value of: %d\n", tmp->data);
    head = head->next;

    free(tmp);
    return head;

}

Node * deleteTail(Node * head){
    if(head->next->next == NULL){
        Node * tmp = head->next;
        printf("Deleting Original Tail with Value of: %d\n", tmp->data);
        head->next = NULL;
        free(tmp);
        return head;
    }
    head->next = deleteTail(head->next);
    return head;
}

Node * deleteByValue(Node *head, int data){
    if(head == NULL){
        printf("Number %d not in list\n", data);
        return head;
    }
    printf("Deleting %d, currently at %d\n", data, head->data);
    if(head->data == data){
        printf("Number %d has been found. Deleting Now...\n", head->data);
        Node * tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }
    head->next = deleteByValue(head->next, data);
    return head;

}

//LEETCODE QUESTION: Remove Duplicated 1
//this will delete duplicates in a sorted list. Will leave only first occurrence.
Node * deleteDuplicates(Node * head){
    if(head == NULL){
        return head;
    }

    if(head->next != NULL && head->next->data == head->data){
        Node * tmp = head->next;
        head->next = head->next->next;
        free(tmp);
        head = deleteDuplicates(head);
    }
    else{
        head->next = deleteDuplicates(head->next);
    }

    return head;

}

//LEETCODE QUESTION: Remove Duplicated 2
Node * onlyDistinct(Node * head){
    if(head == NULL){
        return head;
    }

    // Check if the next value is the same as the head
    if(head->next != NULL && head->next->data == head->data){
        // Remove all nodes with the same value as head
        while(head->next != NULL && head->next->data == head->data){
            Node * tmp = head->next;
            head->next = head->next->next;
            free(tmp);
        }

        // Now head->next is different or NULL
        Node * tmp = head;
        head = head->next;
        free(tmp);

        // Recursively call the function on the new head
        return onlyDistinct(head);
    } else {
        // No duplicates at head, proceed to the next node
        head->next = onlyDistinct(head->next);
        return head;
    }

}

//FE QUESTION: Summer 2024
Node * moveHeadNearTail(Node * head) {
    if(head->next->next == NULL){
        return head;
    }
    int tmp = head->data;
    int tmp2 = head->next->data;

    head->next->data = tmp;
    head->data = tmp2;
    printList(head);
    head->next = moveHeadNearTail(head->next);
    printList(head);
    return head;
}

void markEven(Node * head){
    if(!head){
        return;
    }

    if(head->data % 2 == 0){
        Node * newNode = (Node *) malloc(sizeof(Node));
        newNode->data = -1;
        newNode->next = head->next;
        head->next = newNode;
    }
    markEven(head->next);
}

// void markEven(Node * head){
//     Node * tmp = head;

//     while(tmp != NULL){
//         if(tmp->data % 2 == 0){
//             Node * newNode = (Node *) malloc(sizeof(Node));
//             newNode->data = -1;
//             newNode->next = tmp->next;
//             tmp->next = newNode;
//             tmp = newNode->next;
//         }
//         else{
//             tmp = tmp->next;
//         }
//     }
// }


void printList(Node *head){
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
    // head = insertHead(head, 5);
    // head = insertHead(head, 4);
    // head = insertHead(head, 4);
    // head = insertHead(head, 3);
    head = insertTail(head, 2);
    head = insertTail(head, 6);
    head = insertTail(head, 7);
    head = insertTail(head, 1);
    head = insertTail(head, 3);
    head = insertTail(head, 8);
    // head = insertTail(head, 7);
    // head = insertTail(head, 9);
    // head = insertHead(head, 1);
    while(true){
        printf("Linked List Menu: \n");
        printf("1. Insert New Node: \n");
        printf("2. Delete Node \n");
        printf("3. Print List \n");
        printf("4. Move Head Near Tail\n");
        printf("5. Above Threshold\n");
        printf("6. Insert After N\n");
        printf("7. Mark Even\n");
        printf("8. Exit \n");
        scanf("%d", &option);
        printf("\n");
        switch (option)
        {
        case 1:
            printf("/////////////////////////////////////////////////\n");
            printf("Insert To 1.Head, 2.Tail or 3.Random ?\n");
            int inChoice = 0;
            scanf("%d", &inChoice);
            if(inChoice == 1){
                printf("Enter the Data for the New Node: \n");
                int data;
                scanf("%d", &data);
                head = insertHead(head, data);
            }
            else if(inChoice == 2){
                printf("Enter the Data for the New Node: \n");
                int data;
                scanf("%d", &data);
                head = insertTail(head, data);
            }
            else if(inChoice == 3){
                printf("Enter the Number of Nodes: \n");
                int numNodes;
                scanf("%d", &numNodes);
                for(int i = 0; i < numNodes; i++){
                    head = insertHead(head, (rand() % 101));
                }
            }
            else{
                printf("Incorrect Option, Try Again\n");
            }
            printf("/////////////////////////////////////////////////\n");
            printf("\n");
            break;
        case 2:
            printf("/////////////////////////////////////////////////\n");
            printf("Delete by 1.Head, 2.Tail 3.Value or 4. Delete All Duplicates?\n");
            int delChoice = 0;
            scanf("%d", &delChoice);
            if(delChoice == 1){
                printf("Deleting Node at Head...\n");
                head = deleteHead(head);
            }
            else if(delChoice == 2){
                printf("Deleting Node at Tail...\n");
                head = deleteTail(head);
            }
            else if(delChoice == 3){
                printf("Enter the Number to Delete: \n");
                int numDel;
                scanf("%d", &numDel);
                head = deleteByValue(head, numDel);
            }
            else if(delChoice == 4){
                printf("Leave Only 1. Distinct or 2. no?\n");
                int distinct;
                scanf("%d", &distinct);
                if(distinct == 1){
                    printf("Leaving only Distinct\n");
                    head = onlyDistinct(head);
                }
                else if (distinct == 2)
                { 
                    printf("Deleting all duplicates\n");
                    head = deleteDuplicates(head);
                }
                
            }
            printf("/////////////////////////////////////////////////\n");
            printf("\n");
            break;
        case 3:
            printf("Head -> ");
            printList(head);
            printf("\n");
            break;
        case 4:
            printf("Moving Head Near Tail...\n");
            head = moveHeadNearTail(head);
            break;
        case 5:
            int limit;
            printf("Enter the Limit\n");
            scanf("%d", &limit);
            // printf("%d\n",aboveThreshold(head, limit));
            break;
        case 6:
            int M, N;
            printf("Enter the M\n");
            scanf("%d", &M);
            printf("Enter the N\n");
            scanf("%d", &N);
            // insertAfterN(head, M, N);
            break;
        case 7:
            markEven(head);
            break;
        case 8:
            printf("BYE BYE\n");
            exit(0);
            break;
        default:
            break;
        }

    }
    return 0;
}
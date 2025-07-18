#include<stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;
node* createNode(int x) {
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}
node* createLinkedList(int n) {
    node* head=NULL;
    node* tail=NULL;
    for(int i=0;i<n;i++) {
        int el; scanf("%d", &el);
        node* newNode=createNode(el);
        if (!newNode) {
            while(head) {
                node* tmp=head;
                head=head->next;
                free(tmp);
            }
            return NULL;
        }
        if (head==NULL) {
            head=tail=newNode;
        }else {
            tail->next=newNode;
            tail=newNode;
        }
    }
    return head;
}
void print(node* head) {
    int idx=1;
    while(head) {
        printf("Node %d: %d\n", idx++, head->data);
        head=head->next;
    }
}
main() {
    int n=5;
    node* head=createLinkedList(n);
    if (!head) return 1;
    print(head);
    while(head) {
        node* tmp=head;
        head=head->next;
        free(tmp);
    }
}
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
        if (head) {
            tail->next=newNode;
            tail=newNode;
        }else {
            head=tail=newNode;
        }
    }
    return head;
}
node* insertElHead(node* head, int x) {
    node* newNode=createNode(x);
    if (!newNode) return head;
    newNode->next=head;
    return newNode;
}
void print(node* head) {
    while(head) {
        printf("%d ", head->data);
        head=head->next;
    }
}
main() {
    int n=5;
    node* head=createLinkedList(n);
    if (!head) return 1;
    int x; scanf("%d", &x);
    print(insertElHead(head, x));
    while(head) {
        node* tmp=head;
        head=head->next;
        free(tmp);
    }
}
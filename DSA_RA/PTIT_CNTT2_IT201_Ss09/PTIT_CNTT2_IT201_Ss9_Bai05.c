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
            head=tail=newNode;
        }else {
            tail->next=newNode;
            tail=newNode;
        }
    }
    return head;
}
int cntNode(node* head) {
    int cnt=0;
    node* tmp=head;
    while(tmp) {
        ++cnt;
        tmp=tmp->next;
    }
    return cnt;
}
main() {
    int n; scanf("%d",&n);
    node* head=createLinkedList(n);
    if (!head) return 1;
    printf("Linked List have %d el", cntNode(head));
    while(head) {
        node* tmp=head;
        head=head->next;
        free(tmp);
    }
}
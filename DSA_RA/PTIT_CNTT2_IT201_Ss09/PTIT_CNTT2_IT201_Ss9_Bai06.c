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
node* deleNode(node* head) {
    if (head==NULL) return NULL;
    node* tmp=head;
    head=head->next;
    free(tmp);
    return head;
}
void print(node* head) {
    while(head) {
        printf("%d ", head->data);
        head=head->next;
    }
}
main() {
    int n; scanf("%d",&n);
    node* head=createLinkedList(n);
    if (!head) return 1;
    head=deleNode(head);
    print(head);
    while(head) {
        node* tmp=head;
        head=head->next;
        free(tmp);
    }
}
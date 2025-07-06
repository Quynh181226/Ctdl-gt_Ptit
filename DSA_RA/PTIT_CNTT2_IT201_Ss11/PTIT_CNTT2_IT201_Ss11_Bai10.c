#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;
node* createNode(int x) {
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=x;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
node* swapPairs(node* head) {
    node* curr=head;
    while(curr!=NULL&&curr->next!=NULL) {
        int tmp=curr->data;
        curr->data=curr->next->data;
        curr->next->data=tmp;

        curr=curr->next->next;
    }
}
void print(node* head) {
    node* curr=head;
    while(curr!=NULL) {
        printf("%d ",curr->data);
        curr=curr->next;
    }
}
main() {
    node* head=createNode(1);
    node* n2=createNode(2);
    node* n3=createNode(3);
    node* n4=createNode(4);
    node* n5=createNode(5);
    head->next=n2;
    n2->prev=head;
    n2->next=n3;
    n3->prev=n2;
    n3->next=n4;
    n4->prev=n3;
    n4->next=n5;
    n5->prev=n4;
    swapPairs(head);
    print(head);
}
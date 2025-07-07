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
node* middleEl(node* head) {
    if (head==NULL) return NULL;
    int cnt=0;
    node* curr=head;
    while (curr!=NULL) {
        cnt++;
        curr=curr->next;
    }
    int mIdx=(cnt%2==0)?(cnt/2):(cnt/2);
    curr=head;
    for (int i=0;i<mIdx;i++) {
        curr=curr->next;
    }
    printf("Node %d: %d", mIdx+1, curr->data);
    return curr;
}
void print(node* head) {
    node* temp=head;
    while(temp!=NULL) {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
main() {
    node* head=createNode(1);
    node* n2=createNode(2);
    node* n3=createNode(3);
    node* n4=createNode(4);
    node* n5=createNode(5);
    // node* n6=createNode(6);
    head->next=n2;
    n2->prev=head;
    n2->next=n3;
    n3->prev=n2;
    n3->next=n4;
    n4->prev=n3;
    n4->next=n5;
    n5->prev=n4;
    // n5->next=n6;
    // n6->prev=n5;
    middleEl(head);
    // print(head);
}
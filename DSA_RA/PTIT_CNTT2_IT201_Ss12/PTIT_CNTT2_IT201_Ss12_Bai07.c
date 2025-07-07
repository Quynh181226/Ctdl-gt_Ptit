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
node* select(node* head) {
    node* tmp=head;
    while (tmp!=NULL) {
        node* min=tmp;
        node* j=tmp->next;
        while (j!=NULL) {
            if (j->data < min->data) min=j;
            j=j->next;
        }
        if (min!=tmp) {
            int tmp1=tmp->data;
            tmp->data=min->data;
            min->data=tmp1;
        }
        tmp=tmp->next;
    }
    return head;
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
    node* n4=createNode(8);
    node* n5=createNode(7);
    head->next=n2;
    n2->prev=head;
    n2->next=n3;
    n3->prev=n2;
    n3->next=n4;
    n4->prev=n3;
    n4->next=n5;
    n5->prev=n4;
    head=select(head);
    print(head);
}
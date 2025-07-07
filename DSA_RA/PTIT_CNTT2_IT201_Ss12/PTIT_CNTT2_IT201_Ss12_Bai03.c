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
node* addNode(node** head, int val) {
    node* newNode=createNode(val);
    if (*head==NULL) {
        *head=newNode;
        return;
    }
    node* tmp=*head;
    while((tmp)->next!=NULL) {
        tmp=tmp->next;
    }
    tmp->next=newNode;
    newNode->prev=tmp;
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
    head->next=n2;
    n2->prev=head;
    n2->next=n3;
    n3->prev=n2;
    n3->next=n4;
    n4->prev=n3;
    n4->next=n5;
    n5->prev=n4;
    int val; scanf("%d",&val);
    addNode(&head,val);
    print(head);
}
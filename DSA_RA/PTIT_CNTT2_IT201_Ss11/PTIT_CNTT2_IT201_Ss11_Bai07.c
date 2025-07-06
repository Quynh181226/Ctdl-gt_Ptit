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
void addNode(node** head, int val, int pos) {
    node* newNode=createNode(val);
    if(*head==NULL||pos==0) {
       if(*head!=NULL) {
           newNode->next=*head;
           (*head)->prev=newNode;
       }
        *head=newNode;
        return;
    }
    node* curr=*head;
    int currPos=0;
    while(curr->next!=NULL&&currPos<pos-1) {
        curr=curr->next;
        currPos++;
    }
    newNode->next=curr->next;
    newNode->prev=curr;
    if(curr->next!=NULL) {
        curr->next->prev=newNode;
    }
    curr->next=newNode;
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
    int val, pos; scanf("%d %d",&val,  &pos);
    addNode(&head,val, pos);
    print(head);
}
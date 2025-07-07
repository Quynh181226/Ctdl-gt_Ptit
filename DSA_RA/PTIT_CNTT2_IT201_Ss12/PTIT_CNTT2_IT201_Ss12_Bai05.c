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
void delVal(node** head, int val) {
    if (*head==NULL) return;
    node*tmp=*head;
   while (tmp!=NULL&&tmp->data!=val) {
       tmp=tmp->next;
   }
    if (tmp==NULL) return;
    if (tmp==*head) {
        *head=tmp->next;
        if (*head!=NULL) (*head)->prev=NULL;
        free(tmp);
        return;
    }
    if (tmp->prev!=NULL) tmp->prev->next=tmp->next;
    if (tmp->next!=NULL) tmp->next->prev=tmp->prev;
    free(tmp);
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
    delVal(&head, val);
    print(head);
}
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
node* delNode(node* head, int pos) {
    if (head==NULL) return NULL;
    node* curr=head;
    if (pos==0) {
        node* tmp=head;
        head=head->next;
        if (head!=NULL) head->prev=NULL;
        free(tmp);
        return head;
    }

    int cnt=0;
    while (curr!=NULL&&cnt<pos) {
        curr=curr->next;
        cnt++;
    }
    if (curr==NULL) return head;
    if (curr->prev!=NULL){
        curr->prev->next=curr->next;
    }
    if (curr->next!=NULL) {
        curr->next->prev=curr->prev;
    }
    free(curr);
    return head;
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
    int x; scanf("%d",&x);
    head=delNode(head, x);
    print(head);
}
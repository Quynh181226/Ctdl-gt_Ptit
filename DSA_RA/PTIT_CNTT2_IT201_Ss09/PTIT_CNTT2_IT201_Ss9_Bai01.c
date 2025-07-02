#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;
node* createNode(int d) {
    node* newNode=(node*)malloc(sizeof(node));
    if(newNode==NULL) return;
    newNode->data=d;
    newNode->next=NULL;
    return newNode;
}
node* createLinkedList() {
    int el[]={10,11,12,13,14};
    node* head=NULL;
    node* curr=NULL;
    for(int i=0;i<5;i++) {
        node* newNode=createNode(el[i]);
        if(newNode==NULL) {
            // node* tmp=head;
            while(head!=NULL) {
                node* tmp=head;
                head=head->next;
                free(tmp);
            }
            return NULL;
        }
        if (head==NULL){
            head=curr=newNode;
        }else {
            curr->next=newNode;
            curr=newNode;
        }
    }
    return head;
}
void print(node* head) {
    while(head!=NULL) {
        printf("%d ",head->data);
        head=head->next;
    }
}
main() {
    node* head=createLinkedList();
    if (head==NULL) return 1;
    print(head);
    node* tmp;
    if (head!=NULL) {
        tmp=head;
        head=head->next;
        free(tmp);
    }
}
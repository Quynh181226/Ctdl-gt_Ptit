#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node;
void frees(node* head) {
    while(head!=NULL) {
        node* tmp=head;
        head=head->next;
        free(tmp);
    }
}
node* createNode(int d) {
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=d;
    newNode->next=NULL;
    return newNode;
}
node* createLinkedList(int a[], int n) {
    node* head=NULL;
    node* tail=NULL;
    for(int i=0;i<n;i++) {
        // int el; scanf("%d",&el);
        // node* newNode=createNode(el);
        node* newNode=createNode(a[i]);
        if (!newNode) {
            frees(head);
            return NULL;
        }
        if (head==NULL) {
            head=tail=newNode;
        }else {
            tail->next=newNode;
            tail=newNode;
        }
    }
    return head;
}
node* deleNode(node* head) {
    if (head==NULL) return NULL;
    if (head->next==NULL) {
        free(head);
        return NULL;
    }
    // node* curr=head;//s
    // node* nextNode=curr->next;
    // while (nextNode!=NULL) {
    //     curr=nextNode;
    //     nextNode=curr->next;
    // }
    // free(nextNode);
    // curr->next=NULL;
    // return head;/s
    node* curr=head;
    while (curr->next->next!=NULL) {
        curr=curr->next;
    }
    free(curr->next);
    curr->next=NULL;
    return head;
}
node* print(node* head) {
    if (head==NULL) return NULL;
    while (head!=NULL) {
        printf("%d ",head->data);
        head=head->next;
    }
}
main() {
    int a[]={1,2,2,5,5};
    int n=sizeof(a)/sizeof(a[0]);
    // if (n<=0) return 1;
    node* head=createLinkedList(a, n);
    if (head==NULL) return 1;
    head=deleNode(head);
    print(head);
    frees(head);
}

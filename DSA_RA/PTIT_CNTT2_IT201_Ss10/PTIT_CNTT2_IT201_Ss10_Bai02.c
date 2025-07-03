#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} node;
void frees(node* head) {
    while (head!=NULL) {
        node* tmp=head;
        head=head->next;
        free(tmp);
    }
}
node* createNode(int el) {
    node *newNode=(node*)malloc(sizeof(node));
    if(newNode==NULL) return NULL;
    newNode->data=el;
    newNode->next=NULL;
    return newNode;
}
node* createLinkedList(int n) {
    node* head=NULL;
    node* tail=NULL;
    for (int i=0; i<n; i++) {
        int el; scanf("%d", &el);
        node* newNode=createNode(el);
        //==NULL->fal...
        if (!newNode) {
            frees(head);
            return NULL;
        }
        if (head==NULL) {
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    return head;
}
node* print(node* head) {
    if(head==NULL) return;
    while (head != NULL) {
        printf("data: %d\n", head->data);
        head=head->next;
    }
}
main() {
    int n; scanf("%d", &n);
    node* head=createLinkedList(n);
    print(head);
    frees(head);
}
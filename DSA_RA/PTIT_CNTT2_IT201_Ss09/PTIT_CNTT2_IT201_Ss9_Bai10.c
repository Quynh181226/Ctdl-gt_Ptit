#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
}  node;
node* createNode(int x) {
    node* head=(node*)malloc(sizeof(node));
    head->data=x;
    head->next=NULL;
    return head;
}
void swapPairs(node* head) {
    node* curr=head;
    while (curr!=NULL&&curr->next!=NULL) {
        int tmp=curr->data;
        curr->data=curr->next->data;
        curr->next->data=tmp;

        curr=curr->next->next;
    }
}
void print(node* head) {
    while (head!=NULL) {
        printf("%d ", head->data);
        head=head->next;
    }
}
main() {
    node* head=createNode(11);
    head->next=createNode(22);
    head->next->next=createNode(33);
    head->next->next->next=createNode(44);
    head->next->next->next->next=createNode(55);
    if (!head) return 1;
    swapPairs(head);
    print(head);
}
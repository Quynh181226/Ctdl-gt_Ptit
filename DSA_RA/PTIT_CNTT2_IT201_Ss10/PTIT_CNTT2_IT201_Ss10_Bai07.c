#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* frees(Node* head) {
    while (head) {
        Node* tmp=head;
        head=head->next;
        free(tmp);
    }
    return NULL;
}
Node* createNode(int x) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    if (!newNode) return NULL;
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}
Node* createEl(int n) {
    Node* head=NULL;
    Node* tai=NULL;
    for (int i = 0; i < n; i++) {
        int el; scanf("%d",&el);
        Node* newNode=createNode(el);
        if (!newNode) {
            free(head);
        }
        if (head==NULL) {
            head=tai=newNode;
        }else {
            tai->next=newNode;
            tai=newNode;
        }
    }
    return head;
}
Node* select(Node* head) {
    Node* i=head;
    while (i!=NULL) {
        Node* min=i;
        Node* j=i->next;
        while (j!=NULL) {
            if (j->data<min->data) {
                min=j;
            }
            j=j->next;
        }
        if (min!=i) {
            int tmp=i->data;
            i->data=min->data;
            min->data=tmp;
        }
        i=i->next;
    }
}
Node* print(Node* head) {
    while(head!=NULL) {
        printf("%d ",head->data);
        head=head->next;
    }
}
main() {
    int n; scanf("%d", &n);
    Node* head=createEl(n);
    if (n<0||head==NULL) return 1;
    select(head);
    print(head);
    frees(head);
}
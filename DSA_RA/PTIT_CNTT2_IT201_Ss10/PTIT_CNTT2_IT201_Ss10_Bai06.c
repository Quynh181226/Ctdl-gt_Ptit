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
Node* middleEl(Node* head) {
    if (head==NULL) return NULL;
    int cnt=0;
    Node* tmp=head;
    while (tmp!=NULL) {
        cnt++;
        tmp=tmp->next;
    }
    int mIdx=cnt/2;
    tmp=head;
    for (int i=0;i<mIdx;i++) {
        tmp=tmp->next;
    }
    return tmp;
}
main() {
    int n; scanf("%d", &n);
    Node* head=createEl(n);
    if (n<0||head==NULL) return 1;
    Node* m=middleEl(head);
    printf("Node %d: %d", (n+1)/2+(n%2==0?1:0), m->data);
    // print(head);
    frees(head);
}
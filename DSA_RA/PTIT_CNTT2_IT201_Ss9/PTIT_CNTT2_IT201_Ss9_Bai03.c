#include<stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;
node* createNode(int x) {
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}
node* createLinkedList(int n) {
    node* head=NULL;
    node* tail=NULL;
    for(int i=0;i<n;i++) {
        int el; scanf("%d", &el);
        node* newNode=createNode(el);
        if (!newNode) {
            while(head) {
                node* tmp=head;
                head=head->next;
                free(tmp);
            }
            return NULL;
        }
        if (head) {
            tail->next=newNode;
            tail=newNode;
        }else {
            head=tail=newNode;
        }
    }
    return head;
}
int search(node* head, int f) {
    node* curr=head;
    while (curr) {
        if (curr->data==f) {
            return 1;
        }
        curr=curr->next;
    }
    return 0;
}
// void print(node* head) {
//     while(head) {
//         printf("%d", head->data);
//         head=head->next;
//     }
// }
main() {
    int n=5;
    node* head=createLinkedList(n);
    if (!head) return 1;
    int f; scanf("%d", &f);
    // print(head);
    if (search(head, f)) {
        printf("YES");
    }else {
        printf("NO");
    }
    while(head) {
        node* tmp=head;
        head=head->next;
        free(tmp);
    }
}
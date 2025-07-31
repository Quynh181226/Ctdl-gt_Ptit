//
// Created by TDG on 16/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
typedef struct Question {
    int id;
    char content[101];
    char topic[101];
    int level;
} Question;
typedef struct sNode {
    Question data;
    struct sNode* next;
} sNode;
typedef struct dNode {
    Question data;
    struct dNode* prev;
    struct dNode* next;
} dNode;
sNode* createSNode(Question ques) {
    sNode* newNode=(sNode*)malloc(sizeof(sNode));
    if (newNode==NULL) return NULL;
    newNode->data=ques;
    newNode->next=NULL;
    return newNode;
}
dNode* createDNode(Question ques) {
    dNode* newNode=(dNode*)malloc(sizeof(dNode));
    if (newNode==NULL) return NULL;
    newNode->data=ques;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}
void addSNode(sNode** head, Question ques) {
    sNode* newNode=createSNode(ques);
    if (newNode==NULL) return;
    if (*head==NULL) {
        *head=newNode;
    }else {
        sNode* tmp=*head;
        while (tmp->next!=NULL) {
            tmp=tmp->next;
        }
        tmp->next=newNode;
    }
}
void addDNode(dNode** head, Question ques) {
    dNode* newNode=(dNode*)malloc(sizeof(dNode));
    if (newNode==NULL) return;
    if (*head==NULL) {
        *head=newNode;
    }else {
        dNode* tmp=*head;
        while (tmp->next!=NULL) {
            tmp=tmp->next;
        }
        tmp->next=newNode;
        newNode->prev=tmp;
    }
}
void printQues(Question ques) {
    printf("ID: %d Content: %s Topic: %s Level: %d\n", ques.id, ques.content, ques.topic, ques.level);
}
void displayStuQues(sNode* head) {
    if (head==NULL) return;
    sNode* tmp=head;
    while (tmp!=NULL) {
        printQues(tmp->data);
        tmp=tmp->next;
    }
}
void displayCompleQues(dNode* head) {
    if (head==NULL) {
        printf("ko co cau hoi nao dang luyen\n");
        return;
    }
    printf("\n===danh sach cau hoi dang luyen===\n");
    dNode* tmp=head;
    while (tmp!=NULL) {
        printQues(tmp->data);
        tmp=tmp->next;
    }
}
void updateQues(sNode* head, int id) {
    sNode* tmp=head;
   while (tmp!=NULL) {
       if (tmp->data.id==id) {
           printf("nhap noi dung ms: ");
           fgets(tmp->data.content, 101, stdin);
           tmp->data.content[strlen(tmp->data.content)-1]='\0';
           printf("nhap chu de ms: ");
           fgets(tmp->data.topic, 101, stdin);
           tmp->data.topic[strlen(tmp->data.topic)-1]='\0';
           printf("nhap do kho ms: ");
           scanf("%d", &tmp->data.level);
           getchar();
           return;
       }
       tmp=tmp->next;
   }
    printf("ko tim thay cau hoi vs ID: %d\n", id);
}
void markQues(sNode** stuHead, dNode** compleHead, int id) {
    if (*stuHead==NULL) return;
    sNode *prev=NULL;
    sNode *curr=*stuHead;
    while (curr!=NULL) {
        if (curr->data.id==id) {
            addDNode(compleHead, curr->data);
            if (prev==NULL) {
                *stuHead=curr->next;
            }else {
                prev->next=curr->next;
            }
            free(curr);
            return;
        }
        prev=curr;
        curr=curr->next;
    }
    printf("Cau hoi vs ID %d khong co\n", id);
}
void searchQues(sNode* head, char keyword) {
    int check=0;
    while (head!=NULL) {
        if (strstr(head->data.content, keyword)!=NULL) {
            printQues(head->data);
            check=1;
        }
        head=head->next;
    }
    if (!check) {
        printf("ko tim thay cau hoi vs tu khoa'%s'\n", keyword);
    }
}
void sortQues(sNode** head) {
    // if (*head==NULL&&(*head)->next==NULL) {
       sNode* curr= *head;
       while (curr!=NULL) {
           sNode* min=curr;
           sNode* tmp=curr->next;
           while (tmp!=NULL) {
               if (strlen(tmp->data.content) < strlen(min->data.content)) {
                   min=tmp;
               }
               tmp=tmp->next;
           }
           if (min!=curr) {
               Question tmp=curr->data;
               curr->data=min->data;
               min->data=tmp;
           }
           curr=curr->next;
    }
}
void freeSList(sNode* head) {
    sNode* tmp;
    while (head!=NULL) {
        tmp=head;
        head=head->next;
        free(tmp);
    }
}
void freeDList(dNode* head) {
    dNode* tmp;
    while (head!=NULL) {
        tmp=head;
        head=head->next;
        free(tmp);
    }
}
main() {
    sNode* stuHead=NULL;
    dNode* compleHead=NULL;
    int id, choice, nextId=1;
    do {
        printf("\n===Interview Question===\n");
        printf("1. Them cau hoi ms\n");
        printf("2. Hien thi danh sach cau hoi dang luyen\n");
        printf("3. Cap nhat noi dung cau hoi\n");
        printf("4. Danh dau cau hoi la da luyen xong\n");
        printf("5. Hien thi danh sach cau hoi da luyen xong\n");
        printf("6. Tim kiem cau hoi theo tu khoa\n");
        printf("7. Sap xep danh sach cau hoi theo do dai tang dan\n");
        printf("8. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                Question ques;
                ques.id=nextId++;
                printf("Nhap noi dung cau hoi: ");
                fgets(ques.content, 101, stdin);
                ques.content[strcspn(ques.content, "\n")]='\0';
                printf("Nhap chu de: ");
                fgets(ques.topic, 101, stdin);
                ques.topic[strcspn(ques.topic, "\n")]='\0';
                printf("Nhap do kho: ");
                scanf("%d", &ques.level);
                getchar();
                addSNode(&stuHead, ques);
                break;
            case 2:
                displayStuQues(stuHead);
                break;
            case 3:
                printf("Nhap ID can cap nhat: ");
                 scanf("%d", &id);
                getchar();
                updateQues(stuHead, id);
                break;
            case 4:
                printf("Nhap ID cau hoi can danh dau: ");
                scanf("%d", &id);
                getchar();
                markQues(&stuHead, &compleHead, id);
                break;
            case 5:
                displayCompleQues(compleHead);
                break;
            case 6:
                char keyword[101];
                printf("Nhap tu khoa can tra: ");
                fgets(keyword, 101, stdin);
                keyword[strlen(keyword)-1]='\0';
                searchQues(stuHead, keyword);
                break;
            case 7:
                sortQues(&stuHead);
                break;
            case 8:
                printf("Thoat chuong trinh");
                freeSList(stuHead);
                freeDList(compleHead);
                break;
            default:
                printf("lua chon ko hop le");
        }
    }while (choice!=8);
}
//
// Created by TDG on 14/07/2025.
//
#include <string.h>
#include <ctype.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct Course {
   int id;
   char title[100];
   int credit;
} Course;
typedef struct sNode {
   Course data;
   struct sNode *next;
} sNode;
typedef struct dNode {
   Course data;
   struct dNode* prev;
   struct dNode* next;
} dNode;
sNode* createSNode(Course course) {
   sNode* newNode=(sNode*)malloc(sizeof(sNode));
   if (newNode==NULL) return NULL;
   newNode->data=course;
   newNode->next=NULL;
   return newNode;
}
dNode* createDNode(Course course) {
   dNode* newNode=(dNode*)malloc(sizeof(sNode));
   if (newNode==NULL) return NULL;
   newNode->data=course;
   newNode->prev=NULL;
   newNode->next=NULL;
   return newNode;
}
//add 1 not ms vao cuoi danh sach lien ket don
void addSNode(sNode** head, Course course) {
   sNode* newNode=createSNode(course);
   //ko the tao ms
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
void addDNode(dNode** head, Course course) {
   dNode* newNode=createDNode(course);
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
//del 1 node khoi danh sach don dua tren ID
void delSNode(sNode** head, int id) {
   //danh sach trong
   if (*head==NULL) return;
   //con tro duyet dsach
   //con tro theo doi node trc do
   sNode* curr=*head;
   sNode* prev=NULL;
   //tim node co id can xoa
   while (curr!=NULL&&curr->data.id!=id) {
      prev=curr;
      curr=curr->next;
   }
   //ko tim thay node
   if (curr==NULL) {
      printf("ko tim thay khoa hoc vs ID: %d\n", id);
      return;
   }
   //del node -> cap nhat con tro cua node trc do
   //neu node can xoa la node dau tien
   //ko thi lket node trc vs node sau node can xoa
   //mấy dòng if else này chưa hiểu
   if (prev==NULL) {
      *head=curr->next;
   }else {
      prev->next=curr->next;
   }
   free(curr);
   //da xoa khoa hoc co ID ....////
}
//add 1 khoa hoc ms vao danh sach dang hoc
void addCourse(sNode** head) {
   Course newCourse;
   //ma khoa hoc
   printf("nhap ma khoa hoc: ");
   scanf("%d", &newCourse.id);
   getchar();
   //check ID da ton tai trg danh sach chua
   sNode* tmp= *head;
    while (tmp!=NULL) {
       if (tmp->data.id==newCourse.id) {
          printf("ma khoa hoc da ton tai\n");
          return;
       }
       tmp=tmp->next;
    }
   //input ten khoa hoc so tin chi
   printf("nhap ten khoa hoc: ");
   fgets(newCourse.title, sizeof(newCourse.title), stdin);
   newCourse.title[strcspn(newCourse.title, "\n")]='\0';
   printf("nhap so tin chi: ");
   scanf("%d", &newCourse.credit);
   //add khoa hoc vao danh sach
   addSNode(head, newCourse);
}
//in thong tin cau 1 khoa hoc
void printCourse(Course course) {
   printf("ID: %d, Name: %s, Tin chi %d\n", course.id, course.title, course.credit);
}
void displayStuHead(sNode* head) {
   //danh sach trong
   if (head==NULL) return;
   sNode* tmp=head;
   while (tmp!=NULL) {
      printCourse(tmp->data);
      tmp=tmp->next;
   }
}
void displayCompleHead(dNode* head) {
   if (head==NULL) return;
   dNode* tmp=head;
   while (tmp!=NULL) {
      printCourse(tmp->data);
      tmp=tmp->next;
   }
}
//hien thi tat ca cac khoa hoc (dg hoc va da hoan thanh)
void displayAllCourses(sNode* stuHead, dNode* compleHead) {
   if (stuHead==NULL && compleHead==NULL) {
      printf("ko co khoa hoc nao\n");
      return;
   }
   if (stuHead==NULL) {
      printf("ko co khoa hoc nao dang hoc\n");
   }else {
      printf("danh sach khoa hoc dang hoc\n");
      displayStuHead(stuHead);
   }
   if (compleHead==NULL) {
      printf("ko co khoa hoc nao da hoan thanh\n");
   }else {
      printf("danh sach khoa hoc da hoan thanh\n");
      displayCompleHead(compleHead);
   }
}
//xoa 1 khoa hoc khoi danh sach dang hoc
void delCourse(sNode** head) {
   if (*head==NULL) return;
   printf("nhap ma khoa hoc can xoa: ");
   int id; scanf("%d", &id);
   delSNode(head, id);
}
//cap nhat thong tin khoa hoc
void updateCourse(sNode* head) {
   //check danh sach khoa hoc
   if (head==NULL) return;
   //ma khoa hoc can cap nhat
   printf("nhap ma khoa hoc can cap nhat: ");
   int id; scanf("%d", &id);
   getchar();
   sNode* tmp=head;
   while (tmp!=NULL&&tmp->data.id!=id) {
      tmp=tmp->next;
   }
   //ko tim thay
   //chưa hiểu sao = null lại là ko tìm thấy
   if (tmp==NULL) {
      printf("ko tim thay khoa hoc vs ID: %d\n");
      return;
   }
   char newTitle[100];
   printf("nhap ten ms: ");
   fgets(newTitle, sizeof(newTitle), stdin);
   newTitle[strcspn(newTitle, "\n")]='\0';
   //neu nhap ten ms cap nhat ten
   // if (strlen(newTitle)>0) {
      strcpy(tmp->data.title, newTitle);
   // }
   printf("nhap so tin chi ms: ");
   int newCredit; scanf("%d", &newCredit);
   // if (newCredit>0) {
      tmp->data.credit=newCredit;
   // }
   //cap nhat xg toan bo khoa hoc
}
//danh dau khoa hoc da hoan thanh
//chuyen tu danh sach lket don sang danh sach lket doi
void comple(sNode** stuHead, dNode** compleHead) {
   if (*stuHead==NULL) return;
   //input ma khoa hoc da hoan thanh
   printf("nhap ma khoa hoc da hoan thanh: ");
   int id; scanf("%d", &id);
   sNode* curr=*stuHead;
   sNode* prev=NULL;
   while (curr!=NULL&&curr->data.id!=id) {
      prev=curr;
      curr=curr->next;
   }
   if (curr==NULL) {
      printf("ko tim thay khoa hoc vs ID: %d\n", id);
      return;
   }
   //add vao danh sach da hoan thanh
   addDNode(compleHead, curr->data);
   //del khoi danh sach dang doc
   if (prev==NULL) {
      *stuHead=curr->next;
   }else {
      prev->next=curr->next;
   }
   free(curr);
}
//sap xep khoa hoc theo so tin chi
void sortCredit(sNode** head) {
   // if (*head==NULL||(*head)->next==NULL) return;
   sNode* curr=*head;
   while (curr!=NULL) {
      //gia su node htai co tin chi nho nhat
      sNode* min=curr;
      sNode* tmp=curr->next;
      // tim node co tin chi nho nhat trg phan chua sxep
      while (tmp!=NULL) {
         if (tmp->data.credit < min->data.credit) {
            min=tmp;
         }
         tmp=tmp->next;
      }
      if (min!=curr) {
         Course tmpData=curr->data;
         curr->data=min->data;
         min->data=tmpData;
      }
      curr=curr->next;
   }
//in
}
void searchName(sNode* head) {
   if (head==NULL) return;
   char search[100];
   getchar();
   printf("nhap ten khoa hoc can tim: ");
   fgets(search, sizeof(search), stdin);
   search[strcspn(search, "\n")]='\0';
   //chuyen chuoi tim kiem thanh chu thuong
   for (int i=0; search[i]; i++) {
      search[i]=tolower(search[i]);
   }
   //tim kiem
   sNode* tmp=head;
   int found=0;
   while (tmp!=NULL) {
      char title[100];
      strcpy(title, tmp->data.title);
      for (int i=0; title[i]; i++) {
         title[i]=tolower(title[i]);
      }
      if (strstr(title, search)!=NULL) {
         printCourse(tmp->data);
         found=1;
      }
      tmp=tmp->next;
   }
   //ko tim thay khoa hoc
   if (!found) {
      printf("ko tim thay khoa hoc\n");
      return;
   }
}
void freeList(sNode* stuHead, dNode* compleHead) {
   //don
   sNode* tmpS=stuHead;
   while (tmpS!=NULL) {
      sNode* next=tmpS->next;
      free(tmpS);
      tmpS=next;
   }
   //doi
   dNode* tmpD=compleHead;
   while (tmpD!=NULL) {
      dNode* next=tmpD->next;
      free(tmpD);
      tmpD=next;
   }
}
main() {
   sNode* stuHead=NULL;
   dNode* compleHead=NULL;
   int choice;
   do{
      printf("\n=====Quan ly khoa hoc=====\n");
      printf("1. Them khoa hoc\n");
      printf("2. Hien thi tat ca cac khoa hoc\n");
      printf("3. Xoa khoa hoc theo ID\n");
      printf("4. Cap nhat khoa hoc\n");
      printf("5. Danh dau khoa hoc da hoan thanh\n");
      printf("6. Sap xep khoa hoc theo tin chi\n");
      printf("7. Tim kiem khoa hoc theo ten\n");
      printf("8. Thoat\n");
      printf("Input your choice: ");
      scanf("%d", &choice);
      getchar();
      switch (choice) {
         case 1:
            addCourse(&stuHead);
            break;
         case 2:
            displayAllCourses(stuHead, compleHead);
            break;
         case 3:
            delCourse(&stuHead);
            break;
         case 4:
            updateCourse(stuHead);
            break;
         case 5:
            comple(&stuHead, &compleHead);
            break;
         case 6:
            sortCredit(&stuHead);
            break;
         case 7:
            searchName(stuHead);
            break;
         case 8:
            printf("Thoat chuong trinh\n");
            freeList(stuHead, compleHead);
            return 0;
         default:
            printf("Invalid choice\n");
      }
   }while (choice!=8);
}
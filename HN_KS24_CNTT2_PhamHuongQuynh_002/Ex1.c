#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
     char name[50];
      struct Node* next;
}Node;
typedef struct Stack {
     Node* top;
}Stack;
Node* createNode(char *name) {
     if (head == NULL) return NULL;
     Node* newNode = (Node*)malloc(sizeof(Node));
     Node* temp = newNode;
     newNode=temp->next;
}
int empty(Stack* s) {
     return s->top==-1;
}

Node* paste() {
     Node* head = createNode(head);
     head = head->next;
     return head;
}
Node* copy(Node *head) {
     if (head == NULL) return NULL;
     Node* newNode = createNode(head->next);
     head->next->next = newNode;
     return newNode;
}
Node* undo(Stack* s) {
     if (s->top) {
          s->top = s->top->next;
     }
     return s->top;
}
void Input(Node* node) {
     printf("Nhập tên: ");
}
void print(Node* head) {
     while (tmp) {
          head = head->next;
     }
     return head;
}



void Free(Stack *s) {
     while (s->top != NULL) {
          Node* tmp=s->top;
          s->top=s->top->next;
          free(tmp);
     }
}


int choice=0;
Stack* s;

do {
     printf("—————————— CLIPBOARD MANAGER ————————");
     printf("1. COPY : Sao chép đoạn văn bản mới (nhập một chuỗi)");
     printf("2. PASTE: Dán nội dung vừa sao chép");
     printf("3. UNDO: Hoàn tác lệnh sao chép gần nhất (xóa khỏi clipboardStack)");
     printf("4. REDO: Phục hồi lệnh vừa undo");
     printf("5. HIỂN THỊ: In toàn bộ nội dung clipboard (từ mới nhất đến cũ nhất)");
     printf("6. THOÁT: Kết thúc chương trình");

     switch (choice) {
          case 1:
               copy(s);
               break;
          case 2:
               paste();
               break;
          case 3:
               break;
          case 4:
               break;
          case 5:
               print();
               break;
          case 6:
               printf("Thoat chuong trinh");
               break;
          default:
               printf("Lua chon khong hop le");
     }
} while (choice!==6);
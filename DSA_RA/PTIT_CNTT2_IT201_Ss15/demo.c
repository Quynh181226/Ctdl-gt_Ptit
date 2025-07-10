//
// Created by TDG on 10/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
//
// Created by DELL on 7/10/2025.
//
// THAO TÁC VỚI HÀNG ĐỢI SỬ DỤNG DANH SÁCH LIÊN KẾT
// BƯỚC 1:
typedef struct Node {
    int data;
    struct Node* next;
    // struct Node* prev;
}Node;
typedef struct {
    Node* front; // trỏ đến phần tử đầu tiên của hàng đợi
    Node* rear;  // trỏ đến phần tử cuối cùng
}Queue;
// BƯỚC 2: không có phần tử nào thì front và rear đều là NULL
void initQueue(Queue* queue) {
    queue->front=NULL;
    queue->rear=NULL;
}

// BƯỚC 3:
int isEmptyQueue(Queue* queue) {
    return queue->front==NULL;
}
// kết quả trả về của hàm nếu là 1 tức là không có phần tử, khác 1 có phần tử
// BƯỚC 4:
void enQueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode==NULL) {
        printf("khong the cap phat o nho\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    // nếu hàng đợi không có phần tử nào thì front và rear gán bằng newNode
    if (isEmptyQueue(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }else {
        queue->rear->next = newNode;// liên kết với node cuối
        queue->rear = newNode; // cập nhật lại rear phần tử cuối cùng của hàng đợi
    }
}
// BƯỚC 5: XÓA
int deQueue(Queue* q) {
    // KIEM TRA HANG DOI CO PHAN TU HAY KHONG
    if (isEmptyQueue(q)) {
        printf("hang doi rong\n");
        return -1;
    }
    Node* temp = q->front; // tạo con trỏ, trỏ tới phần tử đầu tiên của hàng đợi
    // để sau này các em free()
    int value = temp->data;// lưu giá trị phan tử cần xóa
    // cập nhật lại phần tử đầu của hàng đợi
    q->front = q->front->next;
    if (q->front == NULL) {
        // không còn phần tu nào trong hàng đợi thì phải gán giá trị rear về NULL
        q->rear = NULL;
    }
    // giải phóng phần tử
    free(temp);
    return value;
}
// BƯỚC 6: HIỂN THỊ PHẦN TỬ ĐẦU TIÊN TRONG HÀNG ĐỢI
int frontValue(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("hang doi rong\n");
        return -1;
    }
    return q->front->data;
}
// BƯỚC 7: HIỂN THỊ
void displayQueue(Queue* q) {
     if (isEmptyQueue(q)) {
         printf("hang doi rong\n");
         return;
     }
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
// BƯỚC 8: TRIỂN KHAI TRONG MAIN

int main() {
    Queue q;
    // gọi hàm khởi tạo
    initQueue(&q);
    enQueue(&q, 1);
    enQueue(&q, 2);
    enQueue(&q, 3);
    enQueue(&q, 4);
    enQueue(&q, 5);
    printf("%d\n", deQueue(&q));
    // displayQueue(&q);
    printf("phan tu dinh la: %d\n", frontValue(&q));
}
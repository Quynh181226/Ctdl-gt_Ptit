#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PHONE_LEN 20

// Cấu trúc lưu thông tin cuộc gọi
typedef struct {
    char phone[PHONE_LEN];
    time_t callTime;
} Call;

// Node cho Stack (danh sách liên kết đơn)
typedef struct StackNode {
    Call data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

// Node cho Queue (danh sách liên kết đơn)
typedef struct QueueNode {
    Call data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// --- Hàm Stack ---
void initStack(Stack* s) {
    s->top = NULL;
}

int isEmptyStack(Stack* s) {
    return s->top == NULL;
}

void pushStack(Stack* s, Call c) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    if (!node) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    node->data = c;
    node->next = s->top;
    s->top = node;
}

Call popStack(Stack* s) {
    if (isEmptyStack(s)) {
        printf("Stack rong!\n");
        exit(1);
    }
    StackNode* temp = s->top;
    Call c = temp->data;
    s->top = temp->next;
    free(temp);
    return c;
}

Call peekStack(Stack* s) {
    if (isEmptyStack(s)) {
        printf("Stack rong!\n");
        exit(1);
    }
    return s->top->data;
}

int stackSize(Stack* s) {
    int count = 0;
    StackNode* cur = s->top;
    while (cur) {
        count++;
        cur = cur->next;
    }
    return count;
}

void clearStack(Stack* s) {
    while (!isEmptyStack(s)) {
        popStack(s);
    }
}

// --- Hàm Queue ---
void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

int isEmptyQueue(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, Call c) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    if (!node) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    node->data = c;
    node->next = NULL;
    if (isEmptyQueue(q)) {
        q->front = q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
}

Call dequeue(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue rong!\n");
        exit(1);
    }
    QueueNode* temp = q->front;
    Call c = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return c;
}

void clearQueue(Queue* q) {
    while (!isEmptyQueue(q)) {
        dequeue(q);
    }
}

// Hiển thị thông tin cuộc gọi
void printCall(Call c) {
    char timebuf[26];
    struct tm* tm_info = localtime(&c.callTime);
    strftime(timebuf, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    printf("So dien thoai: %-15s  Thoi gian goi: %s\n", c.phone, timebuf);
}

// Nhập số điện thoại
void inputPhone(char* buffer, int size) {
    printf("Nhap so dien thoai: ");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Loại bỏ newline
    if (strlen(buffer) == 0) {
        printf("So dien thoai khong duoc rong. Vui long nhap lai.\n");
        inputPhone(buffer, size);
    }
}

int main() {
    Stack callBackStack, callForwardStack;
    Queue callHistoryQueue;

    initStack(&callBackStack);
    initStack(&callForwardStack);
    initQueue(&callHistoryQueue);

    char command[20];

    printf("=== CHUONG TRINH QUAN LY LICH SU CUOC GOI ===\n");
    while(1) {
        printf("\nCAC LUA CHON: CALL, BACK, REDIAL, HISTORY, EXIT\n");
        printf("Nhap lenh: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if(strcasecmp(command, "CALL") == 0) {
            Call newCall;
            inputPhone(newCall.phone, PHONE_LEN);
            newCall.callTime = time(NULL);

            pushStack(&callBackStack, newCall);
            enqueue(&callHistoryQueue, newCall);
            clearStack(&callForwardStack);

            printf("Da goi so: %s\n", newCall.phone);
        }
        else if(strcasecmp(command, "BACK") == 0) {
            if(stackSize(&callBackStack) < 2) {
                printf("Khong co cuoc goi nao truoc do.\n");
            } else {
                Call topCall = popStack(&callBackStack);
                pushStack(&callForwardStack, topCall);

                Call currentTop = peekStack(&callBackStack);
                printf("Quay lai so: %s\n", currentTop.phone);
            }
        }
        else if(strcasecmp(command, "REDIAL") == 0) {
            if(isEmptyStack(&callForwardStack)) {
                printf("Khong co so nao de goi lai.\n");
            } else {
                Call toRedial = popStack(&callForwardStack);
                pushStack(&callBackStack, toRedial);
                printf("Goi lai so: %s\n", toRedial.phone);
            }
        }
        else if(strcasecmp(command, "HISTORY") == 0) {
            if(isEmptyQueue(&callHistoryQueue)) {
                printf("Chua co cuoc goi nao.\n");
            } else {
                printf("=== LICH SU CUOC GOI ===\n");
                QueueNode* cur = callHistoryQueue.front;
                int i = 1;
                while(cur) {
                    printf("%d. ", i++);
                    printCall(cur->data);
                    cur = cur->next;
                }
                printf("=======================\n");
            }
        }
        else if(strcasecmp(command, "EXIT") == 0) {
            printf("Thoat chuong trinh.\n");
            break;
        }
        else {
            printf("Lenh khong hop le, vui long nhap lai.\n");
        }
    }

    clearStack(&callBackStack);
    clearStack(&callForwardStack);
    clearQueue(&callHistoryQueue);

    return 0;
}

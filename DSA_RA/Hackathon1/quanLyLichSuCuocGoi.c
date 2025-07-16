#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PHONE_LEN 20

// Cấu trúc Call lưu số và thời gian gọi
typedef struct {
    char phone[PHONE_LEN];
    time_t callTime;
} Call;

// Node Stack đơn liên kết
typedef struct StackNode {
    Call data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} Stack;

// Node Queue đơn liên kết
typedef struct QueueNode {
    Call data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// --- Hàm xử lý Stack ---
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
    StackNode* tmp = s->top;
    Call c = tmp->data;
    s->top = tmp->next;
    free(tmp);
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
    StackNode* tmp = s->top;
    while(tmp) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

void clearStack(Stack* s) {
    while (!isEmptyStack(s)) {
        popStack(s);
    }
}

// --- Hàm xử lý Queue ---
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

// --- Hàm hiển thị Call ---
void printCall(Call c) {
    char timebuf[26];
    struct tm* tm_info = localtime(&c.callTime);
    strftime(timebuf, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    printf("So: %-15s  Thoi gian: %s\n", c.phone, timebuf);
}

// --- Hàm nhập số điện thoại ---
void inputPhone(char* buffer, int size) {
    printf("Nhap so dien thoai: ");
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Xóa newline
    // Kiểm tra rỗng
    if(strlen(buffer) == 0) {
        printf("So dien thoai khong duoc rong!\n");
        inputPhone(buffer, size);
    }
}

// --- Main ---
int main() {
    Stack callBackStack, callForwardStack;
    Queue callHistoryQueue;

    initStack(&callBackStack);
    initStack(&callForwardStack);
    initQueue(&callHistoryQueue);

    char choice[20];

    printf("=== CALL HISTORY MANAGER ===\n\n");

    while(1) {
        printf("\nChoose command: CALL, BACK, REDIAL, HISTORY, EXIT\n");
        printf("Nhap lenh: ");
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = '\0';

        if (strcasecmp(choice, "CALL") == 0) {
            Call newCall;
            inputPhone(newCall.phone, PHONE_LEN);
            newCall.callTime = time(NULL);

            // Push số mới vào backStack và lịch sử queue
            pushStack(&callBackStack, newCall);
            enqueue(&callHistoryQueue, newCall);

            // Reset forwardStack
            clearStack(&callForwardStack);

            printf("Da goi so: %s\n", newCall.phone);
        }
        else if (strcasecmp(choice, "BACK") == 0) {
            if (stackSize(&callBackStack) < 2) {
                printf("Khong co cuoc goi nao truoc do.\n");
            } else {
                // Pop top hiện tại, push sang forwardstack
                Call topCall = popStack(&callBackStack);
                pushStack(&callForwardStack, topCall);

                // Hiển thị số giờ trên top backStack (cuộc gọi trước đó)
                Call currentTop = peekStack(&callBackStack);
                printf("Quay lai so: %s\n", currentTop.phone);
            }
        }
        else if (strcasecmp(choice, "REDIAL") == 0) {
            if (isEmptyStack(&callForwardStack)) {
                printf("Khong co so nao de goi lai.\n");
            } else {
                // Lấy số trên forwardStack pop ra, push vào backStack
                Call toRedial = popStack(&callForwardStack);
                pushStack(&callBackStack, toRedial);
                printf("Goị lai so: %s\n", toRedial.phone);
            }
        }
        else if (strcasecmp(choice, "HISTORY") == 0) {
            if (isEmptyQueue(&callHistoryQueue)) {
                printf("Chua co cuoc goi nao.\n");
            } else {
                printf("=== Lich su cuoc goi ===\n");
                QueueNode* cur = callHistoryQueue.front;
                int count = 1;
                while(cur) {
                    printf("%d. ", count++);
                    printCall(cur->data);
                    cur = cur->next;
                }
                printf("=======================\n");
            }
        }
        else if (strcasecmp(choice, "EXIT") == 0) {
            printf("Thoat chuong trinh.\n");
            break;
        } else {
            printf("Lenh khong hop le, vui long nhap lai.\n");
        }
    }

    // Giải phóng bộ nhớ
    clearStack(&callBackStack);
    clearStack(&callForwardStack);
    clearQueue(&callHistoryQueue);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 256

typedef struct Question {
    int id;
    char content[MAX_STR];
    char topic[MAX_STR];
    int level; // 1 - 5
} Question;

// Node danh sách đơn (chưa luyện)
typedef struct sNode {
    Question data;
    struct sNode* next;
} sNode;

// Node danh sách đôi (đã luyện)
typedef struct dNode {
    Question data;
    struct dNode* prev;
    struct dNode* next;
} dNode;

// Tạo node đơn
sNode* createSNode(Question q) {
    sNode* node = (sNode*)malloc(sizeof(sNode));
    if (!node) exit(1);
    node->data = q;
    node->next = NULL;
    return node;
}

// Tạo node đôi
dNode* createDNode(Question q) {
    dNode* node = (dNode*)malloc(sizeof(dNode));
    if (!node) exit(1);
    node->data = q;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// Thêm câu hỏi mới vào danh sách đơn cuối cùng
void addQuestion(sNode** head, Question q) {
    sNode* newNode = createSNode(q);
    if (*head == NULL) {
        *head = newNode;
    } else {
        sNode* cur = *head;
        while (cur->next) cur = cur->next;
        cur->next = newNode;
    }
}

// Hiển thị danh sách câu hỏi đơn
void displaySimpleList(sNode* head) {
    if (head == NULL) {
        printf("Danh sach câu hỏi đang luyện trống.\n");
        return;
    }
    printf("\n--- Danh sach cau hoi dang luyen ---\n");
    while (head) {
        printf("ID: %d\nContent: %s\nTopic: %s\nLevel: %d\n\n",
               head->data.id, head->data.content, head->data.topic, head->data.level);
        head = head->next;
    }
}

// Hiển thị danh sách câu hỏi đôi
void displayDoubleList(dNode* head) {
    if (head == NULL) {
        printf("Danh sach câu hỏi đã luyện xong trống.\n");
        return;
    }
    printf("\n--- Danh sach cau hoi da luyen xong ---\n");
    while (head) {
        printf("ID: %d\nContent: %s\nTopic: %s\nLevel: %d\n\n",
               head->data.id, head->data.content, head->data.topic, head->data.level);
        head = head->next;
    }
}

// Tìm câu hỏi trong danh sách đơn theo ID, trả về node và node trước
sNode* findQuestionById(sNode* head, int id, sNode** prev) {
    *prev = NULL;
    while (head && head->data.id != id) {
        *prev = head;
        head = head->next;
    }
    return head;
}

// Cập nhật câu hỏi theo ID
void updateQuestion(sNode* head, int id) {
    while (head && head->data.id != id) head = head->next;
    if (head == NULL) {
        printf("Khong tim thay cau hoi voi ID %d\n", id);
        return;
    }
    printf("Nhap noi dung moi: ");
    fgets(head->data.content, MAX_STR, stdin);
    head->data.content[strcspn(head->data.content, "\n")] = 0;
    printf("Nhap chu de moi: ");
    fgets(head->data.topic, MAX_STR, stdin);
    head->data.topic[strcspn(head->data.topic, "\n")] = 0;
    printf("Nhap do kho moi (1-5): ");
    scanf("%d", &head->data.level);
    getchar();
    printf("Cap nhat thanh cong.\n");
}

// Chuyển câu hỏi từ danh sách đơn sang danh sách đôi theo ID
void markQuestionDone(sNode** srcHead, dNode** doneHead, int id) {
    sNode *prev = NULL, *cur = findQuestionById(*srcHead, id, &prev);
    if (cur == NULL) {
        printf("Khong tim thay cau hoi voi ID %d\n", id);
        return;
    }
    // Thêm câu hỏi vào danh sách đôi
    dNode* newDone = createDNode(cur->data);
    if (*doneHead == NULL) {
        *doneHead = newDone;
    } else {
        dNode* tmp = *doneHead;
        while (tmp->next) tmp = tmp->next;
        tmp->next = newDone;
        newDone->prev = tmp;
    }
    // Xóa câu hỏi khỏi danh sách đơn
    if (prev == NULL) {
        *srcHead = cur->next;
    } else {
        prev->next = cur->next;
    }
    free(cur);
    printf("Da danh dau cau hoi ID %d la da luyen xong.\n", id);
}

// Tìm câu hỏi theo từ khóa trong content trong danh sách đơn
void searchQuestionsByKeyword(sNode* head, char* keyword) {
    int found = 0;
    while (head) {
        if (strstr(head->data.content, keyword) != NULL) {
            printf("ID: %d\nContent: %s\nTopic: %s\nLevel: %d\n\n",
                   head->data.id, head->data.content, head->data.topic, head->data.level);
            found = 1
        }
        head = head->next;
    }
    if (!found) printf("Khong tim thay cau hoi voi tu khoa '%s'\n", keyword);
}

// Sắp xếp danh sách đơn theo độ dài nội dung tăng dần (selection sort)
void sortQuestionsByLength(sNode** head) {
    if (*head == NULL || (*head)->next == NULL) return;
    sNode* i = *head;
    while (i) {
        sNode* min = i;
        sNode* j = i->next;
        while (j) {
            if (strlen(j->data.content) < strlen(min->data.content)) {
                min = j;
            }
            j = j->next;
        }
        if (min != i) {
            Question temp = i->data;
            i->data = min->data;
            min->data = temp;
        }
        i = i->next;
    }
    printf("Da sap xep danh sach câu hỏi theo do dai noi dung tang dan.\n");
}

// Giải phóng danh sách đơn
void freeSList(sNode* head) {
    sNode* tmp;
    while(head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

// Giải phóng danh sách đôi
void freeDList(dNode* head) {
    dNode* tmp;
    while(head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    sNode* toPractice = NULL;
    dNode* practiced = NULL;
    int choice;
    int nextId = 1;

    do {
        printf("\n===== INTERVIEW QUESTIONS MENU =====\n");
        printf("1. Them cau hoi moi\n");
        printf("2. Hien thi danh sach cau hoi dang luyen\n");
        printf("3. Cap nhat cau hoi\n");
        printf("4. Danh dau cau hoi da luyen xong\n");
        printf("5. Hien thi danh sach cau hoi da luyen xong\n");
        printf("6. Tim kiem cau hoi theo tu khoa\n");
        printf("7. Sap xep cau hoi theo do dai noi dung\n");
        printf("8. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1: {
                Question q;
                q.id = nextId++;
                printf("Nhap noi dung cau hoi: ");
                fgets(q.content, MAX_STR, stdin);
                q.content[strcspn(q.content, "\n")] = 0;
                printf("Nhap chu de: ");
                fgets(q.topic, MAX_STR, stdin);
                q.topic[strcspn(q.topic, "\n")] = 0;
                printf("Nhap do kho (1-5): ");
                scanf("%d", &q.level);
                getchar();
                addQuestion(&toPractice, q);
                break;
            }
            case 2:
                displaySimpleList(toPractice);
                break;
            case 3: {
                int id; printf("Nhap ID de cap nhat: ");
                scanf("%d", &id);
                getchar();
                updateQuestion(toPractice, id);
                break;
            }
            case 4: {
                int id; printf("Nhap ID de danh dau: ");
                scanf("%d", &id);
                getchar();
                markQuestionDone(&toPractice, &practiced, id);
                break;
            }
            case 5:
                displayDoubleList(practiced);
                break;
            case 6: {
                char keyword[MAX_STR];
                printf("Nhap tu khoa tim kiem: ");
                fgets(keyword, MAX_STR, stdin);
                keyword[strcspn(keyword, "\n")] = 0;
                searchQuestionsByKeyword(toPractice, keyword);
                break;
            }
            case 7:
                sortQuestionsByLength(&toPractice);
                break;
            case 8:
                printf("Thoat chuong trinh...\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }

    } while(choice != 8);

    freeSList(toPractice);
    freeDList(practiced);
    return 0;
}

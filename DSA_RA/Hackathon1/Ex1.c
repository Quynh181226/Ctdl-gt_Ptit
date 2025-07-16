#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Task {
    int id;
    char title[100];
    int priority;
    char deadline[20];
} Task;

typedef struct sNode {
    Task data;
    struct sNode* next;
} sNode; // Danh sách đơn

typedef struct dNode {
    Task data;
    struct dNode* prev;
    struct dNode* next;
} dNode; // Danh sách đôi

// Hàm tạo node đơn
sNode* createSNode(Task t) {
    sNode* newNode = (sNode*)malloc(sizeof(sNode));
    newNode->data = t;
    newNode->next = NULL;
    return newNode;
}

// Tạo node đôi
dNode* createDNode(Task t) {
    dNode* newNode = (dNode*)malloc(sizeof(dNode));
    newNode->data = t;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// -- Thêm nhiệm vụ cuối danh sách đơn --
void addTask(sNode** head, Task t) {
    sNode* newNode = createSNode(t);
    if (*head == NULL) {
        *head = newNode;
    } else {
        sNode* cur = *head;
        while (cur->next) cur = cur->next;
        cur->next = newNode;
    }
}

// -- Hiển thị danh sách đơn --
void displayTasks(sNode* head) {
    if (head == NULL) {
        printf("Danh sach trong\n");
        return;
    }
    while (head) {
        printf("ID: %d, Title: %s, Priority: %d, Deadline: %s\n",
            head->data.id, head->data.title, head->data.priority, head->data.deadline);
        head = head->next;
    }
}

// -- Tìm node theo ID --
sNode* findTaskById(sNode* head, int id, sNode** prev) {
    *prev = NULL;
    while (head && head->data.id != id) {
        *prev = head;
        head = head->next;
    }
    return head; // NULL nếu ko tìm thấy
}

// -- Xóa node theo ID --
void deleteTask(sNode** head, int id) {
    sNode* prev = NULL;
    sNode* cur = findTaskById(*head, id, &prev);
    if (cur == NULL) {
        printf("Khong tim thay ID %d\n", id);
        return;
    }
    if (prev == NULL) {
        *head = cur->next;
    } else {
        prev->next = cur->next;
    }
    free(cur);
    printf("Da xoa nhiem vu ID %d\n", id);
}

// -- Cập nhật thông tin nhiệm vụ --
void updateTask(sNode* head, int id) {
    while (head && head->data.id != id) head = head->next;
    if (head == NULL) {
        printf("Khong tim thay ID %d\n", id);
        return;
    }
    printf("Nhap ten moi: ");
    fgets(head->data.title, sizeof(head->data.title), stdin);
    head->data.title[strcspn(head->data.title, "\n")] = 0;
    printf("Nhap deadline moi: ");
    fgets(head->data.deadline, sizeof(head->data.deadline), stdin);
    head->data.deadline[strcspn(head->data.deadline, "\n")] = 0;
    printf("Nhap priority moi: ");
    scanf("%d", &head->data.priority);
    getchar();
    printf("Cap nhat thanh cong!\n");
}

// -- Thêm node vào danh sách đôi --
void addCompletedTask(dNode** head, Task t) {
    dNode* newNode = createDNode(t);
    if (*head == NULL) {
        *head = newNode;
    } else {
        dNode* cur = *head;
        while (cur->next) cur = cur->next;
        cur->next = newNode;
        newNode->prev = cur;
    }
}

// -- Đánh dấu hoàn thành --
void markTaskDone(sNode** todoHead, dNode** doneHead, int id) {
    sNode* prev = NULL;
    sNode* cur = findTaskById(*todoHead, id, &prev);
    if (cur == NULL) {
        printf("Khong tim thay ID %d\n", id);
        return;
    }

    // Copy dữ liệu sang danh sách đôi
    addCompletedTask(doneHead, cur->data);

    // Xóa khỏi danh sách đơn
    if (prev == NULL) {
        *todoHead = cur->next;
    } else {
        prev->next = cur->next;
    }
    free(cur);
    printf("Da danh dau nhiem vu ID %d hoan thanh.\n", id);
}

// -- Sắp xếp theo priority (nổi bọt) --
void sortTasksByPriority(sNode** head) {
    if (*head == NULL) return;
    int swapped;
    sNode* ptr1;
    sNode* lptr = NULL;
    do {
        swapped = 0;
        ptr1 = *head;
        while (ptr1->next != lptr) {
            if (ptr1->data.priority > ptr1->next->data.priority) {
                Task temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// -- Tìm kiếm theo tiêu đề --
void searchTaskByTitle(sNode* head, char* keyword) {
    int found = 0;
    while (head) {
        if (strstr(head->data.title, keyword)) {
            printf("ID: %d, Title: %s, Priority: %d, Deadline: %s\n",
                head->data.id, head->data.title, head->data.priority, head->data.deadline);
            found = 1;
        }
        head = head->next;
    }
    if (!found) printf("Khong tim thay nhiem vu nao.\n");
}

// -- Thoát: Giải phóng cả 2 danh sách --
void freeSList(sNode* head) {
    while (head) {
        sNode* temp = head;
        head = head->next;
        free(temp);
    }
}

void freeDList(dNode* head) {
    while (head) {
        dNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    sNode* todoList = NULL;   // danh sách nhiệm vụ đang làm
    dNode* doneList = NULL;   // danh sách nhiệm vụ đã xong

    int choice;
    Task t;
    while (1) {
        printf("\n----- TASK MANAGER -----\n");
        printf("1. Them nhiem vu\n");
        printf("2. Hien thi danh sach\n");
        printf("3. Xoa nhiem vu\n");
        printf("4. Cap nhat nhiem vu\n");
        printf("5. Danh dau hoan thanh\n");
        printf("6. Sap xep theo priority\n");
        printf("7. Tim kiem\n");
        printf("8. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhap ID: "); scanf("%d", &t.id); getchar();
                printf("Nhap tieu de: ");
                fgets(t.title, sizeof(t.title), stdin);
                t.title[strcspn(t.title, "\n")] = 0;
                printf("Nhap deadline: ");
                fgets(t.deadline, sizeof(t.deadline), stdin);
                t.deadline[strcspn(t.deadline, "\n")] = 0;
                printf("Nhap priority: "); scanf("%d", &t.priority); getchar();

                addTask(&todoList, t);
                printf("Da them nhiem vu.\n");
                break;
            case 2:
                printf("Danh sach nhiem vu dang lam:\n");
                displayTasks(todoList);
                printf("\nDanh sach nhiem vu da hoan thanh:\n");
                dNode* temp = doneList;
                while (temp) {
                    printf("ID: %d, Title: %s, Priority: %d, Deadline: %s\n",
                        temp->data.id, temp->data.title, temp->data.priority, temp->data.deadline);
                    temp = temp->next;
                }
                break;
            case 3:
                printf("Nhap ID can xoa: ");
                int delId;
                scanf("%d", &delId); getchar();
                deleteTask(&todoList, delId);
                break;
            case 4:
                printf("Nhap ID can cap nhat: ");
                int upId;
                scanf("%d", &upId); getchar();
                updateTask(todoList, upId);
                break;
            case 5:
                printf("Nhap ID can danh dau hoan thanh: ");
                int doneId;
                scanf("%d", &doneId); getchar();
                markTaskDone(&todoList, &doneList, doneId);
                break;
            case 6:
                sortTasksByPriority(&todoList);
                printf("Da sap xep danh sach theo priority tang dan.\n");
                break;
            case 7:
                {
                    char keyword[100];
                    printf("Nhap tu khoa tim kiem trong tieu de: ");
                    fgets(keyword, sizeof(keyword), stdin);
                    keyword[strcspn(keyword, "\n")] = 0;
                    searchTaskByTitle(todoList, keyword);
                }
                break;
            case 8:
                freeSList(todoList);
                freeDList(doneList);
                printf("Thoat.\n");
                return 0;
            default:
                printf("Lua chon khong hop le.\n");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Để lấy thời gian cho Date (có thể dùng giả lập hoặc thực tế)

#define MAX_STR_LEN 100

// Cấu trúc Activity
typedef struct Activity {
    int id;
    char type[MAX_STR_LEN];
    int duration; // in minutes
    int calories;
    char date[MAX_STR_LEN]; // Format: YYYY-MM-DD
} Activity;

// Node của danh sách liên kết đơn
typedef struct SNode {
    Activity data;
    struct SNode* next;
} SNode;

// Hàm tạo một SNode mới
SNode* createSNode(Activity act) {
    SNode* newNode = (SNode*)malloc(sizeof(SNode));
    if (newNode == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    newNode->data = act;
    newNode->next = NULL;
    return newNode;
}

// 1. Thêm hoạt động vào danh sách
void addActivity(SNode** head, Activity act) {
    SNode* newNode = createSNode(act);
    if (*head == NULL) {
        *head = newNode;
    } else {
        SNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("Da them hoat dong ID: %d\n", act.id);
}

// 2. Hiển thị danh sách hoạt động
void displayActivities(SNode* head) {
    if (head == NULL) {
        printf("Danh sach hoat dong trong.\n");
        return;
    }
    printf("\n=== DANH SACH HOAT DONG ===\n");
    while (head != NULL) {
        printf("ID: %d\n", head->data.id);
        printf("  Loai: %s\n", head->data.type);
        printf("  Thoi luong: %d phut\n", head->data.duration);
        printf("  Calories: %d kcal\n", head->data.calories);
        printf("  Ngay: %s\n", head->data.date);
        printf("---------------------------\n");
        head = head->next;
    }
}

// 3. Xóa hoạt động theo ID
void deleteActivity(SNode** head, int id) {
    if (*head == NULL) {
        printf("Danh sach trong, khong the xoa.\n");
        return;
    }

    SNode* current = *head;
    SNode* prev = NULL;

    // Tìm hoạt động cần xóa
    while (current != NULL && current->data.id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Khong tim thay hoat dong voi ID: %d\n", id);
        return;
    }

    // Xóa node
    if (prev == NULL) { // Nếu là node đầu tiên
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    printf("Da xoa hoat dong ID: %d\n", id);
}

// 4. Cập nhật thông tin hoạt động
void updateActivity(SNode* head, int id) {
    if (head == NULL) {
        printf("Danh sach trong, khong the cap nhat.\n");
        return;
    }

    SNode* current = head;
    while (current != NULL && current->data.id != id) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Khong tim thay hoat dong voi ID: %d\n", id);
        return;
    }

    printf("Cap nhat hoat dong ID: %d\n", id);
    printf("Nhap loai moi (%s): ", current->data.type);
    fgets(current->data.type, sizeof(current->data.type), stdin);
    current->data.type[strcspn(current->data.type, "\n")] = '\0';

    printf("Nhap thoi luong moi (%d phut): ", current->data.duration);
    scanf("%d", &current->data.duration);
    getchar(); // Clear newline

    printf("Nhap calories moi (%d kcal): ", current->data.calories);
    scanf("%d", &current->data.calories);
    getchar(); // Clear newline

    printf("Nhap ngay moi (YYYY-MM-DD) (%s): ", current->data.date);
    fgets(current->data.date, sizeof(current->data.date), stdin);
    current->data.date[strcspn(current->data.date, "\n")] = '\0';

    printf("Cap nhat hoat dong thanh cong!\n");
}

// 5. Thống kê tổng calories tiêu thụ/ngày
void calculateDailyCalories(SNode* head) {
    if (head == NULL) {
        printf("Danh sach hoat dong trong.\n");
        return;
    }
    char targetDate[MAX_STR_LEN];
    printf("Nhap ngay can thong ke (YYYY-MM-DD): ");
    fgets(targetDate, sizeof(targetDate), stdin);
    targetDate[strcspn(targetDate, "\n")] = '\0';

    int totalCalories = 0;
    SNode* current = head;
    while (current != NULL) {
        if (strcmp(current->data.date, targetDate) == 0) {
            totalCalories += current->data.calories;
        }
        current = current->next;
    }
    printf("Tong calories tieu thu vao ngay %s: %d kcal\n", targetDate, totalCalories);
}

// 6. Sắp xếp hoạt động theo calories tiêu thụ (Sắp xếp lựa chọn)
void sortActivitiesByCalories(SNode** head) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("Khong du hoat dong de sap xep.\n");
        return;
    }

    SNode* current = *head;
    while (current != NULL) {
        SNode* minNode = current;
        SNode* temp = current->next;
        while (temp != NULL) {
            if (temp->data.calories < minNode->data.calories) {
                minNode = temp;
            }
            temp = temp->next;
        }
        // Hoán đổi dữ liệu giữa current và minNode
        if (minNode != current) {
            Activity tempData = current->data;
            current->data = minNode->data;
            minNode->data = tempData;
        }
        current = current->next;
    }
    printf("Da sap xep hoat dong theo calories tieu thu tang dan.\n");
}

// 7. Tìm kiếm hoạt động theo kiểu (type)
void searchActivitiesByType(SNode* head) {
    if (head == NULL) {
        printf("Danh sach hoat dong trong.\n");
        return;
    }
    char searchType[MAX_STR_LEN];
    printf("Nhap loai hoat dong can tim: ");
    fgets(searchType, sizeof(searchType), stdin);
    searchType[strcspn(searchType, "\n")] = '\0';

    int found = 0;
    SNode* current = head;
    printf("\n=== KET QUA TIM KIEM ===\n");
    while (current != NULL) {
        if (strstr(current->data.type, searchType) != NULL) { // Tìm kiếm chuỗi con
            printf("ID: %d\n", current->data.id);
            printf("  Loai: %s\n", current->data.type);
            printf("  Thoi luong: %d phut\n", current->data.duration);
            printf("  Calories: %d kcal\n", current->data.calories);
            printf("  Ngay: %s\n", current->data.date);
            printf("---------------------------\n");
            found = 1;
        }
        current = current->next;
    }
    if (!found) {
        printf("Khong tim thay hoat dong loai '%s'.\n", searchType);
    }
}

// Giải phóng bộ nhớ
void freeList(SNode* head) {
    SNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Hàm hỗ trợ nhập số nguyên với getchar()
int getIntInput() {
    int num;
    scanf("%d", &num);
    getchar(); // consume the newline character
    return num;
}

int main() {
    SNode* activityList = NULL;
    int choice;
    int nextId = 1; // Tự động tăng ID

    do {
        printf("\n======== HEALTH TRACKER MENU ========\n");
        printf("1. Them hoat dong\n");
        printf("2. Hien thi danh sach hoat dong\n");
        printf("3. Xoa hoat dong\n");
        printf("4. Cap nhat thong tin hoat dong\n");
        printf("5. Thong ke tong calories tieu thu/ngay\n");
        printf("6. Sap xep hoat dong theo calories\n");
        printf("7. Tim kiem hoat dong theo loai\n");
        printf("8. Thoat chuong trinh\n");
        printf("Nhap lua chon cua ban: ");
        choice = getIntInput();

        switch (choice) {
            case 1: {
                Activity newAct;
                newAct.id = nextId++;
                printf("Nhap loai hoat dong (vd: Running, Swimming): ");
                fgets(newAct.type, sizeof(newAct.type), stdin);
                newAct.type[strcspn(newAct.type, "\n")] = '\0';
                printf("Nhap thoi luong (phut): ");
                newAct.duration = getIntInput();
                printf("Nhap calories tieu thu: ");
                newAct.calories = getIntInput();
                printf("Nhap ngay (YYYY-MM-DD): ");
                fgets(newAct.date, sizeof(newAct.date), stdin);
                newAct.date[strcspn(newAct.date, "\n")] = '\0';
                addActivity(&activityList, newAct);
                break;
            }
            case 2:
                displayActivities(activityList);
                break;
            case 3: {
                printf("Nhap ID hoat dong can xoa: ");
                int idToDelete = getIntInput();
                deleteActivity(&activityList, idToDelete);
                break;
            }
            case 4: {
                printf("Nhap ID hoat dong can cap nhat: ");
                int idToUpdate = getIntInput();
                updateActivity(activityList, idToUpdate);
                break;
            }
            case 5:
                calculateDailyCalories(activityList);
                break;
            case 6:
                sortActivitiesByCalories(&activityList);
                break;
            case 7:
                searchActivitiesByType(activityList);
                break;
            case 8:
                printf("Dang thoat chuong trinh...\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 8);

    freeList(activityList); // Giải phóng bộ nhớ trước khi thoát
    return 0;
}

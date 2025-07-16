#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 100

typedef struct Food {
    int id;
    char name[MAX_STR];
    char category[MAX_STR];
    float price;
} Food;

// Node danh sách đơn - món đang bán
typedef struct sNode {
    Food data;
    struct sNode* next;
} sNode;

// Node danh sách đôi - món đã ngừng bán
typedef struct dNode {
    Food data;
    struct dNode* prev;
    struct dNode* next;
} dNode;

// Tạo node đơn mới
sNode* createSNode(Food f) {
    sNode* node = (sNode*)malloc(sizeof(sNode));
    if (!node) exit(1);
    node->data = f;
    node->next = NULL;
    return node;
}

// Tạo node đôi mới
dNode* createDNode(Food f) {
    dNode* node = (dNode*)malloc(sizeof(dNode));
    if (!node) exit(1);
    node->data = f;
    node->prev = node->next = NULL;
    return node;
}

// 1. Thêm món ăn
void addFood(sNode** head, Food f) {
    sNode* newNode = createSNode(f);
    if (*head == NULL) *head = newNode;
    else {
        sNode* cur = *head;
        while (cur->next) cur = cur->next;
        cur->next = newNode;
    }
    printf("Da them mon: %s\n", f.name);
}

// 2. Hiển thị danh sách món đang bán
void displayFoods(sNode* head) {
    if (head == NULL) {
        printf("Khong co mon an nao dang ban.\n");
        return;
    }
    printf("\n--- Danh sach mon dang ban ---\n");
    while (head) {
        printf("ID: %d\nName: %s\nCategory: %s\nPrice: %.2f\n\n",
               head->data.id, head->data.name, head->data.category, head->data.price);
        head = head->next;
    }
}

// 3. Cập nhật thông tin món ăn theo ID
void updateFood(sNode* head, int id) {
    while (head && head->data.id != id) head = head->next;
    if (!head) {
        printf("Khong tim thay mon an voi ID %d\n", id);
        return;
    }
    printf("Nhap ten moi (cu: %s): ", head->data.name);
    fgets(head->data.name, MAX_STR, stdin);
    head->data.name[strcspn(head->data.name, "\n")] = 0;
    printf("Nhap danh muc moi (cu: %s): ", head->data.category);
    fgets(head->data.category, MAX_STR, stdin);
    head->data.category[strcspn(head->data.category, "\n")] = 0;
    printf("Nhap gia moi (cu: %.2f): ", head->data.price);
    scanf("%f", &head->data.price);
    getchar();
    printf("Cap nhat thanh cong.\n");
}

// Tìm node đơn theo ID và node trước (cho phép sửa hoặc xóa)
sNode* findFoodById(sNode* head, int id, sNode** prev) {
    *prev = NULL;
    while (head && head->data.id != id) {
        *prev = head;
        head = head->next;
    }
    return head;
}

// 4. Đánh dấu ngừng bán: chuyển món khỏi danh sách đơn sang danh sách đôi
void markFoodStopSelling(sNode** saleHead, dNode** stopHead, int id) {
    sNode *prev = NULL, *cur = findFoodById(*saleHead, id, &prev);
    if (!cur) {
        printf("Khong tim thay mon voi ID %d\n", id);
        return;
    }
    dNode* newStop = createDNode(cur->data);
    if (*stopHead == NULL) *stopHead = newStop;
    else {
        dNode* tmp = *stopHead;
        while (tmp->next) tmp = tmp->next;
        tmp->next = newStop;
        newStop->prev = tmp;
    }
    if (prev == NULL) *saleHead = cur->next;
    else prev->next = cur->next;
    free(cur);
    printf("Da danh dau mon ID %d la da ngung ban.\n", id);
}

// 5. Hiển thị danh sách món đã ngừng bán (danh sách đôi)
void displayStoppedFoods(dNode* head) {
    if (!head) {
        printf("Khong co mon nao da ngung ban.\n");
        return;
    }
    printf("\n--- Danh sach mon da ngung ban ---\n");
    while (head) {
        printf("ID: %d\nName: %s\nCategory: %s\nPrice: %.2f\n\n",
               head->data.id, head->data.name, head->data.category, head->data.price);
        head = head->next;
    }
}

// 6. Tìm kiếm món ăn theo tên
void searchFoodByName(sNode* head, char* keyword) {
    int found = 0;
    while (head) {
        if (strstr(head->data.name, keyword) != NULL) {
            printf("ID: %d\nName: %s\nCategory: %s\nPrice: %.2f\n\n",
                   head->data.id, head->data.name, head->data.category, head->data.price);
            found = 1;
        }
        head = head->next;
    }
    if (!found) printf("Khong tim thay mon an voi ten chua '%s'\n", keyword);
}

// 7. Sắp xếp món ăn theo giá tăng dần (selection sort)
void sortFoodsByPrice(sNode** head) {
    if (*head == NULL || (*head)->next == NULL) return;
    sNode* i = *head;
    while (i) {
        sNode* min = i;
        sNode* j = i->next;
        while (j) {
            if (j->data.price < min->data.price) {
                min = j;
            }
            j = j->next;
        }
        if (min != i) {
            Food tmp = i->data;
            i->data = min->data;
            min->data = tmp;
        }
        i = i->next;
    }
    printf("Da sap xep mon an theo gia tang dan.\n");
}

// Giải phóng bộ nhớ
void freeSList(sNode* head) {
    sNode* tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
void freeDList(dNode* head) {
    dNode* tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    sNode* selling = NULL;
    dNode* stopped = NULL;
    int choice;
    int nextId = 1;

    do {
        printf("\n====== RESTAURANT MENU ======\n");
        printf("1. Them mon an\n");
        printf("2. Hien thi danh sach mon dang ban\n");
        printf("3. Cap nhat thong tin mon an\n");
        printf("4. Danh dau ngung ban\n");
        printf("5. Hien thi danh sach mon da ngung ban\n");
        printf("6. Tim kiem mon an theo ten\n");
        printf("7. Sap xep mon an theo gia\n");
        printf("8. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1: {
                Food f;
                f.id = nextId++;
                printf("Nhap ten mon an: ");
                fgets(f.name, MAX_STR, stdin);
                f.name[strcspn(f.name, "\n")] = 0;
                printf("Nhap danh muc: ");
                fgets(f.category, MAX_STR, stdin);
                f.category[strcspn(f.category, "\n")] = 0;
                printf("Nhap gia tien: ");
                scanf("%f", &f.price);
                getchar();
                addFood(&selling, f);
                break;
            }
            case 2:
                displayFoods(selling);
                break;
            case 3: {
                int idUpd;
                printf("Nhap ID can cap nhat: ");
                scanf("%d", &idUpd);
                getchar();
                updateFood(selling, idUpd);
                break;
            }
            case 4: {
                int idStop;
                printf("Nhap ID can danh dau ngung ban: ");
                scanf("%d", &idStop);
                getchar();
                markFoodStopSelling(&selling, &stopped, idStop);
                break;
            }
            case 5:
                displayStoppedFoods(stopped);
                break;
            case 6: {
                char key[MAX_STR];
                printf("Nhap ten hoac tu khoa tim kiem: ");
                fgets(key, MAX_STR, stdin);
                key[strcspn(key, "\n")] = 0;
                searchFoodByName(selling, key);
                break;
            }
            case 7:
                sortFoodsByPrice(&selling);
                break;
            case 8:
                printf("Thoat chuong trinh...\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while(choice != 8);

    freeSList(selling);
    freeDList(stopped);
    return 0;
}

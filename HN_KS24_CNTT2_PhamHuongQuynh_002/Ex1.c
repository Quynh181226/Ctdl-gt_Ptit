#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char name[50];
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Node* createNode(const char *name) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode != NULL) {
        strcpy(newNode->name, name);
        newNode->next = NULL;
    }
    return newNode;
}

Stack *newStack() {
    Stack *newStack = malloc(sizeof(Stack));
    if (newStack != NULL) {
        newStack->top = NULL;
    }
    return newStack;
}

void push(Stack *s, const char *name) {
    Node *newNode = createNode(name);
    if (newNode == NULL) return;
    newNode->next = s->top;
    s->top = newNode;
}

char *pop(Stack *s) {
    if (s->top == NULL) return NULL;
    Node *temp = s->top;
    char *name = malloc(strlen(temp->name) + 1);
    if (name != NULL) {
        strcpy(name, temp->name);
    }
    s->top = s->top->next;
    free(temp);
    return name;
}

char* Input(char *s) {
    printf("Input: ");
    fgets(s, 50, stdin);
    s[strlen(s) - 1] = '\0';
    return s;
}

void Copy(Stack *s) {
    if (s == NULL) return;
    char name[50];
    Input(name);
    push(s, name);
}

void Paste(const Stack *s) {
    if (s == NULL || s->top == NULL) {
        printf("Empty\n");
        return;
    }
    printf("%s\n", s->top->name);
}

void Undo(Stack *s, Stack *redo) {
    if (s == NULL || s->top == NULL) return;
    char *popped = pop(s);
    if (popped != NULL) {
        push(redo, popped);
        free(popped);
    }
}

void Redo(Stack *s, Stack *redo) {
    if (redo == NULL || redo->top == NULL) return;
    char *popped = pop(redo);
    if (popped != NULL) {
        push(s, popped);
        free(popped);
    }
}

void Show(const Stack *s) {
    if (s == NULL || s->top == NULL) {
        printf("Empty\n");
        return;
    }
    Node *current = s->top;
    int i = 1;
    while (current != NULL) {
        printf("%d. %s\n", i, current->name);
        i++;
        current = current->next;
    }
}

void Free(Stack *s) {
    if (s == NULL) return;
    while (s->top != NULL) {
        char *tmp = pop(s);
        free(tmp);
    }
    free(s);
}

main() {
    Stack *copy = newStack();
    Stack *redo = newStack();
    int choice = 0;

    do {
        printf("\n===== CLIPBOARD MANAGER =====\n");
        printf("1. COPY : Sao chép đoạn văn bản mới\n");
        printf("2. PASTE: Dán nội dung vừa sao chép\n");
        printf("3. UNDO : Hoàn tác lệnh sao chép gần nhất\n");
        printf("4. REDO : Phục hồi lệnh vừa undo\n");
        printf("5. HIỂN THỊ: In toàn bộ clipboard\n");
        printf("6. THOÁT\n");
        printf("Your choiuce: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                Copy(copy);
                break;
            case 2:
                Paste(copy);
                break;
            case 3:
                Undo(copy, redo);
                break;
            case 4:
                Redo(copy, redo);
                break;
            case 5:
                Show(copy);
                break;
            case 6:
                Free(copy);
                Free(redo);
                printf("Exit program");
                break;
            default:
                printf("Invalid choice");
                break;
        }
    } while (choice != 6);

    return 0;
}

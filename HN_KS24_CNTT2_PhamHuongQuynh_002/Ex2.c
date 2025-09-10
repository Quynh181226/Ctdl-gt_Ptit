#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct Contact {
    char name[50];
    char phone[15];
    char email[50];
} Contact;

typedef struct TreeNode {
    Contact d;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode *createNode(const Contact contact) {
    TreeNode *newNode = malloc(sizeof(TreeNode));
    if (newNode != NULL) {
        strcpy(newNode->d.name, contact.name);
        strcpy(newNode->d.phone, contact.phone);
        strcpy(newNode->d.email, contact.email);
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

TreeNode *addContact(TreeNode *root, const Contact c) {
    if (root == NULL) return createNode(c);

    if (strcmp(c.name, root->d.name) > 0) {
        root->right = addContact(root->right, c);
    } else if (strcmp(c.name, root->d.name) < 0) {
        root->left = addContact(root->left, c);
    } else {
        printf("Dupli\n");
    }
    return root;
}

char* input(char *s, char *label) {
    printf("%s: ", label);
    fgets(s, 50, stdin);
    s[strlen(s) - 1] = '\0';
    return s;
}

void printContact(Contact c) {
    printf("Name: %s\nPhone: %s\nEmail: %s\n", c.name, c.phone, c.email);
}

void showContact(const TreeNode *root) {
    if (root == NULL) return;
    showContact(root->left);
    printContact(root->d);
    showContact(root->right);
}

TreeNode* findMin(TreeNode* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

void searchName(const TreeNode *root, const char *name) {
    if (root == NULL) return;
    int cmp = strcmp(name, root->d.name);
    if (cmp == 0) {
        printContact(root->d);
    } else if (cmp < 0) {
        searchName(root->left, name);
    } else {
        searchName(root->right, name);
    }
}

TreeNode *deleName(TreeNode *root, char *name) {
    if (root == NULL) return root;
    if (strcmp(name, root->d.name) > 0) {
        root->right = deleName(root->right, name);
    } else if (strcmp(name, root->d.name) < 0) {
        root->left = deleName(root->left, name);
    } else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* min = findMin(root->right);
        root->d = min->d;
        root->right = deleName(root->right, min->d.name);
    }
    return root;
}

void Free(TreeNode *t) {
    if (t == NULL) return;
    Free(t->left);
    Free(t->right);
    free(t);
}

main() {
    int choice = 0;
    TreeNode *contact = NULL;
    char name[50];
    do {
        printf("\n==== Quản lý danh bạ ====\n");
        printf("1. Thêm người vào danh bạ\n");
        printf("2. Hiển thị danh bạ theo ABC\n");
        printf("3. Tìm người theo tên\n");
        printf("4. Xóa người theo tên\n");
        printf("5. Thoát\n");
        printf("Your choiew: ");
        scanf("%d", &choice);
        getchar();
        switch(choice) {
            case 1: {
                Contact c;
                input(c.name, "Name");
                input(c.phone, "Phone");
                input(c.email, "Email");
                contact = addContact(contact, c);
                break;
            }
            case 2:
                showContact(contact);
                break;
            case 3:
                input(name, "Name");
                searchName(contact, name);
                break;
            case 4:
                input(name, "Name");
                contact = deleName(contact, name);
                break;
            case 5:
                Free(contact);
                printf("Exit program");
                break;
            default:
                printf("Invalid choice");
                break;
        }
    } while(choice != 5);
}

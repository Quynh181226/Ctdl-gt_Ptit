//
// Created by TDG on 31/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Book {
    int id;
    char title[50];
    float price;
    char author[50];
    char category[30];
    char date[20];
} Book;
typedef struct NodeD {
    Book data;
    struct NodeD *prev;
    struct NodeD *next;
} NodeD;
typedef struct NodeS {
    Book data;
    struct NodeS *next;
} NodeS;
NodeS* headS=NULL;
NodeD* headD=NULL;
NodeD* tailD=NULL;
NodeD* createNodeD(Book b) {
    NodeD* newNode=(NodeD*) malloc(sizeof(NodeD));
    if (newNode==NULL) return NULL;
    newNode->data=b;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}
NodeS* createNodeS(Book b) {
    NodeS* newNode=(NodeS*) malloc(sizeof(NodeS));
    if (newNode==NULL) return NULL;
    newNode->data=b;
    newNode->next=NULL;
    return newNode;
}
void addBook(Book b) {
    NodeD *p=createNodeD(b);
    if (headD==NULL) {
        headD=tailD=p;
    }else {
        tailD->next=p;
        p->prev=tailD;
        tailD=p;
    }
}
void displayBook() {
    if (tailD==NULL) return;
    NodeD *p=tailD;
    while (p!=NULL) {
        printf("=====Book Store Manager=====");
        printf("ID: %d Title: %s Price: %.2f Author: %s Category: %s Date: %s", p->data.id, p->data.title, p->data.price, p->data.author, p->data.category, p->data.date);
        p=p->prev;
    }
}
NodeD* findBooK(int id) {
    NodeD *p=headD;
    while (p!=NULL) {
        if (p->data.id==id) {
            return p;
        }
        p=p->next;
    }
    return NULL;
}
NodeD* findTitle(char title[]) {
    NodeD *p=headD;
    while (p!=NULL) {
        if (strcmp(p->data.title, title)==0) {
            return p;
        }
        p=p->next;
    }
    return NULL;
}
int deleteBook(int id) {
    NodeD* p=findBooK(id);
    if (p=NULL) return 0;
    if (p==headD&&p==tailD) {
        headD=tailD=NULL;
    }else if (p==headD) {
        headD=headD->next;
        headD->prev=NULL;
    }else if (p==tailD) {
        // tailD=tailD->next;
        tailD->next=NULL;
    }else {
        p->prev->next=p->next;
        p->next->prev=p->prev;
    }
    free(p);
    return 1;
}
int updateBook(int id) {
    NodeD *p=findBooK(id);
    if (p==NULL) return NULL;
    printf("Title: ");
    fgets(p->data.title, sizeof(p->data.title), stdin);
    p->data.title[strcspn(p->data.title), "\n"]=0;
    printf("Input price: ");
    scanf("%d", &p->data.price);
    getchar();
    printf("Author:");
    fgets(p->data.author, sizeof(p->data.author), stdin);
    p->data.author[strcspn(p->data.author, "\n")]=0;
    printf("Input date: ");
    scanf("%f", &p->data.price);
    getchar();
    return 1;
}
Book inputBook() {
    Book b;
    printf("Id: ");
    scanf("%d", &b.id);
    getchar();

    printf("Title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")]=0;

    printf("Input price: ");
    scanf("%d", &b.price);
    getchar();

    printf("Author:");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")]=0;

    printf("Category:");
    fgets(b.category, sizeof(b.category), stdin);
    b.category[strcspn(b.category, "\n")]=0;

    printf("Input date: ");
    fgets(b.date, sizeof(b.date), stdin);
    b.date[strcspn(b.date, "\n")]=0;
    return b;
}
void addRentBook(Book b) {
    NodeS * newNode=createNodeS(b);
    if (headS==NULL) {
        headS=newNode;
    }else {
        NodeS *p=headS;
        while (p->next!=NULL) {
            p=p->next;
        }
        p->next=newNode;
    }
}
int markRent(char title[]) {
    NodeD *p=findTitle(title);
    if (p==NULL) return 0;
    Book b=p->data;
    addRentBook(b);
    if (p==headD&&p==tailD) {
        headD=tailD=NULL;
    }else if (p==headD) {
        headD=headD->next;
        headD->prev=NULL;
    }else if (p==tailD) {
        tailD=tailD->next;
        tailD->next=NULL;
    }else {
        p->prev->next=p->next;
        p->next->prev=p->prev;
    }
    free(p);
    return 1;
}
void search(char *title) {
    char title[50];
    printf("Input book name:");
    getchar();
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")]=0;
    NodeD* p=headD;
    int check=0;
    while (p!=NULL) {
        if (strstr(p->data.title, title)!=NULL) {
            printf("ID: %d Title: %s Price: %.2f Author: %s Category: %s Date: %s", p->data.id, p->data.title, p->data.price, p->data.author, p->data.category, p->data.date);
            check=1;
        }
        p=p->next;
    }
    if (!check) {
        printf("Not found book with name \"%s\"\n", title);
    }
}
void sortAuthor() {
    if (headD==NULL||headD->next==NULL) return;
    NodeD *i=headD;
    while (i->next!=NULL) {
        NodeD *min=i;
        NodeD *j=i->next;
        while (j!=NULL) {
            if (strcmp(j->data.author, min->data.author) < 0) {
                min=j;
            }
            j=j->next;
        }
        if (min!=i) {
            Book tmp=i->data;
            i->data=min->data;
            min->data=tmp;
        }
        i=i->next;
    }
}
void menu() {
    printf("=====Book Store Manager=====");
    printf("1. Add book");
    printf("2. Display list book");
    printf("3. Delete book");
    printf("4. Update book");
    printf("5. Rent book");
    printf("6. Add book");
    printf("7. Add book");
    printf("8. Add book");
}

main() {
    int choice, id;
do {
    menu();
    scanf("%d", &choice);
    getchar();
    switch (choice) {
        case 1:
            Book b=inputBook();
            addBook(b);
            break;
        case 2:
            displayBook();
            break;
        case 3:
            printf("Input id delete:");
            scanf("%d", &id);
            getchar();
            if (!deleteBook(id)) {
                printf("Invalid Id: %d\n", id);
            }
            break;
        case 4:
            printf("Input id update:");
            scanf("%d", &id);
            getchar();
            if (!updateBook(id)) {
                printf("Invalid Id: %d\n", id);
            }
            break;
        case 5:
            char title[50];
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")]=0;
            if (!markRent(title)) {
                printf("Invalid title: %d\n", id);
            }
            break;
        case 6:
            sortAuthor();
            break;
        case 7:
            char title[50];

            search(title);
            break;
        case 8:
            printf("Exit program");
            break;
        default:
            printf("Invalid choice");

    }
}while (choice!=8);
}
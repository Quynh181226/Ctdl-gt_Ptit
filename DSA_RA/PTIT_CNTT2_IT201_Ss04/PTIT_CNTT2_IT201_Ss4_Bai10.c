#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
typedef struct {
    int id;
    char name[20];
    int age;
} student;
void lower(char *str) {
    for (int i=0; i<strlen(str); i++) str[i]=tolower(str[i]);
}
main() {
    int n; scanf("%d", &n);
    student st[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &st[i].id);
        getchar();
        fgets(st[i].name, 20, stdin);
        st[i].name[strlen(st[i].name) - 1] = '\0';
        scanf("%d", &st[i].age);
        getchar();
    }
    char f[20], fname[20];
    gets(f);
    lower(f);
    int check=0;
    for (int i = 0; i < n; i++) {
        strcpy(fname, st[i].name);
        lower(fname);
        if (strstr(fname, f)!=NULL) {
            printf("id: %d, name: \"%s\", age: %d", st[i].id, st[i].name, st[i].age);
            check=1;
        }
    }
    if (check==0) return 1;
}

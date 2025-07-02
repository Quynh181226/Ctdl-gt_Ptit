#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct {
    int id;
    char name[10];
    int age;
} student;
int cmp(const void *a, const void *b) {
    student x = *(student*)a;
    student y = *(student*)b;
    // if (x>y) return 1;
    // else if (x<y) return -1;
    // else return 0;
    return x.id-y.id;
}
int binary(student *st, int n, int f) {
    int l=0, r=n-1;
    while (l<=r) {
        //tinh chi so cua ptu o giua
        int mid=(l+r)/2;
        if (st[mid].id==f) return mid;
        else if (st[mid].id<f) l=mid+1;
        else r=mid-1;
    };
    return -1;
}
main() {
   student st[]={
       {1, "Charlie", 22},
       {5, "Bib", 20},
       {10, "David", 18}
   };
    int n=sizeof(st)/sizeof(student);
    qsort(st,n,sizeof(student),cmp);
    int f; scanf("%d",&f);
    int id=binary(st, n, f);
    if (id!=-1) printf("id: %d, name: \"%s\", age: %d", st[id].id, st[id].name, st[id].age);
    else printf("Invalid student");
}

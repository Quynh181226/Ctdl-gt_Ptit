#include<stdio.h>
void tower(int n, char a, char b, char c) {
if (n==0) return;
    tower(n-1, a, c, b);
    printf("Dia %d di chuyen tu %c sang %c\n", n, a, c);
    tower(n-1, b, a, c);
}
main() {
    int n;
    char a='A'; char b='B'; char c='C';
    scanf("%d",&n);
    if (n<=0) {
        printf("Invalid");
        return 0;
    }
    tower(n, a, b, c);
}
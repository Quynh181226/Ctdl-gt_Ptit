#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char a[30];
int res=0;
int check(char *s) {
    for(int i=0;i<strlen(s);i++) {
        if (!isdigit(s[i])) {
            return 0;
        }
    }
    return 1;
}
int strToInt(int i) {
    if (i>strlen(a)-1) return 0;
    res=res*10+a[i]-'0';
    return strToInt(i+1);
}
main() {
    gets(a);
    a[strlen(a)-1]='\0';
    if(check(a)==0) {
        printf("Invalid");
    }else {
        strToInt(0);
        printf("%d",res);
    }
}


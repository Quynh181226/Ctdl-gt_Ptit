#include<stdio.h>
#include<ctype.h>
#include<string.h>
char s[100];
void select() {
    for (int i=0; i<strlen(s)-1; i++) {
        int min=i;
        for (int j=i+1; j<strlen(s); j++) {
            if (tolower(s[j])<tolower(s[min])) {
                min=j;
            }
        }
        char tmp=s[i];
        s[i]=s[min];
        s[min]=tmp;
    }
}
main(){
    if (gets(s)==NULL||strlen(s)==0) {
        printf("Invalid str");
        return 1;
    }
    s[strcspn(s,"\n")]='\0';
    select();
    // for (int i=0; i<strlen(s); i++) {
        printf("Str = \"%s\"", s);
    // }
}
//chuoi dxung
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

bool palindromeStr(char *a, int l, int r){
    if(l>=r) return true;
    if(a[l]!=a[r]) return false;
    return palindromeStr(a, l+1,r-1);
}
main(){
    char *a=(char*)calloc(50,sizeof(char));
    gets(a);
    a[strlen(a)-1]='\0';
    int n=strlen(a);
    if(palindromeStr(a, 0,n-1)) printf("Palindrome valid");
    else printf("Palindrome invalid");
    free(a);
}

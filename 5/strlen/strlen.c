/*
 * strlen:字符串长度
 * 
 */

#include <stdio.h>
int strlen(char *);

int main(){
        char s[100];
        scanf("%s",s);
        printf("%d",strlen(s));
        return 1;
}

int strlen(char *s){
        char *p = s;
        while(*s != '\0'){
                s++;
        }
        return s - p;
}

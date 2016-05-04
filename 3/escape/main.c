/*
 * escape(s,t):将字符串t复制到字符串s中，并在复制过程中将换行符、制表符等不可见字符分别转化为\n,\t等相应的可见的转义字符序列。要求使用swich
 */
#include <stdio.h>

int main(){
        char s[100];
        scanf("%s",s);
        char *p = s;
        while(*p != '\0'){
                if(*p == '\t'){
                        printf("\t");
                }
                else{
                        printf("%c",*p);
                }
                p++;
        }
        printf("\n");
        return 1;
}

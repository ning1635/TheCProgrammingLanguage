
/*
 * squeeze(s1,s2) 将字符串s1中任何与s2中字符匹配的字符都删除
 * 
 * 疑惑：*s1 ＝ ‘1’；怎么给char * 赋值
 */
#include <stdio.h>

void squeeze(char *s1,char *s2);
int main(){
        char *s1 = "abcdefghijklmn";
        char *s2 = "cdejkl";
        squeeze(s1,s2);
}

void squeeze(char *s1,char *s2){
        char temp[128];
        int i;
        for(i = 0;i < 128;i++){
                temp[i] = '0';
        }
        //在temp中标识s2中的字符
        while(*s2 != '\0'){
                temp[*s2] = '1';
                s2++;
        }
        //在s1中将删除的字符替换成空格
        while(*s1 != '\0'){
                if(temp[*s1] == '1'){
                        printf("%c",' ');
                        //*s1 = 'a';
                }
                else{
                        printf("%c",*s1);
                }
                s1++;
        }
        printf("\n");
}

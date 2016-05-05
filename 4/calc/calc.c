/*
 * 计算器
 * 
 * 1.将输入转成逆波兰表达式
 * 2.
 */

#include <stdio.h>

char inputBuf[100];      //用户输入
char chageBug[100];

void change(char *,char*);   //中序转后序（逆波兰）
int main(){
        scanf("%s",inputBuf);
        printf("%s",inputBuf);
        return 1;
}       

/*
 * 中序转后序
 * 1+1  1+2*3  1*3+2  (1+2)*3
 */
void change(char *s1,char *s2){
        
}       
/*
 * 递归把中序转成后序
 * 
 * 只做+ - * /
 * ()用递归实现
 */
void pushChageBuf(float number,char

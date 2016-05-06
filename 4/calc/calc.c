/*
 * 计算器
 * 
 * 1.将输入转成逆波兰表达式
 * 2.
 */

#include <stdio.h>

char inputBuf[100];      //用户输入
char changeBuf[100];

char stack[10];
char *sp = stack - 1;
char *spbak = stack -1;
char *out = changeBuf;

void change(char *);   //中序转后序（逆波兰）
void pushChangeBuf(char *p);
int priority(char *p);

int main(){
        scanf("%s",inputBuf);
	//stack初始化
	int initStack = 0;
	for(;initStack < 10;initStack++){
		stack[initStack] = '\0';
	}
	change(inputBuf);
        printf("%s\n",changeBuf);
        return 1;
}       

/*
 * 中序转后序
 * 1+1  1+2*3  1*3+2  (1+2)*3
 */
void change(char *s1){
	while(*s1 != '\0'){
		pushChangeBuf(s1);
		s1++;
	}
	//弹出stack
	while(spbak != sp){
		*out = *sp;
		out++;
		sp--;
	}
}       
/*
 * 递归把中序转成后序
 * 
 * 只做+ - * /
 * ()用递归实现
 */
void pushChangeBuf(char *p){
	if(*p == '+' || *p == '-' || *p == '*' || *p == '/'){
		//当前op优先级小于等于stack的优先级时，stack弹出到out
		if(*sp != '\0' && priority(p)){
			*out = *sp;
			*sp = *p;
			out++;
			return;
		}	
		sp++;
		*sp = *p;
	}
	else{
		*out = *p;
		out++;
	}
}

int priority(char *p){
	//当前操作符是+- 或者上一次操作符是*/
	if(*p == '+' || *p == '-' || *sp == '*' || *sp == '/'){
		return 1;
	}
	return 0;
}

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
int outValue(char *);
int main(){
        scanf("%s",inputBuf);
	//stack初始化
	int initStack = 0;
	for(;initStack < 10;initStack++){
		stack[initStack] = '\0';
	}
	change(inputBuf);
        printf("print:%s\n",changeBuf);
	printf("%d\n",outValue(changeBuf));
        return 1;
}       

/*
 * 输出
 *
 */
int outValue(char *p){
	int ret = 0;
	while(*p != '\0'){
		if(*p == '+'){
			//printf("ret:%d,*sp:%d\n",*sp - '0' + *(sp - 1) - '0',*sp - '0');
			printf("%s\n",spbak +1);
		    	ret = *sp - '0' + *(sp - 1) - '0';   
			printf("ret:%d\n",ret);
			sp = sp - 1;
			*sp = ret + '0';
		}
		else if(*p == '-'){
			printf("%s\n",spbak + 1);
		    	ret = *(sp - 1) - '0' - (*sp - '0');
			printf("ret:%d\n",ret);
			sp = sp - 1;
			*sp = ret + '0';
		}
		else if(*p == '*'){
			printf("%s\n",spbak+1);
			ret = (*sp - '0') * (*(sp -1) - '0');
			sp = sp - 1;
			*sp = ret + '0';
			printf("%d",ret);
		}
		else if(*p == '/'){
			ret = (*(sp - 1) - '0') / (*sp - '0');
			sp = sp - 1;
			*sp = ret + '0';
		}
		else{
			sp++;
			*sp = *p;
		}
		p++;
	}
	return ret;
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
 * 如果是操作数，直接输出 
 * 
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
	else if(*p == ')'){
		while(*sp != '('){
			*out = *sp;
			sp--;
			out++;
		}
		sp--;
	}
	else if(*p =='('){
		sp++;
		*sp = *p;
	}
	else{
		*out = *p;
		out++;
	}
}

int priority(char *p){
	if(*sp == '('){
		return 0;
	}
	//当前操作符是+- 或者上一次操作符是*/
	if(*p == '+' || *p == '-' || *sp == '*' || *sp == '/'){
		return 1;
	}
	return 0;
}

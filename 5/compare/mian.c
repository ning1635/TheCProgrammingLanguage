/*
 * 排序输入的内容
 * 支持字符串、数字
 * -n数字 -s字符串
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 100

int numberComp(void *,void *);
void input();
char *linesPrt[MAXLINE];
int main(int argc,char *argv[]){
	input();
	//处理输入的参数
	//接收输入的内容
	//
	return 1;
}
/*
 * input
 */
void input(){
	char **p = linesPrt;
	char *temp;
	do{
		temp = (char *)malloc(sizeof(char)*1000);
		scanf("%s",temp);
		if(*temp == 48){
			break;
		}
		*p++ = temp;
		//printf("%s",*(p - 1));
	}while(1);
	//printf("%d",*linesPrt[1]);
	int a = 0;
	while(*p != linesPrt[a] ){
		printf("%d:%s\n",a,linesPrt[a++]);
	}
}

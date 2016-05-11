/*
 * 排序输入的内容
 * 支持字符串、数字
 * -n数字 -s字符串
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 100

int numberComp(void *,void *);
void input();
void compare();
void printResult();
void swap(char *p[],int i,int j);

char *linesPrt[MAXLINE];//保存输入的内容
char **p = linesPrt;//输入结尾指针
int main(int argc,char *argv[]){
	input();
	compare();
	printResult();
	//处理输入的参数
	//接收输入的内容
	//
	return 1;
}
/*
 * input
 */
void input(){
	//char **p = linesPrt;
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
	//swap(linesPrt,0,1);
	//printf("%d\n",strcmp(*p,*(p+1)));
}
/*
 * 冒泡
 */
void compare(){
	int a = 0;
	int sub = p - linesPrt;
	int i = sub - 1;
	while(*p != linesPrt[a]){
		for(;i > a;i--){
			if(strcmp(linesPrt[i],linesPrt[i - 1]) < 0){
				swap(linesPrt,i,i-1);
			}
		}
		a++;
		i = sub -1;
	}
}
void printResult(){
	int a = 0;
	while(*p != linesPrt[a] ){
		printf("%d:%s\n",a,linesPrt[a++]);
	}

}
void swap(char *p[],int i,int j){
	char *temp;
	temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

/*
 * 排序输入的内容
 * 支持字符串、数字
 * -n数字 -s字符串
 * 指向函数的指针区别ns
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 100

int numberComp(void *,void *);
void input();
void compare(int (*cmp)(void *,void *));
void printResult();
void swap(char *p[],int i,int j);
int numcmp(char *,char *);

char *linesPrt[MAXLINE];//保存输入的内容
char **p = linesPrt;//输入结尾指针
int main(int argc,char *argv[]){
	//(int (*)(void *,void *)) cmp = strcmp;
	//处理参数，判断用哪个方法比较
	int flag = 1;
	if(argc > 1){
		char *param = argv[1];
		if(*param == '-' && *(param + 1) == 's'){
			flag = 0;
		}
	}
	input();
	compare(flag ? (int (*)(void *,void *))numcmp : (int (*)(void *,void *))strcmp);
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
void compare(int (*cmp)(void *,void *)){
	int a = 0;
	int sub = p - linesPrt;
	int i = sub - 1;
	while(*p != linesPrt[a]){
		for(;i > a;i--){
			if(cmp(linesPrt[i],linesPrt[i - 1]) < 0){
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
int numcmp(char *s1,char *s2){
	float f1 = atof(s1);
	float f2 = atof(s2);
	if(f1 > f2){
		return 1;
	}
	else if(f1 == f2){
		return 0;
	}
	else if(f1 < f2){
		return -1;
	}
}

/*
 * strindex(s,t):返回字符串t在s中最右边出现的位置。如果不存在，返回-1.
 *
 * 问题：scanf接收%c
 */
#include <stdio.h>

void strindex(char *,char);

int main(){
	char s[100];
	char t = '3';
	scanf("%s",s);
	//scanf("%c",t);
	strindex(s,t);
	return 1;
}

void strindex(char *s,char t){
	int index = -1;
	int n = 1;
	while(*s != '\0'){
		if(*s == t){
			index = n;
		}
		n++;
		s++;
	}
	printf("%d",index);
}

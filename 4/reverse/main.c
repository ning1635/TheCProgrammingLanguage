/*
 * 将字符串反转
 */

#include <stdio.h>

void revers(char *);

int main(){
	char s[100];
	scanf("%s",s);
	revers(s);
	return 1;
}

void revers(char *s){
	char *temp = s;
	for(;*s != '\0';s++)
		;
	s--;
	while(s != temp){
		printf("%c",*s);
		s--;
	}
	printf("%c",*s);
}

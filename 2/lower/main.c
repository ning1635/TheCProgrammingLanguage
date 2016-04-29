/*
 * 转换成小写字母
 */
/*
 * 将字符转换成小写字母
 */

#include <stdio.h>
void lower(char *);
void main(){
	char s[10];
	scanf("%s",s);
	lower(s);
	printf("%s",s);
}
void lower(char *s){
	while(*s != '\0'){
		if(*s > 'A' && *s < 'Z'){
			*s +=0x20; 
		}
		s++;
	}
}

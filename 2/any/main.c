 /*
 * any(s1,s2);
 * 将字符串s2中的任一字符在字符串s1中第一次出现的位置作为结果返回。
 * 标准库strpbrk()
 * strpbrk 返回第一个找到的字符，此程序找出所有匹配的字符。
 * 解决了重复判断字符出现的问题，加深了对方法传值的理解。
 */

#include <stdio.h>
void any(char *,char *,char *);
int check(char *,char);
int main(){
	char s1[100],s2[100];
	char s3[100];//保存s2已经检查过的字符
	scanf("%s\n%s",s1,s2);
	char *p1,*p2,*p3;
	p1 = s1;
	p2 = s2;
	p3 = s3;
	while(*p2 != '\0'){
		if(check(p3,*p2)){
			any(p1,p2,p3);
		}
		p2++;
	}
	return 1;
}
/* 检查是否匹配过的字符 */
int check(char *p3,char s){
	while(*p3 != '\0'){
		if(s != ' '){
			if(*p3 == s){
				return 0;
			}
			p3++;
		}
		else{
			return 0;
		}
	}
	return 1;
}
void any(char *p1,char *p2,char *p3){
	int num = 1; 
	while(*p1 != '\0'){
		if(*p1 != *p2){
			p1++;
			num++;
		}
		else{
			*p3 = *p2;
			printf("%c is %d\n",*p2,num);
			++p3;
			return;
		}
	}	
}

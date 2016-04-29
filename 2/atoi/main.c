/*
 * 将字符型的数字转化成数值。eg:“123”  123
 */
/*
 * 字符串的数字转成数值
 *
 * 注：1.获得char[]长度 2.从个位开始相加    这种方法太笨
 * 此方法不用知道字符串长度
 */

#include <stdio.h>

int atoi(char []);
void main(){
	char ints[] = "123";
	int i = atoi(ints);
	printf("%d",i);
}

int atoi(char ints[]){
	int i = 0,n = 0;
	for(;ints[i] > '0' && ints[i] < '9';i++){
		n = n * 10 + (ints[i] - '0');
		printf("%d\n",n);
	}
	return n;
}

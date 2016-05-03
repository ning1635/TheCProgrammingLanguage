/*
 * rightrot(x,n);
 * 将x循环右移（从有段移除的位从最左端移入）n位后所得的结果
 * 
 * 程序有bug，带解决
 */

#include <stdio.h>
int rightrot(unsigned int x,unsigned int n);
int main(){
	int x,n;
	scanf("%d %d",&x,&n);
	printf("%d",rightrot(x,n));
	return 1;
}

int rightrot(unsigned int x,unsigned int n){
	while(n >= 0){
		x = ((x & 1) << (sizeof(unsigned int) * 8 - 1)) | (x >> 1);
		n--;
	}
	return x;
}


/*
 * setbits(x,p,n,y);
 * 将x中从第p位开始的n个位设置为y中的最右边的n位的值，x的其余位保持不变。
 */

#include <stdio.h>
int setbits(int x,int p,int n,int y);
int main(){
	int x,p,n,y;
	scanf("%d %d %d %d",&x,&p,&n,&y);
	int ret = setbits(x,p,n,y);
	printf("resulet:%d",ret);
	return 1;
}
/*
 * 1.把x的p开的n位清0
 * 2.把y的其余位清0，最右边的n位像左移动p-n位
 * 3.把1、2的结果取或
 */
int setbits(int x,int p,int n,int y){
	return (x & (~((~(~0<<n))<<(p-n)))) | ((y & ~(~0 << n)) << (p - n));
}


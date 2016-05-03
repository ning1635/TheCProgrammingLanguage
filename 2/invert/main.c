/*
 * invert(x,p,n);
 * 将x中的从第p位开始的n位求反，x的其余位不变。
 */

#include <stdio.h>
int invert(int x,int p,int n);
int main(){
	int x,p,n;
	scanf("%d %d %d",&x,&p,&n);
	printf("result:%d",invert(x,p,n));
	return 1;
}

int invert(int x,int p,int n){
	return x ^ ((~(~0 << n))<<(p - n));
}

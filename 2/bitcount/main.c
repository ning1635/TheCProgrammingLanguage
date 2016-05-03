 /*
 * bitcount(unsigned x)
 * 统计整形参数的值为1的二进制位的个数
 * 
 * 注：scanf("%d",&i); 需要写成&i，不可用i接收。
 */

#include <stdio.h>

int main(){
	int i = 0;
	scanf("%d",&i);
	int num = 32;
	int ret;
	for(ret = 0;num >=0 ;num--){
		if(i&1){
			ret++;
		}	
		i = i>>1;
	}
	printf("total:%d",ret);
	return 1;
}

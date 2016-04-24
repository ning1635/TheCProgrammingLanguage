/*
 * 华氏转摄氏
 */
#include <stdio.h>

void main(){
	int fahr,celsius;
	int lower,upper,step;
	lower = 0;   /* 温度的下限 */
	upper = 300; /* 温度的上限 */
	step = 20;   /* 步长       */
	int point = lower; //显示的华氏温度
	while(upper > point){
		printf("%3d%6d\n",point,5*(point-32)/9);	
		point += step;
	}
}

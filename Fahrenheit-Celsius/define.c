/*
 * define定义
 */
#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20
void main (){
	float fahr;
	for(fahr = LOWER;fahr < UPPER;){
		printf("%3.0f%6.1f\n",fahr,(fahr - 32.0) * 5.0 / 9.0);
		fahr = fahr + 20;
	}
}

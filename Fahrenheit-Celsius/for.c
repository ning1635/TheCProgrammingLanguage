/*
 * for循环打印华氏转温度
 *
 */

void main(){
	float fahr;        /* 华氏 */
	float celsius;     /* 温度 */

	for(fahr = 0;fahr < 300;fahr = fahr + 20){
		printf("%3.0f%6.1f\n",fahr,(fahr - 32.0) * 5.0 / 9.0 );
	}
}

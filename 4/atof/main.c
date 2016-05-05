
#include <stdio.h>

float atof(char *);

int main(){
	char in[100];
	scanf("%s",in);
	float f = atof(in);
	printf("%f",f);
	return 1;
}

float atof(char *s){
	float ret = 0;
	while(*s != '\0' && *s != '.'){
		ret = ret * 10 + *s - '0';
		s++;
	}
	//将指针移到最后
	while(*s != '\0'){
		s++;
	}
	s--;
	printf("%c\n",*s);
	float x = 0.000000;
	while(*s != '.'){
		x = x / 10.000000 + (*s - '0') / 10.000000;
		printf("%f %c\n",x,*s);
		s--;
	}
	ret += x;
	return ret;
}

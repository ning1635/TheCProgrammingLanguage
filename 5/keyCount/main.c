/*
 * C源程序的关键字统计
 */

#include <stdio.h>
struct key{
	char *key;
	int count;
} keyCount[] = {
	"auto",0,
	"break",0,
	"case",0,
	"char",0,
	"const",0,
	"continue",0,
	"default",0,
	"unsigned",0,
	"void",0,
	"volatile",0,
	"while",0
};
void out();
void binsearch(char *);
int main(){
	FILE *f = fopen("KeyCount.c","r");
	char ch;
	char temp[100] = {'\0'};
	int tempi=0;
	while(!feof(f)){
		if(isalpha(ch = fgetc(f))){//取出单词
			tempi = 0;
			do{
				temp[tempi] = ch;
				tempi++;
			}while(isalpha(ch=fgetc(f)));
			temp[tempi] = '\0';
			binsearch(temp);
		}
	}
	out();
	return 1;
}

void binsearch(char *s){
	int length = sizeof(keyCount) / sizeof(struct key);
	int i = 0;
	for(;i <length;i++){
		if(!strcmp(s,keyCount[i].key)){
			keyCount[i].count += 1;
			return;
		}
	}
}

void out(){
	int length = sizeof(keyCount) / sizeof(struct key);
	int i = 0;
	while(i < length){
		if(keyCount[i].count != 0){
			printf("%s:%d\n",keyCount[i].key,keyCount[i].count);
		}
		i++;
	}
}

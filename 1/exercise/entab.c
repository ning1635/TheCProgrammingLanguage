/*
 * 空格串替换成最少数量的制表符和空格，但要保持单词之间的空格不变。
 */

#include <stdio.h>

void main(){
	FILE * finp;
	finp = fopen("1.txt","r");
	int ch;
	ch = getc(finp);
	int flag = 0;//字符标号
	while(!feof(finp)){
		if(ch == '\n'){
			flag = 0;
		}
		if(ch == ' ' && flag == 0){
			int tFlag = 0;
			while(ch == ' '){
				if(tFlag == 8){
					printf("\t");
					tFlag = 0;
				}
				else{
					tFlag++;
				}
				ch = getc(finp);
			}
			
			int i;
			for(i = tFlag;i > 0;i--){
				printf(" ");
			}
		}
		else{
			printf("%c",ch);
			flag++;
			if(flag == 8){
				flag = 0;
			}
		}
		ch = getc(finp);
	}
}

/*
 * 把较长的输入行折成两行或多行，折行的位置在输入行的第n列之前的最后一个非空格之后。
 *
 * 注：未做过多的测试。
 */

#include <stdio.h>

#define COL 7 
void main(){
	FILE * finp;
	finp = fopen("1.txt","r");
	int ch;
	ch = getc(finp);
	int flag = 1;//字符标号
	while(!feof(finp)){
		if(ch == '\n'){
			flag = 1;
		}
		if(flag == COL){
			while(ch != ' '){
				printf("%c",ch);
				if(ch == '\n'){
					goto n;
				}
				ch = getc(finp);
			}	
			printf("\n");
n:
			flag = 1;
		}
		else{
			printf("%c",ch);
			flag++;
		}
		ch = getc(finp);
	}
}

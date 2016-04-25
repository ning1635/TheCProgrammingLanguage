/*
 * 打开文件，读内容后打印
 * 
 * NOTE:%c写成%s了，所以一直报错。
 */
#include <stdio.h>

void main(){
	FILE *fin;
	fin = fopen("text.txt","r");
	char ch;
	//ch = getc(fin);
	//while(!feof(fin)){
	while((ch = getc(fin)) != EOF){
		printf("%c",ch);
		//ch = getc(fin);
	}
	fclose(fin);
}

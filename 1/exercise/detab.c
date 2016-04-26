/*
 * 将输入中的制表符替换成适当数目的空格，使空格充满到下一个制表符终止的地方。
 */
/*
 * 将制表符替换成适当数目的空格
 *
 * 注：判断字符时，ch=="\n"是不能够打到判断的目的的，要改成ch=='\n'
 */

#include <stdio.h>

void main(){
	//printf("a\tb");
	//printf("a    b");
	FILE * finp;
	finp = fopen("1.txt","r");
	int ch;
	ch = getc(finp);
	int flag = 1;//字符标号
	while(!feof(finp)){
		if(ch == '\n'){//行号的时候标号重置
			flag = 1;
		}
		else{
			//flag = flag < 7 ? flag++ : 1;//第8个字符时flag重置
			if(flag < 9){
				flag++;
			}
			else{
				flag = 1;
			}
		}
		if(ch == '\t'){
			int i;
			for(i = flag;i < 9;i++){
				printf("*");
			}
		}
		else{
			printf("%c",ch);
		}
		ch = getc(finp);
	}
}

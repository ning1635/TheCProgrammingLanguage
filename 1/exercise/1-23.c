/* 
 * 删除C语言程序的注释语句。 
 */ 

#include <stdio.h>
//removecomment
void rcomment(FILE *,int);
//inside of comment
void in_rcomment(FILE *);

//处理单引号和双引号里面的情况
void echo(FILE *);
//处理//的情况
void x_rcomment(FILE *);

void main(){
	FILE * finp;
	finp = fopen("main.c","r");
	int ch;
	ch = getc(finp);
	int flag = 1;//字符标号
	while(!feof(finp)){
		rcomment(finp,ch);
		ch = getc(finp);
	}
}

void rcomment(FILE *finp,int ch){
	//处理/的情况
	if(ch == '/'){
		int next = getc(finp);
		if(next == '*'){//*的情况
		    in_rcomment(finp);
		}
		else if(next == '/'){///的情况
		    x_rcomment(finp);
		}
		else{//非注释情况
		    printf("%c",ch);
		    printf("%c",next);
		}
	}		
	//处理单引号、双引号
	else if(ch == '\'' || ch == '\"'){
		//echo(finp);
		//不明白处理的意义，明白后补充代码
		printf("%c",ch);
	}
	else{
		printf("%c",ch);
	}
}
//  /**/
void in_rcomment(FILE *finp){
	int ch = getc(finp);
	if(ch == '*' && (ch = getc(finp)) == '/'){
		return;
	}
	else{
		in_rcomment(finp);
	}
}
//   //
void x_rcomment(FILE *finp){
	int ch = getc(finp);
	while(ch != '\n'){
		ch = getc(finp);
	}
	printf("\n");
}

void echo(FILE *finp){
	
}

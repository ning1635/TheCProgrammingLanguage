#include <stdio.h>

int main(int argc,char *argv[]){
	printf("argc:%d\n",argc);
	if(argc >= 2){
		char **p = argv;
		printf("%s\n",*(p+1));
		printf("%d\n",argv[argc - 1] - *p);
		while(*p++ - argv[argc - 1] != 0){
			printf("%s",*p);
		}
	}
//	int i = 1;
//	for(;i < argc;i++){
//		printf("%s%c",argv[i],(i == (argc - 1) ? '\0':32));
//	}
//	return 1;
}

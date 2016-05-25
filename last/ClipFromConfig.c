/*
 * 读配置文件内容到剪贴板
 */
#include <stdio.h>
#include <windows.h>

struct node{
	char *key;
	char *value;
	struct node *next;
};
struct node *top;
struct node *cur;
struct node *pre;
char *key;
char *value;
ssize_t getline(char **,size_t,FILE *);
void main(int argc,char *argv[]){
	FILE *file = fopen("config.txt","r");
	if(file == NULL)
		exit(EXIT_FAILURE);
	char ch;
	ssize_t read;
	char *line;
	size_t len;
	while((read = getline(&line,&len,file)) != -1){
		//printf("%s,%d",line,strlen(line));
		key = (char *)malloc(strlen(line));
		strcmp(key,line);
		read = getline(&line,&len,file);
		value = (char *)malloc(strlen(line));
		strcmp(value,line);

		cur = (struct node *)malloc(sizeof(struct node));
		cur->key = key;
		cur->value = value;
		cur->next = NULL;
		if(top == NULL){
			top = pre = cur;
		}
		else{
			pre->next = cur;
			pre = cur;
		}
	}
			//printf("\n");
	do{
		printf("%s,%s\n",top->value,top->key);
		top = top->next;
	}while(top->next != NULL)
	if(line)
		free(line);
	char search[10];
	while(1){
		scanf("%s",search);
	   	TCHAR strText[256];   
		if(strcmp(search,"024") == 0){
			strcpy(strText,"C:\\A1_code\\svn\\dev\\java\\trunk\\systemSupport\\024FullText\\src\\main\\java\\com\\rf\\dtd\\knowledgebase\\service");
		}
		else if(strcmp(search,"048") == 0){
			strcpy(strText,"C:\\A1_code\\svn\\dev\\java\\trunk\\epcBusiness\\048a1Business\\src\\main\\java\\com\\rf\\dtd");
		}
		else if(strcmp(search,"088") == 0){
			strcpy(strText,"C:\\A1_code\\svn\\dev\\java\\trunk\\front\\088a1BusinessFront\\src\\main\\webapp\\A1Business\\Module");
		}
		else if(strcmp(search,"074v4") == 0){
			strcpy(strText,"C:\\A1_code\\svn\\dev\\java\\trunk\\front\\074RuanQianReport\\src\\main\\webapp");
		}
		else if(strcmp(search,"074v5") == 0){
			strcpy(strText,"C:\\A1_code\\svn\\dev\\java\\trunk\\front\\074RuanQianV5\\src\\main\\webapp\\mis2\\reportcenter\\res\\NFKT");
		}
		else if(strcmp(search,"094") == 0){
			strcpy(strText,"C:\\A1_code\\svn\\dev\\java\\trunk\\front\\094FullTextFront\\src\\main\\webapp\\FullText\\Module\\Knowledgebase");
		}
	

		 // 打开剪贴板   
	   	 if (!OpenClipboard(NULL)|| !EmptyClipboard())    
	   	 {   
	   	     printf("打开或清空剪切板出错！/n");   
	   	     return;   
	   	 }   
	   	    
	   	 HGLOBAL hMen;   
	   	    
	   	 // 分配全局内存    
	   	 hMen = GlobalAlloc(GMEM_MOVEABLE, ((strlen(strText)+1)*sizeof(TCHAR)));    
	   	    
	   	 if (!hMen)   
	   	 {   
	   	     printf("分配全局内存出错！/n");    
	   	     // 关闭剪切板    
	   	     CloseClipboard();   
	   	     return;         
	   	 }   
	   	    
	   	 // 把数据拷贝考全局内存中   
	   	 // 锁住内存区    
	   	 LPSTR lpStr = (LPSTR)GlobalLock(hMen);    
	   	    
	   	 // 内存复制   
	   	 memcpy(lpStr, strText, ((strlen(strText))*sizeof(TCHAR)));    
	   	 // 字符结束符    
	   	 lpStr[strlen(strText)] = (TCHAR)0;   
	   	 // 释放锁    
	   	 GlobalUnlock(hMen);   
	   	    
	   	 // 把内存中的数据放到剪切板上   
	   	 SetClipboardData(CF_TEXT, hMen);   
	   	 CloseClipboard(); 

	}  
}

/*
 * C源程序的单词统计
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>
struct key{
	char *key;
	int count;
	struct key *left;
	struct key *right;
};
struct key *root = NULL;

void out();
void binsearch(char *,int length);
struct key *searchNode(struct key *node,char *s,int length);
void printNode(struct key *node);
int main(){
	FILE *f = fopen("WordCount.c","r");
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
			binsearch(temp,tempi+1);
		}
	}
	out();
	return 1;
}

void binsearch(char *s,int length){
	if(root == NULL){//根节点
		//struct key *node = malloc(sizeof(struct key));
		root = (struct key *)malloc(sizeof(struct key));
		root->key =strcpy(malloc(sizeof(length)),s);
		root->count = 1;
		root->left = NULL;
		root->right = NULL;
	}
	else{//非根节点
		//查找是否存在节点
		searchNode(root,s,length);
		//如果存在，数量加一
		//如果不存在，返回位置，加入新节点
	}
}

struct key *searchNode(struct key *node,char *s,int length){
	int ret = strcmp(s,node->key);
	if(ret < 0){
		if(node->left == NULL){//创建左子树
			node->left = (struct key *)malloc(sizeof(struct key));
			node->left->key = strcpy(malloc(sizeof(length)),s);
			node->left->count = 1;
			node->left->left = NULL;
			node->left->right = NULL;
		}
		else{
			searchNode(node->left,s,length);
		}
	}
	else if(ret == 0){
		node->count += 1;
	}
	else if(ret > 0){
		if(node->right == NULL){//创建左子树
			node->right = (struct key *)malloc(sizeof(struct key));
			node->right->key = strcpy(malloc(sizeof(length)),s);
			node->right->count = 1;
			node->right->left = NULL;
			node->right->right = NULL;
		}
		else{
			searchNode(node->right,s,length);
		}
	}
}

void out(){
	printNode(root);
}
void printNode(struct key *node){
	if(node->left != NULL){
		printNode(node->left);
	}
	printf("%s:%d\n",node->key,node->count);
	if(node->right != NULL){
		printNode(node->right);
	}
}

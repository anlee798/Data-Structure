#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define OK 1
#define ERROR 0
typedef struct BiNode {
	char *name;
	int score;
	struct BiNode *lchild, *rchild;
}BiTNode, *BiTree;

int main() {
	BiTree B;
	InitBiTree(&B);
	B = NULL;
	printf("请输入姓名，分数(输入“#”键结束)！\n");
	while (1) {
		char name[20];
		int score;
		scanf("%s",name);
		scanf("%d",&score);
		if (!strcmp(name,"#")) {
			break;
		}
		creatBiTree(&B, score, name);
	}

	printf("先序遍历结果：\n");
	inBeforeTraverse(B);

	printf("中序遍历结果：\n");
	InOrderTraverse(B);

	printf("后序遍历结果：\n");
	inLastTraverse(B);

	printf("销毁二叉树!\n");
	destroyBiTree(&B);

}

int InitBiTree(BiTree *T) {
	T = (BiTree*)malloc(sizeof(BiTree));
	if (T == NULL) {
		return ERROR;
	}
	printf("初始化成功！\n");
	return OK;
}

int creatBiTree(BiTree *T, int score,char name[20]) {
	if (!(*T)) {
		BiTree temp = (BiTree*)malloc(sizeof(BiTNode));
		temp->score = score;
		temp->name = strdup(name);
		temp->lchild = temp->rchild = NULL;
		*T = temp;
		return OK;
	}
	if (score<(*T)->score) {
		creatBiTree(&((*T)->lchild), score, name);
	}
	else {
		creatBiTree(&((*T)->rchild), score, name);
	}
}

int destroyBiTree(BiTree *T) {
	if (*T) {
		destroyBiTree(&((*T)->lchild));
		destroyBiTree(&((*T)->rchild));
		free((*T)->name);
		free(*T);
	}
}

int InOrderTraverse(BiTree T) {		//中序遍历
	if (T) {
		InOrderTraverse(T->lchild);
		printf("%10s", T->name);
		printf("%10d\n", T->score);
		InOrderTraverse(T->rchild);
	}
}

int inBeforeTraverse(BiTree T) {	//先序遍历
	if (T) {
		printf("%10s", T->name);
		printf("%10d\n", T->score);
		inBeforeTraverse(T->lchild);
		inBeforeTraverse(T->rchild);
	}
}

int inLastTraverse(BiTree T) {		//后序遍历
	if (T) {
		inLastTraverse(T->lchild);
		inLastTraverse(T->rchild);
		printf("%10s", T->name);
		printf("%10d\n", T->score);
	}
}

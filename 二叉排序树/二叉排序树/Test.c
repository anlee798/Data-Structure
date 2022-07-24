#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define OK 1
#define ERROR 0
typedef struct BiNode {
	int data;
	struct BiNode *lchild, *rchild;
}BiTNode, *BiTree;

int main() {
	BiTree B;
	InitBiTree(&B);
	B = NULL;
	int d=0;
	printf("请输入数据 (输入“0”键结束)！\n");
	while (1) {
		int data;
		scanf("%d",&data);
		if (data==0) {
			break;
		}
		creatBiTree(&B,data);
	}
	printf("中序遍历结果：\n");
	InOrderTraverse(B);
	printf("\n");
	printf("请输入你要删除的数!\n");
	int key;
	scanf("%d",&key);
	DeleteBST(&B,key);
	printf("删除后中序遍历结果：\n");
	InOrderTraverse(B);
}

int DeleteBST(BiTree *T,int key){
	
	BiTree p = *T, f = NULL, q, s;
	//找到要删除的结点
	while (p) {
		if (p->data == key) {
			break;
		}
		f = p;
		if (p->data>key) {
			p = p->lchild;
		}
		else {
			p = p->rchild;
		}
	}
	
	if (!p) {
		return ERROR;
	}
	//3种情况
	q = p;
	if (p->lchild&&p->rchild) {
		s = p->lchild;
		while (s->rchild) {
			q = s;
			s = s->rchild;
		}
		p->data = s->data;
		if (q != p) {
			q->rchild = s->lchild;
		}
		else {
			q->lchild = s->rchild;
		}
		free(s);
		return OK;
	}
	else if(!p->rchild) {
		p = p->lchild;
	}
	else if (!p->lchild) {
		p = p->rchild;
	}
	//挂接
	if (!f) {
		T = p;
	}
	else if (q == f->lchild) {
		f->lchild = p;
	}
	else {
		f->rchild = p;
	}
	free(q);
	return OK;
}

int creatBiTree(BiTree *T, int data) {
	if (!(*T)) {
		BiTree temp = (BiTree*)malloc(sizeof(BiTNode));
		temp->data = data;
		temp->lchild = temp->rchild = NULL;
		*T = temp;
		return OK;
	}
	if (data<(*T)->data) {
		creatBiTree(&((*T)->lchild), data);
	}
	else {
		creatBiTree(&((*T)->rchild), data);
	}
}

int destroyBiTree(BiTree *T) {
	if (*T) {
		destroyBiTree(&((*T)->lchild));
		destroyBiTree(&((*T)->rchild));
		free(*T);
	}
}

int InOrderTraverse(BiTree T) {		//中序遍历
	if (T) {
		InOrderTraverse(T->lchild);
		printf("%10d", T->data);
		InOrderTraverse(T->rchild);
	}
}

int InitBiTree(BiTree *T) {
	T = (BiTree*)malloc(sizeof(BiTree));
	if (T == NULL) {
		return ERROR;
	}
	printf("初始化成功！\n");
	return OK;
}

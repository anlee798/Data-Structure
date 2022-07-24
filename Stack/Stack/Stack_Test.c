#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define Status int
#define SElemType int
#define OK 1
#define ERROR 0
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
int main() {
	SqStack S;
	InitStack(&S);
	Push(&S, 2);
	Push(&S, 4);
	Push(&S, 6);
	Push(&S, 8);
	int *e;
	printf("栈顶元素：%d\n", GetTop(S));
	Pop(&S,&e);
	printf("e:%d\n",e);

	printf("栈顶元素：%d\n", GetTop(S));
	Pop(&S, &e);
	printf("e:%d\n", e);

	printf("栈顶元素：%d\n", GetTop(S));
	Pop(&S, &e);
	printf("e:%d\n", e);

	printf("栈顶元素：%d\n", GetTop(S));
	Pop(&S, &e);
	printf("e:%d\n", e);

	//DestroyStack(&S);
}
Status InitStack(SqStack *S) {
	S->base =(SElemType *) malloc(sizeof(MAXSIZE));
	if (S->base == NULL) {
		printf("创建失败！\n");
		exit(0);
	}
	S->top = S->base;
	S->stacksize = MAXSIZE;
	printf("创建成功！\n");
	return OK;
}
Status Push(SqStack *S, SElemType e) {
	if (S->top - S->base == S->stacksize) {
		return ERROR;
	}
	*S->top++ = e;
	return OK;
}
Status Pop(SqStack *S,SElemType *e) {
	if (S->top == S->base) {
		return ERROR;
	}
	*e = *--S->top;
	return OK;
}
SElemType GetTop(SqStack S) {
	if (S.top != S.base) {
		return *(S.top - 1);
	}
}
Status DestroyStack(SqStack *S) {
	free(S->base);
	S->top = S->base = NULL;
	S->stacksize = 0;
	printf("销毁栈成功！\n");
	return OK;
}
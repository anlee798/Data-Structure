#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#define MAXSIZE 100
#define Status int
#define SElemType int
#define OK 1
#define ERROR 0
#define True 1
#define False 0
typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
SqStack S1, S2, S3;
int str[100];
int count = 1;	//当前要出轨车厢车号
int n;		//车厢数量
int main() {
	InitStack(&S1);		//缓冲铁轨1
	InitStack(&S2);		//缓冲铁轨2
	InitStack(&S3);		//缓冲铁轨3

	DataEnter();
	Rearrangement(n);
}
Status DataEnter() {		//数据进入
	printf("请输入车厢的节数\n");
	scanf("%d", &n);
	printf("请输入入轨时车厢的次序(从左至右)\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &str[i]);
	}
}
Status Rearrangement(int n) {		//重排车厢
	for (int i = n-1; i >= 0; i--) {
		int *e;
		if (str[i] == count) {
			printf("\n车厢 %d 出轨,无需重排\n", count);
			count++;
			OutRail(str[i]);
			continue;
		}
		EnterRail(str[i]);
	}
}
Status OutRail(int n) {			//出缓冲铁轨
	int *e;
	int flag = True;
	while (flag) {
		if (GetTop(S1) == count) {
			printf("\n车厢 %d 由 缓冲铁轨1 出轨\n", count);
			count++;
			Pop(&S1, &e);
			RailMassage();
		}
		else if (GetTop(S2) == count) {
			printf("\n车厢 %d 由 缓冲铁轨2 出轨\n", count);
			count++;
			Pop(&S2, &e);
			RailMassage();
		}
		else if (GetTop(S3) == count) {
			printf("\n车厢 %d 由 缓冲铁轨3 出轨\n", count);
			count++;
			Pop(&S3, &e);
			RailMassage();
		}
		else {
			flag = False;
		}
	}
}
Status EnterRail(int n) {		//进入缓冲铁轨
	if (IsEmpty(S1) || GetTop(S1)>n) {
		Push(&S1, n);
		printf("\n车厢 %d 进入 缓冲铁轨 1\n", n);
		RailMassage();
	}
	else if (IsEmpty(S2) || GetTop(S2) > n) {
		Push(&S2, n);
		printf("\n车厢 %d 进入 缓冲铁轨 2\n", n);
		RailMassage();
	}
	else if (IsEmpty(S3) || GetTop(S3) > n) {
		Push(&S3, n);
		printf("\n车厢 %d 进入 缓冲铁轨 3\n", n);
		RailMassage();
	}
	else {
		printf("出现问题！\n");
	}
}
Status InitStack(SqStack *S) {
	S->base = (SElemType *)malloc(sizeof(MAXSIZE));
	if (S->base == NULL) {
		exit(0);
	}
	S->top = S->base;
	S->stacksize = MAXSIZE;
	return OK;
}
Status Push(SqStack *S, SElemType e) {
	if (S->top - S->base == S->stacksize) {
		return ERROR;
	}
	*S->top++ = e;
	return OK;
}
Status Pop(SqStack *S, SElemType *e) {
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
SElemType IsEmpty(SqStack S) {
	if (S.top == S.base) {
		return True;
	}
	else {
		return False;
	}
}
SElemType RailMassage() {
	TraverseRail(S1, 1);
	TraverseRail(S2, 2);
	TraverseRail(S3, 3);
}
SElemType TraverseRail(SqStack S,int m) {
	if (IsEmpty(S)) {
		printf("缓冲轨%d中：无车厢\n", m);
	}
	else {
		printf("缓冲轨%d中：", m);
		while (!IsEmpty(S)) {
			int *e;
			printf("%d车厢  ", GetTop(S));
			Pop(&S, &e);
		}
		printf("\n");
	}
}

#include<stdio.h>
#include<stdlib.h>
#define MAXQSIZE 100
#define QElemType int
#define Status int
#define OK 1
#define ERROR 0
typedef struct {
	QElemType *base;
	int front;
	int rear;
}SqQueue;
int  main() {
	SqQueue Q;
	InitQueue(&Q);

	EnQueue(&Q, 2);
	EnQueue(&Q, 4);
	EnQueue(&Q, 6);
	EnQueue(&Q, 8);
	EnQueue(&Q, 10);
	printf("%d\n",QueueLength(Q));

	int *e;
	int n = QueueLength(Q);
	for (int i = 0; i < n; i++) {
		printf("队头：%d\n", GetHead(Q));
	}
	printf("--------------------\n");
	for (int i = 0; i < n; i++) {
		DeQueue(&Q, &e);
		printf("出队：%d\n", e);
	}

}

Status InitQueue(SqQueue *Q) {
	Q->base = (QElemType *)malloc(sizeof(MAXQSIZE));
	if (!Q->base) {
		exit(0);
	}
	Q->front = Q->rear = 0;
	return OK;
}

Status QueueLength(SqQueue Q) {
	return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

Status EnQueue(SqQueue *Q,QElemType e) {
	if ((Q->rear + 1) % MAXQSIZE == Q->front) {
		printf("入队失败（队满）！\n");
		return ERROR;
	}
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;
	return OK;
}

Status DeQueue(SqQueue *Q, QElemType *e) {
	if (Q->front == Q->rear) {
		printf("队空！\n");
		return ERROR;
	}
	*e = Q->base[Q->front];
	Q->front = (Q->front + 1) % MAXQSIZE;
	return OK;
}

QElemType GetHead(SqQueue Q) {
	if (Q.front!=Q.rear) {
		return Q.base[Q.front];
	}
}

#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define MAXQSIZE 100
#define MVNum 100     //最大顶点数 
typedef char VerTexType;	//顶点信息
typedef int OtherInfo;	 //和边相关的信息

						 //- - - - -图的邻接表存储表示- - - - - 
typedef struct ArcNode {     //边结点 
	int adjvex;     //该边所指向的顶点的位置 
	struct ArcNode *nextarc;    //指向下一条边的指针 
	OtherInfo info;    //和边相关的信息 
}ArcNode;

typedef struct VNode {
	VerTexType data;     //顶点信息 
	ArcNode *firstarc;    //指向第一条依附该顶点的边的指针 
}VNode, AdjList[MVNum];    //AdjList表示邻接表类型 

typedef struct {
	AdjList vertices;    //邻接表 
	int vexnum, arcnum;    //图的当前顶点数和边数 
}ALGraph;
//-------------------------------------
typedef int Status;
typedef int QElemType;
int visited[MVNum] = { 0 };           	    //访问标志数组，其初值为"false" 
typedef struct {		//队列结构体
	QElemType *base;							//初始化的动态分配存储空间
	int front;								//头指针，若队列不空，指向队头元素
	int rear;								//尾指针，若队列不空，指向队尾元素的下一个位置
}SqQueue;
int main() {
	printf("************算法6.2　采用邻接表表示法创建有向图**************\n");
	ALGraph G;
	CreateUDG(&G);
	printf("*****邻接表表示法创建的有向图*****\n");
	for (int i = 0; i < G.vexnum; ++i) {
		ArcNode *p = G.vertices[i].firstarc;
		if (p == NULL) {
			printf("%c", G.vertices[i].data);
		}
		else {
			printf("%c", G.vertices[i].data);
			while (p) {
				printf("->");
				printf("%d", p->adjvex);
				p = p->nextarc;
			}
		}
		printf("\n");
	}
	printf("*****邻接表表示法创建的无向图的广度优先遍历*****\n");
	printf("请输入遍历依据的顶点");
	char c;
	scanf("%c", &c);
	scanf("%c", &c);
	int v = LocateVex(G, c);
	printf("以%c为顶点遍历结果： ", c);
	BFS(G, v);
	return 0;
}
int LocateVex(ALGraph G, VerTexType v) {
	for (int i = 0; i < G.vexnum; ++i)
		if (G.vertices[i].data == v)
			return i;
	return -1;
}
int FirstAdjVex(ALGraph G, int v) {
	//返回v的第一个邻接点
	int i;
	for (i = 0; i < G.vexnum; ++i) {
		if (visited[i] == 0)
			return i;
	}
	return -1;
}//FirstAdjVex
Status BFS(ALGraph G, int v) {
	SqQueue Q;
	QElemType u, w;
	printf("%c  ", G.vertices[v]);
	visited[v] = 1;
	InitQueue(&Q);
	EnQueue(&Q, v);
	while (!QueueEmpty(Q)) {
		DeQueue(&Q, &u);
		ArcNode *temp = G.vertices[u].firstarc;
		while (temp) {
			if (!visited[temp->adjvex]) {
				printf("%c  ", G.vertices[temp->adjvex]);
				EnQueue(&Q, temp->adjvex);
				visited[temp->adjvex] = 1;
			}
			temp = temp->nextarc;
		}
	}
}
int CreateUDG(ALGraph *G) {
	printf("请输入总顶点数，总边数中间以空格隔开:\n");
	scanf("%d", &(G->vexnum));
	scanf("%d", &(G->arcnum));
	printf("输入点的名称，如 a \n");
	for (int i = 0; i < G->vexnum; i++) {
		printf("请输入第%d个点的名称:", i + 1);
		scanf("%c", &(G->vertices[i].data));
		scanf("%c", &(G->vertices[i].data));
		G->vertices[i].firstarc = NULL;
	}
	printf("请输入一条边依附的顶点,如 a b \n");
	for (int k = 0; k < G->arcnum; k++) {
		VerTexType v1, v2;
		printf("请输入第%d条边依附的顶点:", k + 1);
		scanf("%c", &v1);
		scanf("%c", &v1);
		scanf("%c", &v2);
		scanf("%c", &v2);
		int i = LocateVex(*G, v1);
		int j = LocateVex(*G, v2);
		ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));
		p1->adjvex = j;
		p1->nextarc = G->vertices[i].firstarc;
		G->vertices[i].firstarc = p1;

		ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
		p2->adjvex = i;
		p2->nextarc = G->vertices[j].firstarc;
		G->vertices[j].firstarc = p2;
	}
	return OK;
}
//-----队列操作start-----
Status InitQueue(SqQueue *Q) {
	Q->base = (QElemType *)malloc(sizeof(MAXQSIZE));
	if (!Q->base) {
		exit(0);
	}
	Q->front = Q->rear = 0;
	return OK;
}
Status EnQueue(SqQueue *Q, QElemType e) {
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
Status QueueEmpty(SqQueue Q) {
	//判断是否为空队
	if (Q.rear == Q.front)
		return 1;
	return 0;
}//QueueEmpty
 //-----队列操作end-----

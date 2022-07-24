#include<stdio.h>
#define MVNum 100                       	//最大顶点数
#define MAXQSIZE 100						//最大队列长度
#define Status int
#define OK 1
#define ERROR 0

typedef int QElemType;
int visited[MVNum] = {0};           	    //访问标志数组，其初值为"false" 
typedef struct {		//队列结构体
	QElemType *base;							//初始化的动态分配存储空间
	int front;								//头指针，若队列不空，指向队头元素
	int rear;								//尾指针，若队列不空，指向队尾元素的下一个位置
}SqQueue;

#define MaxInt 32767		  //表示极大值，即∞
typedef char VerTexType;      //假设顶点的数据类型为字符型 
typedef int ArcType;          //假设边的权值类型为整型
typedef struct {
	VerTexType vexs[MVNum];		//顶点表
	ArcType arcs[MVNum][MVNum];		//邻接矩阵
	int vexnum, arcnum;		//点，边
}AMGraph;
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

int LocateVex(AMGraph G, VerTexType v) {
	//确定点v在G中的位置
	for (int i = 0; i < G.vexnum; ++i)
		if (G.vexs[i] == v)
			return i;
	return -1;
}//LocateVex
Status BFS(AMGraph G, int v) {
	SqQueue Q;
	QElemType u,w;
	printf("%c  ", G.vexs[v]);
	visited[v] = 1;
	InitQueue(&Q);
	EnQueue(&Q,v);
	while (!QueueEmpty(Q)) {
		DeQueue(&Q,&u);
		for (w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)) {
			if (!visited[w]) {
				printf("%c  ", G.vexs[w]);
				visited[w] = 1;
				EnQueue(&Q,w);
			}
		}
	}
}
int FirstAdjVex(AMGraph G, int v) {
	//返回v的第一个邻接点
	int i;
	for (i = 0; i < G.vexnum; ++i) {
		if (G.arcs[v][i] != MaxInt && visited[i] == 0)
			return i;
	}
	return -1;
}//FirstAdjVex
int NextAdjVex(AMGraph G, int u, int w) {
	//返回v相对于w的下一个邻接点
	int i;
	for (i = w; i < G.vexnum; ++i) {
		if (G.arcs[u][i] != MaxInt && visited[i] == 0)
			return i;
	}
	return -1;
}//NextAdjVex
int CreateUDN(AMGraph *G) {
	printf("输入总顶点数、总边数(空格隔开)\n");
	scanf("%d", &(G->vexnum));
	scanf("%d", &(G->arcnum));

	printf("输入点的名称，如a\n");
	for (int i = 0; i < G->vexnum; i++) {
		printf("输入第%d个点的点名称:", i + 1);
		G->vexs[i] = getchar();
		scanf("%c", &(G->vexs[i]));
	}
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j] = MaxInt;
		}
	}
	printf("输入边依附的顶点及权值，如 a b 5\n");
	for (int k = 0; k < G->arcnum; k++) {
		VerTexType v1, v2;
		ArcType w;
		printf("请输入第%d条边依附的顶点及权值:", k + 1);
		scanf("%c", &v1);
		scanf("%c", &v1);
		scanf("%c", &v2);
		scanf("%c", &v2);
		scanf("%d", &w);
		printf("\n");
		int i = LocateVex(*G, v1);
		int j = LocateVex(*G, v2);
		G->arcs[i][j] = w;
		G->arcs[j][i] = G->arcs[i][j];
	}
	return OK;
}
int main() {
	AMGraph G;
	CreateUDN(&G);
	printf("---------广度优先搜索遍历---------\n");
	printf("请输入遍历依据的顶点：");
	char c;
	scanf("%c",&c); scanf("%c", &c);
	int v = LocateVex(G, c);
	printf("以%c为顶点遍历结果： ", c);
	BFS(G,v);
}

#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
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
int visited[MVNum] = { 0 };
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
	printf("*****邻接表表示法创建的有向图的深度优先遍历*****\n");
	printf("请输入遍历依据的顶点");
	char c;
	scanf("%c", &c);
	scanf("%c", &c);
	int v = LocateVex(G, c);
	printf("以%c为顶点遍历结果： ", c);
	DFS_AL(G, v);
	return 0;
}
int LocateVex(ALGraph G, VerTexType v) {
	for (int i = 0; i < G.vexnum; ++i)
		if (G.vertices[i].data == v)
			return i;
	return -1;
}
int CreateUDG(ALGraph *G) {
	printf("请输入总顶点数，总边数中间以空格隔开:\n");
	scanf("%d",&(G->vexnum));
	scanf("%d",&(G->arcnum));
	printf("输入点的名称，如 a \n");
	for (int i = 0; i < G->vexnum; i++) {
		printf("请输入第%d个点的名称:",i+1);
		scanf("%c",&(G->vertices[i].data));
		scanf("%c", &(G->vertices[i].data));
		G->vertices[i].firstarc = NULL;
	}
	printf("请输入一条边依附的顶点,如 a b \n");
	for (int k = 0; k < G->arcnum; k++) {
		VerTexType v1, v2;
		printf("请输入第%d条边依附的顶点:",k+1);
		scanf("%c", &v1);
		scanf("%c", &v1);
		scanf("%c", &v2);
		scanf("%c", &v2);
		int i = LocateVex(*G,v1);
		int j = LocateVex(*G,v2);
		ArcNode *p1 =(ArcNode *) malloc(sizeof(ArcNode));
		p1->adjvex = j;
		p1->nextarc = G->vertices[i].firstarc;
		G->vertices[i].firstarc = p1;
	}
	return OK;
}
//深度优先遍历
int DFS_AL(ALGraph G, int v) {
	printf("%c  ", G.vertices[v].data);
	visited[v] = 1;
	ArcNode *p = G.vertices[v].firstarc;
	while (p != NULL) {
		int w = p->adjvex;
		if (!visited[w]) {
			DFS_AL(G, w);
		}
		p = p->nextarc;
	}
}

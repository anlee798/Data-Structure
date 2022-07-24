#include<stdio.h>
#define OK 1
#define ERROR 0
#define MaxInt 32767	//表示极大值，即∞
#define MVNum 100		//最大顶点数
typedef char VerTexType;      //假设顶点的数据类型为字符型 
typedef int ArcType;          //假设边的权值类型为整型
typedef struct {
	VerTexType vexs[MVNum];		//顶点表
	ArcType arcs[MVNum][MVNum];		//邻接矩阵
	int vexnum, arcnum;		//点，边
}AMGraph;
int visited[MVNum] = { 0 };
int main() {
	printf("************算法6.1采用邻接矩阵表示法创建有向图(C语言)**************\n");
	AMGraph G;     int i, j;
	CreateUDN(&G);

	printf("*****邻接矩阵表示法创建的无向网*****\n");

	for (i = 0; i < G.vexnum; i++) {
		for (j = 0; j < G.vexnum; j++) {
			if (j != G.vexnum - 1) {
				if (G.arcs[i][j] != MaxInt)
					printf("%d\t", G.arcs[i][j]);
				else
					printf("∞\t");
			}
			else {
				if (G.arcs[i][j] != MaxInt)
					printf("%d\n", G.arcs[i][j]);
				else
					printf("∞\n");
			}
		}
	}
	//深度优先遍历
	printf("*****邻接矩阵表示法创建的无向图的深度优先遍历*****\n");
	printf("请输入遍历依据的顶点");
	char c;
	scanf("%c", &c);
	scanf("%c", &c);
	int v = LocateVex(G,c);
	printf("以%c为顶点遍历结果： ",c);
	DFS_AL(G, v);
	return 0;

}
int LocateVex(AMGraph G, VerTexType v) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i] == v) {
			return i;
		}
	}
	return -1;
}
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
	}
	return OK;
}
//深度优先遍历
int DFS_AL(AMGraph G, int v) {
	printf("%c  ",G.vexs[v]);
	visited[v] = 1;
	for (int w = 0; w < G.vexnum; w++) {
		if ((G.arcs[v][w] != 0) && (!visited[w])) {
			DFS_AL(G,w);
		}
	}
}
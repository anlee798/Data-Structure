#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define MAX_VERTEX_NUM 20
typedef char VerTexType;
typedef struct ArcBox {
	int tailvex, headvex;		//该弧的尾和头顶点的位置
	struct ArcBox *hlink, *tlink;
	//InfoType *info;
}ArcBox;
typedef struct VexNode {
	VerTexType data;
	ArcBox *firstin, *firstout;
}VexNode;
typedef struct {
	VexNode xlist[MAX_VERTEX_NUM];
	int  vexnum, arcnum;
}OLGraph;
int main(){
	OLGraph G;
	CreateUDG(&G);
	printf("--------------十字链表----------------\n");
	for (int i = 0; i < G.vexnum; i++) {
		ArcBox *p = G.xlist[i].firstout;
		if (p == NULL) {
			printf("%c", G.xlist[i].data);
		}
		else {
			printf("%c", G.xlist[i].data);
			while (p) {
				printf("->");
				printf("%c", p->headvex);
				p = p->tlink;
			}
		}
		printf("\n");
	}
	printf("建立成功！\n");
	return 0;
}
int LocateVex(OLGraph G, VerTexType v) {
	for (int i = 0; i < G.vexnum; ++i)
		if (G.xlist[i].data == v)
			return i;
	return -1;
}
int CreateUDG(OLGraph *G) {
	printf("请输入总顶点数，总边数中间以空格隔开:\n");
	scanf("%d", &(G->vexnum));
	scanf("%d", &(G->arcnum));
	printf("输入点的名称，如 a \n");
	for (int i = 0; i < G->vexnum; i++) {
		printf("请输入第%d个点的名称:", i + 1);
		scanf("%c", &(G->xlist[i].data));
		scanf("%c", &(G->xlist[i].data));
		G->xlist[i].firstin = G->xlist[i].firstout = NULL;
	}
	printf("请输入一条边依附的顶点,如 a b(意思为由a-->b的弧) \n");
	for (int k = 0; k < G->arcnum; k++) {
		VerTexType v1, v2;
		printf("请输入第%d条边依附的顶点:", k + 1);
		scanf("%c", &v1);
		scanf("%c", &v1);
		scanf("%c", &v2);
		scanf("%c", &v2);
		int i = LocateVex(*G, v1);
		int j = LocateVex(*G, v2);
		ArcBox *p1 = (ArcBox *)malloc(sizeof(ArcBox));
		p1->tailvex = v1;
		p1->headvex = v2;
		p1->hlink = p1->tlink = NULL;
		ArcBox *temp1= G->xlist[i].firstout;
		if (temp1 == NULL) {
			G->xlist[i].firstout = p1;
		}
		else {
			while (temp1) {
				if (temp1->tlink==NULL) {
					break;
				}
				temp1 = temp1->tlink;
			}
			temp1->tlink = p1;
		}
		ArcBox *temp2 = G->xlist[j].firstin;
		if (temp2 == NULL) {
			G->xlist[j].firstin = p1;
		}
		else {
			while (temp2) {
				if (temp2->hlink == NULL) {
					break;
				}
				temp2 = temp2->hlink;
			}
			temp2->hlink = p1;
		}
	}
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
#define OK 1;
#define ERROR 0;
typedef int KeyType;
typedef struct {
	KeyType key;
}ElemType;
typedef struct {
	ElemType *R;
	int length;
}SSTable;
void main() {
	SSTable ST;
	CreateList(&ST);
	TraverseList(ST);
	printf("\n折半查找的数位于第%d位\n",Search_Bin(ST, 36)); 
	return 0; 
}
int InitList(SSTable *ST) {
	ST->R = malloc(MAXSIZE * sizeof(ElemType));
	if (ST->R == NULL) {
		printf("存储分配失败！\n");
		return ERROR;
	}
	else {
		printf("存储分配成功！\n");
		ST->length = 0;
		return OK;
	}
}
int CreateList(SSTable *ST) {
	InitList(ST);
	ST->R[1].key = 5;
	ST->R[2].key = 16;
	ST->R[3].key = 20;
	ST->R[4].key = 27;
	ST->R[5].key = 30;
	ST->R[6].key = 36;
	ST->R[7].key = 44;
	ST->R[8].key = 55;
	ST->R[9].key = 60;
	ST->R[10].key = 67;
	ST->R[11].key = 71;
	ST->length = 11;
}
int TraverseList(SSTable ST) {
	printf("数据遍历：\n");
	for (int i = 1; i <= ST.length; i++) {
		printf("%d  ", ST.R[i].key);
	}
}
int Search_Bin(SSTable ST, KeyType key) {
	int low = 1,high = ST.length;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (key == ST.R[mid].key) return mid;
		else if (key < ST.R[mid].key) high = mid - 1;
		else low = mid + 1;
	}
	return 0;
}


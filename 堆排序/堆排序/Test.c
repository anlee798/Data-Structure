#include<stdio.h>
#define MAXSIZE 20
typedef int KeyType;
typedef struct {
	KeyType key;
}RedType;
typedef struct {
	RedType r[MAXSIZE + 1];
	int length;
}SqList;
int main() {
	SqList L;
	CreateList(&L);
	printf("³õÊ¼×´Ì¬:\n");
	for (int i = 1; i <= L.length; i++) {
		printf("%d  ", L.r[i].key);
	}
	printf("\n");
	HeapSort(&L);
	printf("¶ÑÅÅÐòºó£º\n");
	for (int i = 1; i <= L.length; i++) {
		printf("%d  ", L.r[i].key);
	}
}
int HeapSort(SqList *L) {
	CreatHeap(L);
	for (int i = L->length; i > 1; i--) {
		RedType x = L->r[1];
		L->r[1] = L->r[i];
		L->r[i] = x;
		HeapAdjust(L, 1, i - 1);
	}
}
int CreatHeap(SqList *L) {
	int n = L->length;
	for (int i = n / 2; i > 0; i--) {
		HeapAdjust(L, i, n);
	}
}
int HeapAdjust(SqList *L, int s, int m) {
	RedType rc = L->r[s];
	for (int j = 2 * s; j <= m; j *= 2) {
		if (j < m&&L->r[j].key < L->r[j + 1].key) j++;
		if (rc.key >= L->r[j].key) break;
		L->r[s] = L->r[j];
		s = j;
	}
	L->r[s] = rc;
}
int CreateList(SqList *L) {
	L->r[1].key = 49;
	L->r[2].key = 38;
	L->r[3].key = 65;
	L->r[4].key = 97;
	L->r[5].key = 76;
	L->r[6].key = 13;
	L->r[7].key = 27;
	L->r[8].key = 49;
	L->length = 8;
}
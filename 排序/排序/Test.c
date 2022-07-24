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
	//InsertSort(&L);//÷±Ω”≤Â»Î≈≈–Ú
	//BInsertSort(&L);//’€∞Î≤Â»Î≈≈–Ú
	//QuickSort(&L);//øÏÀŸ≈≈–Ú
	int dt[3] = { 5,3,1 };
	ShellSort(&L, dt, 3);//œ£∂˚≈≈–Ú

	for (int i = 1; i <= L.length; i++) {
		printf("%d  ", L.r[i].key);
	}
}
//’€∞Î≤Â»Î≈≈–Ú
int BInsertSort(SqList *L) {
	printf("’€∞Î≤Â»Î≈≈–Ú:\n");
	for (int i = 2; i <= L->length; i++) {
		L->r[0] = L->r[i];
		int low = 1, high = i - 1;
		while (low <= high) {
			int m = (low + high) / 2;
			if (L->r[0].key < L->r[m].key) {
				high = m - 1;
			}
			else {
				low = m + 1;
			}
		}
		for (int j = i - 1; j >= high + 1; j--) {
			L->r[j + 1] = L->r[j];
		}
		L->r[high + 1] = L->r[0];
	}
}
//÷±Ω”≤Â»Î≈≈–Ú
int InsertSort(SqList *L) {
	printf("÷±Ω”≤Â»Î≈≈–Ú:\n");
	for (int i = 2; i <= L->length; i++) {
		if (L->r[i].key < L->r[i - 1].key) {
			L->r[0] = L->r[i];
			L->r[i] = L->r[i - 1];
			int j = 0;
			for (j = i - 2; L->r[0].key < L->r[j].key; j--) {
				L->r[j + 1] = L->r[j];
			}
			L->r[j + 1] = L->r[0];
		}
	}
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
//øÏÀŸ≈≈–Ú
int Partition(SqList *L, int low, int high) {
	L->r[0] = L->r[low];
	int pivotkey = L->r[low].key;
	while (low < high) {
		while (low < high&&L->r[high].key >= pivotkey) {
			high--;
		}
		L->r[low] = L->r[high];
		while (low < high&&L->r[low].key <= pivotkey) {
			low++;
		}
		L->r[high] = L->r[low];
	}
	L->r[low] = L->r[0];
	return low;
}
void QSort(SqList *L, int low, int high) {
	if (low < high) {
		int pivotloc = Partition(L, low, high);
		QSort(L, low, pivotloc - 1);
		QSort(L, pivotloc + 1, high);
	}
}
int QuickSort(SqList *L) {
	printf("øÏÀŸ≈≈–Ú£∫\n");
	QSort(L, 1, L->length);
}
//œ£∂˚≈≈–Ú
int ShellSort(SqList *L, int dt[], int t) {
	printf("œ£∂˚≈≈–Ú:\n");
	for (int k = 0; k < t; k++) {
		ShellInsert(L, dt[k]);
	}
}
int ShellInsert(SqList *L, int dk) {
	for (int i = dk + 1; i <= L->length; i++) {
		if (L->r[i].key < L->r[i - dk].key) {
			L->r[0] = L->r[i];
			int j = 0;
			for (j = i - dk; j > 0 && L->r[0].key < L->r[j].key; j -= dk) {
				L->r[j + dk] = L->r[j];
			}
			L->r[j + dk] = L->r[0];
		}
	}
}
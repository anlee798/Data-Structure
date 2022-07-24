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
	MergeSort(&L);
	for (int i = 1; i <= L.length; i++) {
		printf("%d  ", L.r[i].key);
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
	L->length = 7;
}
int Merge(RedType R[], RedType T[], int low, int mid, int high) {
	int i = low, j = mid + 1, k = low;
	while (i <= mid&&j <= high) {
		if (R[i].key <= R[j].key) {
			T[k++] = R[i++];
		}
		else {
			T[k++] = R[j++];
		}
	}
	while (i <= mid) {
		T[k++] = R[i++];
	}
	while (j <= high) {
		T[k++] = R[j++];
	}
}
int MSort(RedType R[], RedType T[], int low, int high) {
	if (low == high) {
		T[low] = R[low];
	}
	else {
		RedType S[8] = {0};
		int mid = (low + high) / 2;
		MSort(R, S, low, mid);
		MSort(R, S, mid+1, high);
		Merge(S,T,low,mid,high);
	}
}
int MergeSort(SqList *L) {
	MSort(L->r, L->r, 1, L->length);
}
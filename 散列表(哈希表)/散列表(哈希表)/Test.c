#include <stdio.h>
#include <stdlib.h>
#define HASHSIZE 15
#define NULLKEY -32768
typedef struct
{
	int *elem; //数据元素存储地址
	int count;//当前元素个数
}HashTable;
int L = 0; //表的长度
int main() {
	HashTable hashTable;
	int arr[HASHSIZE];
	printf("请输入15个，初始化哈希表的元素：\n");
	for (int i = 0; i < HASHSIZE; i++)
	{
		scanf("%d", &arr[i]);
	}
	Init(&hashTable);
	for (int i = 0; i < HASHSIZE; i++) {
		insert(&hashTable, arr[i]);
	}
	display(&hashTable);
	int x = 0;
	printf("请输入你要查找的元素：\n");
	scanf("%d", &x);
	int result = findNum(hashTable, x);
	if (result)
		printf("查找元素%d在哈希表中的位置为%d\n", x, result);
	else
		printf("没找到！\n");
}
int Init(HashTable *hashTable)//哈希表的初始化
{
	int i;
	L = HASHSIZE;
	hashTable->elem = (int*)malloc(L * sizeof(int));//申请内存
	hashTable->count = L;
	for (i = 0; i < L; i++)
	{
		hashTable->elem[i] = NULLKEY;
	}
	return 1;
}
//哈希函数，除留余数法
int Hash(int data)
{
	return data%L;
}
int insert(HashTable *hashTable, int data)
{
	int Addr = Hash(data);//求哈希地址
	while (hashTable->elem[Addr] != NULLKEY)//求得地址不是初始化时的空，则表示有元素已经插入，会有冲突
	{
		Addr = (Addr + 1) % L;//开放地址线性探测，还可以二次探测
	}
	hashTable->elem[Addr] = data;
}

int display(HashTable *hashTable)
{
	printf(".........结果展示.........\n");
	for (int i = 0; i < hashTable->count; i++)
	{
		printf("%d  ", hashTable->elem[i]);
	}
	printf("\n");
}
int findNum(HashTable hashTable, int data) {
	int Addr = Hash(data);
	while (hashTable.elem[Addr] != data)
	{
		Addr = (Addr + 1) % L;
		if (hashTable.elem[Addr] == NULLKEY || Addr == Hash(data)) {
			return 0;
		}
	}
	return Addr + 1;
}
//测试数据： 19 14 23 1 68 20 84 27 55 11 10 79 95 12 50
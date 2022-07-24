#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define ERROR 0;
#define OK 1;
typedef int ElemType;
typedef struct{
	ElemType *elem;
	int length;
}SqList;
int main(){
	SqList L;
	IniSqList(&L);
	CreatList(&L);
	TraverseList(L);
	ElemType e;
	GetElem(L, 5, &e);
	printf("%d  \n",e);
	/*ClearList(&L);
	TraverseList(L);*/
	ListEmpty(L);
	printf("数据元素个数为：%d\n", ListLength(L));
	printf("数据元素10位于%d位\n",LocateElem(L,21));
	int cur_e=16;
	ElemType pre_e, next_e;
	PriorElem(L, cur_e, &pre_e);
	NextElem(L, cur_e, &next_e);

	int i=4, e2=100;
	ListInsert(&L, i, e2);
	TraverseList(L);
	printf("数据元素个数为：%d\n", ListLength(L));
	ListDelete(&L, i);
	TraverseList(L);
	printf("数据元素个数为：%d\n", ListLength(L));
}
int IniSqList(SqList *L){	//构造空的线性表
	L->elem = (int *)malloc(MAXSIZE*sizeof(int));
	if (L->elem == NULL){
		printf("存储分配失败！\n");
		return ERROR;
	}
	else{
		printf("存储分配成功！\n");
		L->length = 0;
		return OK;
	}
}
int DestroyList(SqList *L){	//销毁线性表
	L->elem = NULL;
	L->length = 0;
	printf("销毁线性表成功！\n");
	return OK;
}
int ClearList(SqList *L){	//将线性表清空
	L->elem = NULL;
	L->length = 0;
	printf("清空线性表成功！\n");
	return OK;
}
int ListEmpty(SqList L){	//判断是否为空表
	if (L.elem != NULL){
		printf("线性表不为空表\n");
		return ERROR;
	}else{
		printf("线性表为空表\n");
		return OK;
	}
}
int ListLength(SqList L){	//元素个数
	return L.length;
}
int CreatList(SqList *L){		//给数据创建值
	for (int i = 0; i < 10; i++){
		L->elem[i] = i*2;
		L->length++;
	}
	return OK;
}
int GetElem(SqList L, int i, ElemType *e){	//获取指定元素的值
	if (i < 1 || i>L.length){
		printf("访问数据非法！\n");
		return ERROR;
	}
	*e = L.elem[i - 1];
	return OK;
}
int LocateElem(SqList L, ElemType e){		//根据值返回元素位置，不存在返回0
	for (int i = 0; i < L.length;i++){
		if (L.elem[i] == e){
			return i+1;
		}
	}
	return 0;
}
int PriorElem(SqList L, ElemType cur_e, ElemType *pre_e){	//前驱
	for (int i = 0; i < L.length; i++){
		if (L.elem[i] == cur_e){
			if (i - 1 <= 0){
				printf("%d无前驱\n",cur_e);
				return ERROR;
			}
			else{
				printf("%d前驱为%d\n", cur_e, L.elem[i - 1]);
				return OK;
			}
		}
	}
}
int NextElem(SqList L, ElemType cur_e, ElemType *next_e){			//后继
	for (int i = 0; i < L.length; i++){
		if (L.elem[i] == cur_e){
			if (i >= L.length){
				printf("%d无后继\n", cur_e);
				return ERROR;
			}
			else{
				printf("%d后继为%d\n", cur_e, L.elem[i + 1]);
				return OK;
			}
		}
	}
}
int ListInsert(SqList *L, int i, ElemType e){		//插入数据到指定位置
	printf("--------插入数据到指定位置--------\n");
	if ((i<1) || (i>L->length + 1)){
		printf("数据插入位置非法！\n");
		return ERROR;
	}
	if (L->length==MAXSIZE){
		printf("当前存储空间已满！\n");
		return ERROR;
	}
	/*if (L->length == MAXSIZE){
		L=(int *)realloc(L, (MAXSIZE+1)* sizeof(int));
	}*/
	for (int j = L->length+1; j >= i; j--){
		L->elem[j] = L->elem[j - 1];
	}
	L->elem[i-1] = e;
	L->length++;
	return OK;
}
int ListDelete(SqList *L, int i){	//删除指定位置数据
	printf("--------删除指定位置数据--------\n");
	if ((i<1) || (i>L->length)){
		printf("删除数据位置非法！\n");
		return ERROR;
	}
	i = i - 1;
	for (i; i < L->length-1; i++){
		L->elem[i] = L->elem[i + 1];
	}
	L->length--;
	return OK;
}
int TraverseList(SqList L){	//遍历数据
	printf("--------遍历数据--------\n");
	for (int i = 0; i < L.length; i++){
		printf("%d  ",L.elem[i]);
	}
	printf("\n");
	return OK;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
#define OK 1;
#define ERROR 0;
typedef struct {
	int num;
	char *name;
	float score;
}Student;
typedef struct {
	Student *elem;
	int length;
}SqList;
void main() {

	SqList L;
	UI();
	while (1) {
		int choose;
		printf("请输入你的选择：\n");
		scanf("%d", &choose);
		switch (choose)
		{
			case 1:IniSqList(&L); UI(); break;
			case 2:CreatList(&L); UI(); break;
			case 3:TraverseList(L); UI(); break;
			case 4:GetElem(L); UI(); break;
			case 5:ListInsert(&L); UI(); break;
			case 6:ListDelete(&L); UI(); break;
			case 7:DestroyList(&L); UI(); break;
			case 8:return 0; break;
			default:printf("操作错误！请重新输入你的选择！\n"); break;
		}
	}
}
int IniSqList(SqList *L) {	//构造空的线性表
	L->elem = (Student *)malloc(MAXSIZE * sizeof(Student));
	if (L->elem == NULL) {
		printf("存储分配失败！\n");
		return ERROR;
	}
	else {
		printf("存储分配成功！\n");
		L->length = 0;
		return OK;
	}
}
int DestroyList(SqList *L) {	//销毁线性表
	L->elem = NULL;
	L->length = 0;
	printf("销毁线性表成功！\n");
	return OK;
}
int CreatList(SqList *L) {		//创建顺序表
	IniSqList(L);
	/*printf("请输入你要创建学生的个数\n");
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ListInsert(L);
	}*/
	L->elem[0].num = 17217014;    //测试使用
	L->elem[0].name = "Jason";
	L->elem[0].score = 80;
	L->length++;
	L->elem[1].num = 17217015;
	L->elem[1].name = "Eason";
	L->elem[1].score = 90;
	L->length++;
	L->elem[2].num = 17217016;
	L->elem[2].name = "Aason";
	L->elem[2].score = 100;
	L->length++;
}
int TraverseList(SqList L) {	//遍历数据
	printf("--------------遍历数据--------------\n");
	if (L.length == 0) {
		printf("暂无数据\n");
		return ERROR;
	}
	for (int i = 0; i < L.length; i++) {
		printf("学号： %10d   ", L.elem[i].num);
		printf("姓名： %10s   ", L.elem[i].name);
		printf("分数： %10.1f\n", L.elem[i].score);
	}
	printf("\n");
	return OK;
}
int GetElem(SqList L) {	//获取指定元素的值
	printf("----------查询数据操作----------\n");
	char name[20];
	int num;
	printf("请输入你要查询的数据：\n");
	int choose = 0;
	printf("\n按姓名查找请按“1”\n按学号查找请按“2”\n\n");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:	printf("请输入你要查询的姓名\n");
		scanf("%s", name);
		for (int i = 0; i < L.length; i++) {
			if (strcmp(L.elem[i].name,name)==0) {
				printf("查找信息：\n");
				printf("学号：%10d    ", L.elem[i].num);
				printf("姓名：%10s    ", L.elem[i].name);
				printf("分数：%10.1f\n", L.elem[i].score);
				return OK;
			}
		}
		break;
	case 2:	printf("请输入你要查询的学号\n");
		scanf("%d", &num);
		for (int i = 0; i < L.length; i++) {
			if (L.elem[i].num == num) {
				printf("查找信息：\n");
				printf("%10d    ", L.elem[i].num);
				printf("%10s    ", L.elem[i].name);
				printf("%10.1f\n", L.elem[i].score);
				return OK;
				break;
			}
		}
		break;
	default:printf("操作错误！\n"); return ERROR;
		break;
	}
	printf("查询无果！\n");
	return ERROR;
}
int ListDelete(SqList *L) {	//删除指定位置数据
	printf("--------删除指定位置数据--------\n");
	char name[20];
	int num;
	printf("请输入你要删除的数据：\n");
	int choose = 0;
	printf("\n按姓名删除请按“1”\n按学号删除请按“2”\n\n");
	scanf("%d", &choose);
	switch (choose)
	{
		case 1:	printf("请输入你要删除数据的姓名\n");
				scanf("%s", name);
				if (strcmp(L->elem[L->length - 1].name, name)==0) {
					L->length--;
					printf("删除数据成功！\n");
					return OK;
				};
				for (int j = 0; j < L->length - 1; j++) {
					if (strcmp(L->elem[j].name, name) == 0) {
						for (int i = j; i < L->length - 1; i++) {
							L->elem[i] = L->elem[i + 1];
						}
						L->length--;
						printf("删除数据成功！\n");
						return OK;
					}
				}
				break;
		case 2:	printf("请输入你要删除数据的学号\n");
				scanf("%d", &num);
				if (L->elem[L->length - 1].num==num) {
					L->length--;
					printf("删除数据成功！\n");
					return OK;
				}
				for (int j = 0; j < L->length - 1; j++) {
					if (L->elem[j].num==num) {
						for (int i = j; i < L->length - 1; i++) {
							L->elem[i] = L->elem[i + 1];
						}
						L->length--;
						printf("删除数据成功！\n");
						return OK;
					}
				}
				break;
		default:printf("操作错误！\n"); return ERROR;break;
	}
	printf("删除失败！（不存在该数据）\n");
	return OK;
}
int ListInsert(SqList *L) {		//插入数据到指定位置
	printf("		-------插入数据-------\n");
	Student s;
	char str[20];
	printf("请输入你要插入的学生学号:\n");
	scanf("%d", &s.num);
	printf("请输入你要插入的学生姓名:\n");
	scanf("%s", str);
	printf("请输入你要插入的学生分数:\n");
	scanf("%f", &s.score);
	s.name = strdup(str);
	if (L->length >= MAXSIZE) {
		printf("数据已满！\n");
		return ERROR;
	}
	for (int i = 0; i < L->length; i++) {
		if (s.score <= L->elem[i].score) {
			for (int j = L->length; j >= i; j--) {
				L->elem[j] = L->elem[j - 1];
			}
			L->elem[i].num = s.num;
			L->elem[i].name = s.name;
			L->elem[i].score = s.score;
			L->length++;
		}
	}
	printf("插入数据成功！\n");
	return OK;
}
int UI() {
	printf("\t\t***************************************\n");
	printf("\t\t*------学生成绩管理系统(顺序表)-------*\n");
	printf("\t\t*		                      *\n");
	printf("\t\t*----------按“1”初始化线性表--------*\n");
	printf("\t\t*----------按“2”创建线性表----------*\n");
	printf("\t\t*----------按“3”遍历线性表----------*\n");
	printf("\t\t*----------按“4”查询数据------------*\n");
	printf("\t\t*----------按“5”插入数据------------*\n");
	printf("\t\t*----------按“6”删除数据------------*\n");
	printf("\t\t*----------按“7”销毁线性表----------*\n");
	printf("\t\t*----------按“8”退出操作系统--------*\n");
	printf("\t\t*		                      *\n");
	printf("\t\t***************************************\n");
	return OK;
}
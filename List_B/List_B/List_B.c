#include<stdio.h>
#include <stdlib.h> 
#include <string.h>
#define OK 1;
#define ERROR 0;
typedef struct {
	int num;
	char *name;
	float score;
}Student;
typedef struct LNode{
	Student *elem;
	struct LNode *next;
}LNode , *LinkList;
int main() {
	LinkList L;
	UI();
	while (1) {
		int choose;
		printf("请输入你的选择：\n");
		scanf("%d",&choose);
		switch (choose)
		{
			case 1:InitList(&L); UI(); break;
			case 2:CreatList(&L); UI(); break;
			case 3:TraverseList(L); UI(); break;
			case 4:LocateElem(L); UI();; break;
			case 5:ListInsert(&L); UI(); break;
			case 6:ListDelete(&L);UI();break;
			case 7:DestroyList(&L); break;
			case 8:return 0; break;
			case 9:ListLength(L); UI(); break;
			case 10:DeleteRepeat(&L); UI(); break;
			default:printf("操作错误！请重新输入你的选择！\n"); break;
		}
	}
}

int InitList(LinkList *L) {
	*L = (LinkList *)malloc(sizeof(LNode));
	(*L)->next = NULL;
	printf("链表初始化成功！\n");
	return OK;
}

int DeleteRepeat(LinkList *L) {
	LinkList p = (*L)->next;
	while (p) {
		if (p->next == NULL) {
			break;
		}
		LinkList m = p;
		while (m->next) {
			if (p->elem->num == m->next->elem->num) {
				LinkList q = m->next;
				m->next = q->next;
				if (q == NULL) {
					break;
				}
				continue;
			}
			m = m->next;
		}
		p = p->next;
	}
	printf("Successful\n");
}

int CreatList(LinkList *L) {
	printf("---------创建单链表操作---------\n");
	InitList(L);
	/*printf("请输入你要创建学生的个数\n");
	int n = 0;
	scanf("%d",&n);

	for (int i = 0; i < n;i++) {
		ListInsert(L);
	}*/

	LinkList p = (LinkList)malloc(sizeof(LNode));   //测试使用
	LinkList r = *L;
	p->elem = (Student *)malloc(sizeof(Student));
	p->elem->num = 17217014;
	p->elem->name = "Jason";
	p->elem->score = 80;
	p->next = NULL;
	r->next = p;
	r = p;

	p = (LinkList)malloc(sizeof(LNode));
	p->elem = (Student *)malloc(sizeof(Student));
	p->elem->num = 17217015;
	p->elem->name = "Eason";
	p->elem->score = 90;
	p->next = NULL;
	r->next = p;
	r = p;

	p = (LinkList)malloc(sizeof(LNode));
	p->elem = (Student *)malloc(sizeof(Student));
	p->elem->num = 17217016;
	p->elem->name = "Aason";
	p->elem->score = 100;
	p->next = NULL;
	r->next = p;
	r = p;

}

int ListInsert(LinkList *L) {
	printf("---------单链表插入操作---------\n");
	LinkList p = *L,q ,r;
	r = p;
	q= (LinkList)malloc(sizeof(LNode));
	q->elem= (Student *)malloc(sizeof(Student));
	Student s;
	char name[20];
	printf("请输入插入的学生学号：\n");
	scanf("%d",&s.num);
	printf("请输入插入的学生姓名：\n");
	scanf("%s",name);
	printf("请输入插入的学生分数：\n");
	scanf("%f",&s.score);
	s.name = strdup(name);
	q->elem->num = s.num;
	q->elem->name = s.name;
	q->elem->score = s.score;
	if (p->next==NULL) {
		q->next = NULL;
		p->next = q;
		printf("插入数据成功！\n");
		return OK;
	}
	p = p->next;
	while (p) {
		if (p->elem->score<s.score&&p->next == NULL) {
			q->next = NULL;
			p->next = q;
			printf("插入数据成功！\n");
			return OK;
		}
		if (p->elem->score<s.score&&p->next->elem->score>s.score) {
			q->next = p->next;
			p->next = q;
			printf("插入数据成功！\n");
			return OK;
		}
		if (p->elem->score>s.score) {
			r->next = q;
			q->next = p;
			printf("插入数据成功！\n");
			return OK;
		}
		p = p->next;
	}
	return ERROR; 
}

int ListLength(LinkList L) {
	LinkList p = L->next;
	int count = 0;
	while (p) {
		count++;
		p=p->next;
	}
	printf("个数：%d\n",count);
}

int TraverseList(LinkList L) {
	printf("---------遍历单链表---------\n");
	if (L==NULL) {
		printf("链表尚未建立！\n");
		return ERROR;
	}
	LinkList p = L->next;
	if (p==NULL) {
		printf("暂无数据！\n");
		return OK;
	}
	while (p) {
		printf("学号：%10d    ",p->elem->num);
		printf("姓名：%10s    ", p->elem->name);
		printf("分数：%10.1f\n", p->elem->score);
		p = p->next;
	}
}
int LocateElem(LinkList L) {
	printf("----------查询数据操作----------\n");
	char name[20];
	int num;
	LinkList p = L->next;
	printf("请输入你要查询的数据：\n");
	int choose = 0;
	printf("\n按姓名查找请按“1”\n按学号查找请按“2”\n\n");
	scanf("%d",&choose);
	switch (choose)
	{
		case 1:	printf("请输入你要查询的姓名\n");
				scanf("%s", name); 
				while (p&& strcmp(p->elem->name, name)) {
					p = p->next;
				}; 
				break;
		case 2:	printf("请输入你要查询的学号\n");
				scanf("%d", &num); 
				while (p&&p->elem->num != num) {
					p = p->next;
				}; 
				break;
		default:printf("操作错误！\n"); return ERROR;
		break;
	}
	
	if (p == NULL) {
		printf("查询无果！（不存在该数据）\n");
		return ERROR;
	}
	printf("查找信息：\n");
	printf("学号：%10d    ", p->elem->num);
	printf("姓名：%10s    ", p->elem->name);
	printf("分数：%10.1f\n", p->elem->score);
	return OK;
}
int ListDelete(LinkList *L) {
	printf("----------删除数据操作----------\n");
	char name[20];
	int num;
	LinkList p = (*L);
	printf("请输入你要删除的数据：\n");
	int choose = 0;
	printf("\n按姓名删除请按“1”\n按学号删除请按“2”\n\n");
	scanf("%d", &choose);
	switch (choose)
	{
		case 1:	printf("请输入你要删除数据的姓名\n");
				scanf("%s", name);
				while (p->next&& strcmp(p->next->elem->name, name)) {
					p = p->next;
				};
				break;
		case 2:	printf("请输入你要删除数据的学号\n");
				scanf("%d", &num);
				while (p->next&&p->next->elem->num != num) {
					p = p->next;
				};
				break;
		default:printf("操作错误！\n"); return ERROR;
				break;
	}
	if (p->next == NULL) {
		printf("删除失败！（不存在该数据）\n");
		return ERROR;
	}
	LinkList q = p->next;
	p->next = q->next;
	free(q->elem);
	free(q);
	printf("删除数据成功！\n");
	return OK;
}
int DestroyList(LinkList *L) {
	printf("----------销毁链表----------\n");
	LinkList p;
	while (*L!=NULL) {
		p = *L;
		*L = (*L)->next;
		free(p->elem);
		free(p);
	}
	return OK;
}
int UI() {
	printf("\t\t***************************************\n");
	printf("\t\t*-------学生成绩管理系统(链表)--------*\n");
	printf("\t\t*		                      *\n");
	printf("\t\t*----------按“1”初始化线性表--------*\n");
	printf("\t\t*----------按“2”创建线性表----------*\n");
	printf("\t\t*----------按“3”遍历线性表----------*\n");
	printf("\t\t*----------按“4”查询数据------------*\n");
	printf("\t\t*----------按“5”插入数据------------*\n");
	printf("\t\t*----------按“6”删除数据------------*\n");
	printf("\t\t*----------按“7”销毁线性表----------*\n");
	printf("\t\t*----------按“8”退出操作系统--------*\n");
	printf("\t\t*----------按“9”计算数据个数--------*\n");
	printf("\t\t*----------按“10”删除重复值---------*\n");
	printf("\t\t*		                      *\n");
	printf("\t\t***************************************\n");
}
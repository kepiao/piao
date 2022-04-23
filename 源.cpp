#include<stdio.h>
#include<string.h>
#include <corecrt_malloc.h>
#include<stdlib.h>
struct Student
{
	int stuid;
	int stuage;
	char stuname[100];
	struct Student* next;
};
struct Student* headP = NULL;
struct Student* tailP = NULL;
void printStudent(struct Student* curp)
{
	printf("学号：%d  年龄：%d  姓名：%s\n", curp->stuid, curp->stuage, curp->stuname);
}
void printLinkedliat(struct Student* headP)
{
	while (headP != NULL)
	{
		printStudent(headP);
		headP = headP->next;
	}
}
void addStudent()
{
	struct Student* nodeP = (struct Student*)malloc(sizeof(struct Student));
	printf("请输入学号：");
	scanf_s("%d", &nodeP->stuid);
	printf("请输入年龄：");
	scanf_s("%d", &nodeP->stuage);
	printf("请输入姓名：");
	scanf_s("%d", &nodeP->stuname);
	nodeP->next = NULL;
	if (headP == NULL)
	{
		headP = nodeP;
		tailP = nodeP;
	}
	else
	{
		tailP->next = nodeP;
		tailP = nodeP;
	}
	printf("添加成功\n");
}

void findStudent()
{
	printf("请输入想要查询的学生学号：");
	int id;
	scanf_s("%d", &id);
	struct Student* curP = headP;
	int flag = 0;
	while (curP != NULL)
	{
		if (curP->stuid == id)
		{
			printStudent(curP);
			flag = 1;
			break;
		}
		else
		{
			curP = curP->next;
		}
	}
	if (flag == 0)
	{
		printf("没有这个学生\n");
	}
}

void printAllStudent()
{
	if (headP == NULL)
	{
		printf("当前没有学生\n");
	}
	else
	{
		printLinkedliat(headP);
	}
}
int deleteStudent()
{
	printf("请输入要删除的学生学号：");
	int id;
	scanf_s("%d", &id);
	struct Student* curP = headP;
	if (curP->stuid == id)
	{
		headP = headP->next;
		free(curP);
		curP = NULL;
		return 0;
	}
	struct Student* preP = curP;
	curP = curP->next;
	while (curP != NULL)
	{
		if (curP->stuid == id)
		{
			struct Student* next = curP->next;
			preP->next = next;
			free(curP);
			curP = NULL;
			printf("已经删除\n");
			return 0;
		}
		else
		{
			preP = curP;
			curP = curP->next;
		}
	}
	printf("该学生不存在，无法删除\n");
}
int main()
{
	printf("           ===================================================\n");
	printf("          =            欢迎使用学生信息管理系统             =\n");
	printf("          =           1=录入学生信息     2=查询学生信息     =\n");
	printf("          =           3=删除学生信息     4=打印所有学生信息 =\n");
	printf("          =           5=退出系统                            =\n");
	printf("           ===================================================\n");
	printf("请选择:");
	while (1)
	{
		char c;
		scanf_s("%c", &c);
		switch (c)
		{
		case'1':
			addStudent();
			break;
		case'2':
			findStudent();
			break;
		case'3':
			printAllStudent();
			break;
		case'4':
			deleteStudent();
			break;
		case'5':
			exit(0);
		default:
			break;
		}
	}

	return 0;
}

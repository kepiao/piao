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
	printf("ѧ�ţ�%d  ���䣺%d  ������%s\n", curp->stuid, curp->stuage, curp->stuname);
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
	printf("������ѧ�ţ�");
	scanf_s("%d", &nodeP->stuid);
	printf("���������䣺");
	scanf_s("%d", &nodeP->stuage);
	printf("������������");
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
	printf("��ӳɹ�\n");
}

void findStudent()
{
	printf("��������Ҫ��ѯ��ѧ��ѧ�ţ�");
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
		printf("û�����ѧ��\n");
	}
}

void printAllStudent()
{
	if (headP == NULL)
	{
		printf("��ǰû��ѧ��\n");
	}
	else
	{
		printLinkedliat(headP);
	}
}
int deleteStudent()
{
	printf("������Ҫɾ����ѧ��ѧ�ţ�");
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
			printf("�Ѿ�ɾ��\n");
			return 0;
		}
		else
		{
			preP = curP;
			curP = curP->next;
		}
	}
	printf("��ѧ�������ڣ��޷�ɾ��\n");
}
int main()
{
	printf("           ===================================================\n");
	printf("          =            ��ӭʹ��ѧ����Ϣ����ϵͳ             =\n");
	printf("          =           1=¼��ѧ����Ϣ     2=��ѯѧ����Ϣ     =\n");
	printf("          =           3=ɾ��ѧ����Ϣ     4=��ӡ����ѧ����Ϣ =\n");
	printf("          =           5=�˳�ϵͳ                            =\n");
	printf("           ===================================================\n");
	printf("��ѡ��:");
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

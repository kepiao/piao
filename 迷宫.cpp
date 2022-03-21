#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define ROW 9
#define COL 11
char map [ROW][COL+1]={
	"*#***#****#",
	"***#***#**#",
	"#####*##*##",
	"##***###***",
	"***#***#*#*",
	"##**##***##",
	"*##**###*#*",
	"*###*##*#*E",
	"#**#******#",
	};

void print_map()//��ӡ��ͼ
{
	for(int i=0;i<ROW;i++)
	{
		puts(map[i]);
	}
}

void show_cursor(int x,int y)//���ƹ��
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	printf("curX=%d,corY=%d\n",x,y);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int curX=0,curY=0;//����ʼλ��
int main()//������
{
	printf("��ͬѧ���ڼ��ڹ����ȥ�����ʱ�򣬱�������һ��С���ϣ�С���Ĵ���������ͬѧ�е������ģ������������޴�ʱ������ͻȻƯ����һ��Ư��ƿ�������и�Сֽ���������һ���ķ��ѾõĹµ�����С����ĳ�������һ��С����ֻҪ�ҵ�С���Ϳ����뿪������ǵ��ϻ������۸��ӣ������Թ�һ���������������ͬѧ�߳��Թ����뿪�µ���//����������������Ѱ�ҳ�·~���������£�\n1.wasd�ֱ���������꣩���������ƶ�\n2.\n#���Թ���ǽ\n*��С������·\n�ߣ������Ǻ�\nE:������С��\n3.���������߳�С�����ҵ�С��������ս�ɹ�������\n�����������!");
	int a;
	a==getch();
	
	while(1)
	{

		system("cls");//ɾ��ǰ���ӡ���
		print_map();//���ú�����ӡ��ͼ
		show_cursor(curX,curY);//���ú������ƹ��

		char t=getch();//���̽���
		if(t=='w')
		{
			if((curY-1)>=0 && (map[curY-1][curX]=='*' || map[curY-1][curX]=='E')) curY--;
		}
		else if(t=='s')
		{
			if((curY-1)<ROW && (map[curY+1][curX]=='*' || map[curY+1][curX]=='E')) curY++;
		}
		else if(t=='a')
		{
			if((curX-1)>=0 && (map[curY][curX-1]=='*' || map[curY][curX-1]=='E')) curX--;
		}
		else if(t=='d')
		{
			if((curX+1)<COL && (map[curY][curX+1]=='*' || map[curY][curX+1]=='E')) curX++;
		}
		if(map[curY][curX]=='E')
		{
			printf("\n");	
			printf("��ϲ��ɹ��߳�С��!!!\n");break;
		
		}
	}
	return 0;
}


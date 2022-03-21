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

void print_map()//打印地图
{
	for(int i=0;i<ROW;i++)
	{
		puts(map[i]);
	}
}

void show_cursor(int x,int y)//控制光标
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	printf("curX=%d,corY=%d\n",x,y);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int curX=0,curY=0;//光标初始位置
int main()//主函数
{
	printf("王同学，在假期过年出去游玩的时候，被困在了一个小岛上，小岛四处环海，王同学感到很伤心，正当他手足无措时，海边突然漂来了一个漂流瓶，里面有个小纸条：“这个一座荒废已久的孤岛，在小岛的某处存放着一条小船，只要找到小船就可以离开这里，但是岛上环境错综复杂，就像迷宫一样”。请你帮助王同学走出迷宫，离开孤岛！//“落入困境，积极寻找出路~”规则如下：\n1.wasd分别控制人物（光标）上下左右移动\n2.\n#：迷宫高墙\n*：小岛可行路\n边：四周是海\nE:出口有小船\n3.控制人物走出小岛，找到小船，及挑战成功！！！\n按任意键继续!");
	int a;
	a==getch();
	
	while(1)
	{

		system("cls");//删除前面打印结果
		print_map();//调用函数打印地图
		show_cursor(curX,curY);//调用函数控制光标

		char t=getch();//键盘接受
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
			printf("恭喜你成功走出小岛!!!\n");break;
		
		}
	}
	return 0;
}


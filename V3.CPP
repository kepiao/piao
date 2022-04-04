#include <stdio.h>
#include <string.h>

int main()
{
	char str[]="2+2*3+2/2-1";
	char ls[100]="\0";
	int a=-1;

	for (int i=0;i<strlen(str);i++)
	{
		if (str[i]=='*')
		{
			int left=ls[a]-'0';
			int right=str[i+1]-'0';
			ls[a]=left*right+'0';
			i++;
		}
		else if(str[i]=='/')
		{
			int left=ls[a]-'0';
			int right=str[i+1]-'0';
			ls[a]=left/right+'0';
			i++;
		}
		else ls[++a]=str[i];
	}

	int sum=ls[0]-'0';
	for(int j=0;j<strlen(ls);j++)
	{
		if (ls[j]=='+')
		{
			int right=ls[j+1]-'0';
			sum=sum+right;j++;
		}
		else if (ls[j]=='-')
		{
			int right=ls[j+1]-'0';
			sum=sum-right;j++;
		}
		
	}
	printf("ÔËËã: %s\n",str);
	printf("½á¹û=%d\n",sum);

	return 0;
}
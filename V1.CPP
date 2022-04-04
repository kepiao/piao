#include <stdio.h>
#include <string.h>

int main()
{
	char str[]="1+2+2+1+2+5+4-1-3+4-8";
	int sum=str[0]-'0';
	for(int i=1;i<strlen(str);i++)
	{
		if (str[i]=='+')
		{
			int a=str[i+1]-'0';
			sum=sum+a;i++;
		}
		else if (str[i]=='-')
		{
			int b=str[i+1]-'0';
			sum=sum-b;i++;
		}
	}
	printf("ÔËËã£º %s\n",str);
	printf("½á¹û=%d\n",sum);

	return 0;
}
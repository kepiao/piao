#include<stdio.h>
#include<string.h>

int count(char sentence[],char word[])//定义函数 统计单词数
{
	int i=0,j,count=0;
	while(sentence[i])
	{
		j=0;
		while(word[j])
		{
			if(word[j]!=sentence[i+j])
			break;
			j++;
		}
		if(!word[j])
		{
			count++;
			i+=j-1;
		}
		i++;
	}
	return count;
}

int main() //主函数
{
	printf("请输入句子：\n");
	char sentence[10000];gets(sentence); //定义数组 输入句子
	printf("请输入单词：\n");
	char word[10];gets(word); //定义数组 输入单词
	printf("%d\n",count(sentence,word)); //调用函数 返回结果
	return 0;
} 

#include<stdio.h>
#include<string.h>

int count(char sentence[],char word[])//���庯�� ͳ�Ƶ�����
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

int main() //������
{
	printf("��������ӣ�\n");
	char sentence[10000];gets(sentence); //�������� �������
	printf("�����뵥�ʣ�\n");
	char word[10];gets(word); //�������� ���뵥��
	printf("%d\n",count(sentence,word)); //���ú��� ���ؽ��
	return 0;
} 

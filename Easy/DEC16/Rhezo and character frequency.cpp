#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	char s[10000];char ch;int p,i,j,temp=0,max,flag=0;
	fflush(stdin);
	scanf("%s",s);
	cin>>ch>>p;
	for(i=0;s[i]!='\0';i++)
	{
		temp=0;
		for(j=i;j<i+p;j++)
		{
			//printf("%c ",s[j]);
			if(s[j]==ch)
					temp++;
		}
		if(temp>max)
			max=temp;
		//printf("\n\n");			
	}
	i--;
	for(;i>=0;i--)
	{
		temp=0;
		for(j=i;j>i-p+1;j--)
		{
			//printf("%c ",s[j]);
			if(s[j]==ch)
					temp++;
		}
		if(temp==max)
		{
			flag=1;
			break;
		}
		//printf("\n\n");		
	}
	if(flag)
		printf("%d",i+1);
	else
		printf("-1");	
}

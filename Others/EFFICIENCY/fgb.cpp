#include<stdio.h>
int main()
{
	int T;	scanf("%d",&T);
	while(T--)
	{
		char ch[25];
		scanf("%s",ch);
		int cost=0;int i;
		for(i=0;ch[i]!='\0';i++)
		{
			cost+=ch[i]-'0';	
		}	
		//printf("%d---%d\n",i,cost);	
		cost=35-cost;
		if(i%2)
		{
				if(cost%7)		printf("Search for a new teammate\n");
				else 	printf("Pro Abhishek\n");										
		}
		else
		{
			if(cost%7==0)	printf("Search for a new teammate\n");
			else	printf("Pro Abhishek\n");
		}
	}
}

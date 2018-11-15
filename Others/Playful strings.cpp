#include<stdio.h>
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		char str[50];
		int pos[50],i,flag=0,j;
		scanf("%s",str);
		for(i=0;str[i]!='\0';i++)
		{
			int d1=(int)str[i-1];
			int d2=(int)str[i];
			int m=0;
			if(d2>d1)
				m=d2-d1;
			else
				m=d1-d2;	
			if(m==1||m==25)
				flag++;
		}	
		if(flag==i-1)
			printf("YES\n");
		else
			printf("NO\n");	
	}
	return 0;
}

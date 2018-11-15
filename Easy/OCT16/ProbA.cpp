#include<stdio.h>
#include<string.h>
#include<iostream>
struct fan
{
	long long int fc;
	char name[25];	
};
int main()
{
	int n,t,i,j;	scanf("%d %d",&n,&t);
	struct fan f[n],temp;
	getchar();
	for(i=0;i<n;i++)
	{
		scanf("%s",f[i].name);
		scanf("%lld",&f[i].fc);
	}
	//printf("YYYYYYYYYYYYY")
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(f[j].fc<f[j+1].fc)
			{
				temp=f[j];
				f[j]=f[j+1];
				f[j+1]=temp;	
			}
		}
	}
	for(i=0;i<n;i++)
	{	
		for(j=0;j<n-1-i;j++)
		{	
			if(f[j].fc==f[j+1].fc)
			{
				if(strcmp(f[j].name,f[j+1].name)>=0)
				{
					//printf("Swapping %s and  %s   \n",f[j].name,f[j+1].name);
					temp=f[j];
					f[j]=f[j+1];
					f[j+1]=temp;
				}
			}
		}
	}
	for(i=0;i<t;i++)
	{
		printf("%s\n",f[i].name);
	}
}

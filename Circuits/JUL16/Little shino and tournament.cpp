#include<stdio.h>
struct fighter
{
	int num;
	int str;
	int mat;	
};
int main()
{
	int n,q,i,m,d,j;
	scanf("%d %d",&n,&q);
	struct fighter s[n],temp;	d=n;
	//int ansque[q];
	for(i=0;i<n;i++)
	{
		s[i].num=i+1;
		s[i].mat=0;
		scanf("%d",&s[i].str);
	}
	/*for(i=0;i<q;i++)
		scanf("%d",&ansque[i]);*/	
	while(n>1)
	{
		m=0;
		for(i=0;i<n;i=i+2)
		{
			if(m==(n/2)&&(n)%2!=0)
			{
				temp=s[m];
				s[m]=s[n-1];
				s[n-1]=temp;
				m++;
				break;
			}
			s[i].mat++;
			s[i+1].mat++;
			if(s[i].str>s[i+1].str)
			{
				temp=s[m];
				s[m]=s[i];
				s[i]=temp;
				m++;
			}
			else
			{
				temp=s[m];
				s[m]=s[i+1];
				s[i+1]=temp;
				m++;
			}
		}
		n=m;
	}	
	/*int g;
	while(q--)
	{
		scanf("%d",&g);
		for(i=0;i<n;i++)
		{
			if(g==s[i].num)
					printf("%d\n",s[i].mat);
		}
	}*/
	for(i=0;i<q;i++)
	{
		for(j=0;j<d;j++)
		{
			if(ansque[i]==s[j].num)
					printf("%d\n",s[j].mat);
		}			
	}
	return 0;
}

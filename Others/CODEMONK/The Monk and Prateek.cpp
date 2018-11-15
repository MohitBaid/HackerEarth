#include<stdio.h>
#include<stdlib.h>
struct n
{
	int p;
	int num;
}A[10000001];
int cmpfunc(const void *p, const void *q) 
{
    int l = ((struct n *)p)->p;
    int r = ((struct n *)q)->p; 
    return (l - r);
}
int fun(int t)
{
	int m=t;
	int s=0;
	while(m!=0)
	{
		s=s+m%10;
		m=m/10;	
	}
	return t^s;
}
int main()
{
	int n,i;	scanf("%d",&n);
	for(i=0;i<=10000000;i++)
	{
		A[i].p=0;
		A[i].num=i;
	}	
	int c=0;
	int max=0;
	int min=1000000;
	for(i=0;i<n;i++)
	{
		int t;	scanf("%d",&t);
		int k=fun(t);
		if(A[k].p==0)
				A[k].p++;
		else
		{
			A[k].p++;
			c++;
		}		
		if(k>max)
			max=k;
		if(k<min)
			min=k;	
	}
	if(c==0)
		printf("%d %d",max,c);
	else
	{
		qsort(A,10000001,sizeof(struct n),cmpfunc);
		for(i=10000000;i>=0;i--)
		{
			if(A[i].p!=A[i-1].p)
			{
				printf("%d %d",A[i].num,c);
				break;
			}
		}
	}	
}

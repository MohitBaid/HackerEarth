#include<stdio.h>
int main()
{
	int n,i;	scanf("%d",&n);
	int A[n+1];
	A[0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&A[i]);
		
	}	
	int s,e;
	scanf("%d %d",&s,&e);
	int t=s;
	int c=0;
	while(c<=n)
	{
		c++;
		if(s==e)
		{
			printf("Yes");
			return 0;
		}	
		else if(s==t)
		{
			break;
		}
		s=A[s];	
	}			
	printf("No");
	return 0;	
}

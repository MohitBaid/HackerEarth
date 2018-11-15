#include<stdio.h>
int cal(int n)
{
	if(n==1)	return 0;
	if(n==2)	return 1;
	if(n==3)	return 2;
	else
	{
		if(n%2==0)
			return 1+cal(n/2);
		else
			return 1+cal((n+1)/2);	
	}	
}
int main()
{
	int t;	scanf("%d",&t);
	while(t--)
	{
		int n,x,turns=0;
		scanf("%d %d",&n,&x);
		turns=cal(x);
		int r=(n)%3;
		if(r==0)	turns+=0;
		else		turns+=1;
		if(turns%2!=0)	printf("Mojo\n");
		else			printf("Jojo\n");				
	}
	return 0;
}

#include<stdio.h>
int main()
{
	int n,m,i;	scanf("%d %d",&n,&m);
	int A[n],S[n];
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	S[0]=A[0];
	for(i=1;i<n;i++)
		S[i]=A[i]+S[i-1];
	while(m--)
	{
		int l,r,x,s;	scanf("%d %d %d",&l,&r,&x);
		l--;	r--;
		if(l!=0)
			s=S[r]-S[l-1];
		else
			s=S[r];	
		int c=s%x;
		int q=s/x;
		printf("%d  %d   %d\n",c,q,s-c);	
	}		
}

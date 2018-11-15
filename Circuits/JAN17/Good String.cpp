#include<stdio.h>
int main()
{
	char ch[10010];
	scanf("%s",ch);
	int i,A[26],ans=0;
	for(i=0;i<26;i++)	A[i]=0;
	for(i=0;ch[i]!='\0';i++)
	 		A[(int)ch[i]-97]++;
	for(i=0;i<26;i++)
		if(A[i]!=0)
			ans+=A[i]-1;
	printf("%d",ans);			
}

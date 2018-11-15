#include<stdio.h>
int main()
{
	int N,i;	scanf("%d",&N);
	char ch[N+2];
	int C[26];
	int B[7];
	for(i=0;i<26;i++)
	{
		C[i]=0;
		if(i<7)
			B[i]=0;
	}
	scanf("%s",ch);
	for(i=0;ch[i]!='\0';i++)
			C[ch[i]-97]++;
	B[0]=C[0]/2;
	B[1]=C[2];
	B[2]=C[4]/2;
	B[3]=C[7]/2;
	B[4]=C[10];
	B[5]=C[17]/2;
	B[6]=C[19];
	int min=B[0];
	for(i=1;i<7;i++)	
	{
		if(min>B[i])
			min=B[i];
	}
	printf("%d\n",min);
	return 0;
}

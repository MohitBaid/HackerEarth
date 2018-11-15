#include<stdio.h>
int main()
{
	/*int k;	scanf("%d",&k);
	char s[5000];	scanf("%s",s);
	int i,j,f,m,res=0; char ch;
	for(i=0;s[i]!='\0';i++)
	{
		m=0;
		int alpha[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		for(j=i;m<=k,s[j]!='\0';j++)
		{
			ch=s[j];
			f=(int)ch;
			if(alpha[f-97]==0)
				{
					m++;
					alpha[f-97]++;
				}	
			if(m==k)
			{
				res++;
				//printf("%dMMMMM%cMMMMMMMM%d\n",res,ch,m);
			}						
		}	 	
	}
	printf("%d",res);*/
	for(int i=97-32;i<97+26;i++)
			printf("%c",i);
	return 0;
}

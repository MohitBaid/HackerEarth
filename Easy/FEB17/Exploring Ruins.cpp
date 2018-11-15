#include<stdio.h>
int main()
{
	char ch[55];int i;
	scanf("%s",ch);
	for(i=0;ch[i]!='\0';i++)
		if(ch[i]=='?')
		{
			if(ch[i+1]=='a'||ch[i-1]=='a')
				ch[i]='b';	
			else
				ch[i]='a';	
		}
	printf("%s",ch);
	return 0;	
}

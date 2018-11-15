#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
		char str[63]="abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		int T;		scanf("%d",&T);
		char ch[1000];
		while(T--)
		{
			int n=1,i,j,val=0,k=0;
			 scanf(" %[^\t\n]s",&ch);
			for(i=0;ch[i]!='\0';i++)
			{
				if(ch[i]==' ')
				{
					n++;
					k=0;
				}	
				else
				{
					for(j=0;str[j]!='\0';j++)
					{
						if(ch[i]==str[j])
						{
							val=val+j+(k++);
							break;
						}
					}
				}	
			}
			printf("%d\n",n*val);
		}
}

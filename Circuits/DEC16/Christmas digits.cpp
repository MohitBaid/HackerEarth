#include<stdio.h>
int main()
{
	char n[1000005];
	char x[1000005];
   char ans[1000005];
	int k,i,j;
	scanf("%s %d %s",n,&k,x);
	int ln,lx;
	for(ln=0;n[ln]!=0;ln++);
	for(lx=0;x[lx]!=0;lx++);
	if(ln==lx)
		printf("%s",n);
	else 
	{
		int c=0;
		int p=0,q=0;
		for(i=0;i<ln+q;i++)
		{
			if(n[i]>x[i])
			{
				ans[i+q]=n[i];	c++;
			}	
			else if(n[i]==x[i])		ans[i+q]=n[i];	
			else
			{	
				if(k>=0)
				{
					ans[i+q]=x[i];
					q++;
					ans[i+q]=n[i];
					k--;
				}
				else	ans[i+q]=n[i];
				printf("%s====",ans);
			}
		}			
		if(lx-ln>=k)
		{	
			for(i=0;i<lx-ln-1;i++)
				printf("9");
			if(!c)	
				printf("%c",x[lx-1]);	
		}
		else
		{
			for(i=0;i<lx-ln;i++)
				printf("9");		
		}		
	}
}

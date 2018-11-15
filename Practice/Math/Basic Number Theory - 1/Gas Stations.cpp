#include<bits/stdc++.h>
using namespace std;
int main()
{
		ios::sync_with_stdio(false); cin.tie(NULL);
		int n,x,i,temp;	scanf("%d %d",&n,&x);
		for(i=1;i<=n;i++)
		{
				scanf("%d",&temp);
				x-=temp;
				if(x<=0)
					break;
		}
		printf("%d\n",i);
}

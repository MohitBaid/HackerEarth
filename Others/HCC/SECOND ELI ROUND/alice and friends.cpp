#include <bits/stdc++.h>
using namespace std;

int main() 
{
	unsigned long long int n,i,j;
	unsigned long long int k,z;
	scanf("%lld",&n);
	n=n%30;
	k=pow(2,n);
	k=k%30;
	z=pow(2,k);
	z=(z-1)%1000000007;
	printf("%d\n",z);	
	return 0;
}	
	

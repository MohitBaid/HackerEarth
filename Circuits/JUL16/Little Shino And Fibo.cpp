#include <stdio.h>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

#define long long long
const long M = 1000000007; // modulo

map<long, long> F;
vector<long> T[1234];

long f(long n, int Depth) {
	T[Depth].push_back(n);
	if (F.count(n)) return F[n];
	long k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k, Depth+1)*f(k, Depth+1) + f(k-1, Depth+1)*f(k-1, Depth+1));
	} else { // n=2*k+1
		return F[n] = (f(k, Depth+1)*f(k+1, Depth+1) + f(k-1, Depth+1)*f(k, Depth+1));
	}
}

main(){
	int T,i;
	cin>>T;
	while(T--)
	{
		int a,b,s=0;
		cin>>a>>b;
		if(a>=15000)
		{
			a=a-15000;
			b=b-15000;
		}
		for(i=a-1;i<b;i++)
		{
			F[0]=F[1]=1;
			if (i==0) 
				s=s+0;
			else 
				s=s+f(i-1, 0);				
		}
		printf("%d\n",s%M);
	}	
}

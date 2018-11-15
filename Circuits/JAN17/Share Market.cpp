
#include<stdio.h>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<vector>
#include<list>
#include<utility>
#include<cstdio>
#include<iostream>

using namespace std;
set < pair <int,int> > s ;


void f(int numbers[], int index, int sum, int fo,int n)
{
     
    if (index == n)
    {
        s.insert(make_pair(fo,sum));
		return;
    }
    f(numbers, index + 1, sum + numbers[index], fo+1,n);
    f(numbers, index + 1, sum, fo,n);
}
int main()
{
    int T;	scanf("%d",&T);
    while(T--)
    {
    	int N,i;	scanf("%d",&N);
    	int A[N];
    	for(i=0;i<N;i++)
    		scanf("%d",&A[i]);
    	f(A,0,0,0,N);
		int k;	scanf("%d",&k);
		int X[k],C[k];
		for(i=0;i<k;i++)		scanf("%d",&X[i]);
		for(i=0;i<k;i++)		scanf("%d",&C[i]);
		for(i=0;i<k;i++)
			if(s.find(make_pair(X[i],C[i]))!=s.end())
				printf("Yes\n");
			else
				printf("No\n");	
    }
}


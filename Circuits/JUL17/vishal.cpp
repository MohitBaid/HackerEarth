#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,s,i,j=0,pos;
	cin>>n>>s;
	int * arr=(int *)malloc(sizeof(int)*n);
	int *brr=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		cin>>arr[i]>>brr[i];
	}
	float max_avg=0.0;
	int *arr_new=(int *)malloc(sizeof(int)*2000001);
	for(i=0;i<n;i++)
	{
		if(i==n-1)	pos=2000000;
		else	pos=arr[i+1];
		for(j=arr[i];j<=pos;j++)
		{
			arr_new[j]=brr[i];
		}
	}
		
	long long int sum=0;j=arr[0];int var=0;
	float time,temp=10000000.0;
	for(i=0;i<=2000000;i++)
	{
		if(j>=arr[n-1])			break;
		if(sum>=s)
		{
			if(arr_new[j]<arr_new[var-1])		time=1.0*(var-j)-(1.0*(sum-s))/arr_new[j];
			else	 							time=1.0*(var-j)-(1.0*(sum-s))/arr_new[var-1];
			if(time<temp)
			{
				temp=time;
				pos=j;
			}
			sum-=arr_new[j];
			j++;
		}
		else
		{
			sum+=arr_new[var];
			var++;
		}
	}
	time=(s*1.0)/brr[n-1];
	if(time<temp)
	{
		long long int num=s;
		long long int den=brr[n-1];
		long long int ans=__gcd(num,den);
		cout<<num/ans<<"/"<<den/ans<<endl;
	}
	else
	{
		sum=0;
		cout<<pos<<" "<<endl;
		for(i=pos;i<=2000000;i++)
		{
			sum+=arr_new[i];
			if(sum>=s)
			{
				time=i+1-pos;
				if(arr_new[i]>=arr_new[pos])
				{
					long long int num=time*arr_new[pos]-(sum-s);
					long long int den=arr_new[pos];
					long long int ans=__gcd(num,den);
					cout<<num/ans<<"/"<<den/ans<<endl;
					break;
				}
				else
				{
					long long int num=time*arr_new[i]-(sum-s);
                    long long int den=arr_new[i];
                    long long int ans=__gcd(num,den);
                    cout<<num/ans<<"/"<<den/ans<<endl;break;
				}
			}
		}
	}
}

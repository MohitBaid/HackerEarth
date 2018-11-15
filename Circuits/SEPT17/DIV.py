MOD = 1000000007
ans=1
x=int(input())
A=list(map(int,input().split()))
temp=1
for i in range(0,x):
	temp=temp*(A[i] +1)
for i in range(0,x):
	tem=( A[i]*(A[i]+1)//2 )*(temp//(A[i]+1))
	ans=ans*(tem+1)
print(ans%MOD)
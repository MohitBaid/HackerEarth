mod=1000000000+7
def powermod(a, b):
    if b == 0:
        return 1    
    if b == 1:
        return a % mod
    r = powermod(a, b//2)
    r = r * r % mod
    if (b & 1) == 1: 
        r = r * a % mod
    return r
for _ in range(int(input())):
	n=int(input())
	ans=(powermod(2,n)-1)%mod
	print( ans)
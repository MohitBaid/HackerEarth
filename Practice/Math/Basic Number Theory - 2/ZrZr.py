for _ in range(int(input())):
	n=int(input())
	ans=0
	p=5
	while n//p > 0:
		ans+=n//p
		p=p*5
	print(ans)
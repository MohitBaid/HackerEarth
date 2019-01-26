for _ in range(int(input())):
	s = list(map(int,input().split()))
	n = s[0]
	k = s[1]
	m = 0
	t = k
	while n >= 2*k :
		n = n - 2 * k
		k = k * t
	if n > k : 
	       m = 1
	if m%2 == 1:
		print("Alice")
	else:
		print("Bob")
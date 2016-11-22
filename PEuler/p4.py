def ispalin(n):
	a = []
	while n >0:
		r = n%10
		a.append(r)
		n = n/10
	
	l = len(a)
	p = 0
	q = l-1
	while p <= q:
		if a[p] != a[q]:
			return 0
		p=p+1
		q = q-1
	return 1

maxm = 10000
for i in range(100,1000):
	for j in range(100,1000):
		mul = i*j
		check = ispalin(mul)
		if check == 1:
			if maxm < mul:
				maxm = mul
				
				
print maxm

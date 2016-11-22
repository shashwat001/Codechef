import math
def retsum(n):
	sr = int(math.sqrt(n))
	if n==sr*sr:
		return 2*retsum(sr)
	i = 2
	j = 0
	while i*i <= n:
		if n%i == 0:
			j = n/i
			break;
		i = i+1
	
	if i*i > n:
		return n
	return retsum(i) + retsum(j)
	
strn = raw_input()
while strn != "":
	n = int(strn)
	print retsum(n)
	strn = raw_input() 

def readint():
	strt = raw_input()
	t = int(strt)
	return t


MAXN = 10
MOD = 100000000000007
a = []
for i in range(2*MAXN+1):
	b = []
	for j in range(i+1):
		if j == 0 or j == i:
			b.append(1)
		else:
			b.append((a[i-1][j-1]+a[i-1][j])%MOD)
	
	a.append(b)
	
n = readint()
r = readint()
print a[n][r]
	


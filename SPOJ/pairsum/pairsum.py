n = input()
sumc = []
f = []
sumc.append(0)
f.append(0)
strk = raw_input()
k = strk.split()
for i in range(1,n+1):
	sumc.append(int(k[i-1])+sumc[i-1])
	f.append(int(k[i-1])*sumc[i]+f[i-1])
	#print sumc[i],f[i]
m = input()
for i in range(m):
	strk = raw_input()
	k = strk.split()
	l = int(k[0])
	r = int(k[1])
	l = l+1
	r = r+1
	val = f[r] - f[l-1] - sumc[l-1]*(sumc[r]-sumc[l-1])
	print val

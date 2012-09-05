MOD = 100000000000007

	
def readint():
	strt = raw_input()
	t = int(strt)
	return t
	
c = []
c.append(1)
c.append(1)
for i in range(1,10000):
	k = (((c[i]))*(4*i+2))/(i+2)
	c.append(k)
	
d = []
d.append(1)
d.append(1)
d.append(2)
for i in range(3,10001):
	l = i+2
	k = ((((2*i+1)*d[i-1]) + ((3*i-3)*d[i-2])))/l
	d.append(k)
	
t = readint()
while t>0:
	s = raw_input()
	a = str.split(s)
	n = int(a[0])
	k = int(a[1])
	if k==0:
		print 0
	if k==1:
		print (d[n]-1)%MOD
	if k>=2:
		summ = (c[n]-1)%MOD
		print summ
	t = t-1


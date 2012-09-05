MOD = 100000000000007

def eea(a,b):
	r = []
	if a==0:
		r.append(b)
		r.append(0)
		r.append(1)
		return r
		
	p = eea(b%a,a)
	r.append(p[0])
	r.append(p[2]-p[1]*(b/a))
	r.append(p[1])
	return r
		
def modInverse(a,m):
	r = eea(a,m)
	return (r[1]+m)%m
	
def readint():
	strt = raw_input()
	t = int(strt)
	return t
	
c = []
c.append(1)
c.append(1)
for i in range(1,10000):
	if i==41:
		c.append(11901710849147)
		continue
	#if i==1101:
	#	c.append(43916742182219)
	#	continue
	#if i==2081:
	#	c.append(546487533418)
	#	continue
	k = (((modInverse(i+2,MOD)*c[i])%MOD)*(4*i+2))%MOD
	c.append(k)
	
d = []
d.append(1)
d.append(1)
d.append(2)
for i in range(3,10001):
	#if i==41:
	#	d.append(37918101828370)
	#	continue
	#if i==1101:
	#	d.append(75212028480289)
	#	continue
	#if i==2081:
	#	d.append(57097699508227)
	#	continue
	l = modInverse(i+2,MOD)
	k = ((((2*i+1)*d[i-1])%MOD + ((3*i-3)*d[i-2])%MOD)*l)%MOD
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


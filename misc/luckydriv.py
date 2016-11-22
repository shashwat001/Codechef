MOD = 1000000007
strt = raw_input()
t = int(strt)
b = []
c = []
for i in range(9):
	d = []
	for j in range(4):
		d.append(0)
	b.append(d)
	
for i in range(9):
	d = []
	for j in range(4):
		d.append(0)
	c.append(d)
		
while t>0:
	a = raw_input()
	l = len(a)
	for i in range(9):
		for j in range(4):
			b[i][j] = c[i][j] = 0
	i = 0
	z = 0
	while i<l:
		n = int(a[i]);
		if n==0:
			z = z+1;
		else:
			for j in range(9):
				c[j][0] = b[j][0]
			for j in range(9):
				for k in range(3):
					c[(j+n)%9][k+1] = (b[(j+n)%9][k+1] + b[j][k])%MOD
			c[n%9][0] = (c[n%9][0] + 1)%MOD
			temp = b
			b = c
			c = temp
		i=i+1
	tot = (b[0][0] + b[0][1] + b[0][2] + b[0][3])%MOD
	sum1 = z
	sum2 = (z*(z-1))/2
	sum3 = (sum2*(z-2))/3
	if z==0:
		sum3 = 0
	tot+= (((sum1+sum2+sum3)%MOD)*b[0][0])%MOD + ((sum1+sum2)*b[0][1])%MOD + (sum1*b[0][2])%MOD
	print tot%MOD
	t = t-1

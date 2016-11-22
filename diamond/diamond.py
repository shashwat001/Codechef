p = []
for i in range(2002):
	q = []
	for j in range(2002):
		q.append(0)
	p.append(q)
p[0][1] = 0
p[0][0] = 0
for i in range(1,2001):
	for j in range(1,((i+1)/2)+1):
	
		if j>(i/2):
			r = p[i-1][i-j]

		else:
			r = p[i-1][j]
		if (j-1)>(i/2):
			s = p[i-1][i-j+1]
		else:
			s = p[i-1][j-1]
		p[i][j] = 1.0 - ((r + s))*0.5
		
		
strt = raw_input()
t = int(strt) 
while t>0:
	res = 0.0;
	strn = raw_input()
	n = int(strn)
	strj = raw_input()
	j = str.split(strj)
	for i in range(1,((n+1)/2)+1):
		res = res+ p[n][i]*int(j[i-1])
	for k in range(i+1,n+1):
		res  = res+ p[n][n+1-k]*int(j[k-1])
	print '%0.3f' % res
	t = t-1
	
#	for i in range(1,11):
#		for j in range(1,(i+1)/2+1):
#			print p[i][j]

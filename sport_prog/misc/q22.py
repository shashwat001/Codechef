import math
strn = raw_input()
n = int(strn)
strt = raw_input()
ti = str.split(strt)
i = 0
while n > 0:
	t = int(ti[i])
	if t==1:
		print "NO"
		n = n-1
		i = i+1
		continue;
	rt = math.sqrt(t)
	j = int(rt)
	if j*j == t:
		print "YES"
	else:
		print "NO"
	n = n-1
	i = i+1

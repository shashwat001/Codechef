t = input()
while t>0:
	strt = raw_input()
	strt = strt.split(" ")
	n = int(strt[0])
	b = int(strt[1])
	q = 0;
	rem = 1;
	for i in range(2,n+1):
		q = (q*i)
		rem = rem*i
		dq = rem/b
		rem = rem%b
		q = (q+dq)%2
	if q==0:
		print "Even"
	else:
		print "Odd"
	t = t-1

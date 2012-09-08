strt = raw_input()
t = int(strt)
a = []
a.append(2)
for i in range(1,55):
	k = (a[i-1]*a[i-1])%1000000007
	a.append(k)
while(t>0):
	strn = raw_input()
	n = int(strn)
	if n==1 or n==2:
		print 0
		t = t-1
		continue
	if n==3:
		print 1
		t = t-1
		continue
	ans = 1;
	i = 0
	temp = n-4
	while temp > 0:
		if temp&1 == 1:
			ans = (ans * a[i])%1000000007
			temp = temp/2
			i = i+1
			continue
		else:
			temp = temp/2
			i = i+1
	print (ans*(n-1))%1000000007
	t = t-1

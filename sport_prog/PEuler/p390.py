import math
maxs = maxi = maxj = 0
for i in range(2,1000000):
	for j in range(i,1000000):
		b = i*i
		c = j*j
		s = b+c+b*c
		a = (b+c)*(b+c)
		if (s <= 1000000) and (s<a):
			ar = math.sqrt(s)
			if ar % 1 == 0:
				if maxs < s:
					maxs = s
					maxi = i
					maxj = j
					print i,j,s
		if s>a or s>1000000:
			break	
print maxs,maxi,maxj

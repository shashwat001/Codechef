i = 3
a = 1
b = 2
c = 3
suma = 2
while c <= 4000000:
	c = a+b
	if c%2 == 0:
		suma = suma+c
	a = b
	b = c
	
print suma

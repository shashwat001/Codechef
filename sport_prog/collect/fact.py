def fact(n):
	if n==1:	
		return 1
	return n*fact(n-1)
	
print (fact(21)*fact(5)/(((fact(4)**5)*fact(5)))%3046201)%3046201

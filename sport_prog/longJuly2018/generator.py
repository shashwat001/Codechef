import random

n = 10000
m = 20000
# k = 3
print n,m
for i in range(n):
    a = random.randint(1,100000)
    print a,
print
for i in range(m):
    a = 1
    b = 1
    while 1==1:
        a = random.randint(1,n)
        b = random.randint(1,n)
        if a != b:
            break
    k = random.randint(0,10)
    if k<3:
        print 2,a,b
    else:
        print 3,a,b,random.randint(1,1000)

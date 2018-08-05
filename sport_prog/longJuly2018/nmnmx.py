MOD = 1000000007
ncr = [[0 for x in range(5050)] for y in range(5050)]

def populatenCr():
    for i in range(1, 5005):
        ncr[i][0] = 1;
        for j in range(1, i):
            ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1])%MOD
        ncr[i][i] = 1

def power(x, y):
    val = 1;
    while y > 0:
        if(y&1) :
            val = (val*x)%MOD
        y>>=1
        x = (x*x)%MOD
    return val

populatenCr()
t = input()

while(t>0):
    x = raw_input()
    x = x.split(' ')
    n = int(x[0])
    k = int(x[1])

    a = [0 for x in range(n)]

    x = raw_input()
    x = x.split(' ')
    for i in range(n):
        a[i] = int(x[i])

    a.sort()
    sumv = 1;
    for i in range(1,n-1):
        left = i
        right = n-1-i
        total = ncr[n-1][k-1]
        if(left >= k-1):
            total = (total - ncr[left][k-1] + MOD)%MOD
        if(right >= k-1):
            total = (total - ncr[right][k-1] + MOD)%MOD

        sumv = (sumv * power(a[i], total))%MOD
    if n < 3:
        print 0
    else:
        print(sumv)
    t = t-1

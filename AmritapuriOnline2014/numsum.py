mod = 1000000007
inv = 111111112

def power(b,e,m):
    res = 1
    while e > 0:
        if e%2 == 1:
            res = (res*b)%m
        e = e/2;
        b = (b*b)%m  
    return res
     

def sumton(n):
    res = 0;
    for i in range(n):
        res = res+i
    return res

def contsum(n,d):
    a = ((power(10,n,mod)*d)/9)%mod
    return a


def sumdigits(n,d):
    an = power(10,n-1,mod)
    k = ((power(10,n-1,mod)-1+mod)*inv)%mod
    ansfirst = (45*(d)*k)%mod
    print ansfirst
    anssecond = (sumton(d)*10*k)%mod
    print anssecond
    ansthird = ((((10*k-n+1)/9)+n-1)*d)%mod
    print ansthird
    t1 = sumton(d)+d
    print t1
    ans = ansfirst+anssecond+ansthird+t1
    return ans

#print sumdigits(2,2)\cc\\\<F12>

def dfs(n,a,arr,idx,totdig):
    curval = contsum(a[idx][0],a[idx][1])
    cursumdigits = sumdigits(a[idx][0],a[idx][1])
    k = 0;
    if idx==0:
        k = 0
    else:
        k = ((power(10,totdig-1,mod)-1+mod)/9)%mod
    ansfirst = (45*k*curval)%mod 
    anssecond = ((cursumdigits-1)*power(10,totdig,mod))%mod
    ansthird = 0;
    if idx==0:
        ansthird = cursumdigits
    else:
        ansthird = (cursumdigits*(arr[idx-1]+1))%mod
    ans = (ansfirst+anssecond+ansthird)%mod
    
    if idx==n-1:
        return ans
    dfs(n,a,arr,idx+1,totdig+a[idx][0])



def storesum(n,a):
    ret = []
    i = 1
    sumd = contsum(a[0][0],a[0][1])
    ret.append(sumd)
    totdig = a[0][0]
    while i<n:
        sumd = contsum(a[i][0],a[i][1])
        sumd = (sumd*power(10,totdig,mod))%mod
        sumd = (sumd+ret[i-1])%mod
        ret.append(sumd)
        totdig = totdig+a[i][0]
        i = i+1

    return ret


t = input()
while t>0:
    t = t-1
    n = input()
    a = []
    for i in range(n):
        strn = raw_input()
        strt = strn.split(' ')
        a.append([int(strt[0]),int(strt[1])])
    print a
    arr = storesum(n,a)
    print arr
    #dfs(n,a,arr,0,0)

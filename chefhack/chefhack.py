
MAXM = 10000000

dx = [0,1,0,-1]
dy = [1,0,-1,0]
def inbds(x,y,n):
	if (x>=0 and x<n and y>=0 and y<n):
		return 1
	return 0


a = [None]*(MAXM+1)
a.append(-1)
a.append(-1)
for i in range(2,MAXM+1):
	a.append(0)
	
cnt = 0
for i in range(2,MAXM+1):
	if a[i]==(-1):
		continue
	a[i] = cnt
	cnt = cnt+1
	k = i+i
	while k <= MAXM:
		a[k] = -1
		k = k+i
		
		
a[0] = -1
a[1] = -1
strt = raw_input()
t = int(strt)
while t>0:
	e = []
	for i in range(351):
		f = []
		for j in range(351):
			f.append(0)
		e.append(f)
	sumd = 0
	strn = raw_input()
	n = int(strn)
	d = []
	for i in range(0,n):
		strd = raw_input()
		arr = str.split(strd)
		f = []
		for j in range(0,n):
			f.append(int(arr[j]))
		d.append(f)
			
	
	
	for i in range(0,n):
		for j in range(0,n):
			if a[d[i][j]]>=0:
				sumd+=a[d[i][j]]
				continue
				
			if ((e[i][j] == 1) or (e[i][j] == 2)):
				continue
			if d[i][j]%2==1:
				flag = 0
				for k in range(4):
					x = i+dx[k]
					y = j+dy[k]
					if (inbds(x,y,n) == 1):
						if (e[x][y] == 1):
							flag = 1
							break
				if flag==0:
					sumd+=(d[i][j]+3)/2
					for p in range(0,2):
						px = i+dx[p]
						py = j+dy[p]
						if inbds(px,py,n)==1:
							if (a[d[px][py]]<0):
								if d[px][py]%2==1:
									e[px][py] = 1

					e[i][j] = 1
				
			else:
				flag = 0
				for k in range(0,4):
					x = i+dx[k]
					y = j+dy[k]
					if (inbds(x,y,n)==1):
						if (e[x][y] == 2):
							flag = 1
							break

				if flag==0:
					sumd+=d[i][j]/2
					for p in range(0,2):
						px = i+dx[p]
						py = j+dy[p]
						check = inbds(px,py,n)
						if check==1:
							if (a[d[px][py]]<0):
								if (d[px][py]%2==0):
									e[px][py] = 2
					e[i][j] = 2

	print sumd
	t = t-1


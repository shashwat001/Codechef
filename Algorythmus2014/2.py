st = raw_input()
st = st.split(" ")
cr = int(st[0])
cc = int(st[1])
cnt = 0
s = "alela"
r = []
for i in range(cr):
	st = raw_input()
	r.append(st)
	r[i] = r[i].lower()

for i in range(cr):
	for j in range(cc-4):
		flag = 0
		for k in range(5):
			if r[i][j+k] != s[k]:
				flag = 1
				break
		if flag==0:
			cnt = cnt+1

for i in range(cc):
	for j in range(cr-4):
			flag = 0
			for k in range(5):
				if r[j+k][i] != s[k]:
					flag = 1
					break
			if flag==0:
				cnt = cnt+1

	
for i in range(cr-4):
	for j in range(cc-4):
			flag = 0
			for k in range(5):
				if r[i+k][j+k] != s[k]:	
					flag = 1				
					break
			if flag==0:
				cnt = cnt+1

for i in range(cr-4):
	for j in range(cc-4):
			flag = 0
			for k in range(5):
				if r[i+k][cc-1-j-k] != s[k]:		
					flag = 1			
					break
			if flag==0:
				cnt = cnt+1
print cnt*2

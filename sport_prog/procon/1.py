strt = raw_input()
t = int(strt)
a = []
a.append(0)
while t > 0:
	for i in range(5):
		s = raw_input()
		ass = s.split(' ');
		a.append(ass)
		
	for i in range(1,6):
		for j in range(1,6):
			for k in range(1,6):
				for l in range(1,6):
					for m in range(1,6):
						flag = 0
						z = []
						z.append(0);
						z.append(i);
						z.append(j);
						z.append(k);
						z.append(l);
						z.append(m);
						if i!=j and i!=k and i!=l and i!=m  and j!=k and j!=l and j!=m and l!=k and l!=m and m!=k:  
							for p in range (1,6):
								for q in range(len(a[p])):
									if a[p][q][0] == 'N':
										if a[p][q][1] <= '9':
											if z[p] == (a[p][q][1]-48):
												flag = 1
										else:
											if (z[p] - z[a[p][q][1]-65] == -1) or (z[p] - z[a[p][q][1]-65] == 1):
												flag = 1
												
									if a[p][q][0] <= '9' and a[p][q][0] >= '1':
										if z[p] != a[p][q][0]-48:
											flag = 1
									
									if a[p][q][0] <= 'E' and a[p][q][0] >= 'A':
										if (z[p] - z[a[p][q][0]-65] != -1) or (z[p] - z[a[p][q][0]-65] != 1):
											flag = 1
											
									if a[p][q][0] == '-':
										if z[p] > z[a[p][q][1]]:
											flag = 1
									if a[p][q][0] == '+':
										if z[p] < z[a[p][q][1]]:
											flag = 1
						
						if flag == 1:
							print "%c%c%c%c%c",z[1]+48,z[2]+48,z[3]+48,z[4]+48,z[5]+48

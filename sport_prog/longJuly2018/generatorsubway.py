import random
n = 8
existingVertices = [1]
remainingVertices = [i for i in range(2,11)]
edges = []


for i in reversed(range (1,n)):
    u = random.randint(0,n-i-1)
    u = existingVertices[u]

    v = random.randint(0, i-1)
    v = remainingVertices.pop(v)

    existingVertices.append(v)
    edges.append((u,v))

edges.extend(edges)
e = len(edges)
color = 5
print n, e
for i in range(len(edges)):
    print edges[i][0], edges[i][1], random.randint(1,color)

q = 10
print q
for i in range(q):
    a = random.randint(1,n)
    b = random.randint(1,n)
    while b == a:
        b = random.randint(1,n)
    print a,b

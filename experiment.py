from random import seed, shuffle, sample

T = 20000
ans = 0
N = 15
K = 3
suc = [0,0,0]
caso = [0,0,0]
TOT = 0

for i in range(T):
	L = [x for x in range(N)]
	shuffle(L)

	M = sample(L,K)
	M.sort()
	G = 49
	TOT = ( (N-K+1)*(N-K) ) / 2
	seen = []

	for x in M:
		good = 0
		for a in L:
			if a not in seen:
				if x + a >= N:
					good += 1
		seen += [x]
		G -= good

	print G / (TOT + .0)

# for i in range(T):
# 	L = [x for x in range(N)]
# 	shuffle(L)

# 	j = 0
# 	forb = []

# 	while j < LIM and len(forb) < (K + 1):
# 		if L[j] <= K:
# 			forb += [j]
# 		else:
# 			L[j] -= (K + 1)
# 		j += 1
	
# 	R = L[j+1::]
# 	M = [L[x] for x in range(N) if x not in forb]

# 	c = 0
	
# 	if len(forb) == 2:
# 		[a,b] = sample(R,2)		
# 	else:
# 		if len(forb) == 1:
# 			[a,b] = sample(M, 2)
# 			c = 1
# 		else:			
# 			[a,b] = sample(M, 2)
# 			c = 2

# 	caso[c] += 1
# 	if (a + b >= N):
# 		ans += 1
# 		suc[c] += 1

# print ans / (T + .0)
# print ans
# for i in range(3):
# 	print caso[i], suc[i] / (caso[i] + .0)
# print suc

# D = 0
# E = 0
# TOT = 0

# for i in range(T):
# 	L = [x for x in range(N)]
# 	shuffle(L)

# 	j = 0
# 	forb = []

# 	while len(forb) < (K + 1):
# 		if L[j] <= K:
# 			forb += [j]
# 		j += 1

# 	R = L[j::]
# 	M = [L[x]-(K+1) for x in range(j) if x not in forb]

# 	c = 0
# 	if len(R) >= 2:
# 		[a,b] = sample(R,2)
# 	else:
# 		if len(R) == 1:			
# 			a = R[0]
# 			TOT += a
# 			[b] = sample(M,1)
# 			c = 1			
# 		else:
# 			[a,b] = sample(M,2)
# 			c = 2

# 	caso[c] += 1
# 	if (a + b >= N):
# 		ans += 1
# 		suc[c] += 1

# print ans / (T + .0)
# print ans
# for i in range(3):
#  	print caso[i], suc[i] / (caso[i] + .0)
# print suc
# print TOT / (caso[1] + .0)
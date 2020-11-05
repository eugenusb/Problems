T = int(raw_input())

for caso in range(T):
	L,N,K = map(int, raw_input().split())

	if L == 1:
		if(K <= N):
			print "Case #",caso + 1, ": ",K
		else:
			print "Case #",caso + 1, ": ",0
	else:
		acum = 0
		ok = False
		for M in range(1,L+1):
			acum += L**((M+1)/2)
			if acum >= K:
				ok = True
				print "Case #",caso + 1, ": ",M
				break
		if not(ok):
			print "Case #",caso + 1, ": ",0

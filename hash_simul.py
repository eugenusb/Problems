from random import seed, sample

seed(123456789)

N = 2000000
L = [n for n in range(1,N+1)]

T = 50
S = 10

for k in range(T):
	M = sample(L, S)

	for d in range(2,N+1):
		s = set([])

		for a in M:
			s.add(a % d)

		if len(s) == S:
			print d,M
			break
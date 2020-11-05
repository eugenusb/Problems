seen = set([])

S = 1611516670
M = (1<<40)

seen.add((S / (1<<20), S % (1<<20)))

for i in range(1<<25):
	S = (S + S/(1<<20) + 12345) % M
	t = (S / (1<<20), S % (1<<20))

	if t in seen:
		print i
		break
	else:
		seen.add(t)
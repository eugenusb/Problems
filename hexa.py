N = int(raw_input())
L = []
dic = {}
tot = [0 for i in range(16)]
for i in range(N):
	a = str(raw_input())
	k = len(a)
	pot = 1
	for i in range(k):
		ind = k-1-i

		c = a[ind]
		j = -1
		if('0' <= c and c <= '9'):
			j = ord(c) - ord('0')
		else:
			j = ord(c) - ord('a') + 10
		tot[j] += j * pot
		pot *= 16

	L.append(a)

tot = sorted(tot)
mini = 0
maxi = 0

MOD = int(1e9+7)

for i in range(16):
	maxi = (maxi + i * tot[i]) % MOD
	mini = (mini + (15-i) * tot[i]) % MOD

maxi = format(maxi, 'x')
mini = format(mini, 'x')

print(mini, maxi)
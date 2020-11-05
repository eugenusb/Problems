from sys import stdin, stdout

MOD = int(1e9 + 7)

def solve():

	N, P = map(int, raw_input().split())

	pot = list(map(int, stdin.readline().strip().split()))

	if P == 1:
		n = len(pot)
		if n & 1:
			return 1
		return 0

	cant = {}
	l = []
	for p in pot:
		if p in cant:
			cant[p] += 1
		else:
			cant[p] = 1
			l += [p]

	l.sort()
	l.reverse()

	big = sum([pow(P, k) for k in pot])

	carry = 0

	for i in range(len(l)):
		po = l[i]
		expo = pow(P, po)
		q = carry / expo
		r = min(cant[po], q)
		carry -= r * expo
		cant[po] -= r
		big -= cant[po] * expo

		if cant[po] & 1:
			if big < expo:
				ans = expo - big
				return (ans % MOD)
			else:
				big -= expo
				carry += expo

	return (big % MOD)


T = int(raw_input())
ans = []

for caso in range(T):
	ans += [str(solve())]

stdout.write("\n".join(ans))
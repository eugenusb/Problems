from math import gcd

def read_int():
	return int(input())
 
def read_ints():
	return map(int, input().split())

def lcm(a,b):
	d = gcd(a,b)
	ans = a * b // d

	return ans

LCM = [2 for i in range(23)]

for i in range(3,23):
	l = lcm(LCM[i-1],i)
	LCM[i] = l

T = read_int()

for _ in range(T):
	n = read_int()
	a = list(read_ints())

	ok = True
	for i in range(min(n,21)):
		if a[i] % LCM[i+2] == 0:
			ok = False
			break

	if ok:
		print('YES')
	else:
		print('NO')
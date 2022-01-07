def read_int():
	return int(input())
 
def read_ints():
	return map(int, input().split())

def solve(s):	
	for cnd in range(2,4+1):
		for i in range(n+1-cnd):
			substr = s[i:i+cnd]
			if substr == 'aa':
				return 2
			if substr == 'aba' or substr == 'aca':
				return 3
			if substr == 'abca' or substr == 'acba':			
				return 4
	cnd = 7
	for i in range(n+1-cnd):
		substr = s[i:i+cnd]
		if substr == 'abbacca' or substr == 'accabba':
			return 7
	return -1

T = read_int()

for _ in range(T):
	n = read_int()
	s = input()
	ans = solve(s)

	print (ans)
def read_int():
	return int(input())
 
def read_ints():
	return map(int, input().split())

def solve_one_dim(k):
	ans = (k+2) // 3
	return (ans)

def solve(n,m):
	
	if n==1:
		ans = solve_one_dim(m)
		return (ans)

	q = n // 3
	r = n % 3
	hor_ans = m*q + r*solve_one_dim(m)
	q = m // 3
	r = m % 3
	ver_ans = n*q + r*solve_one_dim(n)

	ans = min(hor_ans, ver_ans)

	return ans

T = read_int()

for case_num in range(T):
	n,m = read_ints()

	n,m = min(n,m), max(n,m)
	ans = solve(n,m)

	print(ans)
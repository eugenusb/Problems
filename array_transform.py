def read_int():
	return int(input())
 
def read_ints():
	return map(int, input().split())

T = read_int()

for case_num in range(T):
	n = read_int()
	a = list(read_ints())
	b = list(read_ints())

	a.sort()
	b.sort()

	ok = True
	for i in range(n):
		if b[i] - a[i] != 1 and a[i] != b[i]:
			ok = False
			break

	ans = "NO"
	if ok:
		ans = "YES"

	print(ans)
T = int(raw_input())


def calc(pos, dig, pref, rem, lis):
	#print pos,dig,pref,rem,lis
	global dp
	#print dp
	if dp[pos][dig][pref][rem] != -1:
		return dp[pos][dig][pref][rem]
	if dig == 9:
		dp[pos][dig][pref][rem] = 0
		return 0
	if pos == (len(lis)-1):
		if (dig + rem) % 9 == 0:
			dp[pos][dig][pref][rem] = 0
			return 0
		else:
			dp[pos][dig][pref][rem] = 1
			return 1

	ans = 0
	r = (rem + dig) % 9

	if pref:
		for d in range(lis[pos+1]):
			ans += calc(pos+1, d, False, r, lis)
		ans += calc(pos+1, lis[pos+1], True, r, lis)
	else:
		for d in range(9):
			ans += calc(pos+1, d, False, r, lis)

	dp[pos][dig][pref][rem] = ans
	return (ans)

for caso in range(1,T+1):

	F,L = map(int, raw_input().split())

	# tot = 0
	# for d in range(F,L+1):
	# 	s = str(d)
	# 	r = d % 9
	# 	nine = (9 in map(int,s))
	# 	if r != 0 and not(nine):
	# 		tot += 1

	# print tot

	lis = map(int,str(L))
	n = len(lis)
	dp = [ [ [ [-1 for r in range(9)] for p in range(2) ] for j in range(10) ] for i in range(n) ]
	ans = sum([calc(0,d,False,0,lis) for d in range(lis[0])]) + calc(0,lis[0],True,0,lis)

	#print calc(0,lis[0],True,0,lis), sum([calc(0,d,False,0,lis) for d in range(lis[0])])

	lis = map(int,str(F-1))
	n = len(lis)
	dp = [ [ [ [-1 for r in range(9)] for p in range(2) ] for j in range(10) ] for i in range(n) ]
	ans -= (sum([calc(0,d,False,0,lis) for d in range(lis[0])]) + calc(0,lis[0],True,0,lis))
	#print lis,ans

	print "Case #" + str(caso) + ": "+ str(ans)
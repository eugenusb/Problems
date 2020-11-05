T = int(raw_input())

for caso in range(1,T+1):

	N,R,P,S = map(int, raw_input().split())

	ok = False
	ans = ""

	for let in "PRS":
		cur = let
		for i in range(N):
			nex = ""
			for l in cur:
				if(l == 'P'):
					if i < (N-3):
						nex += "RP"
					else:
						nex += "PR"
				if(l == 'S'):
					if i < (N-2):
						nex += "SP"
					else:
						nex += "PS"
				if(l == 'R'):
					if(i < (N-1)):
						nex += "SR"
					else:
						nex += "RS"

			cur = nex

		#print let, cur

		pc,rc,sc = 0,0,0

		for let in cur:
			if(let == "P"):
				pc += 1
			if(let == "S"):
				sc += 1
			if(let == "R"):
				rc += 1

		#print P,R,S,pc,rc,sc 

		if(P == pc and R == rc and S == sc):
			if(ok):
				ans = min(ans, cur)
			else:
				ok = True
				ans = cur

	if ok:
		print "Case #" + str(caso) + ": "+ str(ans)
	else:
		print "Case #" + str(caso) + ": IMPOSSIBLE"
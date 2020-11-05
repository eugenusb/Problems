from random import randint, seed

seed(123456789)

def calc(U):
	exp = [0 for i in range(10)]
	expec = [ [0 for j in range(U+1)] for d in range(10) ]
	expf = [0 for i in range(10)]
	#print expec

	for i in range(10**4):
		M = randint(1,10**U)
		k = randint(1,M)

		s = str(k)
		#print (M,k,s)
		for i in range(len(s)):
			c = ord(s[i]) - ord('0')
			#print c,i
			expec[c][i] += 1
			exp[c] += 1
			if i == 0:
				expf[c] += 1

	#print(expf)
	print(exp)
	#print(expec[15])

U = int(raw_input())

for i in range(10):
	calc(U)

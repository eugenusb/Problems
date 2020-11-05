from random import randint, seed

seed(123456789)

LIM = 100
N = 100000
T = 5

print T

for t in range(T):
	print N
	for i in range(N):
		a = randint(-LIM, LIM)
		print a

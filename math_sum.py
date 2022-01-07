from sys import stdin, stdout
import math

def solve():
	t = int(stdin.readline().strip())

	for caso in range(t):
		u,v = map(int, stdin.readline().split())
		x,y = u*u,-v*v

		stdout.write(str(x) + ' ' + str(y) + '\n')

if __name__ == '__main__':
	solve()
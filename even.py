import sys

def even(start,n):
	if start % 2 == 1:
		start += 1
	else:
		start += 2

	for i in range(n):
		print(start + 2*i, end=" ")

if __name__ == '__main__':
	start, n = int(sys.argv[1]), int(sys.argv[2])
	even(start,n)
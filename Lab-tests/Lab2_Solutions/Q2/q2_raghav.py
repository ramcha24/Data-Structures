# Raghav Passi

N = input()

A = map(int, raw_input().split())

invcount = 0

def mergesort(A, n):
	global invcount
	if n <= 1:
		return A
	X = mergesort(A[:n/2], n/2)
	Y = mergesort(A[n/2:], n - n/2)
	Z = []
	i, j = 0, 0
	while i < n/2 and j < (n - n/2):
		if X[i] <= Y[j]:
			Z.append(X[i])
			i += 1
		else:
			invcount += n/2 - i
			Z.append(Y[j])
			j += 1
	Z += X[i:] + Y[j:]
	return Z

mergesort(A, N)

print invcount
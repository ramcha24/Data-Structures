def mergeAndCount (A,B):

	C = []
	i = 0
	j = 0

	count = 0

	len_a = len (A)
	len_b = len (B)

	while i<(len_a) and j<(len_b):

		C.append (min(A[i],B[j]))

		if B[j] < A[i] :
			count = count + len_a - i
			j = j+1
		else :
			i = i+1

	if i == len_a :
		C = C + B[j:]
	else :
		C = C + A[i:]

	return count,C

def sortAndCount (A):

	if len(A) == 1 :
		return 0,A

	inv_A,P = sortAndCount (A[:len(A)/2])
	inv_B,Q = sortAndCount (A[len(A)/2:])

	count,R = mergeAndCount (P,Q)

	return inv_B+inv_A+count,R


N=input ()
A = map (int,raw_input().split(' '))

answer,sortedArray = sortAndCount (A)

print answer

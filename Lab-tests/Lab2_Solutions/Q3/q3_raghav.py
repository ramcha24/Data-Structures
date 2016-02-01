# Raghav Passi

A, B = map(int, raw_input().split())
M = 10 ** 9 + 7
ans = 1
for x in bin(B)[2:][::-1]:
	if x == '1':
		ans *= A
		ans %= M
	A *= A
	A %= M
print ans
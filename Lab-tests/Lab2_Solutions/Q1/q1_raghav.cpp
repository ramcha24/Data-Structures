// Raghav Passi

#include<bits/stdc++.h>

using namespace std;

int n, A[100000], B[100000];

void mergesort(int * A, int start, int end) {
	if (start == end) return;
	int a, b, c, d;
	a = start;
	b = (start + end)/2;
	c = (start + end)/2 + 1;
	d = end;
	mergesort(A, a, b);
	mergesort(A, c, d);
	int i = a, j = c, k = 0;
	while(i <= b && j <= d) {
		if(A[i] < A[j]) {
			B[k] = A[i];
			k += 1, i += 1;
		} else {
			B[k] = A[j];
			k += 1, j += 1;			
		}
	}
	while(i <= b) {
		B[k] = A[i];
		k += 1, i += 1;		
	}
	while(j <= d) {
		B[k] = A[j];
		k += 1, j += 1;		
	}
	for(i = 0, j = start; j <= end; i += 1, j += 1) {
		A[j] = B[i];
	}
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i += 1) {
		cin >> A[i];
	}
	mergesort(A, 0, n - 1);
	for(int i = 0; i < n; i += 1) {
		cout << A[i] << " ";
	}
	cout << "\n";
}
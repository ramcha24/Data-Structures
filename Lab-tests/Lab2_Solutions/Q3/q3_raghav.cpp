// Raghav Passi

#include<bits/stdc++.h>

using namespace std;

int main() {
	long long A, B, M = 1e9 + 7, ans = 1;
	cin >> A >> B;
	while(B) {
		if(B % 2) {
			ans *= A;
			ans %= M;
		}
		B /= 2;
		A *= A;
		A %= M;
	}
	cout << ans << endl;
}
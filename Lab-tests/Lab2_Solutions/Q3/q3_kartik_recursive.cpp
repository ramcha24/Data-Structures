 #include <iostream>
 using namespace std;
 #define MOD 1000000007
 long long power(long long a, long long  b)
 {
 	if(b==0) return 1;
        long long temp = power(a,b/2);

        if(b%2 == 0) return ( (temp % MOD) * (temp % MOD) ) % MOD;

        else return ( ((a * (temp % MOD))%MOD) * ( temp % MOD ) ) % MOD;
}
int main() {
// your code goes here
	long long t,a,b;
        cin>>a>>b;
        cout<<power(a,b)<<endl;
        return 0;
}

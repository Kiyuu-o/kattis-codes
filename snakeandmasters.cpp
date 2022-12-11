#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e6;

int memo[MOD+1];

int main() {
	int n;
	cin >> n;
	memo[1] = 1;
	memo[2] = 2;
	for (int i = 3; i <= n; i++) {
		memo[i] = (memo[i-1] + memo[i-2]) % MOD;
	}
	cout << memo[n] << '\n';
	return 0;
}

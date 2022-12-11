#include <bits/stdc++.h>
using namespace std;

const ll MOD = 1e9+7;

int factorial(int x) {
	int res = 1;
	for (int i = 2; i <= x; i++)
		res = res * i % MOD;
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;
	int res = 0;

	if (n > m) {
		res = (n - m) 
	} else {
		res = 1;
		for (int i = m + 1; i <= n; i++) {
			res = res * i % MOD;
		}
		res /= factorial(1LL*(n - m));
	}
	cout << res << '\n';
	return 0;
}

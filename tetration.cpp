#include <bits/stdc++.h>
using namespace std;

void solve() {
	double n;
	cin >> n;
	double ans = pow(n, 1/n);
	cout.precision(6);
	cout << ans << "\n";
}

int main() {
	solve();
	return 0;
}

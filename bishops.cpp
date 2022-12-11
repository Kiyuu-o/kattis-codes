#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	while (cin >> n) {
		if (n == 1) {
			cout << 1 << "\n";
		}
		else {
			cout << 2 * n - 2 << "\n";
		}
	}
}

int main() {
	solve();
	return 0;
}

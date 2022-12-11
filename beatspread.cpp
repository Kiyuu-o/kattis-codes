#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	while (n--) {
		int s, d;
		cin >> s >> d;
		int a = (s+d) / 2;
		int b = (s-d) / 2;
		if (s < d || a + b != s) {
			cout << "impossible\n";
		}
		else {
			cout << a << ' ' << b << '\n';
		}
	}
}

int main() {
	solve();
}
